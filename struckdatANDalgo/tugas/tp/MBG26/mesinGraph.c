#include "headGraph.h"

// buat graph kosong
void createEmpty(graph *G){
    G->first = NULL;
}

// nambahin simpul kedalam graphnya
void addSimpul(char temp[], graph *G){
    simpul *baru;
    baru = (simpul *) malloc (sizeof (simpul));
    strcpy(baru->kontainer.namaSimpul, temp);
    baru->kontainer.degre = 0; // set nilai awlanya = 0
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
    baru->visit = 0; // set nilai awlanya 0
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
simpul* findSimpul(char namaSimpul[], graph G){
    simpul *hasil = NULL; // buat nyimpen alamat simpul yang berhasil di cari
    simpul *bantu = G.first;

    int ketemu = 0; // penanda kalo udh ketemu
    // ketika belum sampai ujung dan masih belum ketemu yang di cari
    while((bantu != NULL) && (ketemu == 0)){
        // harus bandingkan semua yang ada di struck nilai
        if(strcmp(bantu->kontainer.namaSimpul, namaSimpul) == 0){
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
// di modiv dikit jadi mulainy anggakk dari G->first tapi langgsung dari node yang jalurnya mau di hapus
void delJalur(char tuju[], simpul *awal){
    jalur *hapus = awal->arc; // ngebantu untuk menulusuri jalur yang sesuai dengan yang mau dihapus

    if(hapus != NULL){ // ada yang bisa dihapus
        jalur *prev = NULL;

        int ketemu = 0; // penanda
        while((hapus != NULL) && (ketemu == 0)){ // kalo belum ditelusuri semua dn belum ketemu
            // check semua yang ada di struck nilai
            if(strcmp(hapus->tujuan->kontainer.namaSimpul, tuju) == 0){
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
        }
        // else{
        //     printf("tidak ada jalur dengan simpul tujuan\n");
        // }
        }
    //     else{
    //     printf("tidak ada jalur dengan simpul tujuan\n");
    // }
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
void delSimpul(char temp[], simpul *node){
    simpul *hapus = node;

    // kalo masih ada yang bisa di telusuri
    if(hapus != NULL){
        simpul *prev = NULL;

        int ketemu = 0; // penanda udh ketemu atau belumnya
        // kalo belum ketemu dan masih ada yang bisa ditelusuri
        while((hapus != NULL) && (ketemu == 0)){
            // harus cek semua yang ada di struck nilai
            if(strcmp(hapus->kontainer.namaSimpul, temp) == 0){
                ketemu = 1;
            }else{
                prev = hapus;
                hapus = hapus->nextSimpul;
            }
        }
        
        // kalo udh ketemu
        if(ketemu == 1){
            simpul *bantu;
            bantu = node;

            // masih ada yang bisa di telusuri
            while(bantu != NULL){
                // kalo bukan dari simpul yang mau di hapus 
                if(bantu != hapus){
                    delJalur(hapus->kontainer.namaSimpul, bantu);
                }
                bantu = bantu->nextSimpul;
            }
        }
        // hapus semua jalur yang ada di simpul yang mau dihapus
        delAllJalur(hapus);

        // kalo si hapus adalah simpul yang pertama
        if(prev == NULL){
            node = hapus->nextSimpul;
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

// buat nandai dari belakang berapa kali harusnya jalurnya di lewatin
int tandaiVisit(int penanda, simpul *awal, simpul *akhir){
    int jalurBerhasil = 0; // set nilai awal
    if(awal != NULL){ // pengaman
        if(awal == akhir){ // kalo udh ketemu akhirnya
            penanda = 1; // tandanya jadi 1
            return penanda; // langsung di balikin
        }
        if(awal->arc != NULL){ // kalo masih ada jalur 
            jalur *hasil = awal->arc;
            while((hasil != NULL) && (awal != akhir)){ // selama masih ada jalur dan bukan di akhir
                penanda = 0; // set ulang penanda
                penanda = tandaiVisit(penanda, hasil->tujuan, akhir); // rekursif ke akhirr
                if(penanda > 0){ // kalo setelahnya bener
                    hasil->visit = penanda; // jalur yang sekarang simpen sebanyak jalur sebelumnya
                    jalurBerhasil += penanda; // buat hitung banyak jalur yang berhasil sebelumnya
                }
                hasil = hasil->nextJalur;
            }
        }
        return jalurBerhasil; // return ulang sebanyak jalur yang berhasil sebelumnya
    }
}

// buat nandain berapa banyak jalur yang bener dari node itu
void tandaiDegre(simpul *awal, simpul *akhir){
    if(awal->arc != NULL){
        jalur *bantu = awal->arc;
        do{
            bantu->tujuan->kontainer.degre += 1; // tabahin buat simpul berikutnya
            tandaiDegre(bantu->tujuan, akhir); // rekursif buat simpul berikutnya
            bantu = bantu->nextJalur;
        }while((bantu != NULL) && (awal != akhir)); // selama masih ada dan belum mentok ke ujung
    }
}

// ngurangi visit yang ada di node
void refreshGraph(simpul *awal, simpul *akhir){
    simpul *bantu = awal;
    if(bantu != akhir){
        while(bantu != akhir){
            jalur *bantuJalur = bantu->arc;
            if(bantu->kontainer.degre <= bantuJalur->visit){ // syarat buat nguranginnya selama degre yang sekarang itu emang lebih kecil dari visitnya
                bantuJalur->visit--;
            }
            bantu = bantuJalur->tujuan;
        }
    }
}

// buat kondisian ngehapus jalur dan simpul
void hapusTidakVisit(simpul *node){
    if(node->arc != NULL){
        jalur *bantu = node->arc;
        do{
            hapusTidakVisit(bantu->tujuan);
            if(node->arc->visit == 0){ // klao visitnya udh kosong berarti udh lewat semua
                if(node->arc->tujuan->kontainer.degre == 0){ // kalo degrenya 0 berarti udh nggak akan dilewatin lagi
                    delSimpul(node->arc->tujuan->kontainer.namaSimpul, node); // hapus simpulnya
                }else{
                    node->arc->tujuan->kontainer.degre--; // kurangi degreenya
                }
                delJalur(node->arc->tujuan->kontainer.namaSimpul, node); // hapus jalurnya
            }
            bantu = bantu->nextJalur;
        } while (bantu != NULL);
        
    }
}

// buat nampilin si graphnya di modif buat nampilin dari awal ke akhir aja nggak lewat G-> first
// dan di ubah jadi fuction buat nyimpen total uang yang di butuhkan buat perjalanan itu
int printGraph(simpul *awal, simpul *akhir){
    simpul *bantu = awal;
    int uangTotal = 0;
    if(bantu != akhir){
        while(bantu != akhir){
            printf("%s", bantu->kontainer.namaSimpul);
            printf(" -> ");
            jalur *bantuJalur = bantu->arc;
            uangTotal += bantuJalur->bobotJalur;
            bantu = bantuJalur->tujuan;
        }
    }
    printf("%s", akhir->kontainer.namaSimpul);
    printf(" Rp. %d\n", uangTotal);
    return uangTotal;
}