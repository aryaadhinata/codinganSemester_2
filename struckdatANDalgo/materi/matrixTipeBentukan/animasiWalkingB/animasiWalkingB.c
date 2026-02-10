#include <stdio.h>
#include <time.h> // library yang digunakan untuk mengelola waktu
#include <stdlib.h>

// program ini menapilkan animasi karakter 'B' yang bergerak secara diagonal dalam matrix 6x6

// prosedur untuk menunggu waktu agar ada jeda tampilan di layar
void wait(float x){
    time_t start; // waktu ketika dimulai 
    time_t curent; // waktu sekarang
    time(&start); // memulai waktu
    
    do{
        // cek waktu dan malukan selama selisih curent dengan start belum lebih dari x
        time(&curent);
    } while(difftime(curent,start) < x);
}

int main() {
    // dekalarasi 
    // *    nilai matrix 6x6 dengan nama arr
    // *    i & j berperan sebagai counter iterator
    // *    default kordinat x,y di (-1,-1) dalam matrix arr
    // *    default kodisi jalan 1 yang digunakan untuk menunjukan arah gerakan entah naik atau turun
    char arr[6][6];
    int i, j, x = -1, y = -1, jalan = 1;

    // looping untuk mengisi nilai default di setiap elemen dalam matrix dengan '-'
    for(i = 0; i < 6; i++) {
        for(j = 0; j < 6; j++) {
            arr[i][j] = '-';
        }
    }

    // looping forever
    while(1){
        system("cls"); // membersihkan layar
        // looping untuk mengisi nilai default di setiap elemen dalam matrix dengan '-' 
        // untuk yang ada 'B' sebelumnya
        if((x >= 0) && (x < 6)){
            arr[x][y] = '-';
        }

        // kondisi untuk penggambaran char 'B'
        if((x == 6) && (y == 6)){
            // border paling bawah sebagai penanda agar bergerak ke atas
            jalan = -1;
            x = x -1;
            y = y -1;
        }else if((x == -1) && (y == -1)){
            // border paling atas sebagai penanda agar bergerak ke bawah
            jalan = 1;
            x = x +1;
            y = y +1;
        }else if(jalan == 1){
            // jika sedang berjalan ke bawah
            x = x +1;
            y = y +1;
        }else{
            // jika sedang berjalan ke atas
            x = x -1;
            y = y -1;
        }

        // menulisakan 'B' nilai pada elemen 
        if((x >= 0) && (x < 6)){
            arr[x][y] = 'B';
        }

        // menampilkan ke terminal
        for(i = 0; i < 6; i++) {
            for(j = 0; j < 6; j++) {
                if(arr[i][j] == '-'){
                    printf("   ");
                }else{
                    printf(" %c ", arr[i][j]);
                }
            }
            printf("\n");
        }
        // delay
        wait(1);
    }
    return 0;
}