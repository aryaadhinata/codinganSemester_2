#include <stdio.h>

// program yang mengenalkan jika dalam elemen matrix tidak hanya satu jenis nilai saja tetapi juga
// bisa dalam bentuk tipe bentukan

// tipe bentukan
// x sebagai nilai kordinat x
// y sebagai nilai kordinat y
typedef struct{ 
    int x, y;
}titik;

int main(){
    // matrix tipe bentukan
    // setiap elemen di dalam matrix 4x4 ada nilai x dan y
    titik matrix[4][4];

    // looping untuk mengisi kordinat masing masing elemen matrix yang ada
    for(int i = 0; i < 4; i++) { // loopnya meminta masukan user sebanyak 32 kali
        for(int j = 0; j < 4; j++) {
            printf("\nmasukan kordinat x:\n");
            scanf("%d", &matrix[i][j].x);
            printf("\nmasukan kordinat y:\n");
            scanf("%d", &matrix[i][j].y);
        }
    }

    // looping untuk menanmpilkan kordinat yang sebelumnya sudah di inputkan
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("kordinat x: %d\n", matrix[i][j].x);
            printf("kordinat y: %d\n", matrix[i][j].y);
        }
    }

    return 0;
}