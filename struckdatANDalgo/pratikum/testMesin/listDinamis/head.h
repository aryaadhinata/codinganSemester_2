#include <stdio.h>
#include <malloc.h>

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tes Mesin List Dinamis dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

typedef struct{
	char brand[33], jenPak[17], avabli[17];
	int stock;
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

void addFirst(nilai temp, list *L);
void addAfter(elemen* prev, nilai temp, list *L);
void addLast(nilai temp, list *L);

void delFirst(list *L);
void delAfter(elemen* prev, list *L);
void delLast(list *L);
void delAll(list *L);

void printElement(list L);