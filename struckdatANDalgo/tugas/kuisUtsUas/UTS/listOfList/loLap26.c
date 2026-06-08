#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan UTS dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

/*
    analisis bigO adalan O(n^2) karena program yang paling worse itu ada nested while
*/

int main(){
    list L;
    createList(&L);
    nilai tempB;
    nilaiSec tempK;
    
    int ban;
    scanf("%d", &ban);

    for(int i = 0; i < ban; i++){
        scanf("%s %s %d %d %s %d", tempB.namPro, tempK.tokSup, &tempK.PersKom, &tempK.harPro, tempB.namaAf, &tempK.proLak);
        addLastB(tempB, &L);
        eBaris *last = lastBaris(L.first);
        addLastK(tempK, last);
    }

    char namProCar[33], namAfCar[33];
    scanf("%s", namProCar);
    scanf("%s", namAfCar);
    
    printElement(namProCar, namAfCar, L);
    return 0;
}