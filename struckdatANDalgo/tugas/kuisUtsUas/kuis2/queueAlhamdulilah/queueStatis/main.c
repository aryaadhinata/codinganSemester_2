#include "head.h"

// greedy yang saya pakai masukan dulu sesuai prioritas lalu saya bagi sesuai batas skala

int main(){
    queue Q;
    createEmpty(&Q);
    nilai temp;

    int banDat;
    scanf("%d", &banDat);

    for(int i = 0; i < banDat; i++){
        scanf("%s %s %d %d %d", temp.nama, temp.negara, &temp.progres, &temp.tahun, &temp.prior);
        addPriority(temp, &Q);
    }

    int batasPrior;
    scanf("%d", &batasPrior);
    
    queue R, S;
    createEmpty(&R);
    createEmpty(&S);

    cek(batasPrior, &Q, &R, &S);
    printQueue(R, S);
    return 0;
}