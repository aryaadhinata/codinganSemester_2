#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tes Mesin Stack dinamis dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

void createEmpty(stack *S){
    (*S).top = NULL;
}

int isEmpty(stack S){
    int hasil = 0;
    if(S.top == NULL){
        hasil = 1;
    }
    return hasil;
}

int countElement(stack S){
    int hasil = 0;

    if(S.top != NULL){
        /* stack tidak kosong */

        elemen* bantu;

        /* inisialisasi */
        bantu = S.top;

        while(bantu != NULL){
            /* proses */
            hasil= hasil + 1;
            /* iterasi */
            bantu = bantu->next;
            }
        }
    return hasil;
}

void push(nilai temp, stack *S ){
    elemen* baru;
    baru = (elemen *) malloc (sizeof (elemen));
    baru->kontainer = temp;
    if((*S).top == NULL){
        //jika stack kosong
        baru->next = NULL;
    }else{
        //jika stack tidak kosong
        baru->next = (*S).top;
    }
    (*S).top = baru;
    baru = NULL;
}

void popto(stack *S, stack *T){
    if((*S).top != NULL){
        /*jika stack bukan list kosong*/
        elemen *pindah = (*S).top;
        
        if(countElement(*S) == 1){
            (*S).top = NULL;
        }else{
            (*S).top = (*S).top->next;
        }
        pindah->next = (*T).top;
        (*T).top = pindah;
    }else{
        printf("stek is emti\n");
    }
}

void pop(stack *S){
    if((*S).top != NULL){
        /*jika stack bukan list kosong*/
        elemen *hapus = (*S).top;
        
        if(countElement(*S) == 1){
            (*S).top = NULL;
        }else{
            (*S).top = (*S).top->next;
        }
        hapus->next = NULL;
        free(hapus);
    }else{
        printf("stek is emti\n");
    }
}

void printStack(stack S, stack T){
    printf("Barang di Gudan9:\n");
    if(S.top != NULL){
        elemen* bantu = S.top;
        int i = 1;

        while(bantu != NULL){
            printf("%d. %s (%d k9)\n", i, bantu->kontainer.nama, bantu->kontainer.berat);
            

            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }else{
        /* proses jika stack kosong */
        printf("-  k0son9!l1\n");
    }
    
    printf("\nBarang di TruK:\n");
    if(T.top != NULL){
        elemen* bantu = T.top;
        int i = 1;
    
        while(bantu != NULL){
            printf("%d. %s (%d k9)\n", i, bantu->kontainer.nama, bantu->kontainer.berat);
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }else{
        /* proses jika stack kosong */
        printf("- Koson9!l1\n");
    }
}