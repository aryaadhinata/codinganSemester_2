#include "head.h"


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

void add(nilai temp, queue *Q){
    elemen* baru;
    baru = (elemen *) malloc (sizeof (elemen));
    baru->kontainer = temp;
    
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

void addPriority(nilai temp, queue *Q){
    elemen* baru;
    baru = (elemen *) malloc (sizeof (elemen));
    baru->kontainer = temp;
    
    baru->next = NULL;
    if((*Q).first == NULL){
        (*Q).first = baru;
        (*Q).last = baru;
    }else{
        if(countElement(*Q) >= baru->kontainer.prio){
            if(baru->kontainer.prio == 1){
                baru->next = (*Q).first;
                (*Q).first = baru;
            }else{
                elemen* bantu = (*Q).first;
                while(bantu->next->kontainer.prio < baru->kontainer.prio){
                    bantu = bantu->next;
                }
                baru->next = bantu->next;
                bantu->next = baru;
            }
        }else{
            (*Q).last->next = baru;
            (*Q).last = baru;
        }
    }
    baru = NULL;
}

void printQueue(queue Q){
    if(Q.first != NULL){
        printf("------isi queue------\n");
        elemen* bantu = Q.first;
        int i = 1;
        while(bantu != NULL){
            printf("====================\n");
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", bantu->kontainer.nim);
            printf("nama : %s\n", bantu->kontainer.nama);
            printf("nilai : %f\n", bantu->kontainer.skor);
            printf("prior : %d\n", bantu->kontainer.prio);
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
