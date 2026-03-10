#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan kuis 1 dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

int cekTemBor(int n, int m, kordinatAtr matrix[n][m]){
    int hasil = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j].mark == 1){
                if(strcmp(matrix[i][j].statN, "memenuhi") == 0){
                    hasil++;
                }
            }else{
                if(strcmp(matrix[i][j].stat, "memenuhi") == 0){
                    hasil++;
                }
            }
        }
    }
    
    return hasil;
}

int cekPotBar(int n, int m, kordinatAtr matrix[n][m]){
    int hasil = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j].mark == 1){
                if(strcmp(matrix[i][j].statN, "memenuhi") == 0){
                hasil += matrix[i][j].potBarN;
            }
            }else{
                if(strcmp(matrix[i][j].stat, "memenuhi") == 0){
                    hasil += matrix[i][j].potBar;
                }
            }
        }
    }
    
    return hasil;
}

int cekUnBor(int n, int m, kordinatAtr matrix[n][m]){
    int hasil = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j].mark == 1){
                if(strcmp(matrix[i][j].statN, "tidak") == 0){
                hasil++;
                }
            }else{
                if(strcmp(matrix[i][j].stat, "tidak") == 0){
                hasil++;
                }
            }
        }
    }
    
    return hasil;
}

int cekPotBarHil(int n, int m, kordinatAtr matrix[n][m]){
    int hasil = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j].mark == 1){
                if(strcmp(matrix[i][j].statN, "tidak") == 0){
                hasil += matrix[i][j].potBarN;
            }
            }else{
                if(strcmp(matrix[i][j].stat, "tidak") == 0){
                    hasil += matrix[i][j].potBar;
                }
            }
        }
    }
    
    return hasil;
}