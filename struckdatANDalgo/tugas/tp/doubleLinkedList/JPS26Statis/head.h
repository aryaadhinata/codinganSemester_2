#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char namBang[33], kateg[33], urgent[33];
}nilai;

typedef struct{
    nilai kontainer;
    int prev;
    int next;
} elemen;

typedef struct{
    int first;
    int tail;
    elemen data[100];
}list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);

void addFirst(nilai temp, list *L);
void addAfter(int before, nilai temp, list *L);
void addBefore(int after, nilai temp, list *L);
void addLast(nilai temp, list *L);

void delFirst(list *L);
void delAfter(int before, list *L);
void delLast(list *L);
void delAll(list *L);

int prioritas(int cek, list *L);
void swap(int p, int q, list *L);
void sort(list *L);

void printElement(list L);
void printElementReverse(list L);