#include "headUndoApay.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Pratikum 5 dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

int main() {
    // create queue awal yang akan digunakan nantinya
    queue Q;
    createEmptyQueue(&Q);

    // menyimpan nilai sementara
    nilai temp;

    // jumlah jumlah tugas yang akan di gunakan
    int jumTugAwa, jumTugPro, jumOpe;
    scanf("%d", &jumTugAwa);
    for(int i = 0; i < jumTugAwa; i++){
        scanf("%s %s %d", temp.namTug, temp.jenTug, &temp.prior);
        addPrior(temp, &Q);
    }

    scanf("%d", &jumTugPro);
    nilai tugPro[jumTugPro];
    for(int i = 0; i < jumTugPro; i++){
        scanf("%s", tugPro[i].namTug);
    }
    
    scanf("%d", &jumOpe);

    printQueueAwal(Q);
    
    // membuat queue baru untuk menyimpan history
    queue Qh;
    createEmptyQueue(&Qh);
    for(int i = 0; i < jumOpe; i++){
        move(&Q, &Qh);
    }
    
    printExecute(Q, Qh);

    // mengcopy queue history ke stack canUndo
    stack canUndo;
    createEmpty(&canUndo);
    for(int i = 0; i < jumOpe; i++){
        push(Qh.data[i], &canUndo);
    }

    // mengeluarkan yang sudah di undo dari stack canUndo ke stack hasUndo
    stack hasUndo;
    createEmpty(&hasUndo);
    popTo(jumTugPro, tugPro, &canUndo, &hasUndo);
    
    printStackUndoBefore(canUndo);
    printStackUndoAfter(hasUndo);
    return 0;
}