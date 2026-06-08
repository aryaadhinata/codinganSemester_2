#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan UTS dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

typedef struct{
    char namaAf[33], namPro[33];
}nilai;

typedef struct{
    char tokSup[20];
    int PersKom, harPro, proLak;
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

void printElement(char namProCar[], char namAfCar[], list L);
eBaris* lastBaris(eBaris *first);