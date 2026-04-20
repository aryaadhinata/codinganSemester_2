#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char nim[10];
    char nama[50];
}nilai;

typedef struct{
    char kode[10];
    char nilai[2];
}nilaiSec;

typedef struct eklm *alamatekolom;
typedef struct eklm{
nilaiSec kontainer_kol;
    alamatekolom next_kol;
}eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr{
    nilai kontainer;
    eKolom *col;
    alamatebaris next;
}eBaris;

typedef struct{
    eBaris *first;
}list;

void createList(list *L){
    (*L).first = NULL;
}

int countElementB(list L){
    int hasil = 0;
    if(L.first !=NULL){
        /*list tidak kosong*/
        eBaris* bantu;
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

int countElementK(eBaris L){
    int hasil = 0;
    if(L.col !=NULL){
        /*list tidak kosong*/
        eKolom* bantu;
        /*inisialisasi*/
        bantu = L.col;

        while(bantu != NULL){
            /*proses*/
            hasil = hasil + 1;

            /*iterasi*/
            bantu = bantu->next_kol;
        }
    }
    return hasil;
}

void addFirstB(nilai temp, list *L){
    eBaris* baru;
    baru = (eBaris *) malloc (sizeof (eBaris));
    baru->kontainer = temp;
    baru->col = NULL;

    if((*L).first == NULL){
        baru->next = NULL;
    }else{
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

void addFirstK(nilaiSec temp, eBaris *L){
    eKolom* baru;
    baru = (eKolom *) malloc (sizeof (eKolom));
    baru->kontainer_kol = temp;
    if((*L).col == NULL){
        baru->next_kol = NULL;
    }else{
        baru->next_kol = (*L).col;
    }
    (*L).col = baru;
    baru = NULL;
}

void addAfterB(eBaris *prev, nilai temp){
    eBaris* baru;
    baru = (eBaris *) malloc (sizeof (eBaris));
    baru->kontainer = temp;
    baru->col = NULL;
    if(prev->next == NULL){
        baru->next = NULL;
    }else{
        baru->next = prev->next;
    }
    prev->next = baru;
    baru = NULL;
}

void addAfterK(eKolom *prev, nilaiSec temp){
    eKolom* baru;
    baru = (eKolom *) malloc (sizeof (eKolom));
    baru->kontainer_kol = temp;
    if(prev->next_kol == NULL){
        baru->next_kol = NULL;
    }else{
        baru->next_kol = prev->next_kol;
    }
    prev->next_kol = baru;
    baru = NULL;
}

void addLastB(nilai temp, list *L){
    if((*L).first == NULL){
        addFirstB(temp, L);
    }else{
        eBaris *last = (*L).first;
        while(last->next != NULL){
            last = last->next;
        }
        addAfterB(last, temp);
    }
}

void addLastK(nilaiSec temp, eBaris *L){
    if((*L).col == NULL){
        addFirstK(temp, L);
    }else{
        eKolom *last = (*L).col;
        while(last->next_kol != NULL){
            last = last->next_kol;
        }
        addAfterK(last, temp);
    }
}

void delFirstK(eBaris *L){
    if((*L).col != NULL){
        eKolom* hapus = (*L).col;
        if(countElementK(*L) == 1){
            (*L).col = NULL;
        }else{
            (*L).col = (*L).col->next_kol;
            hapus->next_kol = NULL;
        }

        free(hapus);
    }
}

void delAfterK(eKolom* prev){
    eKolom* hapus = prev->next_kol;
    if(hapus != NULL){
        if(hapus->next_kol == NULL){
            prev->next_kol = NULL;
        }else{
            prev->next_kol = hapus->next_kol;
            hapus->next_kol = NULL;
        }

        free(hapus);
    }
}

void delLastK(eBaris *L){
    if((*L).col != NULL){
        if(countElementK(*L) == 1){
            delFirstK(L);
        }else{
            eKolom* last = (*L).col;
            eKolom* before_last;

            while(last->next_kol != NULL){
                before_last = last;
                last = last->next_kol;
            }

            delAfterK(before_last);
        }
    }
}

void delAllK(eBaris *L){
    if(countElementK(*L) != 0){
        int i;

        for(i = countElementK(*L); i >= 1; i--){
            delLastK(L);
        }
    }
}

void delFirstB(list *L){
    if((*L).first != NULL){
        eBaris *hapus = (*L).first;

        if(hapus->col != NULL){
            delAllK(hapus);
        }

        if(countElementB(*L) == 1){
            (*L).first = NULL;
        }else{
            (*L).first = (*L).first->next;
        }
        hapus->next = NULL;
        free(hapus);
    }else{
        printf("list kosong");
    }
}

void delAfterB(eBaris *prev){
    if(prev != NULL){
        eBaris *hapus = prev->next;
        if(hapus != NULL){
            if(hapus->col != NULL){
                delAllK;
            }
            
            if(hapus->next == NULL){
                prev->next = NULL;
            }else{
                prev->next = hapus->next;
            }
            hapus->next = NULL;
            free(hapus);
        }
    }
}

void delLastB(list *L){
    if((*L).first != NULL){
        if(countElementB(*L) == 1){
            delFirstB(L);
        }else{
            eBaris *last = (*L).first;
            eBaris *before_last;

            while(last->next != NULL){
                before_last = last;
                last = last->next;
            }

            delAfterB(before_last);
        }
    }
}

void delAllB(list *L){
    if(countElementB(*L) != 0){
        int i;

        for(i = countElementB(*L); i >= 1; i--){
            delLastB(L);
        }
    }
}

void printElement(list L){
    if(L.first != NULL){
        eBaris* bantu = L.first;
        int i = 1;

        while(bantu != NULL){
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", bantu->kontainer.nim);
            printf("nama : %s\n", bantu->kontainer.nama);
            
    list L;
    createList(&L);
    printElement(L);
    nilai tempB;
    nilaiSec tempK;
    printf("=================\n");
    
    strcpy(tempB.nim, "1");
    strcpy(tempB.nama, "orang_1");
    addFirstB(tempB, &L);
    
    strcpy(tempK.kode, "IF40K1");
    strcpy(tempK.nilai, "A");
    addFirstK(tempK, L.first);
    
    strcpy(tempK.kode, "IF40Z1");
    strcpy(tempK.nilai, "A");
    addAfterK(L.first->col, tempK);
    
    strcpy(tempK.kode, "IF40Z1");
    strcpy(tempK.nilai, "A");
    addLastK(tempK, L.first);
    
    
    strcpy(tempB.nim, "2");
    strcpy(tempB.nama, "orang_2");
    addAfterB(L.first, tempB);

    strcpy(tempK.kode, "TI5141");
    strcpy(tempK.nilai, "A");
    addFirstK(tempK, L.first->next);

    strcpy(tempK.kode, "IF5021");
    strcpy(tempK.nilai, "A");
    addLastK(tempK, L.first->next);

    strcpy(tempB.nim, "3");
    strcpy(tempB.nama, "Orang_3");
    addLastB(tempB, &L);

    strcpy(tempK.kode, "IF5321");
    strcpy(tempK.nilai, "A");
    addFirstK(tempK, L.first->next->next);
    printElement(L);
    printf("=================\n");
    delAllB(&L);
    printElement(L);
    printf("=================\n");
    return 0;
}