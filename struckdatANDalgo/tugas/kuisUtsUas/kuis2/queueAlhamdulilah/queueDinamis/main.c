#include "head.h"

int main(){
    queue Q;
    createEmpty(&Q);
    nilai temp;
    printQueue(Q);
    printf("=================\n");
    strcpy(temp.nim, "13507701");
    strcpy(temp.nama, "Nana");
    temp.prio = 3;
    temp.skor = 64.75;
    add(temp, &Q);

    strcpy(temp.nim, "13507702");
    strcpy(temp.nama, "Rudi");
    temp.prio = 1;
    temp.skor = 75.11;
    addPriority(temp, &Q);
    
    strcpy(temp.nim, "13507703");
    strcpy(temp.nama, "Dea");
    temp.prio = 2;
    temp.skor = 84.63;
    addPriority(temp, &Q);

    printQueue(Q);
    printf("=================\n");
    del(&Q);
    del(&Q);
    printQueue(Q);
    printf("=================\n");
    return 0;
}