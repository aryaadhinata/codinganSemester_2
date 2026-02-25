#include <stdio.h>
// program ini mengecek apakah saya sudah paham materi tentang list atau belum, dengan cara modifikasi soal. datanya berubah
// menjadi float dan bentuk listnya berbeda dengan pendahuluan.

// elemen elemen yang ada dalam list
typedef struct{
    float dec;
    int next;
}elemen;

// jumlah listnya dan juga pointer headnya
typedef struct{
    int first;
    elemen data[100];
} list;

// membuat listnya
void createList(list *des, int n){
    (*des).first = -1; // buat head langsung ke null

    for(int i = 0; i < n; i++){
        // proses untuk membuat tanda semua elemen dalam list bahwa belum diisi
        (*des).data[i].next = -2;
    }
}

// menghitung elemen yang tidak kosong dan mengembalikannya untuk diproses berikutnya
int countElement(list des){
    int hasil = 0;
    if(des.first != -1){// cek apakah list pertama kosong atau tidak
        int hitung;

        // inisiasi nilai hitung dengan head terlebih dahulu
        hitung = des.first;

        while(hitung != -1){ // ketika melakukan while dan listnya belum habis
            // penambahan tanda jika listnya tidak kosong
            hasil = hasil + 1;

            // melaukan iterasi dengan mengubah nilai hitung yang sekarang dengan
            // nilai list next
            hitung = des.data[hitung].next;
        }
    }

    // mengembalikan nilai hasil penambahan
    return hasil;
}

// mencari bagian list yang masih belum diisi oleh nilai
int emptyElement(list des){
    int hasil = -1; // nilai indeks awal nuul, nantinya akan disisi dengan indeks list yang masih kosong

    if(countElement(des) < 10){ // selama masih belum melakukn iterasi kurang dari sepuluh
        int ketemu = 0; // penanda jika sudah ketemu atau belum

        int i = 0; // iterator
        while((ketemu == 0)&&(i < 10)){ // looping selama belum menmukan yang kosong dan belum melalui semua list
            if(des.data[i].next == -2){ // jika nilai list berikutnya -2 maka list berikutnya itu kosong
                hasil = i; // indeks sekarang adalah indeksnya
                ketemu = 1; // penanda agar keluar dari loop
            }else{ // tambah iterasi lagi
                i++;
            }
        }
    }
    
    return hasil; // mengembalikan nilai ideks hasil yang kosong
}

void addFirst(list *des, float dec, int n){
    if(countElement(*des) < n){ // selama belum terisi semua maka bisa dilanjutkan untuk mengisi
        int baru = emptyElement(*des); // pointer ke list yang kosong dan yang mau di isi

        // mengisi input user ke dalam listnya
        (*des).data[baru].dec = dec;

        if((*des).first == -1){ // add first jika listnya kosong
            (*des).data[baru].next = -1;
        }else{ // jika sudah ada listnya
            (*des).data[baru].next = (*des).first;
        }

        (*des).first = baru; // menyambungkan list dari yang sudah di tambahkan ke head
    }else{ // jika semua list sudah terisi
        printf("sudah ditambahkan semua\n");
    }
}

// menampilkan list list ke dalam layar
void printElement(list des){
    if(des.first != -1){ // jika listnya bukan merupakan list kosong
        int tunjuk = des.first; // tunjuk untuk menjadi pointer (penunjuk) untuk membaca list
        int i = 1; // iterator di mulai dari 0

        printf("\n");
        while(tunjuk != -1){ // looping selama belum menunjukan bagain akhir atau yang menunjuk null (-1)
            printf("%0.2f\n", des.data[tunjuk].dec);

            tunjuk = des.data[tunjuk].next; // iterasi untuk tunjuk
            i++; // iterasi untuk i
        }
        
    }else{ // jika listnya sudah kosong
        printf("kosong\n");
    }
}

int main() {
    // deklarasi
    //  *n      : untuk panjang atau banyak jumlah list yang dibutuhkan
    //  *nilSec : nilai yang di input user dan akan dimasukan kedalam list
    //  *des    : nama untuk listnya
    int n; 
    float nilSec;
    list des;
    
    scanf("%d", &n);
    createList(&des, n); // membuat listnya
    for(int i = 0; i < n; i++){
        scanf("%f", &nilSec); // input user
        addFirst(&des, nilSec, n); // memasukan input user ke list
    }
    printElement(des); // menampilakan list
    return 0;
}