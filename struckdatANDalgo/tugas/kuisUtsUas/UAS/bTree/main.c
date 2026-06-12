#include "head.h"

int main(){
    tree T;
    nilai temp;

    int banyakSimpul;
    scanf("%d", &banyakSimpul);

    char posisi[9], akar[9];
    for(int i = 0; i < banyakSimpul; i++){
        scanf("%s %s %s %d", temp.namaSimpul, akar, posisi, &temp.bawaan);
        if(strcmp(akar, "akar") == 0){
            makeTree(temp, &T);
        }else{
            cariAkar(posisi, akar, temp, T.root);
            // printf("masuk\n");
        }
    }

    int countParent = 0, sumTot = 0;
    cariAnak(&countParent, &sumTot, T.root);

    printf("jumlah simpul orang tua simpul daun: %d\n", countParent);
    printf("jumlah integer semua simpul orang tua dan simpul daun:%d\n", sumTot);
    // coba ngecek
    // printTreeInOrder(T.root);

    return 0;
}