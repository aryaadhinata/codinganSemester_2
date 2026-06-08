#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan UTS dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

// O(1) nggak ada loop
void createList(list *L){
    (*L).first = NULL;
    (*L).tail = NULL;
}

// O(1) nggak ada loop
int countElement(list L){
    int hasil = 0;

    if(L.first !=NULL){
        elemen* bantu;
        bantu = L.first;

        while(bantu != NULL){
            hasil = hasil + 1;

            bantu = bantu->next;
        }
    }
    return hasil;
}

// O(1) nggak ada loop
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

// O(1) nggak ada loop
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

// O(1) nggak ada loop
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

// O(1) nggak ada loop
void addLast(nilai temp, list *L){
    if((*L).first == NULL){
        /*jika list adalah list kosong*/
        addFirst(temp, L);
    }else{
        /*jika list tidak kosong*/
        addAfter((*L).tail, temp, L);
    }
}

// O(1) nggak ada loop
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

// O(1) nggak ada loop
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

// O(1) nggak ada loop
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

// O(n) karena cuma loop biasa
void delAll(list *L){

    if(countElement(*L) != 0){
        int i;

        for(i=countElement(*L);i>=1;i--){
            /*proses menghapus elemen list*/
            delLast(L);
        }
    }
}


// O(n^2) karena ada nested while
void printElement(int posisi, int banyak, int n, list L){
    if(L.first != NULL){
        elemen* bantu = L.first;

        printf("isi list:\n");
        while(bantu != NULL){
            printf("%s %s %d %lld\n", bantu->kontainer.namCre, bantu->kontainer.temVid, bantu->kontainer.tahVid, bantu->kontainer.jumVie);
            bantu = bantu->next;
        }

        printf("\ntampilan spesifikasi:\n");

        int overlap = 0;
        int temPosisi = posisi;
        int ban = banyak;
        while(ban != 0 && overlap != 1){ // loop sebanyak yang dinginkan
            elemen* banDep = L.first; // untuk print depan
            elemen* banBel = L.tail; // print belakang
            int banJal = temPosisi - 1;// banyak langiah yang diperlukan di kurangi satu karen alangsung gerak
            while(banJal != 0 && overlap != 1){ // gerakan untuk kebagian posisi yang diingainkan
                banDep = banDep->next;
                banBel = banBel->prev;
                if(banDep == banBel || banDep->prev == banBel->next){ // jika sudah sama atau overlap setelah loop ini keluar
                    overlap = 1;
                }
                banJal--;
            }
            printf("\nelemen ke-%d\n", temPosisi);
            if(overlap != 1){
                printf("dari belakang - %s %s %d %lld\n", banBel->kontainer.namCre, banBel->kontainer.temVid, banBel->kontainer.tahVid, banBel->kontainer.jumVie);
                printf("dari depan - %s %s %d %lld\n", banDep->kontainer.namCre, banDep->kontainer.temVid, banDep->kontainer.tahVid, banDep->kontainer.jumVie);
            }else{
                printf("tengah - %s %s %d %lld\n", banDep->kontainer.namCre, banDep->kontainer.temVid, banDep->kontainer.tahVid, banDep->kontainer.jumVie);
            }
            temPosisi++; // jarak dari ujung head dan tail di tambahkan semakin ketengah
            ban--; // kurangi banyak elemen yang sudah di print
        }
    }else{
    }
}