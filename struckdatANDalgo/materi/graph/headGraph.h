#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatSimpul;
typedef struct jlr *alamatJalur;

typedef struct{
    char konten;
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
void addSimpul(nilai temp, graph *G);
void addJalur(simpul *awal, simpul *tujuan, int beban);
simpul* findSimpul(nilai temp, graph G);
void delJalur(nilai tuju, simpul *awal);
void delAllJalur(simpul *awal);
void delSimpul(nilai temp, graph *G);
void printGraph(graph G);