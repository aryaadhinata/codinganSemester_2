#include "head.h"
// ada n masukan string yang tidak terurut. Masukkan ke dalam list tunggal dinamis secara terurut 
// berdasarkan banyaknya huruf a (semua huruf kecil) dari jumlah a terkecil sampai jumlah a terbesar

int main() {
    int banyak; // banyak kata yang ada
    scanf("%d", &banyak);
    char str[banyak][101]; // array of string max karakter per kata 100
    for(int i = 0; i < banyak; i++){ // loop untuk mengisi nilai
        scanf("%s", str[i]);
    }

    int str_inte[banyak]; // array of integer untuk menyimpan banyak charakter a
    for(int i = 0; i < banyak; i++){ // loop untuk menghitung a di setiap kata
        str_inte[i] = cekA(i, str[i]); // fungsi menghitung banyak a
    }
    selec(banyak, str, str_inte); // sorting dan tempat menampilkan hasil

    return 0;
}