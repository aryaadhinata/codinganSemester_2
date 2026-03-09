#include "head.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tes Mesin List Statis dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

void createList(list *L){
    (*L).first = -1;
    for(int i = 0; i < 6; i++){
        (*L).data[i].next = -2;
    }
}

int countElement(list L){
    int hasil = 0;
    if(L.first != -1){
        int hitung;
        hitung = L.first;
        while(hitung != -1){
            hasil = hasil + 1;
            hitung = L.data[hitung].next;
        }
    }
    return hasil;
}

int emptyElement(list L){
    int hasil = -1;
    if(countElement(L) < 6){
        int ketemu = 0;
        int i = 0;
        while((ketemu == 0) && (i < 6)){
            if(L.data[i].next == -2){
                hasil = i;
                ketemu = 1;
            }else{
                i++;
            }
        }
    }
    return hasil;
}

void addFirst(list *L, nilai temp){
    if(countElement(*L) < 6){
        int baru = emptyElement(*L);
        (*L).data[baru].kontainer = temp;
        
        if((*L).first == -1){
            (*L).data[baru].next = -1;
        }else{
            (*L).data[baru].next = (*L).first;
        }
        
        (*L).first = baru;
    }else{
        printf("sudah ditambahkan semua\n");
    }
}

void addAfter(int prev, list *L, nilai temp){
    if(countElement(*L) < 6){ // selama belum terisi semua maka bisa dilanjutkan untuk mengisi
        int baru = emptyElement(*L); // pointer ke list yang kosong dan yang mau di isi

        (*L).data[baru].kontainer = temp;
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
void addLast(list *L, nilai temp){
    if((*L).first == -1){ // ketika listnya masih kosong
        addFirst(L, temp); // karena cara pengerjaannya sama dengan addfirst jika listnya masih kosong
    }else{ // menambahkan listnya di bagian tengah
        if(countElement(*L) < 6){ // selama semua listnya masih belum diisi maka bisa kita isi
            int prev = (*L).first; // prev atau list sebelum yang mau kita add kita sambungkan dengan pointer head

            // looping sampai ketemu list ke dua dari terakhir 
            while((*L).data[prev].next != -1){
                // ubah prev agar menunjuk di bagian akhir dari list
                prev = (*L).data[prev].next;
            }

            // menggunakan addAfter karena mengggunakan teknik atau konsep yang sama
            addAfter(prev, L, temp);
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

void printElement(list L){
    if(L.first != -1){ // jika listnya bukan merupakan list kosong
        int tunjuk = L.first; // tunjuk untuk menjadi pointer (penunjuk) untuk membaca list
        int i = 0; // iterator di mulai dari 0

        printf("----------------------------------------\nData WarungBahari :\n");
        while(tunjuk != -1){ // looping selama belum menunjukan bagain akhir atau yang menunjuk null (-1)
            printf("- %s %s %s %s\n", L.data[tunjuk].kontainer.nama, L.data[tunjuk].kontainer.tipeSen, L.data[tunjuk].kontainer.peluru, L.data[tunjuk].kontainer.avabil);
            
            tunjuk = L.data[tunjuk].next; // iterasi untuk tunjuk
            i++; // iterasi untuk i
        }
    }else{ // jika listnya sudah kosong
        printf("----------------------------------------\nData WarungBahari :\n");
        printf("Ko0o0o0song!\n");
    }
}