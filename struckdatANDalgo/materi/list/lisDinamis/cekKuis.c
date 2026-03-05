#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
    char nama[33], kondPut[33];
    int tahun;
    long long int uang;
}nilai;

typedef struct elmt* alamatelmt;
typedef struct elmt{
    nilai kontainer;
    alamatelmt next;
} elemen;

typedef struct{
    elemen* first;
}list;

void createList(list *L){
    (*L).first = NULL;
}

int countElement(list L){
    int hasil = 0;
    if(L.first != NULL){
        elemen* tunjuk = L.first;
        while(tunjuk != NULL){
            hasil++;
            tunjuk = tunjuk->next;
        }
    }
    return hasil;
}

void addFirst(nilai temp, list *L){
    elemen* baru = (elemen*) malloc(sizeof(elemen));
    baru->kontainer = temp;

    if((*L).first == NULL){
        baru->next = NULL;
    } else {
        baru->next = (*L).first;
    }

    (*L).first = baru;
}

void addAfter(elemen* prev, nilai temp, list *L){
    if(prev != NULL){
        elemen* baru = (elemen*) malloc(sizeof(elemen));
        baru->kontainer = temp;

        if(prev->next == NULL){
            baru->next = NULL;
        } else {
            baru->next = prev->next;
        }

        prev->next = baru;
    }
}

void addLast(nilai temp, list *L){
    if((*L).first == NULL){
        addFirst(temp, L);
    } else {
        elemen* prev = (*L).first;
        while(prev->next != NULL){
            prev = prev->next;
        }
        addAfter(prev, temp, L);
    }
}

void delFirst(list *L){
    if((*L).first != NULL){
        elemen* hapus = (*L).first;

        if(countElement(*L) == 1){
            (*L).first = NULL;
        } else {
            (*L).first = (*L).first->next;
            hapus->next = NULL;
        }

        free(hapus);
    }
}

void delAfter(elemen* prev, list *L){
    if(prev != NULL && prev->next != NULL){
        elemen* hapus = prev->next;

        if(hapus->next == NULL){
            prev->next = NULL;
        } else {
            prev->next = hapus->next;
            hapus->next = NULL;
        }

        free(hapus);
    }
}

void delLast(list *L){
    if((*L).first != NULL){
        if(countElement(*L) == 1){
            delFirst(L);
        } else {
            elemen* last = (*L).first;
            elemen* prev;

            while(last->next != NULL){
                prev = last;
                last = last->next;
            }

            delAfter(prev, L);
        }
    }
}

void delAll(list *L){
    while((*L).first != NULL){
        delLast(L);
    }
}

void pindah(list *L, elemen* pindah){
    elemen* prefPindah = L->first;
    elemen* prefAkhir = L->first;
    //printf("masuk pindah\n");
    if(pindah != L->first){
        while(prefPindah->next != pindah){
            //printf("%d -- %d\n", prefPindah->next->kontainer.tahun, pindah->kontainer.tahun);
            prefPindah = prefPindah->next;
        }
        prefPindah->next = pindah->next;
    }else{ // lsitnya keputus di awal jadi zombie
        L->first = prefPindah->next;
    }
    
    while(prefAkhir->next != NULL){
        //printf("masuk pindah while 2\n");
        prefAkhir = prefAkhir->next;
    }
    
    prefAkhir->next = pindah;
    // pindah->next = NULL;

    pindah->next = NULL;
    prefPindah = NULL;
    prefAkhir = NULL;
}

void walk(list* L, int trashHold){ // belum kepindah
    elemen* tunjuk = (*L).first;
    while((tunjuk != NULL) && (tunjuk->kontainer.uang != 0)){
        if(tunjuk->kontainer.tahun <= trashHold){
            tunjuk->kontainer.uang = 0;
            strcpy(tunjuk->kontainer.kondPut, "diputihkan");
        
            pindah(L, tunjuk);
            tunjuk = (*L).first;
        }else{
            tunjuk = tunjuk->next;
        }
    }
}

void printElemen(list L){
    elemen* tunjuk = L.first;
    while(tunjuk != NULL){
        printf("%s %d %lld %s\n", tunjuk->kontainer.nama, tunjuk->kontainer.tahun, tunjuk->kontainer.uang, tunjuk->kontainer.kondPut);
        tunjuk = tunjuk->next;
    }
}

int main() {
    list L;
    nilai temp;
    createList(&L);

    int banList;
    scanf("%d", &banList);

    for(int i = 0; i < banList; i++){
        scanf("%s %d %lld %s", temp.nama, &temp.tahun, &temp.uang, temp.kondPut);
        addLast(temp, &L);
    }

    int trashHold;
    scanf("%d", &trashHold);

    walk(&L, trashHold);
    printElemen(L);
    return 0;
}