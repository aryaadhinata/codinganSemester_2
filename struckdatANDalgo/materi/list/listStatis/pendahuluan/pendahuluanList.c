#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// program ini mebuat list statis dalam bentuk array dan juga beberapa cara yang bisa dilakukan untuk mengakses list

// first, next, hapus dan tunjuk adalah sebuah pointer tipe integer

// contoh struct untuk isi list dalam bentuk nilai nim, nama dan nilai
typedef struct{
    char nim[10];
    char nama[50];
    char nilai[3];
}nilaiMatKul;

// contoh cara menyiapkan kontainer yang berisi list
typedef struct{
    nilaiMatKul kontainer; // mengkontain satu elemen list
    int next;
}elemen;

// pointer dan juga jumlah data
typedef struct{
    int first;
    elemen data[10]; // banyak data dalam list
}list;

// membuat bentuk list yang ada
void createList(list *L){
    (*L).first = -1; // buat head langsung ke null

    for(int i = 0; i < 10; i++){
        /*proses menginisialisasi isi array*/
        (*L).data[i].next = -2;
    }
}

// menghitung banyak elemen yang tidak kosong
int countElement(list L){
    int hasil = 0;
    if(L.first != -1){// cek apakah list pertama kosong atau tidak
        int hitung;

        // inisiasi nilai hitung dengan head terlebih dahulu
        hitung = L.first;

        while(hitung != -1){ // ketika melakukan while dan listnya belum habis
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

// mencari bagian list yang masih belum di isi oleh nilai
int emptyElement(list L){
    int hasil = -1; // nilai indeks awal, nantinya akan disisi dengan indeks list yang masih kosong

    if(countElement(L) < 10){ // selama masih belum melakukn iterasi kurang dari sepuluh
        int ketemu = 0; // penanda jika sudah ketemu atau belum

        int i = 0; // iterator
        while((ketemu == 0)&&(i < 10)){ // looping selama belum menmukan yang kosong dan belum melalui semua list
            if(L.data[i].next == -2){ // jika nilai list berikutnya -2 maka list berikutny itu kosong
                hasil = i; // indeks sekarang adalah indeksnya
                ketemu = 1; // penanda agar keluar dari loop
            }else{ // tambah iterasi lagi
                i++;
            }
        }
    }
    
    return hasil; // mengembalikan nilai ideks hasil yang kosong
}

// melakukan penambahan list ke sebelum list yang ada (dituju)
void addFirst(list *L, char nim[], char nama[], char nilai[]){
    if(countElement(*L) < 10){ // selama belum terisi semua maka bisa dilanjutkan untuk mengisi
        int baru = emptyElement(*L); // pointer ke list yang kosong dan yang mau di isi

        // mengkopy semua nilai nim, nama dan nilai
        strcpy((*L).data[baru].kontainer.nim, nim);
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.nilai, nilai);

        if((*L).first == -1){ // add first jika listnya kosong
            (*L).data[baru].next = -1;
        }else{ // jika sudah ada listnya
            (*L).data[baru].next = (*L).first;
        }

        (*L).first = baru; // menyambungkan list dari yang sudah di tambahkan ke head
    }else{ // jika semua list sudah terisi
        printf("sudah ditambahkan semua\n");
    }
}

// melakukan penambahan setelah list yang ada (dituju)
void addAfter(int prev, list *L, char nim[], char nama[], char nilai[]){
    if(countElement(*L) < 10){ // selama belum terisi semua maka bisa dilanjutkan untuk mengisi
        int baru = emptyElement(*L); // pointer ke list yang kosong dan yang mau di isi

        // mengkopy semua nilai nim, nama dan nilai
        strcpy((*L).data[baru].kontainer.nim, nim);
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.nilai, nilai);

        if((*L).data[prev].next == -1){ // add after jika data yang di tambah di akhir
            (*L).data[baru].next = -1;
        }else{ // jika data yang ditambahkan ada di tengah
            (*L).data[baru].next = (*L).data[prev].next;
        }

        (*L).data[prev].next = baru; // menyambungkan list yang baru ke list yang sebelumnya
    }else{ // jika semua list sudah terisi
        printf("sudah ditambahkan semua\n");
    }
}

// melakukan penambahan di bagian akhir dari list
void addLast(list *L, char nim[], char nama[], char nilai[]){
    if((*L).first == -1){ // ketika listnya masih kosong
        addFirst(L, nim , nama, nilai); // karena cara pengerjaannya sama dengan addfirst jika listnya masih kosong
    }else{ // menambahkan listnya di bagian tengah
        if(countElement(*L) < 10){ // selama semua listnya masih belum diisi maka bisa kita isi
            int prev = (*L).first; // prev atau list sebelum yang mau kita add kita sambungkan dengan pointer head

            // looping sampai ketemu list ke dua dari terakhir 
            while((*L).data[prev].next != -1){
                // ubah prev agar menunjuk di bagian akhir dari list
                prev = (*L).data[prev].next;
            }

            // menggunakan addAfter karena mengggunakan teknik atau konsep yang sama
            addAfter(prev, L, nim, nama, nilai);
        }else{
            // sudah tidak ada list yang kosong
            printf("sudah tidak bisa ditambahkan lagi\n");
        }
    }
}

// melakukan delete ke bagain awal dari list (dituju)
void delFirst(list *L){
    if((*L).first != -1){ // jika list tidak kosong
        int hapus = (*L).first; // pointer hapus disamakan dengan pointer first
        
        if(countElement(*L) == 1){ // jika cuma ada satu list yang terisi (ada nilainya)
            (*L).first = -1; // buat first jadi null
        }else{ // lebih dari satu list yang berisi (ada niainya)
            (*L).first = (*L).data[hapus].next; // sambungkan bagian setelah hapus.next ke first
        }

        (*L).data[hapus].next = -2; // free memory bagian hapus.next
    }else{ // jika listnya kosong
        printf("List kosong\n");
    }
}

// melakukan delete ke list setelah dari list yang dituju
void delAfter(int prev, list *L){
    if(prev != -1){ // bagan prev harus menunjuk ke sesuatu tidak boleh kosong
        int hapus = (*L).data[prev].next; // hapus menunjuk ke prev.next

        if(hapus != -1){ // bagian hapus juga tidak boleh tidak menunjuk kemanapun
            if((*L).data[hapus].next == -1){ // jika yang ditunjuk berada di bagian paling akhir dari list 
                (*L).data[prev].next = -1; // ubah jadi null
            }else{ // jika bukan di bagian paling akhir dari list
                (*L).data[prev].next = (*L).data[hapus].next; // sambungkan prev.next ke hapus.next
            }
        }
        // hapus akses ke data yang ingin di hapus
        (*L).data[hapus].next = -2;
    }
}

// melakukan delete ke bagian paling belakang dari list yang dituju
void delLast(list *L){
    if((*L).first != -1){ // jika listnya bukan merupakan list kosong
        if(countElement(*L) == 1){ // jika cuma ada satu list
            delFirst(L); // langsung gunakan delFirst karena mekanismenya jadi sama
        }else{ // lebih dari satu list yang ada
            int hapus = (*L).first; // buat bagian hapus menunjuk bagian first juga
            int prev = -1; // preev belum menunjuk kemana mana

            // loop selama belum menemukan ujung dari list
            while((*L).data[hapus].next != -1){
                prev = hapus; // prev menunjuk bagian yang sebelumnya ditunjuk
                hapus = (*L).data[hapus].next; // hapus maju ke nextnya
            }

            // mengunakan delAfter karena teknik atau konsep yang sama
            delAfter(prev, L);
        }
    }else{ // tidak ada list yang bisa dihapus
        printf("List kosong\n");
    }
}

// menghappus semua akses ke dalam list
void delAll(list *L){
    for(int i = countElement(*L); i >= 1; i--){
        delLast(L); // bisa delLast bisa delFirst
    }
}

// menampilkan list list ke dalam layar
void printElement(list L){
    if(L.first != -1){ // jika listnya bukan merupakan list kosong
        int tunjuk = L.first; // tunjuk untuk menjadi pointer (penunjuk) untuk membaca list
        int i = 1; // iterator di mulai dari 0

        printf("\n======== LIST ========\n");
        while(tunjuk != -1){ // looping selama belum menunjukan bagain akhir atau yang menunjuk null (-1)
            printf("elemen ke : %d\n", i);
            printf("nim \t: %s\n", L.data[tunjuk].kontainer.nim);
            printf("nama \t: %s\n", L.data[tunjuk].kontainer.nama);
            printf("nilai \t: %s\n", L.data[tunjuk].kontainer.nilai);
            printf("next \t: %d\n", L.data[tunjuk].next);
            printf("------------\n");
            
            tunjuk = L.data[tunjuk].next; // iterasi untuk tunjuk
            i++; // iterasi untuk i
        }
        printf("======================\n");
    }else{ // jika listnya sudah kosong
        printf("\n======================\n");
        printf("     list kosong\n");
        printf("======================\n");
    }
}

int main(){
    list L;
    createList(&L);

    // deklarasi out untuk tanda kalo program keluar, kondAwal untuk menyimpan input yang diberikan user untuk pertanyaan
    // switch pertama, sementara kondSec untuk menyimpan jawaban untuk switch kedua
    int out = 0, kondAwal, kondSec;
    do{
        printf("\n========= Menu =========\n");
        printf("1. Add\n");
        printf("2. Delete\n");
        printf("9. PrintOut\n");
        printf("0. Out\n");
        printf("pilih dalam bentuk angkanya : ");
        scanf("%d", &kondAwal);
        
        switch(kondAwal){
            case 1 :{ // jika memilih untuk add ke dalam list
                // deklarasi untuk menyimpan nim, nama dan nilai yang akan dimasukan kedalam list
                char nimSec[10], namaSec[50], nilaiSec[3];

                printf("masukan valuenya\n");
                printf("nim \t: ");
                scanf("%s", nimSec);
                printf("nama \t: ");
                scanf("%s", namaSec);
                printf("nilai \t: ");
                scanf("%s", nilaiSec);
                
                printf("\n======== Menu Add =======\n");
                printf("1. addFirst\n");
                printf("2. addAfter\n");
                printf("3. addLast\n");
                printf("9. PrintOut\n");
                printf("0. Out\n");
                printf("pilih dalam bentuk angkanya : ");
                scanf("%d", &kondSec);
                
                switch(kondSec){
                    case 1 :{ // jika yang diminta adalah addFirst
                        addFirst(&L, nimSec, namaSec, nilaiSec);
                        break;
                    }
                    case 2 :{ // jika yang diminta adalah addAfter
                        // deklarasi prev agar user bisa memutuskan untuk di add di sebelah mana
                        int prev;
                        
                        printf("Masukan alamat sebelum list yang ingin di tambahkan : ");
                        scanf("%d", &prev);
                        addAfter(prev, &L, nimSec, namaSec, nilaiSec);
                        break;
                    }
                    case 3 :{ // jika yang ditambahkan adalah addLast
                        addLast(&L, nimSec, namaSec, nilaiSec);
                        break;
                    }
                    case 9:
                    case 0:{ // karena ada dua perintah yang sama jadi pengkondisiannya
                        // diluar switch ini
                        break;
                    }
                    default :{ // input yang diberikan salah
                        printf("masukan anda salah\n");
                        break;
                    }
                }
                break;
            }
            case 2 :{ // jika memilih untuk delete ke dalam list
                printf("\n===== Menu Del =====\n");
                printf("1. DelFirst\n");
                printf("2. DelAfter\n");
                printf("3. DelLast\n");
                printf("4. DelAll\n");
                printf("9. PrintOut\n");
                printf("0. Out\n");
                printf("pilih dalam bentuk angkanya : ");
                scanf("%d", &kondSec);
                
                switch(kondSec){
                    case 1 :{ // jika memilih untuk delFirst
                        delFirst(&L);
                        break;
                    }
                    case 2 :{ // jika memilih delAfter
                        // deklarasi prev agar user bisa memutuskan untuk di del di sebelah mana
                        int prev;

                        printf("Masukan alamat sebelum list yang ingin di delete : ");
                        scanf("%d", &prev);
                        delAfter(prev, &L);
                        break;
                    }
                    case 3 :{ // jika memilih delLast
                        delLast(&L);
                        break;
                    }
                    case 4 :{ // jika memilih delAll
                        delAll(&L);
                        break;
                    }
                    case 9 :
                    case 0 :{ // karena ada dua perintah yang sama jadi pengkondisiannya
                        // di opariskan diluar switch
                        break;
                    }
                    default :{ // input yang diberikan salah
                        printf("masukan anda salah\n");
                        break;
                    }
                }
                break;
            }
            case 9 :
            case 0 :{ // karena ada dua perintah yang sama jadi pengkondisiannya
                // dikosongkan karena akan dilakukan di luar dari switch
                break;
            }
            default : { // input yang diberikan salah
                printf("masukan anda salah\n");
                break;
            }
        }

        system("cls");
        // pengkondisian jika memilih untuk menampilkan elemen atau keluar dari loop
        if(kondAwal == 9 || kondSec == 9){
            printElement(L);
        }else if(kondAwal == 0 || kondSec == 0){
            out = 1;
        }
    }while(out != 1);

    // bagian ini salah karena langsung mengisi ke dalam list bukan melalui perantara, ini berbahaya dan tidak boleh dilakukan
    // karena jadinya konsep yang digunakan adalah array bukan lagi list. !!! jangan memperlakukan list sebagai array !!!
    // int out = 0, iter = 0;
    // do{
    //     printf("masukan nim (no space) :");
    //     scanf("%s", (L).data[iter].kontainer.nim);
    //     printf("masukan nama (no space) :");
    //     scanf("%s", (L).data[iter].kontainer.nama);
    //     printf("masukan nilai (no space) :");
    //     scanf("%s", (L).data[iter].kontainer.nilai);

    //     iter++;
    //     printf("ketik 1 untuk keluar dari loop\n");
    //     scanf("%d", out);
    // }while(out == 1);

    // addfirst(&L, (L).data->kontainer.nim, (L).data->kontainer.nama, (L).data->kontainer.nilai);
    return 0;
}

// belajar makro bung