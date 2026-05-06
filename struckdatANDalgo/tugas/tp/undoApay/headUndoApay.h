#include <stdio.h>
#include <string.h>

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Pratikum 5 dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

typedef struct{
    char namTug[65];
    char jenTug[9];
    int prior;
}nilai;

typedef struct{
    int first;
    int last;
    nilai data[129];
}queue;

typedef struct{
    int top;
    nilai data[129];
}stack;

void createEmptyQueue(queue *Q);
int isEmptyQueue(queue Q);
int isFullQueue(queue Q);
int countQueue(queue Q);
void addPrior(nilai temp, queue *Q );
void addTo(nilai temp, queue *Q );
void del(queue *Q);
void move(queue *Q, queue *R);

void createEmpty(stack *S);
int isEmpty(stack S);
int isFull(stack S);
void push(nilai temp, stack *S );
void popTo(int banCek, nilai cek[], stack *S, stack *T);

void printQueueAwal(queue Q);
void printExecute(queue Q, queue R);
void printStackUndoBefore(stack S);
void printStackUndoAfter(stack S);