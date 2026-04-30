#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char namBang[33], kateg[33], urgent[33];
}nilai;

typedef struct elmt *alamatelmt;

typedef struct elmt{
    nilai kontainer;
    alamatelmt prev;
    alamatelmt next;
} elemen;

typedef struct{
    elemen *first;
    elemen *tail;
}list;

void createList(list *L);
int countElement(list L);
void addFirst(nilai temp, list *L);
void addAfter(elemen* before, nilai temp, list *L);
void addBefore(elemen* after, nilai temp, list *L);
void addLast(nilai temp, list *L);

void delFirst(list *L);
void delAfter(elemen* before, list *L);
void delLast(list *L);
void delAll(list *L);

int prioritas(elemen *cek, list *L);
void swap(elemen *p, elemen *q, list *L);
void ins(list *L);

void printElement(list L);
void printElementReverse(list L);