#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct{
    char nim[10];
    char nama[50];
    float nilai;
}nilaiMatKul;

typedef struct elm *alamatelmt;
typedef struct elm{
    nilaiMatKul kontainer;
    alamatelmt next;
}elemen;

typedef struct{
    elemen *first;
    elemen *last;
}queue;

void createEmpty(queue *Q){
    (*Q).first = NULL;
    (*Q).last = NULL;
}

int isEmpty(queue Q){
    int hasil = 0;
    if(Q.first == NULL){
        hasil = 1;
    }
    return hasil;
}

int countElement(queue Q){
    int hasil = 0;
    if(Q.first != NULL){
        /* queue tidak kosong */
        elemen* bantu;
        /* inisialisasi */
        bantu = Q.first;

        while(bantu != NULL){
            /* proses */
            hasil= hasil + 1;

            /* iterasi */
            bantu = bantu->next;
        }

    }

    return hasil;
}

void add(char nim[], char nama[], float nilai, queue *Q ){
    elemen* baru;
    baru = (elemen *) malloc (sizeof (elemen));
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.nilai = nilai;
    
    baru->next = NULL;
    if((*Q).first == NULL){
        (*Q).first = baru;
    }
    else{
        (*Q).last->next = baru;
    }
    
    (*Q).last = baru;
    baru = NULL;
}

void del(queue *Q){
    if((*Q).first != NULL){
        /* jika queue bukan queue kosong */
        elemen *hapus = (*Q).first;
        
        if(countElement(*Q) == 1){
            (*Q).first = NULL;
            (*Q).last = NULL;
            }else{
            (*Q).first = (*Q).first->next;
            hapus->next = NULL;
        }
        
        free(hapus);
    }
}

void printQueue(queue Q){
    if(Q.first != NULL){
        printf("------isi queue------\n");
        elemen* bantu = Q.first;
        int i = 1;
        while(bantu != NULL){
        printf("====================\n");
        printf("elemen ke : %d\n", i);
        printf("nim : %s\n",
        bantu->kontainer.nim);
        printf("nama : %s\n",

        bantu->kontainer.nama);

        printf("nilai : %f\n",
        bantu->kontainer.nilai);

        /* iterasi */
        bantu = bantu->next;
        i = i + 1;

        }
        printf("---------------------\n");
    }
    else{
        /* proses jika queue kosong */
        printf("queue kosong\n");
    }
}

int main(){
    queue Q;
    createEmpty(&Q);
    printQueue(Q);
    printf("=================\n");
    add("13507701", "Nana", 64.75, &Q);
    add("13507702", "Rudi", 75.11, &Q);
    add("13507703", "Dea", 84.63, &Q);
    printQueue(Q);
    printf("=================\n");
    del(&Q);
    del(&Q);
    printQueue(Q);
    printf("=================\n");
    return 0;
}