#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tes Mesin Stack dinamis dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

int main(){
    stack gudang; // s1
    stack truk; // s2
    nilai temp[7];
    createEmpty(&gudang);
    createEmpty(&truk);
    
    for(int i = 0; i < 7; i++){
        scanf("%s %d", temp[i].nama, &temp[i].berat);
    }
    printf("--------------------------------------------\n");
    printStack(gudang, truk);
    
    push(temp[0], &gudang);
    push(temp[1], &gudang);
    push(temp[2], &gudang);
    printf("--------------------------------------------\n");
    printStack(gudang, truk);
    
    popto(&gudang, &truk);
    popto(&gudang, &truk);
    printf("--------------------------------------------\n");
    printStack(gudang, truk);
    
    push(temp[3], &gudang);
    push(temp[4], &truk);
    push(temp[5], &truk);
    push(temp[6], &gudang);
    

    pop(&truk);
    popto(&truk, &gudang);
    popto(&truk, &gudang);
    printf("--------------------------------------------\n");
    printStack(gudang, truk);
    
    printf("--------------------------------------------\n");
    pop(&truk);
    pop(&truk);
    pop(&truk);
    printf("--------------------------------------------\n");
    printStack(gudang, truk);
    
}