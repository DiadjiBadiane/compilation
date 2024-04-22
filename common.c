
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <inttypes.h>
#include <unistd.h>
#include <getopt.h>

#include "defs.h"
#include "common.h"
#include "arch.h"


extern char * infile;
extern char * outfile;
int32_t trace_level = DEFAULT_TRACE_LEVEL;
extern bool stop_after_syntax;
extern bool stop_after_verif;


void parse_args(int argc, char ** argv) {
    //infile = argv[1];
    // A implementer (la ligne suivante est a changer)
    outfile = "out.s";
    int nb_fichier_c = 0;
    int i;
    char* liste_options = "Usage: ./minicc <options> <infile>\n <infile>     : Input file to compile (mandatory)\noptions:\n-o <filename> : Set out file name (default = out.s).\n-t <int>      : Set trace level between 0 and 5 (0 = no trace, 5 = all traces. default = 0).\n-r <int>      : Set maximum number of registers to use (default = 8).\n-s            : Stop the compilation after the syntax anlysis(default = no).\n-v            : Stop compilation after the verification pass (default = no).\n-h            : Display this help\nOptions 's' and 'v' are incompatible\n";
    
    //Affichage de la liste des options (option -h)
    for(i = 1; i < argc; i ++){
        if(!(strcmp(argv[i], "-h"))){
            printf("%s", liste_options);
            exit(0);
        }
    }



    //Affichage de la bannière (option -b)
    for(i = 1; i < argc; i ++){
        if(!(strcmp(argv[i], "-b"))){
            if(argc == 2){ //l' option -b doit être utilisée seule
                printf("Compilateur de:\nUGUR Remi\nBADIANE Diadji\n");
                exit(0);
            }
            else{
                printf("Error: option '-b' must not be used with other options\n\n");
                printf("%s", liste_options);
                exit(1);
            }
        }
    }


    //parsing du fichier c
    for(i = 1; i < argc; i ++){
        //Recherche des fichiers  dans la ligne de commande (toute chaine sauf précédé par "-" ou suivi de -o ou -t ou -r)
        if(argv[i][0] != '-' && strcmp(argv[i - 1], "-o") != 0 && strcmp(argv[i - 1], "-r") != 0 && strcmp(argv[i - 1], "-t") != 0){
            FILE *testFichier = fopen(argv[i], "r");
            nb_fichier_c ++;
            if (!(strcmp(argv[i] + strlen(argv[i]) - 2, ".c")) && testFichier != NULL){
                    infile = argv[i];
                    fclose(testFichier);
                }
            else{
                printf("Error: file %s doesn' t exist\n", argv[i]);
                exit(1);
            }
        }
        if(nb_fichier_c > 1){ //Plus de 1 fichier .c 
            printf("Error: two input files given\n\n");
            printf("%s", liste_options);
            exit(1);
        }
    }

    
    if(!(nb_fichier_c)){
        printf("Error: input file not given\n\n");
        printf("%s", liste_options);
        exit(1);
    }


   
    for(i = 1; i < argc; i ++){
        if(argv[i][0] == '-'){
            //Parsing du fichier assembleur (option -o)
            if(!(strcmp(argv[i], "-o"))){
                if(i + 1 < argc){
                    outfile = argv[i + 1];
                }
                else{
                    printf("Error: output file after option '-o' not given\n\n");
                    printf("%s", liste_options);
                    exit(1);
                }
            }


            //Definition du niveau de trace (option -t)
            else if(!(strcmp(argv[i], "-t"))){
                if(i + 1 < argc){
                    if(!(atoi(argv[i + 1])) && (strcmp(argv[i + 1], "0"))){
                        printf("Error: trace level cannot be converted to an integer\n");
                        exit(1);
                    }
                    else if(atoi(argv[i + 1]) <= 5 && atoi(argv[i + 1]) >= 0){//Le niveau de trace doit être en 0 et 5
                        trace_level = atoi(argv[i + 1]);
                    }
                    else{
                        printf("Error: trace level must be comprised between 0 and 5\n\n");
                        printf("%s", liste_options);
                        exit(1);
                    }
                }
                else{
                    printf("Error: trace level after option '-t' not given\n\n");
                    printf("%s", liste_options);
                    exit(1);
                }
            }


            //Definition du nombre maximum de registre à utiliser (option -r)
            else if(!(strcmp(argv[i], "-r"))){
                if(i + 1 < argc){
                    if(!(atoi(argv[i + 1])) && (strcmp(argv[i + 1], "0"))){
                        printf("Error: number of register cannot be converted to an integer\n");
                        exit(1);
                    }
                    else if(atoi(argv[i + 1]) < 4 || atoi(argv[i + 1]) > 8){
                        printf("Error: the maximum number of registers to use  must be comprised between 4 and 8\n\n");
                        printf("%s", liste_options);
                        exit(1);
                    }
                    //Nombre maximum de registres à utiliser(entre 4 et 8)
                    else{
                        set_max_registers(atoi(argv[i + 1]));
                    }
                }
                else{
                    printf("Error: number of registers after option '-r' not given\n\n");
                    printf("%s", liste_options);
                    exit(1);
                }
            }



            //Arrêt de la compilation après l' analyse syntaxique(option -s)
            else if(!(strcmp(argv[i], "-s"))){ 
                for(int j = i; j < argc; j ++){
                    if(!(strcmp(argv[j], "-v"))){
                        printf("Options '-s' and '-v' are incompatible\n\n");
                        printf("%s", liste_options);
                        exit(1);
                    }
                }
                stop_after_syntax = true;
            }


            //Arrêt de la compilation après la passe de verification (option -v)
            else if(!(strcmp(argv[i], "-v"))){
                for(int k = i; k < argc; k ++){
                    if(!(strcmp(argv[k], "-s"))){
                        printf("Options '-s' and '-v' are incompatible\n\n");
                        printf("%s", liste_options);
                        exit(1);
                    }
                }
                stop_after_verif = true;
            }

            else{
                printf("Error: Unknown option: %s\n", argv[i]);
                exit(1);
            }
        }

    }
}







void free_nodes(node_t root) {
    //exploration de tout les noeuds
    ////printf("node->nature %s\n", node_nature2string(root->nature));
    if(root == NULL){
        return;
    }

    for(int i=0; i< root->nops;i++){
        //printf("%d\n", i);
        if(root->opr[i]!=NULL){
            //free_passe1(root->opr[i]);
            free(root->opr[i]);
        }
        root->opr[i] = NULL;
    }


    if(root->opr != NULL){
        free(root->opr);
        root->opr = NULL;
    }

    //printf(" free(decl_node)\n");
    //si nous sommes ici alors le noeud courrant de l'arbre actuel est devenue un noeud terminal
    if(root->decl_node!=NULL){
    //printf("node->nature: %s root->decl_node!=NULL\n", node_nature2string(root->nature));
        root->decl_node=NULL;
    }
    //printf(" free(ident)\n");
    if(root->ident!=NULL){
    //printf("ident : %s, node->nature: %s root->ident!=NULL\n", root->ident, node_nature2string(root->nature));
        free(root->ident);
        root->ident=NULL;
         
    }

    //printf(" free(str)\n");
    if(root->str!=NULL){
        //printf("root->str : %s, node->nature: %s root->str!=NULL\n", root->str, node_nature2string(root->nature));
        free(root->str);
        root->str=NULL;
    }


    free(root);
}



char * strdupl(char * s) {
    char * r = malloc(strlen(s) + 1);
    strcpy(r, s);
    return r;
}


static int32_t dump_tree2dot_rec(FILE * f, node_t n, int32_t node_num) {

    if (n == NULL) {
        fprintf(f, "    N%d [shape=record, label=\"{{NULL}}\"];\n", node_num);
        return node_num;
    }

    switch (n->nature) {
        case NODE_IDENT:
            {
                node_t decl_node = n->decl_node;
                fprintf(f, "    N%d [shape=record, label=\"{{NODE %s|Type: %s}|{<decl>Decl      |Ident: %s|Offset: %d}}\"];\n", node_num, node_nature2string(n->nature), node_type2string(n->type), n->ident, n->offset);
                if (decl_node != NULL && decl_node != n) {
                    fprintf(f, "    edge[tailclip=false];\n");
                    fprintf(f, "    \"N%d\":decl:c -> \"N%d\" [style=dashed]\n", node_num, decl_node->node_num);
                }
                break;
            }
        case NODE_INTVAL:
        case NODE_BOOLVAL:
            fprintf(f, "    N%d [shape=record, label=\"{{NODE %s|Type: %s}|{Value: %" PRId64 "}}\"];\n", node_num, node_nature2string(n->nature), node_type2string(n->type), n->value);
            break;
        case NODE_STRINGVAL:
            {
                char str[32];
                int32_t i = 1;
                while (true) {
                    str[i - 1] = n->str[i];
                    i += 1;
                    if (n->str[i] == '"') {
                        str[i - 1] = '\0';
                        break;
                    }
                }
                fprintf(f, "    N%d [shape=record, label=\"{{NODE %s|Type: %s}|{val: %s}}\"];\n", node_num, node_nature2string(n->nature), node_type2string(n->type), str);
            }
            break;
        case NODE_TYPE:
            fprintf(f, "    N%d [shape=record, label=\"{{NODE %s|Type: %s}}\"];\n", node_num, node_nature2string(n->nature), node_type2string(n->type));
            break;
        case NODE_LIST:
            fprintf(f, "    N%d [shape=record, label=\"{{NODE LIST}}\"];\n", node_num);
            break;
        case NODE_PROGRAM:
        case NODE_BLOCK:
        case NODE_DECLS:
        case NODE_DECL:
        case NODE_IF:
        case NODE_WHILE:
        case NODE_FOR:
        case NODE_DOWHILE:
        case NODE_PRINT:
            fprintf(f, "    N%d [shape=record, label=\"{{NODE %s|Nb. ops: %d}}\"];\n", node_num, node_nature2string(n->nature), n->nops);
            break;
        case NODE_FUNC:
            fprintf(f, "    N%d [shape=record, label=\"{{NODE %s|Nb. ops: %d}|{offset: %d}}\"];\n", node_num, node_nature2string(n->nature), n->nops, n->offset);
            break;
        case NODE_PLUS:
        case NODE_MINUS:
        case NODE_MUL:
        case NODE_DIV:
        case NODE_MOD:
        case NODE_LT:
        case NODE_GT:
        case NODE_LE:
        case NODE_GE:
        case NODE_EQ:
        case NODE_NE:
        case NODE_AND:
        case NODE_OR:
        case NODE_BAND:
        case NODE_BOR:
        case NODE_BXOR:
        case NODE_SRA:
        case NODE_SRL:
        case NODE_SLL:
        case NODE_NOT:
        case NODE_BNOT:
        case NODE_UMINUS:
        case NODE_AFFECT:
            fprintf(f, "    N%d [shape=record, label=\"{{NODE %s|Type: %s|Nb. ops: %d}}\"];\n", node_num, node_nature2string(n->nature), node_type2string(n->type), n->nops);
            break;
        default:
            printf("*** Error in %s: unknow nature : %s\n", __func__, node_nature2string(n->nature));
            assert(false);
    }

    n->node_num = node_num;

    int32_t curr_node_num = node_num + 1;
    for (int32_t i = 0; i < n->nops; i += 1) {
        int32_t new_node_num = dump_tree2dot_rec(f, n->opr[i], curr_node_num);

        fprintf(f, "    edge[tailclip=true];\n");
        fprintf(f, "    N%d -> N%d\n", node_num, curr_node_num);
        curr_node_num = new_node_num + 1;
    }

    return curr_node_num - 1;
}



static void dump_tree2dot(FILE * f, node_t root) {
    assert(root->nature == NODE_PROGRAM);

    int32_t curr_node_num = 1;
    dump_tree2dot_rec(f, root, curr_node_num);
}


void dump_tree(node_t prog_root, const char * dotname) {

    FILE * f;

    f = fopen(dotname, "w");
    fprintf(f, "digraph global_vars {\n");
    dump_tree2dot(f, prog_root);
    fprintf(f, "}");    
    fclose(f);
}


const char * node_type2string(node_type t) {
    switch (t) {
        case TYPE_NONE:
            return "TYPE NONE";
        case TYPE_INT:
            return "TYPE INT";
        case TYPE_BOOL:
            return "TYPE BOOL";
        case TYPE_VOID:
            return "TYPE VOID";
        default:
            assert(false);
    }
}


const char * node_nature2string(node_nature t) {
    switch (t) {
        case NONE:
            return "NONE";
        case NODE_PROGRAM:
            return "PROGRAM";
        case NODE_BLOCK:
            return "BLOCK";
        case NODE_LIST:
            return "LIST";
        case NODE_DECLS:
            return "DECLS";
        case NODE_DECL:
            return "DECL";
        case NODE_IDENT:
            return "IDENT";
        case NODE_TYPE:
            return "TYPE";
        case NODE_INTVAL:
            return "INTVAL";
        case NODE_BOOLVAL:
            return "BOOLVAL";
        case NODE_STRINGVAL:
            return "STRINGVAL";
        case NODE_FUNC:
            return "FUNC";
        case NODE_IF:
            return "IF";
        case NODE_WHILE:
            return "WHILE";
        case NODE_FOR:
            return "FOR";
        case NODE_DOWHILE:
            return "DOWHILE";
        case NODE_PLUS:
            return "PLUS";
        case NODE_MINUS:
            return "MINUS";
        case NODE_MUL:
            return "MUL";
        case NODE_DIV:
            return "DIV";
        case NODE_MOD:
            return "MOD";
        case NODE_LT:
            return "LT";
        case NODE_GT:
            return "GT";
        case NODE_LE:
            return "LE";
        case NODE_GE:
            return "GE";
        case NODE_EQ:
            return "EQ";
        case NODE_NE:
            return "NE";
        case NODE_AND:
            return "AND";
        case NODE_OR:
            return "OR";
        case NODE_BAND:
            return "BAND";
        case NODE_BOR:
            return "BOR";
        case NODE_BXOR:
            return "BXOR";
        case NODE_SLL:
            return "SLL";
        case NODE_SRA:
            return "SRA";
        case NODE_SRL:
            return "SRL";
        case NODE_NOT:
            return "NOT";
        case NODE_BNOT:
            return "BNOT";
        case NODE_UMINUS:
            return "UMINUS";
        case NODE_AFFECT:
            return "AFFECT";
        case NODE_PRINT:
            return "PRINT";
        default:
            fprintf(stderr, "*** Error in %s: Unknown node nature: %d\n", __func__, t);
            exit(1);
    }
}




const char * node_nature2symb(node_nature t) {
    switch (t) {
        case NONE:
        case NODE_PLUS:
            return "+";
        case NODE_MINUS:
            return "-";
        case NODE_MUL:
            return "*";
        case NODE_DIV:
            return "/";
        case NODE_MOD:
            return "%";
        case NODE_LT:
            return "<";
        case NODE_GT:
            return ">";
        case NODE_LE:
            return "<=";
        case NODE_GE:
            return ">=";
        case NODE_EQ:
            return "==";
        case NODE_NE:
            return "!=";
        case NODE_AND:
            return "&&";
        case NODE_OR:
            return "||";
        case NODE_BAND:
            return "&";
        case NODE_BOR:
            return "|";
        case NODE_BXOR:
            return "^";
        case NODE_SRA:
            return ">>";
        case NODE_SRL:
            return ">>>";
        case NODE_SLL:
            return "<<";
        case NODE_NOT:
            return "!";
        case NODE_BNOT:
            return "~";
        case NODE_UMINUS:
            return "-";
        default:
            fprintf(stderr, "*** Error in %s: Unknown node nature: %d\n", __func__, t);
            exit(1);
    }
}




