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
        (*L).data[baru].kontainer.mark = 0;
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
        (*L).data[baru].kontainer.mark = 0;
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

void pindah(int tunjuk, list *L){
    int prefPindah = L->first;
    int prefAkhir  = L->first;

    if(tunjuk != L->first){
        // cari node sebelum tunjuk
        while(L->data[prefPindah].next != tunjuk){
            prefPindah = L->data[prefPindah].next;
        }
        // putuskan tunjuk dari posisi lamanya
        L->data[prefPindah].next = L->data[tunjuk].next;
    } else {
        // tunjuk adalah node pertama, geser first
        L->first = L->data[L->first].next;
    }

    // cari node paling akhir
    while(L->data[prefAkhir].next != -1){
        prefAkhir = L->data[prefAkhir].next;
    }

    // sambungkan akhir → tunjuk, dan tunjuk jadi ekor
    L->data[prefAkhir].next = tunjuk;
    L->data[tunjuk].next    = -1;
}

void cek(int batas, list *L){
    int tunjuk = (*L).first;

    while(tunjuk != -1){
        // cek apakah node ini sudah pernah dipindahkan (mark = 1 → berhenti)
        if((*L).data[tunjuk].kontainer.mark == 1) break;

        int untungKasar = (*L).data[tunjuk].kontainer.kuota * (*L).data[tunjuk].kontainer.harJul;
        int next = (*L).data[tunjuk].next; // simpan next SEBELUM operasi apapun

        if(untungKasar < (*L).data[tunjuk].kontainer.biPeng){
            // hapus tunjuk
            if(tunjuk == (*L).first){
                delFirst(L);
                tunjuk = (*L).first; // first sudah bergeser
            }else{
                // cari prev
                int prev = (*L).first;
                while((*L).data[prev].next != tunjuk){
                    prev = (*L).data[prev].next;
                }
                delAfter(prev, L);   // hapus tunjuk (node setelah prev)
                tunjuk = next;       // lanjut ke node berikutnya
            }

        }else if(untungKasar - (*L).data[tunjuk].kontainer.biPeng < batas){
            (*L).data[tunjuk].kontainer.mark = 1;
            pindah(tunjuk, L);
            tunjuk = next; // next sudah disimpan sebelum pindah

        }else{
            tunjuk = next; // untung >= batas, lanjut saja
        }
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
