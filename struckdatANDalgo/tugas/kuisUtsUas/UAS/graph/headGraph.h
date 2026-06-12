#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan UAS dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

typedef struct smp *alamatSimpul;
typedef struct jlr *alamatJalur;

typedef struct{
    int mark, berat;
    char konten[3];
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
void resetVisit(graph *G);
void jalan(char begin[], char end[], simpul *node);
void printGraph(graph G);