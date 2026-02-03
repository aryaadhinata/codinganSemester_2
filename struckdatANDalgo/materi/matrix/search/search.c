#include <stdio.h>
// kode untuk mencari nilai di elemen matrix

int main(){
    int matrix[3][3]; // deklarasi matrix dengan ordo 3×3
    int baris, kolom; // deklarasi ordo matrix dalam bentuk baris dan kolom
    for(int baris = 0; baris < 3; baris++) { // loop untuk baris 
        for(int kolom = 0; kolom < 3; kolom++) { // loop untuk kolom
            printf("Masukkan elemen matrix[%d][%d]: ", baris+1, kolom+1); // UI untuk memasukan nilai ke elemen matrix
            scanf("%d", &matrix[baris][kolom]); // memasukan nilai ke elemen matrix
        }
    }
    
    int victim; // deklarasi nilai yang inigin di cari
    printf("\nmasukan nilai elemen yang di cari :"); // UI untuk memasukan nilai yang ingin dicari
    scanf("%d", &victim); // memasukan nilai yang ingin dicari
    printf("\n");

    int mark = 0; // penanda untuk menunjukan nilai yang di cari sudah ketemu atau belum
    baris = 0; // reset baris ke 0
    while(baris < 3 && mark == 0 ){ // loop untuk baris dan selama belum ketemu
        kolom = 0; // reset kolom ke 0
        while(kolom < 3 && mark == 0){ // loop untuk kolom dan selama belum ketemu
            if(matrix[baris][kolom] == victim){ // jika sudah bertemu dengan nilai yang dicari
                printf("nilai di temukan di elemen [%d][%d]\n", baris+1, kolom+1); // UI bahwa nilai sudah ditemukan di elemen tersebut 
                mark = 1; // tanda bahwa sudah ketemu
            }else{
                kolom++; // penambahann jika belum bertemu
            }
        }
        baris++; // penambahan jika belum bertemu
    }
    if(mark = 0){ // kondisi ketika sampai akhir nilainya tidak ketemu
        printf("tidak ditemukan nilai %d di elemen matrix", victim); // UI bahwa nilai tidak ditemukan di matrix
    }

    return 0;
}