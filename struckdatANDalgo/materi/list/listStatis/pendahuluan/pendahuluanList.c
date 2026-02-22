#include <stdio.h>
#include <string.h>
// program ini mebuat list statis dalam bentuk array dan juga beberapa cara yang bisa dilakukan untuk mengakses list


// contoh struct untuk isi list dalam bentuk nilai nim, nama dan nilai
typedef struct{
    char nim[10];
    char nama[50];
    char nilai[2];
}nilaiMatKul;

// contoh cara menyiapkan kontainer yang berisi list
typedef struct{
    nilaiMatKul kontainer;
    int next;
}elemen;

// pointer dan juga jumlah data
typedef struct{
    int first;
    elemen data[10];
}list;

// membuat bentuk list yang ada
void createList(list *L){
    (*L).first = -1;
    int i;

    for(i=0;i<10;i++){
        /*proses menginisialisasi isi array*/
        (*L).data[i].next = -2;
    }
}

int countElement(list L){
    int hasil = 0;
    if(L.first != -1){// cek apakah list pertama kosong atau tidak
        int hitung;

        // inisiasi nilai hitung dengan head terlebih dahulu
        hitung = L.first;

        while(hitung != -1){ // ketika melakukan while dan listnya tidak kosong
            // penambahan tanda jika listnya tidak kosong
            hasil = hasil + 1;

            // melaukan iterasi dengan mengubah nilai hitung yang sekarang dengan
            // nilai list next
            hitung = L.data[hitung].next;
        }
    }

    // mengembalikan nilai hasil penambahan
    return hasil;
}

int main(){
    list L;
    createList(&L);

    return 0;
}
