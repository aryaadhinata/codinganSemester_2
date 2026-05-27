#include "headGraph.h"

// buat graph kosong
void createEmpty(graph *G){
    G->first = NULL;
}

// nambahin simpul kedalam graphnya
void addSimpul(nilai temp, graph *G){
    simpul *baru;
    baru = (simpul *) malloc (sizeof (simpul));
    baru->kontainer = temp;
    baru->nextSimpul = NULL;
    baru->arc = NULL;

    // kalo simpul yang dibuat itu belum ada (yang pertama) ><
    if(G->first == NULL){
        G->first = baru;
    }else{ // kalo udh ada yang lainya
        simpul *last = G->first;

        // cari yang paling akhir
        while(last->nextSimpul != NULL){
            last = last->nextSimpul;
        }

        last->nextSimpul = baru;
        baru = NULL;
    }
}

// nambah jalur dari simpul awal ke simpul tujuan dengan bebannya
void addJalur(simpul *awal, simpul *tujuan, int beban){
    jalur *baru;
    baru = (jalur *) malloc (sizeof (jalur));
    baru->bobotJalur = beban;
    baru->nextJalur = NULL;
    baru->tujuan = tujuan;

    // kalo belum ada simpul tujuan yang terhubung dengan simpul awal
    if(awal->arc == NULL){
        awal->arc = baru;
    }else{ // kalo udah ada simpul tujuan yang terhung simpul awal
        jalur *last = awal->arc;

        // cari akhir dari jalur yang sekarang
        while(last->nextJalur != NULL){
            last = last->nextJalur;
        }

        last->nextJalur = baru;
        baru = NULL;
    }
}

// buat nyari simpul
simpul* findSimpul(nilai temp, graph G){
    simpul *hasil = NULL; // buat nyimpen alamat simpul yang berhasil di cari
    simpul *bantu = G.first;

    int ketemu = 0; // penanda kalo udh ketemu
    // ketika belum sampai ujung dan masih belum ketemu yang di cari
    while((bantu != NULL) && (ketemu == 0)){
        // harus bandingkan semua yang ada di struck nilai
        if(bantu->kontainer.konten == temp.konten){
            hasil = bantu;
            ketemu = 1;
        }else{
            bantu = bantu->nextSimpul;
        }
    }
    bantu = NULL;

    return hasil;
}

// buat hapus jalur dari simpul yang dinginkan dengan simpul yang punya isi sama dengan apa yang di input
void delJalur(nilai tuju, simpul *awal){
    jalur *hapus = awal->arc; // ngebantu untuk menulusuri jalur yang sesuai dengan yang mau dihapus

    if(hapus != NULL){ // ada yang bisa dihapus
        jalur *prev = NULL;

        int ketemu = 0; // penanda
        while((hapus != NULL) && (ketemu == 0)){ // kalo belum ditelusuri semua dn belum ketemu
            // check semua yang ada di struck nilai
            if(hapus->tujuan->kontainer.konten == tuju.konten){
                ketemu = 1;
            }else{
                prev = hapus;
                hapus = hapus->nextJalur;
            }
        }

        // kalo udh ketemu
        if(ketemu == 1){
            // kalo di jalur pertama
            if(prev == NULL){
                awal->arc = hapus->nextJalur;
                hapus->nextJalur = NULL;
            }else{
                // kalo dia jalur terakhir
                if(hapus->nextJalur == NULL){
                    prev->nextJalur = NULL;
                }else{
                    prev->nextJalur = hapus->nextJalur;
                    hapus->nextJalur = NULL;
                }
            }
            free(hapus);
        }else{
            printf("tidak ada jalur dengan simpul tujuan\n");
        }
    }else{
        printf("tidak ada jalur dengan simpul tujuan\n");
    }
}

// baut hapus semua jalur di satu simpul
void delAllJalur(simpul *awal){
    jalur *bantu;
    bantu = awal->arc;
    jalur *hapus;

    // kalo masih ada yang bisa di telusuri
    while(bantu != NULL){
        hapus = bantu;
        bantu = bantu->nextJalur;
        awal->arc = bantu;
        hapus->nextJalur = NULL;
        free(hapus);
    }
}

// buat hapus simpul dengan isi simpul yang sama dengan yang diinginkan
void delSimpul(nilai temp, graph *G){
    simpul *hapus = G->first;

    // kalo masih ada yang bisa di telusuri
    if(hapus != NULL){
        simpul *prev = NULL;

        int ketemu = 0; // penanda udh ketemu atau belumnya
        // kalo belum ketemu dan masih ada yang bisa ditelusuri
        while((hapus != NULL) && (ketemu == 0)){
            // harus cek semua yang ada di struck nilai
            if(hapus->kontainer.konten = temp.konten){
                ketemu = 1;
            }else{
                prev = hapus;
                hapus = hapus->nextSimpul;
            }
        }
        
        // kalo udh ketemu
        if(ketemu == 1){
            simpul *bantu;
            bantu = G->first;

            // masih ada yang bisa di telusuri
            while(bantu != NULL){
                // kalo bukan dari simpul yang mau di hapus 
                if(bantu != hapus){
                    delJalur(hapus->kontainer, bantu);
                }
            }
            bantu = bantu->nextSimpul;
        }
        // hapus semua jalur yang ada di simpul yang mau dihapus
        delAllJalur(hapus);

        // kalo si hapus adalah simpul yang pertama
        if(prev == NULL){
            G->first = hapus->nextSimpul;
            hapus->nextSimpul = NULL;
        }else{
            // kalo si hapus ada di paling ujung
            if(hapus->nextSimpul == NULL){
                prev->nextSimpul = NULL;
            }else{
                prev->nextSimpul = hapus->nextSimpul;
                hapus->nextSimpul = NULL;
            }
        }
        free(hapus);
    }else{
        printf("tidak ada simpul yang sesuai dengan masukan\n");
    }
}

// buat nampilin si graphnya
void printGraph(graph G){
    simpul *bantu = G.first;

    if(bantu != NULL){
        while(bantu != NULL){
            printf("simpul : %c\n", bantu->kontainer.konten);

            jalur *bantuJalur = bantu->arc;
            while(bantuJalur != NULL){
                printf("- ada jalur ke simpul : %c, dengan beban : %d\n", bantuJalur->tujuan->kontainer.konten, bantuJalur->bobotJalur);
                bantuJalur = bantuJalur->nextJalur;
            }
            bantu = bantu->nextSimpul;
        }
    }else{
        printf("graph kosong\n");
    }
}