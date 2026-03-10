#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan kuis 1 dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

void createList(list *L){
    (*L).first = -1;
    for(int i = 0; i < 100; i++){
        (*L).data[i].next = -2;
    }
}

int countElement(list L){
    int hasil = 0;
    if(L.first != -1){
        int hitung;
        hitung = L.first;
        while(hitung != -1){
            hasil = hasil + 1;
            hitung = L.data[hitung].next;
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

void addFirst(list *L, nilai temp){
    if(countElement(*L) < 100){
        int baru = emptyElement(*L);
        (*L).data[baru].kontainer = temp;
        
        if((*L).first == -1){
            (*L).data[baru].next = -1;
        }else{
            (*L).data[baru].next = (*L).first;
        }
        
        (*L).first = baru;
    }else{
        // printf("sudah ditambahkan semua\n");
    }
}

void addAfter(int prev, list *L, nilai temp){
    if(countElement(*L) < 100){
        int baru = emptyElement(*L);

        (*L).data[baru].kontainer = temp;
        if((*L).data[prev].next == -1){
            (*L).data[baru].next = -1;
        }else{
            (*L).data[baru].next = (*L).data[prev].next;
        }

        (*L).data[prev].next = baru;
    }else{
        // printf("sudah ditambahkan semua\n");
    }
}

void addLast(list *L, nilai temp){
    if((*L).first == -1){
        addFirst(L, temp);
    }else{
        if(countElement(*L) < 100){
            int prev = (*L).first;

            while((*L).data[prev].next != -1){
                prev = (*L).data[prev].next;
            }

            addAfter(prev, L, temp);
        }else{
            // printf("sudah tidak bisa ditambahkan lagi\n");
        }
    }
}

void delFirst(list *L){
    if((*L).first != -1){
        int hapus = (*L).first;
        
        if(countElement(*L) == 1){
            (*L).first = -1;
        }else{
            (*L).first = (*L).data[hapus].next;
        }

        (*L).data[hapus].next = -2;
    }else{
        // printf("List kosong\n");
    }
}

void delAfter(int prev, list *L){
    if(prev != -1){
        int hapus = (*L).data[prev].next;

        if(hapus != -1){
            if((*L).data[hapus].next == -1){
                (*L).data[prev].next = -1;
            }else{
                (*L).data[prev].next = (*L).data[hapus].next;
            }
        }

        (*L).data[hapus].next = -2;
    }
}

void delLast(list *L){
    if((*L).first != -1){
        if(countElement(*L) == 1){
            delFirst(L);
        }else{
            int hapus = (*L).first;
            int prev = -1;

            while((*L).data[hapus].next != -1){
                prev = hapus;
                hapus = (*L).data[hapus].next;
            }

            delAfter(prev, L);
        }
    }else{
        // printf("List kosong\n");
    }
}

void delAll(list *L){
    for(int i = countElement(*L); i >= 1; i--){
        delLast(L);
    }
}

void pindah(int tunjuk, list L){
    int prefPindah = L.first; // list sebelum dipindah
    int prefAkhir = L.first; // list paling ujung

    if(tunjuk != L.first){ // bukan list pertama
        while(L.data[prefPindah].next != tunjuk){ // cari pref sebelumnya
            prefPindah = L.data[prefPindah].next;
        }
        L.data[prefPindah].next = L.data[tunjuk].next; // iterasi
    }else{ // list pertama
        L.first = L.data[prefPindah].next;
    }
    
    while(L.data[prefAkhir].next != -1){ // cari bagian akhir list
        prefAkhir = L.data[prefAkhir].next;
        L.data[prefAkhir] = L.data[prefAkhir].next; // iterasi
    }
    
    L.data[prefAkhir].next = tunjuk; // sambungkan list akhir ke tunjuk

    // free pointer
    L.data[tunjuk].next = -1; 
    prefPindah = -1;
    prefAkhir = -1;
}

void cek(int batas, list *L){
    int tunjuk = (*L).first;
    while((tunjuk != -1) && ((*L).data[tunjuk].kontainer.mark != 1)){ // cek selama belum sampai ujung dan juga belum ketemu list yang dipindahkan kebelakang
        int untungKasar = (*L).data[tunjuk].kontainer.kuota * (*L).data[tunjuk].kontainer.harJul; // agar lebih mudah untuk mengkondisikannya
        if(untungKasar < (*L).data[tunjuk].kontainer.biPeng){ // jika tidak ada untungnya sama sekali
            if(tunjuk == (*L).first){ // jika dibagian awal array langsung delFirst
                delFirst(L);
            }else{ // selain itu langsung delafter (kayaknya salah hapus deh harusnya yang sebelumnya bukan tunjuk sekarang)
                delAfter(tunjuk, L);
            }
        }else if(untungKasar - (*L).data[tunjuk].kontainer.biPeng < batas){ // ada untung tetapi belum melewati trashhold
            (*L).data[tunjuk].kontainer.mark = 1; // penanda list sudah dipindahkan
            pindah(tunjuk, *L); // prosedur untuk memindahkan
        }
        tunjuk = (*L).data[tunjuk].next; // iterasi
    }
}

void printElement(list L){
    if(L.first != -1){
        int tunjuk = L.first;

        while(tunjuk != -1){
            printf("%d %d %s %d %d %d\n",
                L.data[tunjuk].kontainer.x, L.data[tunjuk].kontainer.y, L.data[tunjuk].kontainer.kodTen,
                L.data[tunjuk].kontainer.kuota, L.data[tunjuk].kontainer.harJul, L.data[tunjuk].kontainer.biPeng);
            
            tunjuk = L.data[tunjuk].next;
        }
    }else{
        // printf("----------------------------------------\nData WarungBahari :\n");
        // printf("Ko0o0o0song!\n");
    }
}
