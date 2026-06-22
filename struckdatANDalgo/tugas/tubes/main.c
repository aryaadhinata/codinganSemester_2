#include "head.h"

int main(){
    tree T;
    nilai temp;
    
    // nyoba convers berhasil
    // char coba[33];
    // scanf("%s", coba);

    // int hasil = convers(coba);
    // printf("%d\n", hasil);

    int banyak;
    int pertama = 1;
    scanf("%d\n", &banyak);
    //ternyatra ada buffernya sebelumnya aku kaliin dua karena dalam sekali input langsung kepake dua iterasi
    // if(banyak % 2 == 0){
    //     banyak = banyak*2 + 1;
    // }else{
    //     banyak = banyak*2 - 1;
    // }

    char pita[129];
    char namaRoot[129];
    simpul *cari = NULL;

    for(int i = 0; i < banyak; i++){
        scanf("%128[^\n]%*c", pita);
        // printf("%s -1 ", pita);
        // printf("-masuk\n");
        STARTWORD(pita);
        strcpy(temp.node, GETWORD());
        INCWORD(pita);
        strcpy(namaRoot, GETWORD());
        INCWORD(pita);
        temp.poin = convers(GETWORD());
        INCWORD(pita);
        temp.banyakPeluang = convers(GETWORD());
        // printf("%s %s %d %d\n", temp.node, namaRoot, temp.poin, temp.banyakPeluang);
        
        for(int j = 0; j < temp.banyakPeluang; j++){
            // printf(" 8- %s\n", pita);
            scanf("%s\n", temp.peluang[j]); // ada buffer sebelumnya jadi di kasih \n disini biar buffernya hilang
        }
        
        if(pertama != 1){
            cari = findSimpul(namaRoot, T.root);
        }
        // printf("masuk luar\n");
        if(pertama == 1){
            // printf("masuk iya\n");
            makeTree(temp, &T);
            pertama = 0;
        }else{
            // printf("masuk nggak\n");
            addChild(temp, cari);
        }
        // printf("\n==- %d -==\n", i);
    }
    
    char pilihPeluang[129];
    scanf("%s", pilihPeluang);

    int banyakLayer = countLayer(T.root); // nyimpen banyak layer
    int spasi[banyakLayer]; // jadiin array buat setiap layer
    spasi[0] = 0; // nilai awal
    for(int i = 1; i <= banyakLayer; i++){
        spasi[i] = cariSpasi(i-1, T.root) + spasi[i-1]; // ngambil dari nilai sekarang + nilai sebelumnya
    }
    // for(int i = 1; i <= banyakLayer + 1; i++){
    //     spasi[i] = cariSpasi(i-1, T.root);
    // }
    
    // for(int i = 0; i < banyakLayer + 1; i++){
    //     printf("%d ==[%d]==\n", i, spasi[i]);
    // }
    // printf("\n====== %d =====\n", banyakLayer);

    printTreePreOrder(spasi, banyakLayer, T.root);
    // printf("===========================================================================================\n\n");
    // printTreePostOrder(spasi, banyakLayer, T.root);
    
    // printf("%s\n", pilihPeluang);
    simpul *ceks = findSimpul(pilihPeluang, T.root);
    if(ceks != NULL){
        ceks = findPeluang(pilihPeluang, T.root);
    }
    
    if(ceks != NULL){
        // printf("masuk\n");
        hapusTidakVisit(T.root);
    }
    spasi[0] = 0; // nilai awal
    for(int i = 1; i <= banyakLayer; i++){
        spasi[i] = cariSpasi(i-1, T.root) + spasi[i-1]; // ngambil dari nilai sekarang + nilai sebelumnya
    }
    // delChild(T.root);
    printTreePreOrder(spasi, banyakLayer, T.root);
    // printTreePostOrder(spasi, banyakLayer, T.root);
    
    int TotalPoin = 0; // nyimpen total poin yang akan di tampilkan 
    TotalPoin = countPoin(TotalPoin, T.root); // hitung banyak poin yang ada di tree sekarang
    
    printf("peluang akhir yang diambil: %s\n", pilihPeluang);
    printf("total value: %d\n", TotalPoin);
    printf("semua peluang:\n");
    printPeluang(T.root);
    return 0;
}