#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan remedial dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/


// sesuain nilai struck kontainer masing masing sesuai spesifikasi soal
typedef struct{
    char perusahaan[65], kodePer[37];
}nilai;

typedef struct{
    char obat[65], jenisObat[9];
    int bulan, tahun;
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

eBaris *findBaris(char cari[], list *L); // buat cari baris yang sesuai
void pindahElement(eBaris *awal, eKolom *pindah, eBaris *tujuan); // buat mindahin tapi nggak jadi terlalu ribet

void delFirstB(list *L);
void delAfterB(eBaris *prev);
void delLastB(list *L);
void delAllB(list *L);

void printElementSesuai(list L, eBaris *batas, int batasTahun, int batasBulan); // buat print yang nggak dipindahin
void printElementXSesuai(list L, eBaris *batas, int batasTahun, int batasBulan); // print yang dipindahin
eBaris* lastBaris(eBaris *first);