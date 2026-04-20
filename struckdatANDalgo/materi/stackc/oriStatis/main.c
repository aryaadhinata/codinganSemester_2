#include <stdio.h>
#include <string.h>

typedef struct{
    char nim[10];
    char nama[50];
    float skor;
}nilai;

typedef struct{
    int top;
    nilai data[10];
}stack;

void createEmpty(stack *S){
    (*S).top = -1;
}

int isEmpty(stack S){
    int hasil = 0;
    if(S.top == -1){
        hasil = 1;
    }
    return hasil;
}

int isFull(stack S){
    int hasil = 0;
    if(S.top == 9){
        hasil = 1;
    }
    return hasil;
}

void push(nilai temp, stack *S ){

    if(isFull(*S) == 1){
        /*jika stack penuh*/
        printf("stack penuh\n");
    }else{
        if(isEmpty(*S) == 1){
            /* jika stack kosong */
            (*S).top = 0;
            (*S).data[0] = temp;
        }else{
            /* jika stack tidak kosong */
            (*S).top = (*S).top + 1;
            (*S).data[(*S).top] = temp;
        }
    }
}

void pop(stack *S){
    if((*S).top == 0){
        /*jika stack berisi satu elemen*/
        (*S).top = -1;
    }else{
        if((*S).top != -1){
            /*jika stack tidak kosong*/
            (*S).top = (*S).top - 1;
        }
    }
}

void printStack(stack S){
    if(S.top != -1){
        printf("------isi stack------\n");
        int i;
        for(i=S.top;i>=0;i--){
            printf("====================\n");
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", S.data[i].nim);
            printf("nama : %s\n", S.data[i].nama);
            printf("nilai : %f\n", S.data[i].skor);
        }
        printf("---------------------\n");
    }else{
        /* proses jika stack kosong */
        printf("stack kosong\n");
    }
}

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
    printf("=================\n");
    pop(&S);
    pop(&S);
    printStack(S);
    printf("=================\n");
    return 0;
}