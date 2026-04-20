#include "head.h"

void createList(list *L){
    (*L).first = NULL;
    (*L).tail = NULL;
}

int countElement(list L){
    int hasil = 0;

    if(L.first !=NULL){
        /*list tidak kosong*/

        elemen* bantu;

        /*inisialisasi*/
        bantu = L.first;

        while(bantu != NULL){
            /*proses*/
            hasil = hasil + 1;

            /*iterasi*/
            bantu = bantu->next;
        }
    }
    return hasil;
}

void addFirst(nilai temp, list *L){
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    baru->kontainer = temp;

    if((*L).first == NULL){

        baru->prev = NULL;
        baru->next = NULL;

        (*L).tail = baru;
    }else{

        baru->next = (*L).first;
        baru->prev = NULL;
        (*L).first->prev = baru;

    }
    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen* before, nilai temp, list *L){
    if(before != NULL){
        elemen* baru;
        baru = (elemen*) malloc (sizeof (elemen));
        baru->kontainer = temp;

        if(before->next == NULL){
            baru->next = NULL;
            (*L).tail = baru;
        }else{
            baru->next = before->next;
            baru->next->prev = baru;
        }
        
        baru->prev = before;
        before->next = baru;
        baru = NULL;
    }
}

void addBefore(elemen* after, nilai temp, list *L){
    if(after != NULL){
        elemen* baru;
        baru = (elemen*) malloc (sizeof (elemen));
        baru->kontainer = temp;

        if(after->prev == NULL){
            baru->prev = NULL;
            (*L).first = baru;
        }else{
            baru->prev = after->prev;
            baru->prev->next = baru;
        }
        
        baru->next = after;
        after->prev = baru;
        baru = NULL;
    }
}

void addLast(nilai temp, list *L){
    if((*L).first == NULL){
        /*jika list adalah list kosong*/
        addFirst(temp, L);
    }else{
        /*jika list tidak kosong*/
        addAfter((*L).tail, temp, L);
    }
}

void delFirst(list *L){
    if((*L).first != NULL){
    /*jika list bukan list kosong*/
        elemen* hapus = (*L).first;
        if(countElement(*L) == 1){
            (*L).first = NULL;
            (*L).tail = NULL;
        }else{
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            hapus->next = NULL;

        }
    free(hapus);
    }
}

void delAfter(elemen* before, list *L){
    if(before != NULL){
        elemen* hapus = before->next;
        if(hapus != NULL){
            if(hapus->next == NULL){
                before->next = NULL;
                (*L).tail = before;
            }else{
                before->next = hapus->next;
                hapus->next->prev = before;
                hapus->next = NULL;
            }
        hapus->prev = NULL;
        free(hapus);
        }
    }
}

void delLast(list *L){
    if((*L).first != NULL){
        /*jika list tidak kosong*/
        if(countElement(*L) == 1){
            /*list terdiri dari satu elemen*/
            delFirst(L);
        }
        else{
            /*jika banyak elemen*/
            delAfter((*L).tail->prev, L);
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
    printf("+-------------------------------------+\n");
    printf("|         List Katalog Laptop         |\n");
    printf("+-------------------------------------+\n");
    if(L.first != NULL){
        /*jika list tidak kosong*/
        /*inisialisasi*/
        elemen* bantu = L.first;
        int i = 1;
        while(bantu != NULL){
            /*proses*/
            printf("| %d. %s %s %d %d\n", i, bantu->kontainer.merk, bantu->kontainer.tipe, bantu->kontainer.stock, bantu->kontainer.harga);
            /*iterasi*/
            bantu = bantu->next;
            i++;
        }
    }else{
        /*proses jika list kosong*/
        printf("| - Katalog lagi kosong\n");
    }
    printf("+-------------------------------------+\n");
}

void printElementReverse(list L){
    printf("+-------------------------------------+\n");
    printf("|         List Katalog Laptop         |\n");
    printf("+-------------------------------------+\n");
    if(L.tail != NULL){
        /*jika list tidak kosong*/
        /*inisialisasi*/
        elemen* bantu = L.tail;
        int i = 1;
        while(bantu != NULL){
            /*proses*/
            printf("| %d. %s %s %d %d\n", i, bantu->kontainer.merk, bantu->kontainer.tipe, bantu->kontainer.stock, bantu->kontainer.harga);
            /*iterasi*/
            bantu = bantu->prev;
            i++;
        }
    }else{
        /*proses jika list kosong*/
        printf("| - Katalog lagi kosong\n");
    }
    printf("+-------------------------------------+\n");
}