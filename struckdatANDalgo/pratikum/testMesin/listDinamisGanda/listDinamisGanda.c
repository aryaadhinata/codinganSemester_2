#include "head.h"

int main(){
    list L;
    nilai temp[6];

    createList(&L);
    for(int i = 0; i < 7; i++){
        scanf("%s %s %d %d", temp[i].merk, temp[i].tipe, &temp[i].harga, &temp[i].stock);
    }
    addLast(temp[0], &L);
    addFirst(temp[1], &L);
    addLast(temp[2], &L);
    addBefore(L.first, temp[3], &L);
    printElement(L);
    
    addAfter(L.first, temp[4], &L);
    delLast(&L);
    delAfter(L.first, &L);
    addBefore(L.tail, temp[5], &L);
    delFirst(&L);
    printElementReverse(L);

    delAll(&L);
    printElement(L);
    
    addLast(temp[6], &L);
    printElement(L);
    
    delLast(&L);
    printElement(L);
    
    return 0;
}