#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tes Mesin Stack dinamis dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

typedef struct{
    char nama[33];
    int berat;
}nilai;

typedef struct elmt *alamatelmt;
typedef struct elmt{
    nilai kontainer;
    alamatelmt next;
}elemen;

typedef struct {
    elemen* top;
}stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(nilai temp, stack *S );
void popto(stack *S, stack *T);
void pop(stack *S);
void printStack(stack S, stack T);