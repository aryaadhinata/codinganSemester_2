#include <stdio.h>

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan kuis 1 dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

typedef struct{
    int x, y, kuota, harJul, biPeng, mark;
    char kodTen[11];
}nilai;

typedef struct{
    nilai kontainer;
    int next;
}elemen;

typedef struct{
    int first;
    elemen data[100];
}list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);

void addFirst(list *L, nilai temp);
void addAfter(int prev, list *L, nilai temp);
void addLast(list *L, nilai temp);

void delFirst(list *L);
void delAfter(int prev, list *L);
void delLast(list *L);
void delAll(list *L);

void pindah(int tunjuk, list *L);
void cek(int batas, list *L);

void printElement(list L);