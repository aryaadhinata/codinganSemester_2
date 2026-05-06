#include <stdio.h>
#include <string.h>

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan kuis 2 dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

typedef struct{
    char nama[65], negara[65];
    int progres, tahun;
    int prior;
}nilai;

typedef struct{
    int first;
    int last;
nilai data[65];
}queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int isFull(queue Q);
void add(nilai temp, queue *Q );
void del(queue *Q);
void addPriority(nilai temp, queue *Q );
void cek(int batas, queue *Q, queue *R, queue *S);
void printQueue(queue Q, queue R);