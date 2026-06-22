#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Pratikum 7 dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

typedef struct smp *alamatSimpul;
typedef struct jlr *alamatJalur;

// strucktur yang di tambahin degre buat nyimoer drajat si simpul 
// dan visit buat nyimpen seberapa banya jalur itu harus di lewatin

typedef struct{
    int degre;
    char namaSimpul[65];
}nilai;

typedef struct smp{
    nilai kontainer;
    alamatSimpul nextSimpul;
    alamatJalur arc; 
}simpul;

typedef struct jlr{
    int bobotJalur, visit;
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
void delJalur(char tuju[], simpul *awal); // di edit biar sesuai sama yang di butuhkan jadi cuma nyari dari awal sampai sama tuju[]
void delAllJalur(simpul *awal);
void delSimpul(char temp[], simpul *node);
int tandaiVisit(int penanda, simpul *awal, simpul *akhir); // buat nandain visit backtrack dari akhir ke awal jadi add yang overlap juga
void tandaiDegre(simpul *awal, simpul *akhir); // ini drajat simpulnya maksudnya berapa banyak kemungkinan sampe kesitu
void refreshGraph(simpul *awal, simpul *akhir); // ngurangi visitnya dengan kondisi kalo derajat yang sebelumnya itu harus sama dengan jumlah visit yang belum di kurangi
void hapusTidakVisit(simpul *node); // hapus yang visit nya 0 dan degreenya 0 juga
int printGraph(simpul *awal, simpul *akhir); // ngeprint yang diperluin aja