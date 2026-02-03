#include <stdio.h>
// kode untuk melakukan perkalian pada matrix

int main() {
    int matrix1[2][2]; // deklarasi matrix pertama dengan ordo 2×2
    int matrix2[2][2]; // deklarasi matrix kedua dengan ordo 2×2
    int matrix_hasil[2][2]; // deklarasi hasil matrix dengan ordo 2×2
    int baris, kolom; // deklarasi baris dan kolom yang akan membentuk ordo
    for(int baris = 0; baris < 2; baris++) { // loop untuk baris
        for(int kolom = 0; kolom < 2; kolom++) { // loop untuk kolom
            printf("Masukkan elemen [%d][%d] dari matrix pertama: ", baris+1, kolom+1); // UI untuk meminta mengisis elemen pada matrix pertama
            scanf("%d", &matrix1[baris][kolom]); // mengisi elemen matrix pertama
        }
    }

    printf("\n\n");
    
    for(int baris = 0; baris < 2; baris++){ // loop untuk baris
        for(int kolom = 0; kolom < 2; kolom++){ // loop untuk kolom
            printf("Masukkan elemen [%d][%d] dari matrix kedua: ", baris+1, kolom+1); // UI untuk meminta mengisi elemen pada matrix kedua
            scanf("%d", &matrix2[baris][kolom]); // megisi elemen pada matrix kedua
        }
    }

    for(int baris = 0; baris < 2; baris++){ // loop untuk baris
        for(int kolom = 0; kolom < 2; kolom++){ // loop untuk kolom
            matrix_hasil[baris][kolom] = 0; // menetapkan nilai untuk matrix hasil di elemen sekarang masih nol
            for(int jumlah_kali = 0; jumlah_kali < 2; jumlah_kali++){ // melakukan loop untuk penjumlahan sebanyak jumlah kalinya
                matrix_hasil[baris][kolom] += (matrix1[baris][jumlah_kali] * matrix2[jumlah_kali][kolom]); // melakukan penjumlahan dan perkalian sesuai dengan peraturan matrix
            }
        }
        printf("\n");
    }

    printf("matrix pertama :\n"); // menunjukan isi elemen pada matrix pertama
    for(int baris = 0; baris < 2; baris++){ // loop untuk baris
        for(int kolom = 0; kolom < 2; kolom++){ // loop untuk kolom
            printf("%d ", matrix1[baris][kolom]); // menunjukan matrix pertama kepada user
        }
        printf("\n");
    }
    printf("matrix kedua :\n"); // menunjukan isi elemen pada matrix kedua
    for(int baris = 0; baris < 2; baris++){ // loop untuk baris 
        for(int kolom = 0; kolom < 2; kolom++){ // loop untuk kolom
            printf("%d ", matrix2[baris][kolom]); // menunjukan matrix kedua kepada user
        }
        printf("\n");
    }

    printf("\nmatrix hasil :\n"); // menunjukan isi elemen pada matrix hasil
    for(int baris = 0; baris < 2; baris++){ // loop untuk baris
        for(int kolom = 0; kolom < 2; kolom++){ // loop untuk kolom
            printf("%d ", matrix_hasil[baris][kolom]); // menunjukan matrix hasil kepada user
        }
        printf("\n");
    }

    return 0;
}