#include "head.h"

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

void popTo(stack *S, stack *T){
    if((*S).top != -1){
        push((*S).data[(*S).top], T);
        pop(S);
    }else{
        // kosong nieh
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