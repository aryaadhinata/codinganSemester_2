#include "head.h"

void createList(list *L){
    (*L).first = -1;
    (*L).tail = -1;
    for(int i = 0; i < 100; i++){
        (*L).data[i].next = -2;
    }
}

int countElement(list L){
    int hasil = 0;

    if(L.first != -1){
        int bantu;
        bantu = L.first;

        while(bantu !=  -1){
            hasil = hasil + 1;

            bantu = L.data[bantu].next;
        }
    }
    return hasil;
}

int emptyElement(list L){
    int hasil = -1;
    if(countElement(L) < 100){
        int ketemu = 0;
        int i = 0;
        while((ketemu == 0) && (i < 100)){
            if(L.data[i].next == -2){
                hasil = i;
                ketemu = 1;
            }else{
                i++;
            }
        }
    }
    return hasil;
}

void addFirst(nilai temp, list *L){
    if(countElement(*L) < 100){
        int baru;
        baru = emptyElement(*L);
        (*L).data[baru].kontainer = temp;
        
        if((*L).first == -1){
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = -1;
            
            (*L).tail = baru;
        }else{
            (*L).data[baru].next = (*L).first;
            (*L).data[baru].prev = -1;
            (*L).data[(*L).first].prev = baru;

        }
        (*L).first = baru;
        baru = -1;
    }
}

void addAfter(int before, nilai temp, list *L){
    if(countElement(*L) < 100){
        if(before != -1){
            int baru;
            baru = emptyElement(*L);
            (*L).data[baru].kontainer = temp;

            if((*L).data[before].next == -1){
                (*L).data[baru].next = -1;
                (*L).tail = baru;
            }else{
                (*L).data[baru].next = (*L).data[before].next;
                (*L).data[(*L).data[baru].next].prev = baru;
            }
            
            (*L).data[baru].prev = before;
            (*L).data[before].next = baru;
            baru = -1;
        }
    }
}

void addBefore(int after, nilai temp, list *L){
    if(countElement(*L) < 100){
        if(after != -1){
            int baru;
            baru = emptyElement(*L);
            (*L).data[baru].kontainer = temp;

            if((*L).data[after].prev == -1){
                (*L).data[baru].prev = -1;
                (*L).first = baru;
            }else{
                (*L).data[baru].prev = (*L).data[after].prev;
                (*L).data[(*L).data[baru].prev].next = baru;
            }
            
            (*L).data[baru].next = after;
            (*L).data[after].prev = baru;
            baru = -1;
        }
    }
}

void addLast(nilai temp, list *L){
    if((*L).first == -1){
        /*jika list adalah list kosong*/
        addFirst(temp, L);
    }else{
        /*jika list tidak kosong*/
        addAfter((*L).tail, temp, L);
    }
}

void delFirst(list *L){
    if((*L).first != -1){
    /*jika list bukan list kosong*/
        int hapus = (*L).first;
        if(countElement(*L) == 1){
            (*L).first = -1;
            (*L).tail = -1;
        }else{
            (*L).first = (*L).data[(*L).first].next;
            (*L).data[(*L).first].prev = -1;
            (*L).data[hapus].next = -1;
        }
    
    (*L).data[hapus].prev = -2;
    (*L).data[hapus].next = -2;
    }
}

void delAfter(int before, list *L){
    if(before != -1){
        int hapus = (*L).data[before].next;
        if(hapus != -1){
            if((*L).data[hapus].next == -1){
                (*L).data[before].next = -1;
                (*L).tail = before;
            }else{
                (*L).data[before].next = (*L).data[hapus].next;
                (*L).data[(*L).data[hapus].next].prev = before;
                (*L).data[hapus].next = -1;
            }
        (*L).data[hapus].prev = -2;
        (*L).data[hapus].next = -2;
        }
    }
}

void delLast(list *L){
    if((*L).first != -1){
        /*jika list tidak kosong*/
        if(countElement(*L) == 1){
            /*list terdiri dari satu elemen*/
            delFirst(L);
        }
        else{
            /*jika banyak elemen*/
            delAfter((*L).data[(*L).tail].prev, L);
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

int prioritas(int cek, list *L){
    if(strcmp((*L).data[cek].kontainer.urgent, "Mendesak") == 0){
        if(strcmp((*L).data[cek].kontainer.kateg, "Fragile") == 0){
            return 1;
        }else if(strcmp((*L).data[cek].kontainer.kateg, "Normal") == 0){
            return 2;
        }else if(strcmp((*L).data[cek].kontainer.kateg, "Heavy") == 0){
            return 3;
        }
    }else{
        if(strcmp((*L).data[cek].kontainer.kateg, "Fragile") == 0){
            return 4;
        }else if(strcmp((*L).data[cek].kontainer.kateg, "Normal") == 0){
            return 5;
        }else if(strcmp((*L).data[cek].kontainer.kateg, "Heavy") == 0){
            return 6;
        }
    }
}

void swap(int p, int q, list *L){
    int prevP = (*L).data[p].prev;
    int nextQ = (*L).data[q].next;
    
    if(p == (*L).first){
        (*L).first = q;
        (*L).data[q].prev  = -1;
    }else{
        (*L).data[prevP].next = q;
    }
    
    if(q == (*L).tail){
        (*L).tail = p;
    }else{
        (*L).data[nextQ].prev = p;
    }
    (*L).data[q].prev = prevP;
    (*L).data[q].next = p;
    (*L).data[p].prev = q;
    (*L).data[p].next = nextQ;
    
}

void sort(list *L){
    int p, awalNMen, awalN, akhirNMen, akhirN; // deklarasi pointer yang akan digunakan
    int loop; // penanda apakah ada pertukaran yang artinya list belum terurut
    
    //  do while nya dipakai untuk menandai apakah ada swap atau tidak jika masih ada maka akan looping terus
    // sampai tidak ada yang di swap
    do{
        loop = 0; // set nilai default setiap do while

        // set nilai default setiap do while
        p = (*L).first;
        
        // while digunakan untuk melakukan penelusuran dari head sampai nuul
        while(p != -1){ // selama bukan list yang berisi saru kontainaer maka kita cek
            awalN = (*L).first;
            awalNMen = (*L).first;
            akhirN = (*L).tail;
            akhirNMen = (*L).tail;
            int iter = 0; // deklrasi dan nilai default apakah ada yang di swap agar urutan pointernya sama lagi
            int stopAw, stopAk;
            if(prioritas(p, L) != 2){
                stopAw = 0;
                stopAk = 0;
                while(awalNMen != (*L).tail && stopAw != 1){
                    if(prioritas(awalNMen, L) == 2){
                        stopAw = 1;
                    }else{
                        awalNMen = (*L).data[awalNMen].next;
                    }
                }
                while(akhirNMen != (*L).first && stopAk != 1){
                    if(prioritas(akhirNMen, L) == 2){
                        stopAk = 1;
                    }else{
                        akhirNMen = (*L).data[akhirNMen].prev;
                    }
                }
                if(prioritas(p, L) == 1){
                    swap(p, awalNMen, L);
                    iter = (*L).data[p].next;
                    loop = 1;
                }else if(prioritas(p, L) == 3){
                    swap(akhirNMen, p, L);
                    iter = (*L).data[p].next;
                    loop = 1;
                }
            }else{
                stopAw = 0;
                stopAk = 0;
                while(awalN != (*L).tail && stopAw != 1){
                    if(prioritas(awalN, L) == 2){
                        stopAw = 1;
                    }else{
                        awalN = (*L).data[awalN].next;
                    }
                }
                while(akhirN != (*L).first && stopAk != 1){
                    if(prioritas(akhirN, L) == 2){
                        stopAk = 1;
                    }else{
                        akhirN = (*L).data[akhirN].prev;
                    }
                }
                if(prioritas(p, L) == 4){
                    swap(p, awalN, L);
                    iter = (*L).data[p].next;
                    loop = 1;
                }else if(prioritas(p, L) == 6){
                    swap(akhirN, p, L);
                    iter = (*L).data[p].next;
                    loop = 1;
                }
            }

            // bagian iterasi
            if(iter == 0){ // jika tidak ada yang di swap maka iterasinya sama aja
                p = (*L).data[p].next;
            }else{ // jika ada yang di tukah maka ada perubahann dikit agar
                // yang tadinya first->q->p->... | ...->->q->p->... jadi kebentuk awalnya lagi
                p = iter;
            }
        }
    }while(loop == 1); // tetep loop selama masih ada yang di ubah
    p = -1;
}

void printElement(list L){
    printf("Data Paket dari Depan :\n");
    printf("+-----------------+-----------------+-----------------+\n");
    printf("|      Nama       |     Kategori    |     Urgensi     |\n");
    printf("+-----------------+-----------------+-----------------+\n");
    if(L.first != -1){
        /*jika list tidak kosong*/
        /*inisialisasi*/
        int bantu = L.first;
        int panj = 16;
        while(bantu != -1){
            printf("| %s", L.data[bantu].kontainer.namBang);
            if(panj > strlen(L.data[bantu].kontainer.namBang)){
                for(int i = 0; i < (panj - strlen(L.data[bantu].kontainer.namBang)); i++){
                    printf(" ");
                }
            }
            printf("| %s", L.data[bantu].kontainer.kateg);
            if(panj > strlen(L.data[bantu].kontainer.kateg)){
                for(int i = 0; i < (panj - strlen(L.data[bantu].kontainer.kateg)); i++){
                    printf(" ");
                }
            }
            printf("| %s", L.data[bantu].kontainer.urgent);
            if(panj > strlen(L.data[bantu].kontainer.urgent)){
                for(int i = 0; i < (panj - strlen(L.data[bantu].kontainer.urgent)); i++){
                    printf(" ");
                }
            }
            printf("|\n");
            bantu = L.data[bantu].next;
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
    if(L.tail != -1){
        /*jika list tidak kosong*/
        /*inisialisasi*/
        int bantu = L.tail;
        int panj = 16;
        while(bantu != -1){
            printf("| %s", L.data[bantu].kontainer.namBang);
            if(panj > strlen(L.data[bantu].kontainer.namBang)){
                for(int i = 0; i < (panj - strlen(L.data[bantu].kontainer.namBang)); i++){
                    printf(" ");
                }
            }
            printf("| %s", L.data[bantu].kontainer.kateg);
            if(panj > strlen(L.data[bantu].kontainer.kateg)){
                for(int i = 0; i < (panj - strlen(L.data[bantu].kontainer.kateg)); i++){
                    printf(" ");
                }
            }
            printf("| %s", L.data[bantu].kontainer.urgent);
            if(panj > strlen(L.data[bantu].kontainer.urgent)){
                for(int i = 0; i < (panj - strlen(L.data[bantu].kontainer.urgent)); i++){
                    printf(" ");
                }
            }
            printf("|\n");
            bantu = L.data[bantu].prev;
        }
    }else{
        /*proses jika list kosong*/
        printf("\n");
    }
    printf("+-----------------+-----------------+-----------------+\n");
}