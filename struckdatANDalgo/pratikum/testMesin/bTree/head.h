#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
    char konten;
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
void printTreePreOrder(simpul *root);
void printTreeInOrder(simpul *root);
void printTreePostOrder(simpul *root);
int isEqual(simpul *root1, simpul *root2);
