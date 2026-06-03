#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct smp *alamatSimpul;
typedef struct jlr *alamatJalur;

typedef struct{
    char konten[65];

}nilai;

typedef struct smp{
    nilai kontainer;
    alamatSimpul nextSimpul;
    alamatJalur arc; 
}simpul;

typedef struct jlr{
    int bobotJalur;
    alamatJalur nextJalur;
    simpul *tujuan;
}jalur;

typedef struct{
    simpul* first;
}graph;

void createEmpty(graph *G);
void addSimpul(char temp[], graph *G);
void addJalur(simpul *awal, simpul *tujuan, int beban);
simpul* findSimpul(char konten[], graph G);
void delJalur(char tuju[], simpul *awal);
void delAllJalur(simpul *awal);
void delSimpul(char temp[], graph *G);
void printGraph(graph G);