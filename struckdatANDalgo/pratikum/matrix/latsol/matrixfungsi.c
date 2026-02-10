#include <stdio.h>
// program ini berisi berbagai macam menu penggunaan matrix

int main(){
    int n, m; // deklarasi baris dan kolom matrix
    char menu; // dekalrasi variabel yang digunakan untuk menyimpoan menu (dalam bentuk karakter)
    scanf("%d %d", &n, &m); // inisialisasi nilai baris dan kolom
    int matrix[n][m]; // deklarasi matrix

    // looping untuk scaning pengisian matrix
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    scanf(" %c", &menu); // scan untuk menu
    switch (menu){ // switch untuk pemilihan menu
        case 'a':{ // bagian untuk menyari nilai di elemen
            int k; // variabel yang ingin di cari
            scanf("%d", &k);
            int mark = 0; // penanda
            
            int baris = 0; // reset baris ke 0
            while(baris < n && mark == 0 ){ // loop untuk baris dan selama belum ketemu
                int kolom = 0; // reset kolom ke 0
                while(kolom < m && mark == 0){ // loop untuk kolom dan selama belum ketemu
                    if(matrix[baris][kolom] == k){ // jika sudah bertemu dengan nilai yang dicari
                        printf("baris ke-%d\n", baris);
                        printf("kolom ke-%d\n", kolom);
                        mark = 1; // tanda bahwa sudah ketemu
                    }else{
                        kolom++; // penambahann jika belum bertemu
                    }
                }
                baris++; // penambahan jika belum bertemu
            }
            if(mark = 0){ // kondisi ketika sampai akhir nilainya tidak ketemu
                printf("tidak ditemukan nilai %d di elemen matrix", k); // UI bahwa nilai tidak ditemukan di matrix
            }
            break;
        }
        case 'b':{ // bagian menambahkan matrix dengan konstanta
            int x; // konstanta yang ingin ditambahkan ke dalam matrix
            scanf("%d", &x); 
            // looping untuk penambahan nilai pada matrix
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    matrix[i][j] += x;
                }
            }
            
            // menampilkan hasil matrix
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
            break;
        }
        case 'c':{ // menampilkkan transpose dari matrix
            // menampilkan transpose matrix
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    printf("%d ", matrix[j][i]); // karena transpose penulisan i dan j (baris dan kolom) di tukar
                }
                printf("\n");
            }
            break;
        }
        case 'd':{ // menampilkan refleksi atau pencerminan
            // melakukan pencerminan
            for(int i = 0; i < n; i++) {
                for(int j = m-1; j >= 0; j--) { // barisnya tidak berunbah tetapi urutannya terbalik (refleksi)
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
            break;
        }
        case 'e':{ // membandingkan dua matrix
            int matrix_temp[n][m]; // matrix yang ingin dibandingkan
            int mark = 0; // penanda banyak elemen yang sama

            // looping untuk scanning nilai matrix yang baru
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    scanf("%d", &matrix_temp[i][j]);
                }
            }

            // looping untuk mengecek banyak nilai matrix yang sama
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(matrix_temp[i][j] == matrix[i][j]){ // pengkondisian yang mengeceknya
                        mark++; // penanda kalo ada yang sama
                    }
                }
            }
            if(mark == (n*m)){ // cek apakah nilai yang sama sebanyak nilai elemen matrix yang awal
                printf("==\n"); // tanda berhasil
            }else{ // jika tidak sama
                printf("!=\n"); // tanda gagal
            }
            
            break;
        }
    }
    return 0;
}