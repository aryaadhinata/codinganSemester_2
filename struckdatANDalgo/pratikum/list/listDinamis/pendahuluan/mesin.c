#include "head.h"

void createList(list *L){
    (*L).first = NULL;
}

int countElement(list L){
    int hasil = 0;

    if(L.first !=NULL){
        /*list tidak kosong*/

        elemen* tunjuk;

        /*inisialisasi*/
        tunjuk = L.first;

        while(tunjuk != NULL){
        /*proses*/
        hasil = hasil + 1;

        /*iterasi*/
        tunjuk = tunjuk->next;
        }

    }

    return hasil;
}

void addFirst(nilai temp, list *L){
    elemen* baru;
    baru = (elemen*) malloc(sizeof(elemen));
    baru->kontainer = temp;

    if((*L).first == NULL){
    // jika list kosong
    baru->next = NULL;

    }else{
    // jika bukan list kosong
    baru->next = (*L).first;
    }

    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen* prev, nilai temp, list *L){
    elemen* baru;
    baru = (elemen*) malloc(sizeof(elemen));
    baru->kontainer = temp;

    if(prev->next == NULL){
    // jika elemen di akhir (prev next null)
    baru->next = NULL;
    } else{

    // jika elemen bukan di akhir
    baru->next = prev->next;
    }

    prev->next = baru;
    baru = NULL;
}

void addLast(nilai temp, list *L){
    if((*L).first == NULL){
        // jika list kosong gunakan addFirst
        addFirst(temp, L);
    } else{
        // jika list tidak kosong
        elemen* prev = (*L).first;

        while(prev->next != NULL){
        prev = prev->next;
        }
        // gunakan addAfter setelah ketemu
        //prev di akhir
        addAfter(prev, temp, L);
    }
}

void delFirst(list *L){
    if((*L).first != NULL){
        // jika list tidak kosong
        elemen* hapus = (*L).first;

        if(countElement(*L) == 1){
            // jika elemen hanya 1
            (*L).first = NULL;

        } else{
            // jika elemen lebih dari 1
            (*L).first = (*L).first->next;
            hapus->next = NULL;
        }

    // hapus di free kan
    free(hapus);
    }
}

void delAfter(elemen* prev, list *L){

    if(prev != NULL){
    // jika prev bukan NULL
    // declare pointer hapus dan diisi prev next

    elemen* hapus = prev->next;
        if(hapus->next == NULL){
        // jika elemen di akhir
        prev->next = NULL;
        }else{
        // jika elemen bukan di akhir
        prev->next = hapus->next;
        hapus->next = NULL;
        }
    // hapus di free kan
    free(hapus);
    }
}

void delLast(list *L){
    if((*L).first != NULL){
    // jika list tidak kosong 
        if(countElement(*L) == 1){
        // jika elemen hanya 1 gunakan delFirst
        delFirst(L);
        }else{
        // jika elemen lebih dari 1
        // declare pointer last dan prev
        elemen* last = (*L).first;
        elemen* prev;

        // loop untuk mencari posisi last dan prev
        while(last->next != NULL){
            prev = last;
            last = last->next;
        }
        delAfter(prev, L);
        }
    }
}

void delAll(list *L){
    if(countElement(*L) != 0){
    int i;

    for(i=countElement(*L);i>=1;i--){
        /*proses menghapus elemen list*/
        delLast(L);
    }
}
}

void printElement(list L){
    if(L.first != NULL){
        /*jika list tidak kosong*/
        /*inisialisasi*/
        elemen* tunjuk = L.first;
        
        printf("Data Schneider :\n");
        while(tunjuk != NULL){
            /*proses*/
            printf("- %s %s %d %s\n",tunjuk->kontainer.brand, tunjuk->kontainer.jenPak, tunjuk->kontainer.stock, 
                tunjuk->kontainer.avabli);
                
                /*iterasi*/
                tunjuk = tunjuk->next;
            }
        printf("----------------------------------------\n");
    }else{
        /*proses jika list kosong*/
        printf("Data Schneider :\n");
        printf("Ko0o0o0song!\n");
        printf("----------------------------------------\n");
    }
}
