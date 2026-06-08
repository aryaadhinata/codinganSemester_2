#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan UTS dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

typedef struct{
    char namCre[33], temVid[65];
    int tahVid;
    long long int jumVie;
}nilai;

typedef struct elmt *alamatelmt;

typedef struct elmt{
    nilai kontainer;
    alamatelmt prev;
    alamatelmt next;
} elemen;

typedef struct{
    elemen *first;
    elemen *tail;
}list;

void createList(list *L);
int countElement(list L);
void addFirst(nilai temp, list *L);
void addAfter(elemen* before, nilai temp, list *L);
void addBefore(elemen* after, nilai temp, list *L);
void addLast(nilai temp, list *L);

void delFirst(list *L);
void delAfter(elemen* before, list *L);
void delLast(list *L);
void delAll(list *L);

void printElement(int posisi, int banyak, int n, list L);