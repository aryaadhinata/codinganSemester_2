#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

/*
    Saya Mohammad Arya Dhinata mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Algoritma dan 
    Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah 
    dispesifikasikan. Aamiin. 
*/

// variable global untuk mesin kata
extern int indeks;
extern int panjangKata;
extern char cw[65]; // ada 65 kata

// prosedur dan function untuk mesin kata dan EOPnya di ganti jadi " " dan spasinya di ganti "#"
void STARTWORD(char pita[]);
void RESETWORD();
void INCWORD(char pita[]);
char* GETWORD();
int GETPANJANGKATA();
int EOPWORD(char pita[]);

// struck bawaan dari nr-tree hanya saja bagian nilai di ubah untuk menyesuaikan kebutuhan
typedef struct{
    char node[129]; // nama simpulnya
    char peluang[17][129]; // kumpulan peluangnya jadi array 2d agar mudah
    int poin; // poin dari simpulnya
    int banyakPeluang, layer, visit; // atribut yang membantu tetatpi tidak di tampilkan
    // banyakPeluang : menyimpan total peluar yang akan dan digunakan
    // layer : menandai dia urutan ke-root dan root = 0
    // visit : tanda buat nanti kalo tidak visit berarti di hapus
}nilai;

typedef struct smp *alamatSimpul;
typedef struct smp{
    nilai kontainer;
    alamatSimpul sibling;
    alamatSimpul child;
}simpul;

typedef struct{
    simpul *root;
}tree;

void makeTree(nilai temp, tree *T); // set layer jadi 0 dan juga visit 0
void addChild(nilai temp, simpul *root); // set visit jadi 0 dan layer jadi layer sebelumnya + 1
void delAll(simpul *root);
void delChild(simpul *root); // cuma menghapus yang nggak di kasih tanda visit
simpul* findSimpul(char temp[], simpul *root);
int countLayer(simpul *root); // menghitung banyak layer yang ada
int cariSpasi(int layer, simpul *root); // menghitung banyak spasi yang akan di gunakan
simpul *findPeluang(char temp[], simpul *root); // menandai secara backtracking yang sesuai kodenya modifikasi postOrder rekursif dulu baru cek
void hapusTidakVisit(simpul *root); // menghapus menggunakan delChild yang sudah di modifikasi 
void printTreePreOrder(int spasi[], int banyakLayer, simpul *root); // menyesuaikan sama output perintah
void printTreePostOrder(int spasi[], int banyakLayer, simpul *root); // ide backtrack karena lihat ini rekursif dulu baru cek
int countPoin(int hasil, simpul *root); // hitung banyak poin dari node yang tersisa
void printPeluang(simpul *root); // menampilkan semua peluang
int convers(char str[]); // ubah str jadi int
int countDigit(int n); // hitung banyak digit
// int isEqual(simpul *root1, simpul *root2);