#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan UTS dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

/*
    analisis bigO program ini adalah O(n^2) karena ada nested while dan bigO tersebut adalah yang tertinggi dari seluruh
    program ini
*/

// O(n) karena ada Looping
int main(){
    list L;
    nilai temp;
    createList(&L);
    
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s %s %d %lld", temp.namCre, temp.temVid, &temp.tahVid, &temp.jumVie);
        if(i % 2 == 0){
            addLast(temp, &L);
        }else{
            if(i == 1){
                addFirst(temp, &L);
            }else{
                addAfter(L.tail->prev, temp, &L);
            }
        }
    }
    int posisi, banyak;
    scanf("%d", &posisi);
    scanf("%d", &banyak);

    printElement(posisi, banyak, n, L);

    return 0;
}