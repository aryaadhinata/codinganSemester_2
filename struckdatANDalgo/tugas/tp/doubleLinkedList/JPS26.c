#include "head.h"

int main(){
    list L;
    nilai temp;
    createList(&L);
    
    int jumBar;
    scanf("%d", &jumBar);
    for(int i = 0; i < jumBar; i++){
        scanf("%s %s %s", temp.namBang, temp.kateg, temp.urgent);
        addLast(temp, &L);
    }
    ins(&L);
    printElement(L);
    printf("\n");
    printElementReverse(L);

    return 0;
}