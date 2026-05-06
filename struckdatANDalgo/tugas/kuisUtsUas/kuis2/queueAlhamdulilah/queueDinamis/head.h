#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char nim[10];
    char nama[50];
    int prio;
    float skor;
}nilai;

typedef struct elm *alamatelmt;
typedef struct elm{
    nilai kontainer;
    alamatelmt next;
}elemen;

typedef struct{
    elemen *first;
    elemen *last;
}queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(nilai temp, queue *Q);
void del(queue *Q);
void addPriority(nilai temp, queue *Q);
void printQueue(queue Q);