#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tes Mesin List Statis dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

int main() {
    list L;
    createList(&L);
    nilai temp[6];

    for(int i = 0; i < 6; i++){
        scanf("%s %s %s %s", temp[i].nama, temp[i].tipeSen, temp[i].peluru, temp[i].avabil);
    }
    int j = 0;
    addFirst(&L, temp[j]);j++;
    addFirst(&L, temp[j]);j++;
    addAfter(L.first, &L, temp[j]);j++;
    addLast(&L, temp[j]);j++;
    printElement(L);
    
    delFirst(&L);
    addAfter(L.data[L.first].next, &L, temp[j]);j++;
    delLast(&L);
    printElement(L);

    delAfter(L.first, &L);
    addLast(&L, temp[j]);j++;
    
    printElement(L);
    delAll(&L);

    printElement(L);
    printf("----------------------------------------\n");
    return 0;
}