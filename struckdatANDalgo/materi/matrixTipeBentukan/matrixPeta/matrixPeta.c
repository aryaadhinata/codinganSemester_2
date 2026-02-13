#include <stdio.h>
#include <string.h>

// program ini membuat peta dalam bentuk model 3 dimensi
int main() {
    // variabel n & m berfungsi untuk menyimpan nilai baris dan kolom untuk matrix yang akan di deklarasikan
    int n, m;
    scanf("%d %d", &n, &m);
    
    // deklarasi matrix tiga dimensi dengan n dam m sebagai baris dan max char di 16 
    char warung [n][m][17];

    // inisiasi nilai awal dengan spasi untuk menghindari kesalahan saat print
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // masih perlu di optimalisasi di bagian print agar lebih rapih dan terlihat dengan jelas
            strcpy(warung[i][j], "|   |"); 
        }
    }
    
    // deklarasi variabel variabel yang digunakan di dalam loop do while
    // * cn     : counting agar tidak melebihi baris matrix yang tersedia
    // * cm     : counting agar tidak melebihi kolom matrix yang tersedia
    // * flag   : tanda bahwa user ingin keluar dari loop
    // * x      : menyimpan kordinat baris dari user di peta
    // * y      : menyimpan kordinat kolom dari user di peta
    // * keadnn : karakter yang perlu di input agar looping selesai
    int cn = 0, cm = 0, flag = 1, x, y;
    char keadnn;
    do{
        printf("\nmasukan kordinat warung :");
        scanf("%d %d", &x, &y);

        printf("\nmasukan nama warung (max 16 char) :");
        scanf("%s", warung[x][y]);

        printf("\nSudah mengisi semua (s)?");
        scanf(" %c", &keadnn);
        
        // selama keadaan belum terpenuhi flag tetap di nilai awal
        if(keadnn == 's'){
            flag = 0;
        }

        cm++; // menambahkan nilai kolom setiap iterasi
        if(cm == m){ // jika kolom sudah maks maka reset kembali dan tambahkan nilai baris
            cn++;
            cm = 0;
        }
    }while((cn < n) && (flag == 1));

    // looping untuk menampilkan hasil peta ke layar
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf(" %s", warung[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}