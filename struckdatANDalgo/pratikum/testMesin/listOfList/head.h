#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char kateg[17];
}nilai;

typedef struct{
    char nama[37];
    char penulis[37];
    int jumHal;
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

void printElement(list L);
eBaris* lastBaris(eBaris *first);