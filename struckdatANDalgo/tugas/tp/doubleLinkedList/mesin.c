#include "head.h"

void createList(list *L){
    (*L).first = NULL;
    (*L).tail = NULL;
}

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

int prioritas(elemen *cek, list *L){
    if(strcmp(cek->kontainer.urgent, "Mendesak") == 0){
        if(strcmp(cek->kontainer.kateg, "Fragile") == 0){
            return 1;
        }else if(strcmp(cek->kontainer.kateg, "Normal") == 0){
            return 2;
        }else if(strcmp(cek->kontainer.kateg, "Heavy") == 0){
            return 3;
        }
    }else{
        if(strcmp(cek->kontainer.kateg, "Fragile") == 0){
            return 4;
        }else if(strcmp(cek->kontainer.kateg, "Normal") == 0){
            return 5;
        }else if(strcmp(cek->kontainer.kateg, "Heavy") == 0){
            return 6;
        }
    }
}

// prosedur unutk melakukan swap karena saya rasa terlalu berulanng jadi di buatkan prosedur
void swap(elemen *p, elemen *q, list *L){
    // first->p->q->... || ...->p->q->... bentuk awalnya
    if(p == L->first){
        L->first = q;
        q->prev = NULL;
    }else{
        p->prev->next = q;
        q->prev = p->prev;
    }
    
    if(q == L->tail){
        L->tail = p;
    }else{
        q->next->prev = p;
    }
    p->next = q->next;
    p->prev = q;
    q->next = p;
    
    // first->q->p->... || ...->q->p->... bentuk akhirnya
}

void ins(list *L){
    elemen *p, *q; // deklarasi pointer yang akan digunakan
    int loop; // penanda apakah ada pertukaran yang artinya list belum terurut
    
    //  do while nya dipakai untuk menandai apakah ada swap atau tidak jika masih ada maka akan looping terus
    // sampai tidak ada yang di swap
    do{
        loop = 0; // set nilai default setiap do while

        // set nilai default setiap do while
        p = L->first;
        q = p->next;

        // while digunakan untuk melakukan penelusuran dari head sampai nuul
        while(q != NULL){ // selama bukan list yang berisi saru kontainaer maka kita cek
            int iter = 0; // deklrasi dan nilai default apakah ada yang di swap agar urutan pointernya sama lagi
            if(prioritas(p, L) > prioritas(q, L)){
                swap(p, q, L);
                iter = 1;
                loop = 1;
            }
            // bagian iterasi
            if(iter == 0){ // jika tidak ada yang di swap maka iterasinya sama aja
                p = q;
                q = q->next;
            }else{ // jika ada yang di tukah maka ada perubahann dikit agar
                // yang tadinya first->q->p->... | ...->->q->p->... jadi kebentuk awalnya lagi
                q = p->next;
            }
        }
    }while(loop == 1); // tetep loop selama masih ada yang di ubah
    p = NULL;
    q = NULL;
}

void printElement(list L){
    printf("Data Paket dari Depan :\n");
    printf("+-----------------+-----------------+-----------------+\n");
    printf("|      Nama       |     Kategori    |     Urgensi     |\n");
    printf("+-----------------+-----------------+-----------------+\n");
    if(L.first != NULL){
        /*jika list tidak kosong*/
        /*inisialisasi*/
        elemen* bantu = L.first;
        int panj = 16;
        while(bantu != NULL){
            printf("| %s", bantu->kontainer.namBang);
            if(panj > strlen(bantu->kontainer.namBang)){
                for(int i = 0; i < (panj - strlen(bantu->kontainer.namBang)); i++){
                    printf(" ");
                }
            }
            printf("| %s", bantu->kontainer.kateg);
            if(panj > strlen(bantu->kontainer.kateg)){
                for(int i = 0; i < (panj - strlen(bantu->kontainer.kateg)); i++){
                    printf(" ");
                }
            }
            printf("| %s", bantu->kontainer.urgent);
            if(panj > strlen(bantu->kontainer.urgent)){
                for(int i = 0; i < (panj - strlen(bantu->kontainer.urgent)); i++){
                    printf(" ");
                }
            }
            printf("|\n");
            bantu = bantu->next;
        }
    }else{
        /*proses jika list kosong*/
        printf("\n");
    }
    printf("+-----------------+-----------------+-----------------+\n");
}

void printElementReverse(list L){
    printf("Data Barang dari Belakang :\n");
    printf("+-----------------+-----------------+-----------------+\n");
    printf("|      Nama       |     Kategori    |     Urgensi     |\n");
    printf("+-----------------+-----------------+-----------------+\n");
    if(L.tail != NULL){
        /*jika list tidak kosong*/
        /*inisialisasi*/
        elemen* bantu = L.tail;
        int panj = 16;
        while(bantu != NULL){
            printf("| %s", bantu->kontainer.namBang);
            if(panj > strlen(bantu->kontainer.namBang)){
                for(int i = 0; i < (panj - strlen(bantu->kontainer.namBang)); i++){
                    printf(" ");
                }
            }
            printf("| %s", bantu->kontainer.kateg);
            if(panj > strlen(bantu->kontainer.kateg)){
                for(int i = 0; i < (panj - strlen(bantu->kontainer.kateg)); i++){
                    printf(" ");
                }
            }
            printf("| %s", bantu->kontainer.urgent);
            if(panj > strlen(bantu->kontainer.urgent)){
                for(int i = 0; i < (panj - strlen(bantu->kontainer.urgent)); i++){
                    printf(" ");
                }
            }
            printf("|\n");
            bantu = bantu->prev;
        }
    }else{
        /*proses jika list kosong*/
        printf("\n");
    }
    printf("+-----------------+-----------------+-----------------+\n");
}