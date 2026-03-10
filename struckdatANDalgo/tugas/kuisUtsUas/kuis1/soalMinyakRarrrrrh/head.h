#include <stdio.h>
#include <string.h>

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan kuis 1 dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

typedef struct{
    int potBar, potBarN, mark;
    char kodTem[5], kodTemN[5], stat[17], statN[17];
}kordinatAtr;

int cekTemBor(int n, int m, kordinatAtr matrix[n][m]);
int cekPotBar(int n, int m, kordinatAtr matrix[n][m]);
int cekUnBor(int n, int m, kordinatAtr matrix[n][m]);
int cekPotBarHil(int n, int m, kordinatAtr matrix[n][m]);