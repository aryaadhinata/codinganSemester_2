#include "head.h"

int main(){
    tree T;
    nilai temp;
    strcpy(temp.node, "root");
    makeTree(temp, &T);

    char state[513] = "root";
    char log[513] = "root";

    char pita[257];
    char perintah[9] = "belum";
    
    int awal = 1;
    do{
        char tengah[239] = "";
        char ukuran[9] = "";
        printf("┌──(zicofarry㉿Asoes36)-[%s]\n", log);
        printf("└─$ ");
        scanf("%256[^\n]%*c", pita);
        STARTWORD(pita);
        strcpy(perintah, GETWORD());

        if(strcmp(perintah, "exit") != 0 
            && strcmp(perintah, "ls") != 0 
            && strcmp(perintah, "whoami") != 0){
            
            while(EOPWORD(pita) != 1){
                INCWORD(pita);
                if((EOPWORD(pita) == 1) && (strcmp(perintah, "touch") == 0)){
                    strcat(ukuran, GETWORD());
                }else{
                    strcat(tengah, GETWORD());
                    strcat(tengah, " ");
                }
            }
        }
        tengah[strlen(tengah) - 1] = '\0';

        if(awal != 1){
            int ind = strlen(log);
            char saveDululah[ind];
            int indx = 0;
            while(log[ind] != '/'){
                saveDululah[indx] = log[ind];
                indx++;
                ind--;
            }
    
            char sementara[indx];
            for(int i = 0; i < indx; i++){
                sementara[i] = saveDululah[indx - i];
            }
            printf("%s", saveDululah);
        }
        awal = 0;


        strcpy(state, saveDululah);
        
        simpul *penghubung;
        penghubung = findSimpul(state, T.root);
        if(strcmp(perintah, "mkdir") == 0){
            strcpy(temp.node, tengah);
            temp.status = 'd';
            addChild(temp, penghubung);
            strcat(log, "/");
            strcat(log, temp.node);
        }else if(strcmp(perintah, "touch") == 0){
            strcpy(temp.node, tengah);
            temp.ukuran = atoi(ukuran);
            temp.status = 'f';
            addChild(temp, penghubung);
        }else if(strcmp(perintah, "rmdir") == 00){
            if(penghubung->kontainer.status == 'd'){
                delChild(penghubung->kontainer, penghubung);
            }
        }else if(strcmp(perintah, "rm") == 0){
            if(penghubung->kontainer.status == 'f'){
                delChild(penghubung->kontainer, penghubung);
            }
        }else if(strcmp(perintah, "rm -rf *") == 0){
            delAll(T.root);
        }else if(strcmp(perintah, "ls") == 0){
            printTreePreOrder(penghubung);
        }else if(strcmp(perintah, "cd") == 0){
            if(strcmp(tengah, "..") == 0){
                
            }else{

            }
        }else if(strcmp(perintah, "find") == 0){

        }else if(strcmp(perintah, "whoami") == 0){

        }
        printf("\n%s-%s-%s\n", perintah, tengah, ukuran);
    }while(strcmp(perintah, "exit") != 0);

    printf("logout\n");
    return 0;
}