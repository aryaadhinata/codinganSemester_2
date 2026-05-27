#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
    char str[13];
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
simpul* findSimpul(nilai temp, simpul *root);
void printTreePreOrder(simpul *root);
void printTreePostOrder(simpul *root);
int isEqual(simpul *root1, simpul *root2);