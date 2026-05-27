#include "headGraph.h"

int main(){
    graph G;
    nilai temp;

    createEmpty(&G);
    temp.konten = 'A';
    addSimpul(temp, &G);
    temp.konten = 'B';
    addSimpul(temp, &G);
    temp.konten = 'C';
    addSimpul(temp, &G);
    temp.konten = 'D';
    addSimpul(temp, &G);
    temp.konten = 'E';
    addSimpul(temp, &G);
    temp.konten = 'F';
    addSimpul(temp, &G);
    
    temp.konten = 'A';
    simpul *begin = findSimpul(temp, G);
    temp.konten = 'B';
    simpul *end = findSimpul(temp, G);
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 3);
    }
    
    temp.konten = 'B';
    begin = findSimpul(temp, G);
    temp.konten = 'D';
    end = findSimpul(temp, G);
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 3);
    }
    
    temp.konten = 'E';
    end = findSimpul(temp, G);
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 7);
    }
    
    temp.konten = 'C';
    begin = findSimpul(temp, G);
    temp.konten = 'A';
    end = findSimpul(temp, G);
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 3);
    }
    
    temp.konten = 'D';
    begin = findSimpul(temp, G);
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 8);
    }
    
    temp.konten = 'C';
    end = findSimpul(temp, G);
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 3);
    }
    
    temp.konten = 'E';
    begin = findSimpul(temp, G);
    temp.konten = 'D';
    end = findSimpul(temp, G);
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 4);
    }
    
    temp.konten = 'f';
    end = findSimpul(temp, G);
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 4);
    }
    
    temp.konten = 'f';
    begin = findSimpul(temp, G);
    temp.konten = 'D';
    end = findSimpul(temp, G);
    if((begin != NULL) && (end != NULL)){
        addJalur(begin, end, 2);
    }

    printf("=======================\n");
    printGraph(G);
    printf("=======================\n");
    
    temp.konten = 'A';
    begin = findSimpul(temp, G);
    if(begin != NULL){
        temp.konten = 'B';
        delJalur(temp, begin);
    }
}