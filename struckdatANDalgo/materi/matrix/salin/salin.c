#include <stdio.h>
// kode penalinan matrix

int main(){
    int matrix1[3][3]; // deklarasi mattrix awal dengan ordo 3×3
    int matrix2[3][3]; // deklarasi matrrix yang akan menyalin 3×3
    int baris, kolom; // drklarasi baris kolom untuk membentuk ordo
    for(int baris = 0; baris < 3; baris++){ // looping baris
        for(int kolom = 0; kolom < 3; kolom++){ // looping kolom
            printf("Masukkan elemen matrix[%d][%d]: ", baris+1, kolom+1); // UI untuk meminta isi nilai pada elemen matrix
            scanf("%d", &matrix1[baris][kolom]); // mengisi elemen matrix
        }
    }

    printf("memindahkan matrix\n"); // mencetak penanda bahwa matrix akan di salin / dipindahkan
    
    // tahap seperti ini juga disebut sebagai scaning
    for(int baris = 0; baris < 3; baris++){ // looping baris penyalinan
        for(int kolom = 0; kolom < 3; kolom++){ // looping baris kolom
            matrix2[baris][kolom] = matrix1[baris][kolom]; // melakukan penyalinan
        }
    }

    printf("hasil pemindahan matrix:\n"); // menunjukan hasil penyalinan / pemindahan

    // looping untuk mencetak matrix yang sudah di salin
    for(int baris = 0; baris < 3; baris++){ // loop baris
        for(int kolom = 0; kolom < 3; kolom++){ // loop kolom
            printf("%d ", matrix2[baris][kolom]); // mencetk nilai masing masing elemen
        }
        printf("\n");
    }


    return 0;
}