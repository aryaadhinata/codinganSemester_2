#include <stdio.h>
// Program untuk mengubah elemen genap dalam matriks 3x3 dengan nilai yang diberikan pengguna

int main(){
    int matrix[3][3]; // deklarasi matriks 3x3
    int baris, kolom; // variabel untuk iterasi baris dan kolom
    for(int baris = 0; baris < 3; baris++) { // loop untuk baris
        for(int kolom = 0; kolom < 3; kolom++) { // loop untuk kolom
            printf("masukan nilai pada elemen [%d][%d] :", baris+1, kolom+1); // input elemen matriks
            scanf("%d", &matrix[baris][kolom]); // menyimpan input ke dalam matriks
        }
    }

    int x; // variabel untuk nilai pengganti elemen genap
    printf("\nmasukan nilai yang akan mengubah nilai genap :"); // input nilai pengganti
    scanf("%d", &x); // menyimpan nilai pengganti

    for(int baris = 0; baris < 3; baris++) { // loop untuk menampilkan dan mengubah elemen matriks
        for(int kolom = 0; kolom < 3; kolom++) { // loop untuk kolom
            if(matrix[baris][kolom] % 2 == 0){ // cek apakah elemen genap
                matrix[baris][kolom] = x; // ubah elemen genap dengan nilai x
            }
            printf("%d ", matrix[baris][kolom]); // tampilkan elemen matriks
        }
        printf("\n");
    }

    return 0;
}