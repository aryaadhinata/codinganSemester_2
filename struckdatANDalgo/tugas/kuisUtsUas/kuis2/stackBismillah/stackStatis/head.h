#include <stdio.h>
#include <string.h>

typedef struct{
    char nim[10];
    char nama[50];
    float skor;
}nilai;

typedef struct{
    int top;
    nilai data[10];
}stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int isFull(stack S);

void push(nilai temp, stack *S );
void pop(stack *S);
void popTo(stack *S, stack *T);
void printStack(stack S);