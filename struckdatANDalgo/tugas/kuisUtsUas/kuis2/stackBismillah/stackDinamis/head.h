#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan kuis 2 dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

typedef struct{
    char id[17], nama[37];
    int skorKompe, skorBah, hardSkill, teswan;
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
void pop(stack *S);
void popTo(elemen* pindah, stack *S, stack *T);
int sumScore(elemen* S);
void move(int batas, stack *S, stack *T, stack *U);
void printStack(stack S);
void printStackDua(stack S, stack T);