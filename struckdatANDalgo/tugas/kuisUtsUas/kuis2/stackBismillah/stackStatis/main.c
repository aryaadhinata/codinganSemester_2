#include "head.h"

int main(){
    stack S;
    createEmpty(&S);
    printStack(S);
    nilai temp;
    printf("=================\n");
    strcpy(temp.nim, "13507701");
    strcpy(temp.nama, "Nana");
    temp.skor = 64.75;
    push(temp, &S);
    strcmp(temp.nim, "13507702");
    strcmp(temp.nama, "Rudi");
    temp.skor = 75.11;
    push(temp, &S);
    strcmp(temp.nim, "13507703");
    strcmp(temp.nama, "Dea");
    temp.skor = 84.63;
    push( temp, &S);
    printStack(S);
    
    stack T;
    createEmpty(&T);
    popTo(&S, &T);
    popTo(&S, &T);
    printf("=================\n");
    printStack(T);
    printf("=================\n");
    pop(&T);
    pop(&T);
    printStack(T);
    printf("=================\n");
    return 0;
}