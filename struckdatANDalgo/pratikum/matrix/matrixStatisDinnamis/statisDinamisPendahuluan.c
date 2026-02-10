#include <stdio.h>
// program ini berisis pendahuluan matrix dalam pratikum

int main(){
    // matrix statis dan inisialisai
    int matrix_statis[7][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {3, 1, 1},
        {1, 1, 5},
        {1, 7, 8},
        {9, 0, 1}
    };

    
    // matrix dinamis
    int n, m;
    scanf("%d %d", &n, &m);
    int matrix_dinamis[n][m];
    
    // inisialisasi dinamis
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("Masukkan nilai matriks[%d][%d]: ", i, j);
            scanf("%d", &matrix_dinamis[i][j]);
        }
    }
    
    // akses nilai elemen matrix
    for (int i = 0; i < 3; i++) {
        printf("Kolom %d: ", i+1);
    }
    printf("\n");


    for(int i = 0; i < 7; i++) {
        printf("---------------------------\n");
        for(int j = 0; j < 3; j++) {
            printf("|   %d   |", matrix_statis[i][j]); // ini bagian yang bisa diganti
        }
        printf(" baris ke-%d\n", i+1);
    }
    printf("---------------------------\n");

    // akses ideks matrix
    for (int i = 0; i < 3; i++) {
        printf("        %d        ", i);
    }
    printf("\n");
    for (int i = 0; i < 7; i++) {
        printf("---------------------------------------------------\n");
        for (int j = 0; j < 3; j++) {
            printf("| matriks[%d][%d] |", i, j);
        }
        printf(" %d\n", i);
    }
    printf("---------------------------------------------------\n");
    
    return 0;
}