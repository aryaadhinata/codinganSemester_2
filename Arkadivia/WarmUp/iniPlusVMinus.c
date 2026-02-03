#include <stdio.h>
/*
Deskripsi
Di papan tulis, terdapat N buah angka 1 yang berjejeran. Tugas Anda adalah memberikan tanda plus (+)
atau minus (-) dan harus diberikan di antara setiap dua angka 1 yang bersebelahan. Setelah memberikan
tanda, hitung hasil ekspresi matematika yang terbentuk.
Pertanyaannya adalah: Apakah mungkin untuk mencapai nilai K setelah memberikan tanda-tanda
tersebut?

Format Masukan
Baris pertama berisi dua bilangan bulat:
• N (2≤N ≤106), yang menyatakan jumlah angka 1 di papan tulis.
• K (−109 ≤K ≤109), yang menyatakan nilai target yang ingin dicapai.

Format Keluaran
Cetak ”YES” jika mungkin mencapai nilai K dengan memberikan tanda + atau- di antara setiap dua angka
1. Jika tidak, cetak ”NO”.
*/

int main(){
    int awal, tujuan; // deklarsi nilai awal dan tujuan
    scanf("%d %d", &awal, &tujuan); // memasukan nilai awal dan tujuan

    // kondisi untuk menentukan apakah bisa mencapai tujuan atau tidak
    if(((awal >= tujuan) && (awal >= 2)) && (((awal % 2 == 0) && (tujuan % 2 == 0)) || ((awal % 2 != 0) && (tujuan % 2 != 0)))){ // jika awal lebih dari sama dengan tujuan dan awal lebih dari sama dengan 2 serta kedua nilai memiliki parity yang sama
        if(tujuan >= 0){ // jika tujuan lebih dari sama dengan nol
            printf("YES\n");
        }else{ // jika tujuan kurang dari nol
            if(tujuan >= (awal * -1)+2){ // jika tujuan lebih dari sama dengan (awal * -1)+2
                printf("Yes\n");
            }else{ // jika tujuan kurang dari (awal * -1)+2
                printf("NO\n"); 
            }
        }
    }else{ // jika tidak memenuhi kondisi di atas
        printf("NO\n");
    }

    return 0;
}