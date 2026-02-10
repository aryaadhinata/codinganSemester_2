#include <stdio.h>
#include <string.h>
// program tipe bentukan matrix

typedef struct{
    char nama[51], jenis_kelamin; // untuk data umur dan jenis kelamin
    int umur; // untuk data umur
}kotak;

int main(){
    int baris, kolom; // deklarasi baris dan kolom
    scanf("%d %d", &baris, &kolom); // inisialisasi baris dan kolom

    kotak data[baris][kolom]; // matrix bentukan

    for(int i = 0; i < baris; i++){ // loop untuk baris
        for(int j = 0; j < kolom; j++){ // loop untuk kolom
            scanf("%s %d %c", data[i][j].nama, &data[i][j].umur, &data[i][j].jenis_kelamin); // mengisi nilai matrix bentukan
        }
    }

    printf("==========================================\n");
    for(int i = 0; i < baris; i++){ // loop untuk baris
        printf("Baris ke %d:\n", i + 1); // print penanda untuk baris
        for(int j = 0 ; j < kolom; j++){ // loop untuk kolom
            // menampilkan tipe bentukan
            printf("%d. %s %d %c (kolom %d)\n", j+ 1, data[i][j].nama, data[i][j].umur, data[i][j].jenis_kelamin, j + 1);
        }
        printf("==========================================\n");
    }

    return 0;
}