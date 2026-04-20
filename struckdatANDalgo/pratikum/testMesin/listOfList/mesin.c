#include "head.h"

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

        printf("+=================================+\n");
        while(bantu != NULL){
            printf("%s:\n", bantu->kontainer.kateg);
            eKolom* help = bantu->col;
            while(help != NULL){
                printf("| - %s : %s - %d halaman\n", help->kontainer_kol.nama, help->kontainer_kol.penulis, help->kontainer_kol.jumHal);
                help = help->next_kol;
            }
            bantu = bantu->next;
        }
    }else{
        printf("+=================================+\n");
        printf("Listnya kosong kak..\n");
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