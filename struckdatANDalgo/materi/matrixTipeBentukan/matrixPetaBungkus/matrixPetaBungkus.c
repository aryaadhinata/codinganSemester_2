#include <stdio.h>
#include <string.h>

typedef struct{
    int harga[16];
    char nama[16][16];
}menu;

// program ini membuat peta dalam bentuk model 3 dimensi
int main() {
    // variabel n & m berfungsi untuk menyimpan nilai baris dan kolom untuk matrix yang akan di deklarasikan
    int n, m;
    scanf("%d %d", &n, &m);
    
    // deklarasi matrix tiga dimensi dengan n dam m sebagai baris dan max char di 16 
    menu warung [n][m][17];

    // inisiasi nilai awal dengan "-" untuk menghindari kesalahan saat print
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            strcpy(warung[i][j], "-"); 
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
        // input untuk menandai kordinat warung di peta
        printf("\nmasukan kordinat warung :");
        scanf("%d %d", &x, &y);
        
        // agar nilai yang di input sesuai dengan dimensi dari matrixnya
        while ((x >= n) || (y >= m)){
            printf("\nnilai x, y masih salah coba input ulang :");
            scanf("%d %d", &x, &y);
        }
        
        // memasukan nama warung
        printf("\nmasukan nama warung (max 16 char) :");
        scanf("%s", warung[x][y]);
        int charnam = 0;
        do
        {
            scanf("%s")
            charnam++;
        } while ((charnam < 16) || );
        

        // menanyakan apakah sudah diisi semua atau tidak
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

    // deklarasi maxLen untuk menyimpan nilai terpanjang sepanjang warung
    int maxLen = 0;
    // penyesuaian panjang nama warung yang terpanjang
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maxLen < strlen(warung[i][j])){
                maxLen = strlen(warung[i][j]);
            }
        }
    }
    
    // looping untuk menampilkan hasil peta ke layar
    printf("\nPeta warung :\n");
    for(int i = 0; i < n; i++) {
        // garis horizontal untuk memisahkan masing masing baris
        for(int j = 0; j < (maxLen+2) *m; j++) {
            printf("-");
        }
        printf("\n");

        // looping untuk print isi elemen
        for(int j = 0; j < m; j++) {
            // jika menemukan "-" makan ubah jadi spasi
            if(strcmp(warung[i][j], "-") == 0){
                printf("|");
                for(int k = 0; k < maxLen; k++){
                    printf(" ");
                }
                printf("|");
            
            // kondisi sesungguhnya
            }else{
                // kondisi ketika ada selisih space dengan maxLen
                if(strlen(warung[i][j]) < maxLen){
                    // deklarasi variabel space untuk menghitung selisih dari maxLen dengan
                    // warung[i][j] yang sekarang, digunakan untuk menyamakan panjang agar rapi
                    int space = 0;
                    space = maxLen - strlen(warung[i][j]);

                    printf("|");
                    // (space + 1)/ 2 digunakan untuk membagi selisih jadi dua dan menampilkan setengahnya di bagian depan
                    // dan jika ganjil tetap di print
                    for(int k = 0; k < (space+1) /2; k++) {
                        printf(" ");
                    }

                    printf("%s", warung[i][j]);
                    
                    // menampilkan setengah lainnya
                    for(int k = 0; k < space /2; k++) {
                        printf(" ");
                    }
                    printf("|");
                
                // jika warung[i][j] yang sekarang adalah yang terpanjang
                }else{
                    printf("|%s|", warung[i][j]);
                }
            }
        }
        printf("\n");
    }

    // menampilak garis horizontal terakhir sebagai pembatas
    for(int j = 0; j < (maxLen+2) *m; j++) {
        printf("-");
    }

    
    printf("\n");
    
    return 0;
}