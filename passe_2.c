#include <stdio.h>
#include <stdlib.h>

#include "utils/miniccutils.h"
#include "defs.h"
#include "passe_2.h"
#include "arch.h"

//second parcourt d'arbre

//on prendl'offset des variable globale qu'on ajoute au .data
//on ajoute ensuite les chaines de caractères dans le .data

//les variables temporaires sont en piles


int label_count=0;
int maxreg=0;
int32_t i;
extern char * outfile;
void exploration2(node_t root);
void ajout_asciiz_data();

void affect_registre();
int32_t precedent_reg;
int affiche_ident = 0;
void appel_systeme(node_t root);
bool r8_utilise = false;


void affect_op(node_t root);
void choix_node(node_t root, int32_t precedent_reg);
void choix_node_restore(node_t root);


void gen_code_passe_2(node_t root) {
    //à l'issu de la première passe nous avons l'offset total du code
    //le code est censé être totalement bon
    maxreg=get_num_registers();
    /*data_sec_inst_create();
    char* tmp=create_label();
    */
    
    create_program();
    dump_mips_program(outfile);
    data_sec_inst_create();
    //printf("%d", get_num_registers());
 
    exploration2(root);
    //comment_inst_create("exit");
    ori_inst_create(2, 0, 10);
    syscall_inst_create();
    //free_program();
}



void exploration2(node_t root){
    switch(root->nature){



        case(NODE_PROGRAM):
        //printf("node_program : \n");

        if(root->opr[0] != NULL){
            exploration2(root->opr[0]);
        }

        exploration2(root->opr[1]);
        //free_program();
        break;



        case(NODE_FUNC):
        //printf("node_func : \n");
        reset_temporary_max_offset();
        set_temporary_start_offset(root->offset);
        ajout_asciiz_data();
        text_sec_inst_create();
        label_str_inst_create(root->opr[1]->ident);
        stack_allocation_inst_create();
        exploration2(root->opr[2]);
        stack_deallocation_inst_create(root->offset + get_temporary_max_offset());
        break;




        case(NODE_DECLS):
        //si c'est un déclaration de variable globale on écrit dans le .data via
        //...
        //printf("NODE_DECLS\n");
        exploration2(root->opr[1]);
        //si c'est une variable locale on l'écrit en pile
        break;



        case(NODE_DECL):
        //printf("NODE_DECL\n");
        r8_utilise = false;
        if(root->opr[0]->nature == NODE_IDENT){
            if(root->opr[0]->global_decl == true){
                if(root->opr[1] != NULL){
                    word_inst_create(root->opr[0]->ident, root->opr[1]->value);
                }
            }

            else{
                if(root->opr[0]!= NULL){
                    exploration2(root->opr[0]);
                }
                if(root->nops > 1 && root->opr[1] != NULL && root->opr[0] != NULL){
                    affect_registre(root->opr[1]);
                    exploration2(root->opr[1]);
                    sw_inst_create(get_current_reg(), root->opr[0]->offset, 29);
                }
            }
    
        }
        break;



        case(NODE_LIST):
        //printf("node_list : \n");

        exploration2(root->opr[0]);
        if(root->opr[0]->nature == NODE_STRINGVAL){
            lui_inst_create(4, 0x1001);
            ori_inst_create(4, 4, root->opr[0]->offset);
            ori_inst_create(2, 0, 4);
            syscall_inst_create();
        }

        if(root->opr[1] != NULL){
            exploration2(root->opr[1]);
            if(root->opr[1]->nature == NODE_STRINGVAL){
            lui_inst_create(4, 0x1001);
            ori_inst_create(4, 4, root->opr[1]->offset);
            ori_inst_create(2, 0, 4);
            syscall_inst_create();
            }
        }
        if(affiche_ident != 0){
            if(root->opr[0]->nature == NODE_IDENT){
                appel_systeme(root->opr[0]);
            }
            if(root->opr[1]->nature == NODE_IDENT){
                appel_systeme(root->opr[1]);
            }
        }
        break;



        case(NODE_BLOCK):
        //printf("node_block\n");

        if(root->opr[0] != NULL){
            exploration2(root->opr[0]);
        }

        if(root->opr[1] != NULL){
            exploration2(root->opr[1]);
        }
        break;



        case(NODE_WHILE):
        //printf("node_while\n");
        int avant_cond_label = get_new_label();
        int fin_boucle_label = get_new_label(); //la seule méthode pour ne pas écraser nos label dans le cas de boucle imbriqués
       
        label_inst_create( avant_cond_label); //label avant les conditions
        exploration2(root->opr[0]);
        affect_registre(root->opr[0]);
       
        //si if est faux donc 0 je vais à fin_boucle_label
        beq_inst_create(get_current_reg(), get_r0(), fin_boucle_label);
        if(root->opr[1] != NULL){
            exploration2(root->opr[1]);
        }
       
        j_inst_create(avant_cond_label); //pour pouvoir retester
        label_inst_create( fin_boucle_label);
        //label de fin qui permet de sortir en cas de condition fausse
        break;



        case(NODE_FOR):
        //printf("node_for\n");
       
        //printf("node_for\n");
        int avant_cond_for = get_new_label();
        int fin_for = get_new_label();
        r8_utilise = false;
        
        //codition initiale
        exploration2(root->opr[0]);
        affect_registre(root->opr[0]);
       
        label_inst_create(avant_cond_for);
       
        exploration2(root->opr[1]);
        affect_registre(root->opr[1]);
       
        //résultat de l'expression chargé dans R8
        //si R8=0 on sort de la boucle
        //on doit donc utiliser un beq
       
        beq_inst_create(get_current_reg(), get_r0(), fin_for);
       
        if(root->opr[3] != NULL){
            exploration2(root->opr[3]);
        }
       
        //car c'est l'expression éffectué à chaque tour de boucle
        exploration2(root->opr[2]);
       
        j_inst_create(avant_cond_for);
        label_inst_create(fin_for);
        break;




        case (NODE_DOWHILE):
        //printf("node_DOWHILE\n");
        r8_utilise = false;
        int tmp_label = get_new_label();
        label_inst_create(tmp_label);
        if(root->opr[0] != NULL){
            exploration2(root->opr[0]);
        }
        exploration2(root->opr[1]);
        //charger la valeur on suppose qu'elle se trouve dans R8
        affect_registre(root->opr[1]);
       
        //si la condition est vraie alos on branche => donc beq
        bne_inst_create(get_current_reg(), get_r0(), tmp_label);
        break;




        case (NODE_IF):
        //printf("node_if\n");

        
            exploration2(root->opr[0]);
            r8_utilise = false;
            int label_if = get_new_label();
        
            //branche vers if si la condition est respectée on considère que le résultat de l'expression est rangé dans $8
            // si r8==0 => on va vers le else
            affect_registre(root->opr[0]);
            beq_inst_create(get_current_reg(), get_r0(), label_if);

            if(root->opr[1] != NULL){
                exploration2(root->opr[1]);
            }
            
            if(root->opr[2] == NULL){
                label_inst_create( label_if);
            }
            else{
                 int label_fin = get_new_label();
                j_inst_create(label_fin);
                label_inst_create(label_if);
                exploration2(root->opr[2]);
                label_inst_create(label_fin);
            }
        break;





        case(NODE_PRINT):
        //printf("node_print\n");
        if(root->opr[0]->nature == NODE_STRINGVAL || root->opr[0]->nature == NODE_IDENT ){
            appel_systeme(root->opr[0]);
        }
        else{
            affiche_ident = 1;
        }
        exploration2(root->opr[0]);
        affiche_ident = 0;
        break;




        case(NODE_PLUS):
        //printf("node_PLUS\n");
        affect_op(root);
        
        break;



        case(NODE_MINUS):
        //printf("node_minus\n");
        affect_op(root);
        break;
    

        case(NODE_MUL):
        //printf("node_mult\n");
        affect_op(root);
        break;

        case(NODE_DIV):
        affect_op(root);
        break;


        case(NODE_MOD):
        affect_op(root);
        break;


        case(NODE_BAND):
        //printf("node_band\n");
        affect_op(root);
        break;

        case(NODE_BOR):
        //printf("node_bor\n");
       affect_op(root);
        break;

        case(NODE_BXOR):
        //printf("node_bxor\n");
        affect_op(root);
        break;

        case(NODE_OR):
        //printf("node_or\n");
        affect_op(root);
        break;

        case(NODE_AND):
        //printf("node_and\n");
       affect_op(root);
        break;

        case (NODE_LT):
        //printf("node_lt\n");
        exploration2(root->opr[0]);
        exploration2(root->opr[1]);
        affect_registre(root->opr[0]);
        precedent_reg = get_current_reg();
        allocate_reg();
        affect_registre(root->opr[1]);
        slt_inst_create(precedent_reg, precedent_reg, get_current_reg());
        release_reg();
        break;

        case (NODE_GT):
        //printf("node_gt\n");
        exploration2(root->opr[0]);
        exploration2(root->opr[1]);
        affect_registre(root->opr[0]);
        precedent_reg = get_current_reg();
        allocate_reg();
        affect_registre(root->opr[1]);
        slt_inst_create(precedent_reg, get_current_reg(), precedent_reg);
        release_reg();
        break;
    
        case (NODE_LE):
        //printf("node_le\n");
        exploration2(root->opr[0]);
        exploration2(root->opr[1]);
        affect_registre(root->opr[0]);
        precedent_reg = get_current_reg();
        allocate_reg();
        affect_registre(root->opr[1]);
        slt_inst_create(precedent_reg, get_current_reg(), precedent_reg);
        xori_inst_create(precedent_reg, precedent_reg, 0x1);
        release_reg();
        break;

        case (NODE_GE):
        //printf("node_ge\n");
        exploration2(root->opr[0]);
        exploration2(root->opr[1]);
        affect_registre(root->opr[0]);
        precedent_reg = get_current_reg();
        allocate_reg();
        affect_registre(root->opr[1]);
        slt_inst_create(precedent_reg, precedent_reg, get_current_reg());
        xori_inst_create(precedent_reg, precedent_reg, 0x1);
        release_reg();
        break;

        case (NODE_EQ):
        //printf("node_eq\n");
        exploration2(root->opr[0]);
        exploration2(root->opr[1]);
        affect_registre(root->opr[0]);
        precedent_reg = get_current_reg();
        allocate_reg();
        affect_registre(root->opr[1]);
        xor_inst_create(precedent_reg, precedent_reg, get_current_reg());
        sltiu_inst_create(precedent_reg, precedent_reg, 1);
        release_reg();
        break;


        case (NODE_NE):
        //printf("node_ne\n");
        exploration2(root->opr[0]);
        exploration2(root->opr[1]);
        affect_registre(root->opr[0]);
        precedent_reg = get_current_reg();
        allocate_reg();
        affect_registre(root->opr[1]);
        xor_inst_create(precedent_reg, precedent_reg, get_current_reg());
        sltu_inst_create(precedent_reg, get_r0(), precedent_reg);
        release_reg();
        break;

        case(NODE_NOT):
        //printf("node_not\n");
        exploration2(root->opr[0]);
        affect_registre(root->opr[0]);
        xori_inst_create(get_current_reg(), get_current_reg(), 0x1);
        break;

        case(NODE_BNOT):
        //printf("node_bnot\n");
        exploration2(root->opr[0]);
        affect_registre(root->opr[0]);
        nor_inst_create(get_current_reg(), get_r0(), get_current_reg());
        break;

        case(NODE_SLL):
        //printf("node_sll\n");
        affect_op(root);
        break;

        case(NODE_SRA):
        //printf("node_sra\n");
        affect_op(root);
        break;


        case(NODE_SRL):
        //printf("node_srl\n");
        affect_op(root);
        break;


        case(NODE_UMINUS):
        //printf("node_uminus\n");
        exploration2(root->opr[0]);
        affect_registre(root->opr[0]);
        subu_inst_create(get_current_reg(), get_r0(), get_current_reg());
        break;


        case(NODE_AFFECT):
        //printf("node_affect\n");
        r8_utilise = false;
        exploration2(root->opr[0]);
        exploration2(root->opr[1]);
        affect_registre(root->opr[1]);

        if(root->opr[0]->decl_node->global_decl == true){
            precedent_reg = get_current_reg();
            allocate_reg();
            lui_inst_create(get_current_reg(), 0x1001);
            sw_inst_create(precedent_reg, root->opr[0]->offset, get_current_reg());
            release_reg();
        }
        else{
            sw_inst_create(get_current_reg(), root->opr[0]->offset, 29);
        }
        break;

        
    }
}


void ajout_asciiz_data(){
    for(i = 0; i < get_global_strings_number(); i ++){
        asciiz_inst_create(NULL, get_global_string(i));
    }

}


//Fonction pour mettre une valeur dans un registre
void affect_registre(node_t root){
    if(root->nature == NODE_INTVAL || root->nature == NODE_BOOLVAL){
        ori_inst_create(get_current_reg(), get_r0(), root->value);         
    }

    else if(root->nature == NODE_IDENT){
        if(root->decl_node->global_decl == false){
            lw_inst_create(get_current_reg(), root->offset, 29);
        }

        else{
            lui_inst_create(get_current_reg(), 0x1001);
            lw_inst_create(get_current_reg(), root->offset, get_current_reg());
        }
    }
}


void appel_systeme(node_t root){
    if(root->nature == NODE_STRINGVAL){
            lui_inst_create(4, 0x1001);
            ori_inst_create(4, 4, root->offset);
        }
    else if(root->nature == NODE_IDENT){
        if(root->decl_node->global_decl == false){
            lw_inst_create(4, root->offset,29);
        }
        else{
            lui_inst_create(4, 0x1001);
            lw_inst_create(4, root->offset, 4);
        }
    }
        ori_inst_create(2, get_r0(), 0x1);
        syscall_inst_create();
}
//Eventuellement envisager fonction pour les op binaires et pour les op unaires car assez répétitif si on a le temps;



void affect_op(node_t root){
    if((root->opr[0]->nature!= NODE_IDENT && root->opr[0]->nature!= NODE_INTVAL && root->opr[0]->nature!= NODE_BOOLVAL) && (root->opr[1]->nature == NODE_IDENT || root->opr[1]->nature == NODE_INTVAL || root->opr[1]->nature == NODE_BOOLVAL)){
        exploration2(root->opr[0]);
        precedent_reg = get_current_reg();
        allocate_reg();
        affect_registre(root->opr[1]);
        choix_node(root, precedent_reg);
        release_reg();
    }

    else if((root->opr[1]->nature!= NODE_IDENT && root->opr[1]->nature!= NODE_INTVAL && root->opr[1]->nature!= NODE_BOOLVAL) && (root->opr[0]->nature == NODE_IDENT || root->opr[0]->nature == NODE_INTVAL || root->opr[0]->nature == NODE_BOOLVAL)){
        if(get_current_reg()< get_num_registers() + get_num_arch_registers() - 2){
            affect_registre(root->opr[0]);
            if(reg_available){
                allocate_reg();
            }
            exploration2(root->opr[1]);
            precedent_reg = get_current_reg() - 1;
            choix_node(root, precedent_reg);
            release_reg();
        }

        else if(get_current_reg() ==  get_num_registers() + get_num_arch_registers() - 2 && r8_utilise == false){
            r8_utilise = true;
            affect_registre(root->opr[0]);
            push_temporary(get_current_reg());
            exploration2(root->opr[1]);
            pop_temporary(get_restore_reg());
            choix_node_restore(root);
            r8_utilise = false;
        }

        else{
            push_temporary(get_current_reg());
            affect_registre(root->opr[0]);
            exploration2(root->opr[1]);
            pop_temporary(get_restore_reg());
            choix_node(root, precedent_reg);
            }
        }

    else if((root->opr[0]->nature!= NODE_IDENT && root->opr[0]->nature!= NODE_INTVAL && root->opr[0]->nature!= NODE_BOOLVAL) && ((root->opr[1]->nature!= NODE_IDENT && root->opr[1]->nature!= NODE_INTVAL && root->opr[1]->nature!= NODE_BOOLVAL))){
        exploration2(root->opr[0]);
        precedent_reg = get_current_reg();
        allocate_reg();
        exploration2(root->opr[1]);
        choix_node(root, get_current_reg()- 1);
        release_reg();
    }

    else{
        r8_utilise = false;
        if(get_current_reg()< get_num_registers() + get_num_arch_registers() - 2){
            affect_registre(root->opr[0]);
            if(reg_available){
                allocate_reg();
            }
            affect_registre(root->opr[1]);
            precedent_reg = get_current_reg() - 1;
            choix_node(root, precedent_reg);
            release_reg();
        }

        else if(get_current_reg() ==  get_num_registers() + get_num_arch_registers() - 2 && r8_utilise == false){
            r8_utilise = true;
            affect_registre(root->opr[0]);
            push_temporary(get_current_reg());
            affect_registre(root->opr[1]);
            pop_temporary(get_restore_reg());
            choix_node_restore(root);
            r8_utilise = false;
            }

        else{
            push_temporary(get_current_reg());
            affect_registre(root->opr[0]);
            push_temporary(get_current_reg());
            affect_registre(root->opr[1]);
            pop_temporary(get_restore_reg());
            choix_node_restore(root);
            pop_temporary(get_restore_reg());
            choix_node_restore(root);
        }
    }
}



void choix_node(node_t root, int32_t precedent_reg){
    if(root->nature ==  NODE_PLUS){
        addu_inst_create(precedent_reg, precedent_reg, get_current_reg());
    }


    else if(root->nature ==  NODE_MINUS){
        subu_inst_create(precedent_reg, precedent_reg, get_current_reg());

    }

    else if(root->nature ==  NODE_MUL){
        mult_inst_create(precedent_reg, get_current_reg());
        mflo_inst_create(precedent_reg);

    }
    else if(root->nature ==  NODE_DIV){
        div_inst_create(precedent_reg, get_current_reg());
        teq_inst_create(get_current_reg(),get_r0());
        mflo_inst_create(precedent_reg);

    }

    else if(root->nature ==  NODE_MOD){
        div_inst_create(precedent_reg, get_current_reg());
        teq_inst_create(get_current_reg(),get_r0());
        mfhi_inst_create(precedent_reg);

    }
    

    else if(root->nature ==  NODE_AND){
        and_inst_create(precedent_reg, precedent_reg, get_current_reg());

    }

    else if(root->nature ==  NODE_OR){
        or_inst_create(precedent_reg, precedent_reg, get_current_reg());

    }

    else if(root->nature ==  NODE_BAND){
        and_inst_create(precedent_reg, precedent_reg, get_current_reg());

    }

    else if(root->nature ==  NODE_BOR){
        or_inst_create(precedent_reg, precedent_reg, get_current_reg());

    }

    else if(root->nature == NODE_BXOR){
        xor_inst_create(precedent_reg, precedent_reg, get_current_reg());

    }


    else if(root->nature == NODE_SLL){
        sllv_inst_create(precedent_reg, precedent_reg, get_current_reg());

    }


    else if(root->nature == NODE_SRA){
        srlv_inst_create(precedent_reg, precedent_reg, get_current_reg());

    }


    else if(root->nature == NODE_SRL){
        srav_inst_create(precedent_reg, precedent_reg, get_current_reg());

    }
}




void choix_node_restore(node_t root){
    if(root->nature ==  NODE_PLUS){
        addu_inst_create(get_current_reg(), get_restore_reg(), get_current_reg());
    }


    else if(root->nature ==  NODE_MINUS){
        subu_inst_create(get_current_reg(), get_restore_reg(), get_current_reg());

    }

    else if(root->nature ==  NODE_MUL){
        mult_inst_create(get_restore_reg(), get_current_reg());
        mflo_inst_create(get_current_reg());

    }
    else if(root->nature ==  NODE_DIV){
        div_inst_create(get_restore_reg(), get_current_reg());
        teq_inst_create(get_current_reg(),get_r0());
        mflo_inst_create(get_current_reg());

    }

    else if(root->nature ==  NODE_MOD){
        div_inst_create(get_restore_reg(), get_current_reg());
        teq_inst_create(get_current_reg(),get_r0());
        mfhi_inst_create(get_current_reg());

    }
    

    else if(root->nature ==  NODE_AND){
        and_inst_create(get_current_reg(), get_restore_reg(), get_current_reg());

    }

    else if(root->nature ==  NODE_OR){
        or_inst_create(get_current_reg(), get_restore_reg(), get_current_reg());

    }

    else if(root->nature ==  NODE_BAND){
        subu_inst_create(get_restore_reg(),get_restore_reg(), get_current_reg());

    }

    else if(root->nature ==  NODE_BOR){
        or_inst_create(get_restore_reg(), get_restore_reg(), get_current_reg());

    }

    else if(root->nature == NODE_BXOR){
        xor_inst_create(get_restore_reg(), get_restore_reg(), get_current_reg());

    }


    else if(root->nature == NODE_SLL){
        sllv_inst_create(get_restore_reg(), get_restore_reg(), get_current_reg());

    }


    else if(root->nature == NODE_SRA){
        srlv_inst_create(get_current_reg(), get_restore_reg(), get_current_reg());

    }


    else if(root->nature == NODE_SRL){
        srav_inst_create(get_restore_reg(), get_restore_reg(), get_current_reg());

    }
}



    
    
    
   