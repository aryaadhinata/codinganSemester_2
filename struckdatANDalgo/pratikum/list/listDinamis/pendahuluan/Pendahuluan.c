#include "head.h"
    
int main() {
        list L;
        nilai Temp[6];
        createList(&L);
        int i = 0;
        for(i = 0; i < 6; i++){
            scanf("%s %s %d %s", Temp[i].brand, Temp[i].jenPak, &Temp[i].stock, Temp[i].avabli);
        }
        i = 0;
        
        addFirst(Temp[i], &L);
        i++;
        addFirst(Temp[i], &L);
        i++;
        addAfter(L.first, Temp[i], &L);
        i++;
        addLast(Temp[i], &L);
        i++;
        
        printf("----------------------------------------\n");
        printElement(L);
        
        delFirst(&L);
        addAfter(L.first->next, Temp[i], &L);
        i++;
        delLast(&L);
        
        printElement(L);
        
        delAfter(L.first, &L);
        addLast(Temp[i], &L);
        i++;
        
        printElement(L);
        
        delAll(&L);
        printElement(L);
    return 0;
}