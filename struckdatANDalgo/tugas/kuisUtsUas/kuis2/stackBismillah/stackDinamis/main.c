#include "head.h"

// gready saya menggunakan stack lain untuk membalikan stack awal

int main(){
    stack S;
    createEmpty(&S);
    nilai temp;

    int daPer;
    scanf("%d", &daPer);

    for(int i = 0; i < daPer; i++){
        scanf("%s %s %d %d %d %d", temp.id, temp.nama, &temp.skorKompe, &temp.skorBah, &temp.hardSkill, &temp.teswan);
        push(temp, &S);
    }

    int threshold;
    scanf("%d", &threshold);

    printStack(S);

    stack T;
    createEmpty(&T);
    stack U;
    createEmpty(&U);
    move(threshold, &S, &T, &U);
    
    printStackDua(U, T);
    return 0;
}