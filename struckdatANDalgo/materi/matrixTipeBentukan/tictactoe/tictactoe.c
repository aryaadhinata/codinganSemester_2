#include <stdio.h>
#include <stdlib.h> // library ini digunakan untuk memanipusai syestem (terminal)

// contoh pembuatan game yang clean di terminal tic tac toe

int main() {
    system("cls"); // membersihkan layar terminal

    // deklarasi untuk matrixnya yang bernama papan dengan dimensi 3x3
    // dan juga deklarasi iterator yang akan digunakan
    int papan[3][3];
    int i, j, k;
    
    // looping untuk set semua nilai elemen untuk jadi 0
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            papan[i][j] = 0;
        }
    }

    // dekalarasi dan set up nilai awal dari variabel
    // *    variabel pemain untuk menunjukan giliran siapa sekarang dan di set -1 karena 
    //      program akan menyiapkan papan terlebih dahulu belum boleh di mainkan
    //      pemain 1 ditandai dengan nilai 1
    //      pemain 2 ditandai dengan nilai 2
    // *    variabel x dan y marking kordinat yang digunakan menyimpan dan melakukan langkah yang 
    //      di inginkan oleh user
    int pemain = -1;
    int x = -1, y = -1;

    // !! looping dengan iterasi i digunakan untuk banyak input sehingga ada 9 kali input dalam program ini !!
    for(int i = 0; i <= 9; i++) {

        // kondisi jika pemain sudah melakukan langkah maka ubah nilai di elemen yang dimaksud dengan nilai pemain
        if((x != -1) && (y != -1)){
            papan[x][y] = pemain;
        }

        // bagian untuk pengelolaan tampilan papan
        printf("Kondisi Papan:\n");
        printf("-------------\n");
        for(int j = 0; j < 3; j++) {
            printf("| ");
            // pengkondisian untuk mengecek nilai pemain di setiap elemen yang ada
            for(k = 0; k < 3; k++){
                if(papan[k][j] == 0){
                    printf("  | ");
                }else if(papan[k][j] == 1){
                    printf("O | ");
                }else if(papan[k][j] == 2){
                    printf("X | ");
                }
            }
            printf("\n-------------\n");
        }
        printf("\n");

        // mengganti status pemain yang mengisi sekarang
        if(pemain == 1){
            pemain = 2;
        }else{
            pemain = 1;
        }

        // meminta pengisisan untuk bermain
        printf("Masukan X, Y (Pemain %d): ", pemain);
        scanf("%d %d", &x, &y);
        system("cls");
    }

    return 0;
}