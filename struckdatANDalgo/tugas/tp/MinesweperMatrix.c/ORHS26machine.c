#include "headORHS26.h"

// prosedur untuk mengecek dan mengubah arah serta menampilkannya
void cekBomPutarPrint(int n, int m, int matrix[n][m], char arah){
    // loop untuk memberitahu area sekitar -1 untuk ditambahkan +1
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == -1){ // jika menemukan -1
                // cek sekeliling apakah tidak ada -1 lain dan masih berada dalam ukuran matrix
                if((matrix[i-1][j-1] != -1) && ((i-1 >= 0) && (j-1 >= 0))){
                    matrix[i-1][j-1] += 1;
                }
                if((matrix[i-1][j] != -1) && (i-1 >= 0)){
                    matrix[i-1][j] += 1;    
                }
                if((matrix[i-1][j+1] != -1) && ((i-1 >= 0) && (j+1 < m))){
                    matrix[i-1][j+1] += 1;
                }
                if((matrix[i][j-1] != -1) && (j-1 >= 0)){
                    matrix[i][j-1] += 1;                   
                }
                if((matrix[i][j+1] != -1) && (j+1 < m)){
                    matrix[i][j+1] += 1;                   
                }
                if((matrix[i+1][j-1] != -1) && ((i+1 < n) && (j-1 >= 0))){              
                    matrix[i+1][j-1] += 1;
                }
                if((matrix[i+1][j] != -1) && (i+1 < n)){
                    matrix[i+1][j] += 1;                           
                }
                if((matrix[i+1][j+1] != -1) && ((i+1 < n) && (j+1 < m))){
                    matrix[i+1][j+1] += 1;        
                }
            }
        }
    }
    
    int maxv = 1; // nilai max jumlah digit
    // loop maxv digunakan agar nanti spacenya bisa disamakan
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] < 0){ // jika nilainya di bawah 0 maka ubah dulu jadi positif dan +1 untuk simbol minus
                if(((matrix[i][j]* -1 /10) +1) > maxv){
                    maxv = (matrix[i][j] * -1)/10 +1;
                }
            }else{
                if(matrix[i][j]/10 > maxv){
                    maxv = matrix[i][j]/10;
                }
            }
        }
    }

    printf("Peta Zona Aman:\n");
    int space;
    switch (arah){ // case untuk arah yang diinginkan
        case 'U':{ // case ketika menghadap utara
            for(int i = 0; i < n; i++) {
                printf("| ");
                for(int j = 0; j < m; j++) {
                    // menyamakan jarak space
                    if(matrix[i][j] < 0){ // kondisi di bawah 0
                        if(maxv > ((matrix[i][j]*-1) /10 +1)){ // ubah ke positif, +1 untuk simbol -
                            space = maxv - (matrix[i][j]/10 +1);
                            for(int k = 0; k < space; k++) {
                                printf(" ");
                            }
                        }
                    }else{
                        if(maxv > (matrix[i][j]/10)){ // kondisi lebih dari 0
                            space = maxv - (matrix[i][j]/10);
                            for(int k = 0; k < space; k++) {
                                printf(" ");
                            }
                        }
                    }
                    printf("%d ", matrix[i][j]);
                }
                printf("|");
                printf("\n");
            }
            break;
        }
        case 'S':{ // arah ke selatan
            for(int i = n-1; i >= 0; i--) {
                printf("| ");
                for(int j = m-1; j >= 0; j--) {
                    // menyamakan jarak spasi
                    if(matrix[i][j] < 0){ // kondisi di bawah 0
                        if(maxv > ((matrix[i][j]*-1) /10 +1)){ // ubah ke positif, +1 untuk simbol -
                            space = maxv - (matrix[i][j]/10 +1);
                            for(int k = 0; k < space; k++) {
                                printf(" ");
                            }
                        }
                    }else{
                        if(maxv > (matrix[i][j]/10)){ // kondisi lebih dari 0
                            space = maxv - (matrix[i][j]/10);
                            for(int k = 0; k < space; k++) {
                                printf(" ");
                            }
                        }
                    }
                    printf("%d ", matrix[i][j]); 
                }
                printf("|");
                printf("\n");
            }
            break;
        }
        case 'T':{ // arah ke timur
            for(int i = 0; i < m; i++) {
                printf("| ");
                for(int j = n-1; j >= 0 ; j--) {
                    // menyamakan jarak spasi
                    if(matrix[j][i] < 0){ // kondisi di bawah 0
                        if(maxv > ((matrix[j][i]*-1) /10 +1)){ // ubah ke positif, +1 untuk simbol -
                            space = maxv - (matrix[j][i]/10 +1);
                            for(int k = 0; k < space; k++) {
                                printf(" ");
                            }
                        }
                    }else{
                        if(maxv > (matrix[j][i]/10)){ // kondisi lebih dari 0
                            space = maxv - (matrix[j][i]/10);
                            for(int k = 0; k < space; k++) {
                                printf(" ");
                            }
                        }
                    }
                    printf("%d ", matrix[j][i]); 
                }
                printf("|");
                printf("\n");
            }
            break;
        }
        case 'B':{ // arah ke barat
            for(int i = m-1; i >= 0; i--) {
                printf("| ");
                for(int j = 0; j < n ; j++) {
                    // menyamakan jarak spasi
                    if(matrix[j][i] < 0){ // kondisi di bawah 0
                        if(maxv > ((matrix[j][i]*-1) /10 +1)){ // ubah ke positif, +1 untuk simbol -
                            space = maxv - (matrix[j][i]/10 +1);
                            for(int k = 0; k < space; k++) {
                                printf(" ");
                            }
                        }
                    }else{
                        if(maxv > (matrix[j][i]/10)){ // kondisi lebih dari 0
                            space = maxv - (matrix[j][i]/10);
                            for(int k = 0; k < space; k++) {
                                printf(" ");
                            }
                        }
                    }
                    printf("%d ", matrix[j][i]); 
                }
                printf("|");
                printf("\n");
            }
            break;
        }
    }
}