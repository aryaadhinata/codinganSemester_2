#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan UTS dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

void createList(list *L){
    (*L).first = NULL;
}

int countElementB(list L){
    int hasil = 0;
    if(L.first != NULL){
        eBaris* bantu = L.first;
        while(bantu != NULL){
            hasil++;
            bantu = bantu->next;
        }
    }
    return hasil;
}

int countElementK(eBaris L){
    int hasil = 0;
    if(L.col != NULL){
        eKolom* bantu = L.col;
        while(bantu != NULL){
            hasil++;
            bantu = bantu->next_kol;
        }
    }
    return hasil;
}

void addFirstB(nilai temp, list *L){
    eBaris* baru = (eBaris *) malloc(sizeof(eBaris));
    baru->kontainer = temp;
    baru->col = NULL;
    baru->next = (*L).first;
    (*L).first = baru;
}

void addFirstK(nilaiSec temp, eBaris *L){
    eKolom* baru = (eKolom *) malloc(sizeof(eKolom));
    baru->kontainer_kol = temp;
    baru->next_kol = (*L).col;
    (*L).col = baru;
}

void addAfterB(eBaris *prev, nilai temp){
    eBaris* baru = (eBaris *) malloc(sizeof(eBaris));
    baru->kontainer = temp;
    baru->col = NULL;
    baru->next = prev->next;
    prev->next = baru;
}

void addAfterK(eKolom *prev, nilaiSec temp){
    eKolom* baru = (eKolom *) malloc(sizeof(eKolom));
    baru->kontainer_kol = temp;
    baru->next_kol = prev->next_kol;
    prev->next_kol = baru;
}

void addLastB(nilai temp, list *L){
    if((*L).first == NULL){
        addFirstB(temp, L);
    } else {
        eBaris *last = (*L).first;
        while(last->next != NULL) last = last->next;
        addAfterB(last, temp);
    }
}

void addLastK(nilaiSec temp, eBaris *L){
    if((*L).col == NULL){
        addFirstK(temp, L);
    } else {
        eKolom *last = (*L).col;
        while(last->next_kol != NULL) last = last->next_kol;
        addAfterK(last, temp);
    }
}

void delFirstK(eBaris *L){
    if((*L).col != NULL){
        eKolom* hapus = (*L).col;
        (*L).col = hapus->next_kol;
        hapus->next_kol = NULL;
        free(hapus);
    }
}

void delAfterK(eKolom* prev){
    if(prev != NULL && prev->next_kol != NULL){
        eKolom* hapus = prev->next_kol;
        prev->next_kol = hapus->next_kol;
        hapus->next_kol = NULL;
        free(hapus);
    }
}

void delLastK(eBaris *L){
    if((*L).col != NULL){
        if(countElementK(*L) == 1){
            delFirstK(L);
        } else {
            eKolom* last = (*L).col;
            eKolom* before_last = NULL;
            while(last->next_kol != NULL){
                before_last = last;
                last = last->next_kol;
            }
            delAfterK(before_last);
        }
    }
}

void delAllK(eBaris *L){
    while((*L).col != NULL){
        delFirstK(L);
    }
}

void delFirstB(list *L){
    if((*L).first != NULL){
        eBaris *hapus = (*L).first;
        delAllK(hapus);
        (*L).first = hapus->next;
        hapus->next = NULL;
        free(hapus);
    } else {
        printf("list kosong");
    }
}

void delAfterB(eBaris *prev){
    if(prev != NULL && prev->next != NULL){
        eBaris *hapus = prev->next;
        delAllK(hapus);
        prev->next = hapus->next;
        hapus->next = NULL;
        free(hapus);
    }
}

void delLastB(list *L){
    if((*L).first != NULL){
        if(countElementB(*L) == 1){
            delFirstB(L);
        } else {
            eBaris *last = (*L).first;
            eBaris *before_last = NULL;
            while(last->next != NULL){
                before_last = last;
                last = last->next;
            }
            delAfterB(before_last);
        }
    }
}

void delAllB(list *L){
    while((*L).first != NULL){
        delFirstB(L);
    }
}

/*
 * Format keluaran:
 * 1. Isi list of list (semua data)
 *    <namaAf>
 *    - <tokSup> <PersKom> <harPro> <proLak>
 *    ...
 * 2. Daftar affiliator dari produk masukan
 *    daftar affiliate <namPro>
 *    - <namaAf> <proLak>
 *    ...
 * 3. Daftar produk dari affiliator masukan
 *    daftar produk <namaAf>
 *    - <namPro> <tokSup> <PersKom> <harPro>
 *    ...
 */
void printElement(char namProCar[], char namAfCar[], list L){
    if(L.first == NULL) return;

    /* Bagian 1: cetak seluruh isi list of list */
    eBaris* bantu = L.first;
    while(bantu != NULL){
        printf("%s\n", bantu->kontainer.namaAf);
        eKolom* help = bantu->col;
        while(help != NULL){
            printf("- %s %d %d %d\n",
                help->kontainer_kol.tokSup,
                help->kontainer_kol.PersKom,
                help->kontainer_kol.harPro,
                help->kontainer_kol.proLak);
            help = help->next_kol;
        }
        bantu = bantu->next;
    }

    /* Bagian 2: daftar affiliator dari produk yang dicari */
    printf("daftar affiliate %s\n", namProCar);
    bantu = L.first;
    while(bantu != NULL){
        if(strcmp(bantu->kontainer.namPro, namProCar) == 0){
            eKolom* help = bantu->col;
            while(help != NULL){
                printf("- %s %d\n",
                    bantu->kontainer.namaAf,
                    help->kontainer_kol.proLak);
                help = help->next_kol;
            }
        }
        bantu = bantu->next;
    }

    /* Bagian 3: daftar produk dari affiliator yang dicari */
    printf("daftar produk %s\n", namAfCar);
    bantu = L.first;
    while(bantu != NULL){
        if(strcmp(bantu->kontainer.namaAf, namAfCar) == 0){
            eKolom* help = bantu->col;
            while(help != NULL){
                printf("- %s %s %d %d\n",
                    bantu->kontainer.namPro,
                    help->kontainer_kol.tokSup,
                    help->kontainer_kol.PersKom,
                    help->kontainer_kol.harPro);
                help = help->next_kol;
            }
        }
        bantu = bantu->next;
    }
}

eBaris* lastBaris(eBaris *first){
    if(first != NULL){
        while(first->next != NULL){
            first = first->next;
        }
    }
    return first;
}