#include "headGraph.h"

int main(){
    graph G;
    int banyak;
    scanf("%d", &banyak);
    nilai temp[banyak];
    char tujuan[banyak][65];
    int bobot[banyak];

    for(int i = 0; i < banyak; i++){
        scanf("%s %s %d", temp[i].konten, tujuan[i], &bobot[i]);
    }

    char hilang[65];
    scanf("%s", hilang);

    // char pembanding[banyak*8][65];
    // int a = 0;
    // for(int i = 0; i < banyak; i++){
    //     for(int j = 0; j < banyak; j++){
    //         if(strcmp(temp[i].konten, tujuan[j]) != 0){
    //             for(int k = a; k < banyak*8; k++){
    //                 if(strcmp(temp[i].konten, pembanding[k]) != 0){
    //                     strcpy(pembanding[a], temp[i].konten);
    //                     a++;
    //                 }
    //             }
    //             for(int l = a; l < banyak*8; l++){
    //                 if(strcmp(tujuan[j], pembanding[l]) != 0){
    //                     strcpy(pembanding[a], tujuan[j]);
    //                     a++; 
    //                 }
    //             }
    //         }
    //     }
    // }
    
    createEmpty(&G);
    simpul *cari;
    for(int i = 0; i < banyak; i++){
        cari = findSimpul(temp[i].konten, G);
        if(cari == NULL){
            addSimpul(temp[i].konten, &G);
        }
        cari = findSimpul(tujuan[i], G);
        if(cari == NULL){
            addSimpul(tujuan[i], &G);
        }
    }
    
    simpul *begin;
    simpul *end;
    
    for(int i = 0; i < banyak; i++){
        begin = findSimpul(temp[i].konten, G);
        end = findSimpul(tujuan[i], G);
        addJalur(begin, end, bobot[i]);
    }
    
    printf("before:\n");
    printGraph(G);
    
    delSimpul(hilang, &G);
    printf("\nafter:\n");
    printGraph(G);

    return 0;
}