#include "headORHS26.h"
/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Pratikum 1 dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int matrix[n][m];
    char arah;
    scanf(" %c", &arah);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    cekBomPutarPrint(n, m, matrix, arah);
    
    return 0;
}