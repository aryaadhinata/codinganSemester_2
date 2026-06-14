#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Pratikum 6 dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

extern int indeks;
extern int panjangKata;
extern char cw[65];

void STARTWORD(char pita[]);
void RESETWORD();
void INCWORD(char pita[]);
void INCWORD(char pita[]);
char* GETWORD();
int GETPANJANGKATA();
int EOPWORD(char pita[]);

typedef struct{
    char node[257];
    char status;
    int ukuran;
}nilai;

typedef struct smp *alamatSimpul;
typedef struct smp{
    nilai kontainer;
    alamatSimpul sibling;
    alamatSimpul child;
}simpul;

typedef struct{
    simpul *root;
}tree;

void makeTree(nilai temp, tree *T);
void addChild(nilai temp, simpul *root);
void delAll(simpul *root);
void delChild(nilai temp, simpul *root);
simpul* findSimpul(char temp[], simpul *root);
void printTreePreOrder(simpul *root);
void printTreePostOrder(simpul *root);
// int isEqual(simpul *root1, simpul *root2);