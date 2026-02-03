#include <stdio.h>
// kode untuk melakukan penjumlahan atau pengurangan dalam matrix

int main() {
    int matrix1[3][3]; // deklarasi matrix pertama dengan ordo 3×3
    int matrix2[3][3]; // deklarasi matrix kedua dengan ordo 3×3
    int baris, kolom; // deklarasi baris dan kolom untuk membentuk ordo
    for(int baris = 0; baris < 3; baris++) { // looping baris
        for(int kolom = 0; kolom < 3; kolom++) { // looping kolom
            printf("Masukkan elemen [%d][%d] dari matrix pertama: ", baris+1, kolom+1); // UI untuk memasukan nilai pada masing-masing elemenn matrix pertama
            scanf("%d", &matrix1[baris][kolom]); // memasukan nilai pada setiap elemen matrix pertama
        }
    }

    printf("\n\n");
    
    for(int baris = 0; baris < 3; baris++) { // looping baris
        for(int kolom = 0; kolom < 3; kolom++) { // looping kolom
            printf("Masukkan elemen [%d][%d] dari matrix kedua: ", baris+1, kolom+1); // UI untuk memasukan nilai pada setiap elemen matrix kedua
            scanf("%d", &matrix2[baris][kolom]); // memasukan nilai pada setiap elemen matrix kedua
        }
    }

    int kondisi; // deklarasi kondisi
    printf("Pilih operasi (1 untuk penjumlahan, 2 untuk pengurangan): "); // UI pertanyaan operasi apa yang akan digunakan
    scanf("%d", &kondisi); // memasukan kondisi

    for(int baris = 0; baris < 3; baris++){ // looping baris
        for(int kolom = 0; kolom < 3; kolom++){ // looping kolom
            if(kondisi == 1){ // jika kondisi 1 untuk penjumlahan
                printf("%d ", matrix1[baris][kolom] + matrix2[baris][kolom]); // melakukan penjumlahan matrix
            }else if(kondisi == 2){ // jika kondisi 2 untuk penhgurangan
                printf("%d ", matrix1[baris][kolom] - matrix2[baris][kolom]); // melakukan pengurangan matrix
            }else{ // kondisi ketika user salah memasukan nilai untuk menunjukan kondisi
                printf("Operasi tidak valid\n");
            }
        }
        printf("\n");
    }


    return 0;
}