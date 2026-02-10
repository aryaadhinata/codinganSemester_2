#include <stdio.h>
#include <string.h>
// program mengubah urutan dalam matrix yang telah ditentukan 

typedef struct{ // tipe bentukan untuk menyimpan bagian yang atribut data matrix
    char nama[17], att, kelamin;
}data;

int main(){
    int n, m; // deklarasi bagian baris dan kolom (n & m)
    scanf("%d %d", &n, &m); // inisialisasi niali kolom dan baris
    data matrix[n][m], temp; // deklarasi tipe bentukan matrix dan array bentukan sementara

    // loop untuk mengisis data dalam matrix
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < m; j++) {
            scanf("%s %c %c", matrix[i][j].nama, &matrix[i][j].att, &matrix[i][j].kelamin);
        }
    }
    
    char pindah1[17], pindah2[17]; // menyimpan nama yang ingin dipindahkan
    scanf("%s %s", pindah1, pindah2); // inisialisasi nama yang ingin pindah

    printf("Data sebelum Pindah :\n");
    printf("============================\n");
    int p1 = 0, q1 = 0, p2 = 0, q2 = 0; // menyimpan indeks orang yang akan pindah
    for(int i = 0; i < n; i++){
        printf("lantai : %d\n", i+1);
        for(int j = 0; j < m; j++){
            switch (matrix[i][j].att){ // kondisi unutk jenis attack
                case 'W':{
                    printf("%d. %s -> White (%c)\n", j+1, matrix[i][j].nama, matrix[i][j].kelamin);
                    break;
                }
                case 'R':{
                    printf("%d. %s -> Red (%c)\n", j+1, matrix[i][j].nama, matrix[i][j].kelamin);
                    break;
                }
                case 'B':{
                    printf("%d. %s -> Black (%c)\n", j+1, matrix[i][j].nama, matrix[i][j].kelamin);
                    break;
                }
                case 'P':{
                    printf("%d. %s -> Pale (%c)\n", j+1, matrix[i][j].nama, matrix[i][j].kelamin);
                    break;
                }
            }
            if(strcmp(matrix[i][j].nama, pindah1) == 0){ // menyimpan nilai indeks dari nama pertama yang ingin dipindahkan
                p1 = i;
                q1 = j;
            }
            if(strcmp(matrix[i][j].nama, pindah2) == 0){ // menyimpan nilai indeks dari nama kedu yang ingin dipindahkan
                p2 = i;
                q2 = j;
            }
        }
        printf("-----------------\n");
    }
    
    // menukarkan nilai pada matrix yang sudah diketahui datanya
    temp = matrix[p1][q1];
    matrix[p1][q1] = matrix[p2][q2];
    matrix[p2][q2] = temp;
    
    // print data yang sudah dipindahkan
    printf("\nData setelah Pindah :\n");
    printf("============================\n");
    for(int i = 0; i < n; i++){
        printf("lantai : %d\n", i+1);
        for(int j = 0; j < m; j++){
            switch (matrix[i][j].att){ // kondisi untuk jenis attack
                case 'W':{
                    printf("%d. %s -> White (%c)\n", j+1, matrix[i][j].nama, matrix[i][j].kelamin);
                    break;
                }
                case 'R':{
                    printf("%d. %s -> Red (%c)\n", j+1, matrix[i][j].nama, matrix[i][j].kelamin);
                    break;
                }
                case 'B':{
                    printf("%d. %s -> Black (%c)\n", j+1, matrix[i][j].nama, matrix[i][j].kelamin);
                    break;
                }
                case 'P':{
                    printf("%d. %s -> Pale (%c)\n", j+1, matrix[i][j].nama, matrix[i][j].kelamin);
                    break;
                }
            }
        }
        printf("-----------------\n");
    }
    return 0;
}