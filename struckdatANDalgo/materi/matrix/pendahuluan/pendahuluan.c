#include <stdio.h>
// kode pendahuluan yang memuat tamplate dasar dari matrix

int main(){
    int matrix[3][3]; // deklarasi matrix dengan ordo 3×3
    int baris, kolom; // deklarasi ordo dalam bentuk baris dan kolom
    for(int baris = 0; baris < 3; baris++){ // loop baris
        for(int kolom = 0; kolom < 3; kolom++){ // loop kolom
            printf("Masukkan elemen matrix[%d][%d]: ", baris+1, kolom+1); // UI meminta pengisian untuk elemen matrix
            scanf("%d", &matrix[baris][kolom]); // mengisi elemen matrix
            printf("\n");
        }
    }
    
    for(int baris = 0; baris < 3; baris++){ // loop baris
        for(int kolom = 0; kolom < 3; kolom++){ // loop kolom
            printf("%d ", matrix[baris][kolom]); // mencetak UI matrix
        }
        printf("\n");
    }


    return 0;
}