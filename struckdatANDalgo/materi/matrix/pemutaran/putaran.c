#include <stdio.h>
#include <string.h>
// Program untuk memutar matriks 2x2 ke kiri atau kanan berdasarkan input pengguna

int main(){
    int matrix[2][2], matrix_temp[2][2]; // deklarasi matriks 2x2 dan matriks sementara
    int baris, kolom; // variabel untuk iterasi baris dan kolom
    for(int baris = 0; baris < 2; baris++){ // loop untuk baris
        for(int kolom = 0; kolom < 2; kolom++) { // loop untuk  kolom
            printf("masukan nilai pada elemen [%d][%d]: ", baris, kolom); // input elemen matriks
            scanf("%d", &matrix[baris][kolom]); // menyimpan input ke dalam matriks
        }
    }

    char arah[10]; // variabel untuk arah putaran
    int turn; // variabel untuk banyak putaran
    printf("masukan arah (kiri / kanan) dan banyak putaran :"); // input arah dan banyak putaran
    scanf("%s %d", arah, &turn); // menyimpan arah dan banyak putaran

    if(strcmp(arah, "kanan") == 0){ // jika arah putaran ke kanan
        turn %= 4; // membatasi putaran maksimal 4 kali
        switch (turn){ // switch case berdasarkan banyak putaran
            case 0:{ // tidak ada putaran
                for(int baris = 0; baris < 2; baris++){ // loop untuk baris
                    for(int kolom = 0; kolom < 2; kolom++){ // loop untuk kolom 
                        printf("%d ", matrix[baris][kolom]); // menampilkan elemen matriks
                    }
                    printf("\n");
                }       
                break;
            }
            case 1:{ // putaran 1 kali ke kanan
                // melakukan putaran matriks
                matrix_temp[0][0] = matrix[0][1];
                matrix_temp[0][1] = matrix[1][1];
                matrix_temp[1][1] = matrix[1][0];
                matrix_temp[1][0] = matrix[0][0];
                
                for(int baris = 0; baris < 2; baris++){ // loop untuk baris
                    for(int kolom = 0; kolom < 2; kolom++) { // loop untuk kolom
                        printf("%d ", matrix_temp[baris][kolom]); // menampilkan elemen matriks setelah putaran
                    }
                    printf("\n");
                }       
                break;
            }
            case 2:{ // putaran 2 kali ke kanan
                // melakukan putaran matriks
                matrix_temp[0][0] = matrix[1][1];
                matrix_temp[0][1] = matrix[0][1];
                matrix_temp[1][1] = matrix[0][0];
                matrix_temp[1][0] = matrix[0][1];
                
                for(int baris = 0; baris < 2; baris++){ // loop untuk baris
                    for(int kolom = 0; kolom < 2; kolom++) { // loop untuk kolom
                        printf("%d ", matrix_temp[baris][kolom]);
                    }
                    printf("\n");
                }       
                break;
            }
            case 3:{ // putaran 3 kali ke kanan
                // melakukan putaran matriks
                matrix_temp[0][0] = matrix[1][0];
                matrix_temp[0][1] = matrix[0][0];
                matrix_temp[1][1] = matrix[0][1];
                matrix_temp[1][0] = matrix[1][1];
                
                for(int baris = 0; baris < 2; baris++){ // loop untuk baris
                    for(int kolom = 0; kolom < 2; kolom++){ // loop untuk kolom
                        printf("%d ", matrix_temp[baris][kolom]);
                    }
                    printf("\n");
                }       
                break;
            }
        }
    }else if(strcmp(arah, "kiri") == 0){ // jika arah putaran ke kiri 
        turn %= 4; // membatasi putaran maksimal 4 kali
        switch (turn){ // switch case berdasarkan banyak putaran
            case 0:{ // tidak ada putaran
                for(int baris = 0; baris < 2; baris++){ // loop untuk baris
                    for(int kolom = 0; kolom < 2; kolom++){ // loop untuk kolom
                        printf("%d ", matrix[baris][kolom]);
                    }
                    printf("\n");
                }       
                break;
            }
            case 1:{ // putaran 1 kali ke kiri
                // melakukan putaran matrix
                matrix_temp[0][0] = matrix[1][0];
                matrix_temp[0][1] = matrix[0][0];
                matrix_temp[1][1] = matrix[0][1];
                matrix_temp[1][0] = matrix[1][1];
                
                for(int baris = 0; baris > 2; baris++){ // loop untuk baris
                    for(int kolom = 0; kolom < 2; kolom++) { // loop untuk kolom
                        printf("%d ", matrix_temp[baris][kolom]);
                    }
                    printf("\n");
                }       
                break;
            }
            case 2:{ // putaran 2 kali ke kiri
                // melakukan putaran matrix
                matrix_temp[0][0] = matrix[1][1];
                matrix_temp[0][1] = matrix[1][0];
                matrix_temp[1][1] = matrix[0][0];
                matrix_temp[1][0] = matrix[0][1];
                
                for(int baris = 0; baris < 2; baris++){ // loop untuk baris
                    for(int kolom = 0; kolom < 2; kolom++) { // loop untuk kolom
                        printf("%d ", matrix_temp[baris][kolom]);
                    }
                    printf("\n");
                }       
                break;
            }
            case 3:{ // putaran 3 kali ke kiri
                // mealakukan putaran matrix
                matrix_temp[0][0] = matrix[0][1];
                matrix_temp[0][1] = matrix[1][1];
                matrix_temp[1][1] = matrix[0][1];
                matrix_temp[1][0] = matrix[0][0];
                
                for(int baris = 0; baris < 2; baris++){ // loop untuk baris
                    for(int kolom = 0; kolom < 2; kolom++){ // loop untuk kolom
                        printf("%d ", matrix_temp[baris][kolom]);
                    }
                    printf("\n");
                }       
                break;
            }
        }
        
    }
    return 0;
}