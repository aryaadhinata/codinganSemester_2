#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan UAS dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

typedef struct{
    char namaSimpul[17];
    int bawaan;
}nilai;

typedef struct smp *alamatSimpul;
typedef struct smp{
    nilai kontainer;
    alamatSimpul right;
    alamatSimpul left;
}simpul;

typedef struct{
    simpul* root;
}tree;

void makeTree(nilai temp, tree *T);
void addRight(nilai temp, simpul *root);
void addLeft(nilai temp, simpul *root);
void delAll(simpul *root);
void delRight(simpul *root);
void delLeft(simpul *root);
void cariAkar(char posisi[], char namaParent[], nilai temp, simpul *root);
void cariAnak(int *countParent, int *sumTotal, simpul *root);
void printTreePreOrder(simpul *root);
void printTreeInOrder(simpul *root);
void printTreePostOrder(simpul *root);
int isEqual(simpul *root1, simpul *root2);
