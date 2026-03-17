#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Pratikum 2 dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

typedef struct{
    char namPem[33], rolPem[33];
    int comScor;
}nilai;

typedef struct elmt* alamatelmt;
typedef struct elmt{
    nilai kontainer;
    alamatelmt next;
} elemen;

typedef struct{
    elemen* first;
}list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);

void addFirst(nilai temp, list *L);
void addAfter(elemen* prev, nilai temp, list *L);
void addLast(nilai temp, list *L);

void delFirst(list *L);
void delAfter(elemen* prev, list *L);
void delLast(list *L);
void delAll(list *L);

void swap(elemen *prefP, elemen *p, elemen *q, list *L);
void sort(int kead[], list *L);
void kait(elemen *prefCek, elemen *cek, elemen *merge, list *L1, list *L2);
void mergeList(int kead[], list *L1, list *L2);

int digLeng(int n);
void printElemen(list L);