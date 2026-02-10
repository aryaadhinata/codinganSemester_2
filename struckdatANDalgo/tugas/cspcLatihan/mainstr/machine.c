#include "head.h"

int cekA(int n, char str[]){ // fungsi untuk menhitung banyak a di setiap array (kata)
    int hasil = 0; // set nilai hasil
    for(int i = 0; i < (strlen(str)); i++) { // loop sepanjanh kata
        if(str[i] == 'a'){ // kondisi ketika ada karakter a
            hasil++;
        }
    }
    return hasil; // mengembalikan nilai hasil yang sudah ditemukan
}

void selec(int n, char str[n][101], int str_int[]){ // sorting selection
    int i, j, minIndeks, tempa; // deklarasi untuk manipulasi indeks
    char temp[101];
	for(i = 0; i < n ; i++) {
		// inisialisasi indeks elemen minimum
		minIndeks = i;
		//perulangan mencari nilai minimum sepanjang indeks i + 1 sampai jumlah elemen array
		for(j = (i + 1); j < n; j++){
			if(str_int[minIndeks] > str_int[j]){ // ketika ada yang lebih kecil lagi
				minIndeks = j;
				}
			}
		// menukar posisi elemen
        strcpy(temp, str[i]);
		strcpy(str[i], str[minIndeks]);
		strcpy(str[minIndeks], temp);
        // menukar posisi a
        tempa = str_int[i];
		str_int[i] = str_int[minIndeks];
		str_int[minIndeks] = tempa;
	}
	
	for(int a = 0; a < n; a++){ // loop untuk menampilkan hasilnya
		printf("%s\n", str[a]);
	}
}