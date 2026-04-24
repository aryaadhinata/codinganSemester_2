#include <stdio.h>
#include <string.h>

typedef struct{
    char nim[10];
    char nama[50];
    float skor;
}nilai;

typedef struct{
    int first;
    int last;
nilai data[10];
}queue;

void createEmpty(queue *Q){
    (*Q).first = -1;
    (*Q).last = -1;
}

int isEmpty(queue Q){
    int hasil = 0;
    if(Q.first == -1){
        hasil = 1;
    }
    return hasil;
}

int isFull(queue Q){
    int hasil = 0;
    if(Q.last == 9){
        hasil = 1;
    }
return hasil;
}

void add(nilai temp, queue *Q ){
    if(isEmpty(*Q) == 1){
        /* jika queue kosong */
        (*Q).first = 0;
        (*Q).last = 0;
        (*Q).data[0] = temp;
    }else{
        /* jika queue tidak kosong */
        if(isFull(*Q) != 1){
            (*Q).last = (*Q).last + 1;
            (*Q).data[(*Q).last] = temp;
        }else{
            printf("queue penuh\n");
        }
    }
}

void del(queue *Q){
    if((*Q).last == 0){
        (*Q).first = -1;
        (*Q).last = -1;
    }else{
        /*menggeser elemen ke depan*/
        int i;
        for(i=((*Q).first + 1);i<=(*Q).last;i++){
            (*Q).data[i-1] = (*Q).data[i];
        }
        (*Q).last = (*Q).last - 1;
    }
}

void printQueue(queue Q){
    if(Q.first != -1){
        printf("------isi queue------\n");
        int i;
        for(i=Q.last;i>=Q.first;i--){
            printf("====================\n");
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", Q.data[i].nim);
            printf("nama : %s\n", Q.data[i].nama);
            printf("nilai : %f\n", Q.data[i].skor);
        }
        printf("---------------------\n");
    }else{
        /* proses jika queue kosong */
        printf("queue kosong\n");
    }
}

int main(){
    queue Q;
    createEmpty(&Q);
    nilai temp;
    printQueue(Q);
    printf("=================\n");
    strcpy(temp.nim, "13507701");
    strcpy(temp.nama, "Nana");
    temp.skor = 64.75;
    add(temp, &Q);

    strcmp(temp.nim, "13507702");
    strcmp(temp.nama, "Rudi");
    temp.skor = 75.11;
    add(temp, &Q);
    
    strcmp(temp.nim, "13507703");
    strcmp(temp.nama, "Dea");
    temp.skor = 84.63;
    add(temp, &Q);
    
    printQueue(Q);
    printf("=================\n");
    del(&Q);
    del(&Q);
    printQueue(Q);
    printf("=================\n");

    return 0;
}