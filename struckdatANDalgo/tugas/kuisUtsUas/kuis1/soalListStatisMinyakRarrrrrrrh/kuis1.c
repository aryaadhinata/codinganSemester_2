#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan kuis 1 dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

int main() {
    list L;
    nilai temp;
    createList(&L);
    
    int banList;
    scanf("%d", &banList);

    for(int i = 0; i < banList; i++){
        scanf("%d %d %s %d %d %d", &temp.x, &temp.y, temp.kodTen, &temp.kuota, &temp.harJul, &temp.biPeng);
        addLast(&L, temp);
    }
    
    int batas;
    scanf("%d", &batas);
    
    cek(batas, &L);
    printElement(L);
    return 0;
}