#include <stdio.h>

// program yang menunjukan salah saatu bentuk pengaplikasian matrix yaitu
// pembuatan gambar yang terdiri dari red, green dan blue

// tipe bentukan yang digunakan untuk menyimpan nilai warna pada piksel
// red, green dan blue
typedef struct{
    int red, green, blue;
}piksel;

int main() {
    // deklarasi dimensi matrix dan meminta nilai untuk dimensi matrix dalam bentuk baris dan kolom
    int baris, kolom;
    printf("masukan banyak baris\n");
    scanf("%d", &baris);
    printf("masukan banyak kolom\n");
    scanf("%d", &kolom);

    // deklarasi matrix tipe bentukan dengan dimensi baris x kolom dan juga 
    // variabel b & k sebagai iterator
    piksel arr[baris][kolom];
    int b, k;

    // bagian yang penting untuk matrix tipe bentukan selalu set nilai default atau
    // bagian inisialisasi awal
    for(b = 0; b < baris; b++) {
        for(k = 0; k < kolom; k++) {
            arr[b][k].red = 255;
            arr[b][k].green = 255;
            arr[b][k].blue = 255;
        }
    }
    
    // perubahan nilai untuk indeks 0,1 (sebagai contoh mudah)
    arr[0][1].red = 0;
    arr[0][1].green = 255;
    arr[0][1].blue = 0;

    // looping menampilkan nilai untuk setiap elemen (bukan warna sesungguhnya (hanya nama warna) agar lebih mudah)
    for(int b = 0; b < baris; b++) {
        for(int k = 0; k < kolom; k++) {
            // kondisi yang dibutuhkan agar bisa disebut putih
            if((arr[b][k].red == 255) && (arr[b][k].green == 255) && (arr[b][k].blue == 255)){
                printf(" putih ");
            }
            // kondisi yang dibutuhkan agar bisa disebut hijau
            else if((arr[b][k].red == 0) && (arr[b][k].green == 255) && (arr[b][k].blue == 0)){
                printf(" hijau ");
            }
        }
        printf("\n");
    }
    return 0;
}