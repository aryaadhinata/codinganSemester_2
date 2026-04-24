#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Pratikum 4 dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

int main(){
    list L;
    createList(&L);
    nilai tempB;
    nilaiSec tempK;
    
    int jumBang; // deklarasi variabel untuk menyimpan banyak bangsal yang akan digunakan
    scanf("%d", &jumBang);

    // looping sebanyak bangsal yang digunakan untuk mengisi nama bangsal dan juga isinya (id, nama, peyakit dan umur dari pasien)
    for(int i = 0; i < jumBang; i++){
        scanf("%s %d", tempB.namBang, &tempB.jumPas);
        addLastB(tempB, &L);

        eBaris *last = lastBaris(L.first);
        for(int j = 0; j < tempB.jumPas; j++){
            scanf("%d %s %s %d", &tempK.id, tempK.nama, tempK.peny, &tempK.usia);
            addLastK(tempK, last);
        }
    }

    int banPasPul; // deklarasi variabel untuk menyimpan banyak pasien pulangnya
    scanf("%d", &banPasPul);
    int pasPul[banPasPul]; // saya jadi kan array id pasien yang pulang agar lebih mudah di akses ketika pencarian
    // looping mengisi id pasien yang pulang
    for(int i = 0; i < banPasPul; i++){
        scanf("%d", &pasPul[i]);
    }

    char pinPen[33];
    scanf("%s", pinPen);

    char pinBan[33];
    scanf("%s", pinBan);

    printHead();
    prosesPulang(banPasPul, pasPul, pinPen, pinBan, &L);
    printElement(L);
    return 0;
}