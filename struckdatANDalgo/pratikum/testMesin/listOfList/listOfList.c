#include "head.h"

int main(){
    list L;
    createList(&L);
    nilai tempB;
    nilaiSec tempK;
    
    int banGen;
    scanf("%d", &banGen);

    for(int i = 0; i < banGen; i++){
        scanf("%s", tempB.kateg);
        addLastB(tempB, &L);

        eBaris *last = lastBaris(L.first);
        for(int j = 0; j < 5; j++){
            switch(j){
                case 0 :{
                    scanf("%s %s %d", tempK.nama, tempK.penulis, &tempK.jumHal);
                    addLastK(tempK, last);
                    break;
                }
                case 1 :{
                    scanf("%s %s %d", tempK.nama, tempK.penulis, &tempK.jumHal);
                    addFirstK(tempK, last);
                    break;
                }
                case 2 :{
                    scanf("%s %s %d", tempK.nama, tempK.penulis, &tempK.jumHal);
                    addAfterK(last->col->next_kol, tempK);
                    break;
                }
                case 3 :{
                    scanf("%s %s %d", tempK.nama, tempK.penulis, &tempK.jumHal);
                    addFirstK(tempK, last);
                    break;
                }
                case 4 :{
                    scanf("%s %s %d", tempK.nama, tempK.penulis, &tempK.jumHal);
                    addLastK(tempK, last);   
                    break;
                }
            }
        }
    }
    printElement(L);
    delFirstB(&L);
    printElement(L);
    delAfterB(L.first->next);
    delAfterK(L.first->next->col);
    printElement(L);
    delLastK(L.first);
    delFirstK(L.first->next);
    printElement(L);
    delAllB(&L);
    printElement(L);
    printf("+=================================+\n");
    return 0;
}