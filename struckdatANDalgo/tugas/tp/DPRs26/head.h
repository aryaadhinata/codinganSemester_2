#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    int jumPas;
    char namBang[33];
}nilai;

typedef struct{
    int id, usia;
    char nama[37], peny[37];
}nilaiSec;

typedef struct eklm *alamatekolom;
typedef struct eklm{
nilaiSec kontainer_kol;
    alamatekolom next_kol;
}eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr{
    nilai kontainer;
    eKolom *col;
    alamatebaris next;
}eBaris;

typedef struct{
    eBaris *first;
}list;

void createList(list *L);
int countElementB(list L);
int countElementK(eBaris L);

void addFirstB(nilai temp, list *L);
void addFirstK(nilaiSec temp, eBaris *L);
void addAfterB(eBaris *prev, nilai temp);
void addAfterK(eKolom *prev, nilaiSec temp);
void addLastB(nilai temp, list *L);
void addLastK(nilaiSec temp, eBaris *L);

void delFirstK(eBaris *L);
void delAfterK(eKolom* prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);

void delFirstB(list *L);
void delAfterB(eBaris *prev);
void delLastB(list *L);
void delAllB(list *L);

// ini yang di buat dan modif

eBaris* lastBaris(eBaris *first); // mencari elemen baris terkahir
eKolom* lastBeforeTarget(eBaris *base, eKolom *target); // mencari elemen kolom sebelum target
void pindahBangsal(eBaris* nowB, eKolom* nowK, char target[], list *L); // memindahkan pasien

void printHead(); // print header rumah sakit
void prosesPulang(int banPasPul,int pasPul[], char pinPen[], char pinBan[], list *L); // print dan proses kepulangngan dan perpindahan
void printElement(list L); // print elemen pada umumnya 