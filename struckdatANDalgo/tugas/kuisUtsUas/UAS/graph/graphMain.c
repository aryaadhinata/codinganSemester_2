#include "headGraph.h"

int main(){
    graph G;
    nilai temp;

    int banyak;
    char tujuan[3];
    scanf("%d", &banyak);

    createEmpty(&G);
    simpul *begin;
    simpul *end;
    for(int i = 0; i < banyak; i++){
        scanf("%s %s %d", temp.konten, tujuan, &temp.berat);
        begin = findSimpul(temp.konten, G);
        if(begin == NULL){
            addSimpul(temp.konten, &G);
        }
        end = findSimpul(tujuan, G);
        if(end == NULL){
            addSimpul(tujuan, &G);
        }
        begin = findSimpul(temp.konten, G);
        end = findSimpul(tujuan, G);
        addJalur(begin, end, temp.berat);
        // printf("masuk\n");
    }

    char start[3], finish[3];
    scanf("%s %s", start, finish);
    return 0;
}