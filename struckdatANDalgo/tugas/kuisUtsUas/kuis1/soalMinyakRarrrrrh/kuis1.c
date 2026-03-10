#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan kuis 1 dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    kordinatAtr matrix[n][m];
    for(int i = 0; i < n; i++){
        for( int j = 0; j < m; j++){
            matrix[i][j].potBar = 0;
            strcpy(matrix[i][j].kodTem, "0");
            strcpy(matrix[i][j].stat, "kosong");
            matrix[i][j].mark = 0;
        }
    }

    int x, y, datWal, datUb;
    scanf("%d", &datWal);
    for(int i = 0; i < datWal; i++){
        scanf("%d %d", &x, &y);
        scanf("%d %s %s", &matrix[x][y].potBar, matrix[x][y].kodTem, matrix[x][y].stat);
    }
    
    scanf("%d", &datUb);
    for(int i = 0; i < datUb; i++){
        scanf("%d %d", &x, &y);
        scanf("%d %s %s", &matrix[x][y].potBarN, matrix[x][y].kodTemN, matrix[x][y].statN);
        matrix[x][y].mark = 1; 
    }

    printf("kesimpulan data pengeboran minyak:\n\n");
    printf("potensi tempat dibor: %d\n", cekTemBor(n, m, matrix));
    printf("potensi barrel: %d\n", cekPotBar(n, m, matrix));

    printf("\ntidak berpotensi dibor: %d\n", cekUnBor(n, m, matrix));
    printf("potensi barrel hilang: %d\n", cekPotBarHil(n, m, matrix));
    return 0;
}