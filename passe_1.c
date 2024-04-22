#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "defs.h"
#include "passe_1.h"
#include "miniccutils.h"

extern int trace_level;

//NB le contexte ne contient que les informations sur le type et l'ident
//environement => empilement de contextes

int est_global = 1;


void exploration_arbre(node_t root);


void analyse_passe_1(node_t root) {
    //printf("\nentering analyse_passe_1\n");
    if(root->nature==NODE_PROGRAM){
        exploration_arbre(root);
    }
    else{
        //traiter les autres cas
        printf("Error line %d: la racine n'est pas de type NODE_PROGRAM", root->lineno);
    }
}
 


void exploration_arbre(node_t root){
    //printf("exploration arbre\n");

    switch(root->nature){

        case(NODE_PROGRAM):
        //printf("node_program : \n");

        if(root->opr[0] != NULL){
            push_global_context();
            exploration_arbre(root->opr[0]);
        }

        exploration_arbre(root->opr[1]);

        if(root->opr[0] != NULL){
            pop_context();
        }
        break;



        case(NODE_FUNC):
        //printf("node_func : \n");
        est_global = 0;
        reset_env_current_offset();
        if(strcmp(root->opr[1]->ident, "main")!= 0){
            printf("Error line %d: the name of the main function should be 'main'\n", root->opr[1]->lineno);
            exit(1);
        }

        else if(root->opr[0]->type != TYPE_VOID){
            printf("Error line %d: Return type of 'main()' function should be 'void'\n", root->opr[0]->lineno);
            exit(1);
        }

        push_context();
        exploration_arbre(root->opr[2]);
        pop_context();
        root->offset = get_env_current_offset();
        break;



        case(NODE_DECLS):
        //printf("node_decls : \n");
        

        if(root -> opr[0] -> type == TYPE_VOID){
            printf("Error line %d: variable of type void\n", (root->opr[0])->lineno);
            exit(1);
        }
        root->opr[1]->type = root->opr[0] ->type;
        exploration_arbre(root->opr[1]);
        break;



        case(NODE_LIST):
        //printf("node_list : \n");

        root->opr[0]->type = root ->type;
        exploration_arbre(root->opr[0]);

        if(root->opr[1] != NULL){
            root->opr[1]->type = root ->type;
            exploration_arbre(root->opr[1]);
        }
        break;



        case(NODE_DECL):
        //printf("node_decl\n");
    
        if(est_global){
            root->opr[0]->global_decl = true;
        }

        else{
            root->opr[0]->global_decl = false;
        }  

        root->opr[0]->offset = env_add_element(root->opr[0]->ident, root->opr[0]);
        if(root->opr[0] != NULL  && root->opr[0]->offset < 0){
            printf("Error line %d: Variable %s defined multiple times\n", (root->opr[0])->lineno, (root->opr[0])->ident);
            exit(1);
        }

        root->opr[0]->type = root->type;
        if(root->nops > 1 && root->opr[1] != NULL && root->opr[0] != NULL){
            exploration_arbre(root->opr[1]);
            if (root->opr[1] ->type != root->opr[0]->type){
                printf("Error line %d: variable initialized with wrong type\n", root->opr[0]->lineno);
                exit(1);
            }

            if(root->opr[0]->global_decl == true){
                if(root->opr[1] -> nature != NODE_BOOLVAL && root->opr[1] -> nature != NODE_INTVAL){
                    printf("Error line %d: global variables can only be initialized with a constant value\n", root->opr[0]->lineno);
                    exit(1);
                }
            }
        }
        break;



        case(NODE_BLOCK):
        //printf("node_block\n");

        if(root->opr[0] != NULL){
            exploration_arbre(root->opr[0]);
        }

        if(root->opr[1] != NULL){
            exploration_arbre(root->opr[1]);
        }
        break;



        case(NODE_WHILE):
        //printf("node_while\n");

        exploration_arbre(root->opr[0]);
        if(root->opr[0]->type != TYPE_BOOL){
            printf("Error line %d: 'while' condition does not have a boolean type\n", root->opr[0]->lineno);
            exit(1);
        }

        if(root->opr[1] != NULL){
            push_context();
            exploration_arbre(root->opr[1]);
            pop_context();
        }
        break;



        case(NODE_FOR):
        //printf("node_for\n");

        exploration_arbre(root->opr[0]);
        exploration_arbre(root->opr[1]);
        if(root->opr[1]->type != TYPE_BOOL){
            printf("Error line %d: 'for' condition does not have a boolean type\n", root->opr[0]->lineno);
            exit(1);
        }

        exploration_arbre(root->opr[2]);
        if(root->opr[3] != NULL){
            push_context();
            exploration_arbre(root->opr[3]);
            pop_context();
        }
        break;



        case (NODE_DOWHILE):
        //printf("node_DOWHILE\n");

        if(root->opr[0] != NULL){
            push_context();
            exploration_arbre(root->opr[0]);
            pop_context();
        }
        exploration_arbre(root->opr[1]);
        if(root->opr[1]->type != TYPE_BOOL){
            printf("Error line %d: 'while' condition in do-while statement does not have a boolean type\n", root->opr[1]->lineno);
            exit(1);
        }
        break;



        case (NODE_IF):
        //printf("node_if\n");

        exploration_arbre(root->opr[0]);
        if(root->opr[0]->type != TYPE_BOOL){
            printf("Error line %d: 'if' condition does not have a boolean type\n", root->opr[0]->lineno);
            exit(1);
        }

        if(root->opr[1] != NULL){
            push_context();
            exploration_arbre(root->opr[1]);
            pop_context();
        }

        if(root->opr[2] != NULL){
            push_context();
            exploration_arbre(root->opr[2]);
            pop_context();
        }
        break;



        case(NODE_PRINT):
        //printf("node_print\n");

        exploration_arbre(root->opr[0]);
        break;



        case (NODE_PLUS):
        //printf("node_plus\n");

        root->type = TYPE_INT;
        exploration_arbre(root->opr[0]);
        exploration_arbre(root->opr[1]);
        if(root->opr[1]->type != TYPE_INT){
            printf("Error line %d: Operator '+' cannot have right operand of TYPE BOOL\n", root->lineno);
            //exit(1);
        }

        else if(root->opr[0]->type != TYPE_INT){
            printf("Error line %d: Operator '+' cannot have left operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }
        break;



        case (NODE_MINUS):
        //printf("node_minus\n");

        root->type = TYPE_INT;
        exploration_arbre(root->opr[0]);
        exploration_arbre(root->opr[1]);
        if(root->opr[1]->type != TYPE_INT){
            printf("Error line %d: Operator '-' cannot have right operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }

        else if(root->opr[0]->type != TYPE_INT){
            printf("Error line %d: Operator '-' cannot have left operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }
        break;



        case (NODE_MUL):
        //printf("node_mul\n");

        root->type = TYPE_INT;
        exploration_arbre(root->opr[0]);
        exploration_arbre(root->opr[1]);
        if(root->opr[1]->type != TYPE_INT){
            printf("Error line %d: Operator '*' cannot have right operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }

        else if(root->opr[0]->type != TYPE_INT){
            printf("Error line %d: Operator '*' cannot have left operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }
        break;



        case (NODE_DIV):
        //printf("node_div\n");

        root->type = TYPE_INT;
        exploration_arbre(root->opr[0]);
        exploration_arbre(root->opr[1]);
        if(root->opr[1]->type != TYPE_INT){
            printf("Error line %d: Operator '/' cannot have right operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }

        else if(root->opr[0]->type != TYPE_INT){
            printf("Error line %d: Operator '/' cannot have left operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }
        break;




        case (NODE_MOD):
        //printf("node_mod\n");

        root->type = TYPE_INT;
        exploration_arbre(root->opr[0]);
        exploration_arbre(root->opr[1]);
        if(root->opr[1]->type != TYPE_INT){
            printf("Error line %d: Operator mod cannot have right operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }

        else if(root->opr[0]->type != TYPE_INT){
            printf("Error line %d: Operator mod cannot have left operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }
        break;




        case(NODE_LT):
    //printf("node_lt\n");

        root->type = TYPE_BOOL;
        exploration_arbre(root->opr[0]);
        exploration_arbre(root->opr[1]);
        if(root->opr[1]->type != TYPE_INT){
            printf("Error line %d: Operator '<' cannot have right operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }

        else if(root->opr[0]->type != TYPE_INT){
            printf("Error line %d: Operator '<' cannot have left operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }
        break;



        case (NODE_GT):
        //printf("node_GT\n");

        root->type = TYPE_BOOL;
        exploration_arbre(root->opr[0]);
        exploration_arbre(root->opr[1]);
        if(root->opr[1]->type != TYPE_INT){
            printf("Error line %d: Operator '>' cannot have right operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }

        else if(root->opr[0]->type != TYPE_INT){
            printf("Error line %d: Operator '>' cannot have left operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }
        break;



        case (NODE_LE):
        //printf("node_le\n");

        root->type = TYPE_BOOL;
        exploration_arbre(root->opr[0]);
        exploration_arbre(root->opr[1]);
        if(root->opr[1]->type != TYPE_INT){
            printf("Error line %d: Operator '<=' cannot have right operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }

        else if(root->opr[0]->type != TYPE_INT){
            printf("Error line %d: Operator '<=' cannot have left operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }
        break;




        case (NODE_GE):
        //printf("node_ge\n");

        root->type = TYPE_BOOL;
        exploration_arbre(root->opr[0]);
        exploration_arbre(root->opr[1]);
        if(root->opr[1]->type != TYPE_INT){
            printf("Error line %d: Operator '>=' cannot have right operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }

        else if(root->opr[0]->type != TYPE_INT){
            printf("Error line %d: Operator '>=' cannot have left operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }
        break;



        case (NODE_EQ):
        //printf("node_eq\n");

        root->type = TYPE_BOOL;
        exploration_arbre(root->opr[0]);
        exploration_arbre(root->opr[1]);
        if(root->opr[0]->type != root->opr[1]->type){
            printf("Error line %d: Operator '==' have different operand types \n", root->lineno);
            exit(1);
        }
        break;



        case (NODE_NE):
        //printf("node_ne\n");

        root->type = TYPE_BOOL;
        exploration_arbre(root->opr[0]);
        exploration_arbre(root->opr[1]);
        if(root->opr[0]->type != root->opr[1]->type){
            printf("Error line %d: Operator '!=' have different operand types \n", root->lineno);
            exit(1);
        }
        break;



        case (NODE_AND):
        //printf("node_and\n");

        root->type = TYPE_BOOL;
        exploration_arbre(root->opr[0]);
        exploration_arbre(root->opr[1]);
        if(root->opr[1]->type != TYPE_BOOL){
            printf("Error line %d: Operator '&&' cannot have right operand of TYPE INT\n", root->lineno);
            exit(1);
        }

        else if(root->opr[0]->type != TYPE_BOOL){
            printf("Error line %d: Operator '&&' cannot have left operand of TYPE INT\n", root->lineno);
            exit(1);
        }
        break;



        case (NODE_OR):
        //printf("node_or\n");

        root->type = TYPE_BOOL;
        exploration_arbre(root->opr[0]);
        exploration_arbre(root->opr[1]);
        if(root->opr[1]->type != TYPE_BOOL){
            printf("Error line %d: Operator '||' cannot have right operand of TYPE INT\n", root->lineno);
            exit(1);
        }

        else if(root->opr[0]->type != TYPE_BOOL){
            printf("Error line %d: Operator '||' cannot have left operand of TYPE INT\n", root->lineno);
            exit(1);
        }
        break;




        case (NODE_BAND):
        //printf("node_band\n");

        root->type = TYPE_INT;
        exploration_arbre(root->opr[0]);
        exploration_arbre(root->opr[1]);
        if(root->opr[1]->type != TYPE_INT){
            printf("Error line %d: Operator '&' cannot have right operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }

        else if(root->opr[0]->type != TYPE_INT){
            printf("Error line %d: Operator '&' cannot have left operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }
        break;




        case (NODE_BOR):
        //printf("node_bor\n");

        root->type = TYPE_INT;
        exploration_arbre(root->opr[0]);
        exploration_arbre(root->opr[1]);
        if(root->opr[1]->type != TYPE_INT){
            printf("Error line %d: Operator '|' cannot have right operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }

        else if(root->opr[0]->type != TYPE_INT){
            printf("Error line %d: Operator '|' cannot have left operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }
        break;




        case (NODE_BXOR):
        //printf("node_bxor\n");

        root->type = TYPE_INT;
        exploration_arbre(root->opr[0]);
        exploration_arbre(root->opr[1]);
        if(root->opr[1]->type != TYPE_INT){
            printf("Error line %d: Operator '^' cannot have right operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }

        else if(root->opr[0]->type != TYPE_INT){
            printf("Error line %d: Operator '^' cannot have left operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }
        break;




        case (NODE_NOT):
        //printf("node_not\n");

        root->type = TYPE_BOOL;
        exploration_arbre(root->opr[0]);
        if(root->opr[0]->type != TYPE_BOOL){
            printf("Error line %d: Operator '!' cannot have operand of TYPE INT\n", root->lineno);
            exit(1);
        }
        break;




        case (NODE_BNOT):
        //printf("node_bnot\n");

        root->type = TYPE_INT;
        exploration_arbre(root->opr[0]);
        if(root->opr[0]->type != TYPE_INT){
            printf("Error line %d: Operator '~' cannot have operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }
        break;




        case (NODE_SLL):
        //printf("node_sll\n");

        root->type = TYPE_INT;
        exploration_arbre(root->opr[0]);
        exploration_arbre(root->opr[1]);
        if(root->opr[1]->type != TYPE_INT){
            printf("Error line %d: Operator '<<' cannot have right operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }

        else if(root->opr[0]->type != TYPE_INT){
            printf("Error line %d: Operator '<<' cannot have left operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }
        break;




        case (NODE_SRA):
        //printf("node_sra\n");

        root->type = TYPE_INT;
        exploration_arbre(root->opr[0]);
        exploration_arbre(root->opr[1]);
        if(root->opr[1]->type != TYPE_INT){
            printf("Error line %d: Operator '>>>' cannot have right operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }

        else if(root->opr[0]->type != TYPE_INT){
            printf("Error line %d: Operator '>>>' cannot have left operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }
        break;




        case (NODE_SRL):
        //printf("node_srl\n");

        root->type = TYPE_INT;
        exploration_arbre(root->opr[0]);
        exploration_arbre(root->opr[1]);
        if(root->opr[1]->type != TYPE_INT){
            printf("Error line %d: Operator '>>' cannot have right operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }

        else if(root->opr[0]->type != TYPE_INT){
            printf("Error line %d: Operator '>>' cannot have left operand of TYPE BOOL\n", root->lineno);
            exit(1);
        }
        break;




        case (NODE_UMINUS):
        //printf("node_uminus\n");

        root->type = TYPE_INT;
        exploration_arbre(root->opr[0]);
        if(root->opr[0]->type != TYPE_INT){
            printf("Error line %d: Operator '-' cannot have operand of type BOOL\n", root->lineno);
            exit(1);
        }
        break;




        case (NODE_AFFECT):
        //printf("node_affect\n");

        exploration_arbre(root->opr[0]);
        exploration_arbre(root->opr[1]);
        if(root->opr[1]->type != root->opr[0]->type){
            printf("Error line %d: affectation of variable '%s' of wrong type\n", root->lineno, root->opr[0]->ident);
            exit(1);
        }

        else{
            root->type = root->opr[0]->type;
        }
        break;




        case (NODE_INTVAL):
        //printf("node_intval\n");
        root->type = TYPE_INT;
        break;
        



        case (NODE_BOOLVAL):
        //printf("node_boolval\n");
        root->type = TYPE_BOOL;
        break;




        case (NODE_STRINGVAL):
        //printf("node_stringval\n");
        root->offset = add_string(root->str);
        break;




        case (NODE_IDENT):
        //printf("node_ident\n");

        root->decl_node = get_decl_node(root->ident);
        if(root->decl_node != NULL){
            root->type = root->decl_node->type; 
            if(root->global_decl == false){
                root->offset = root->decl_node->offset; 
            }
        }

        else{
            printf("Error line %d: Variable '%s' undeclared\n", root->lineno, root->ident);
            exit(1);
        }
        break;
    }
}
