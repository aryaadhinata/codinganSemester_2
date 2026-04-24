#include "head.h"

void createList(list *L){
    (*L).first = NULL;
}

int countElementB(list L){
    int hasil = 0;
    if(L.first !=NULL){
        /*list tidak kosong*/
        eBaris* bantu;
        /*inisialisasi*/
        bantu = L.first;

        while(bantu != NULL){
            /*proses*/
            hasil = hasil + 1;

            /*iterasi*/
            bantu = bantu->next;
        }
    }
    return hasil;
}

int countElementK(eBaris L){
    int hasil = 0;
    if(L.col !=NULL){
        /*list tidak kosong*/
        eKolom* bantu;
        /*inisialisasi*/
        bantu = L.col;

        while(bantu != NULL){
            /*proses*/
            hasil = hasil + 1;

            /*iterasi*/
            bantu = bantu->next_kol;
        }
    }
    return hasil;
}

void addFirstB(nilai temp, list *L){
    eBaris* baru;
    baru = (eBaris *) malloc (sizeof (eBaris));
    baru->kontainer = temp;
    baru->col = NULL;
    
    if((*L).first == NULL){
        baru->next = NULL;
    }else{
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

void addFirstK(nilaiSec temp, eBaris *L){
    eKolom* baru;
    baru = (eKolom *) malloc (sizeof (eKolom));
    baru->kontainer_kol = temp;
    if((*L).col == NULL){
        baru->next_kol = NULL;
    }else{
        baru->next_kol = (*L).col;
    }
    (*L).col = baru;
    baru = NULL;
}

void addAfterB(eBaris *prev, nilai temp){
    eBaris* baru;
    baru = (eBaris *) malloc (sizeof (eBaris));
    baru->kontainer = temp;
    baru->col = NULL;
    if(prev->next == NULL){
        baru->next = NULL;
    }else{
        baru->next = prev->next;
    }
    prev->next = baru;
    baru = NULL;
}

void addAfterK(eKolom *prev, nilaiSec temp){
    eKolom* baru;
    baru = (eKolom *) malloc (sizeof (eKolom));
    baru->kontainer_kol = temp;
    if(prev->next_kol == NULL){
        baru->next_kol = NULL;
    }else{
        baru->next_kol = prev->next_kol;
    }
    prev->next_kol = baru;
    baru = NULL;
}

void addLastB(nilai temp, list *L){
    if((*L).first == NULL){
        addFirstB(temp, L);
    }else{
        eBaris *last = (*L).first;
        while(last->next != NULL){
            last = last->next;
        }
        addAfterB(last, temp);
    }
}

void addLastK(nilaiSec temp, eBaris *L){
    if((*L).col == NULL){
        addFirstK(temp, L);
    }else{
        eKolom *last = (*L).col;
        while(last->next_kol != NULL){
            last = last->next_kol;
        }
        addAfterK(last, temp);
    }
}

void delFirstK(eBaris *L){
    if((*L).col != NULL){
        eKolom* hapus = (*L).col;
        if(countElementK(*L) == 1){
            (*L).col = NULL;
        }else{
            (*L).col = (*L).col->next_kol;
            hapus->next_kol = NULL;
        }

        free(hapus);
    }
}

void delAfterK(eKolom* prev){
    eKolom* hapus = prev->next_kol;
    if(hapus != NULL){
        if(hapus->next_kol == NULL){
            prev->next_kol = NULL;
        }else{
            prev->next_kol = hapus->next_kol;
            hapus->next_kol = NULL;
        }

        free(hapus);
    }
}

void delLastK(eBaris *L){
    if((*L).col != NULL){
        if(countElementK(*L) == 1){
            delFirstK(L);
        }else{
            eKolom* last = (*L).col;
            eKolom* before_last;

            while(last->next_kol != NULL){
                before_last = last;
                last = last->next_kol;
            }

            delAfterK(before_last);
        }
    }
}

void delAllK(eBaris *L){
    if(countElementK(*L) != 0){
        int i;

        for(i = countElementK(*L); i >= 1; i--){
            delLastK(L);
        }
    }
}

void delFirstB(list *L){
    if((*L).first != NULL){
        eBaris *hapus = (*L).first;

        if(hapus->col != NULL){
            delAllK(hapus);
        }

        if(countElementB(*L) == 1){
            (*L).first = NULL;
        }else{
            (*L).first = (*L).first->next;
        }
        hapus->next = NULL;
        free(hapus);
    }else{
        printf("list kosong");
    }
}

void delAfterB(eBaris *prev){
    if(prev != NULL){
        eBaris *hapus = prev->next;
        if(hapus != NULL){
            if(hapus->col != NULL){
                delAllK(hapus);
            }
            
            if(hapus->next == NULL){
                prev->next = NULL;
            }else{
                prev->next = hapus->next;
            }
            hapus->next = NULL;
            free(hapus);
        }
    }
}

void delLastB(list *L){
    if((*L).first != NULL){
        if(countElementB(*L) == 1){
            delFirstB(L);
        }else{
            eBaris *last = (*L).first;
            eBaris *before_last;

            while(last->next != NULL){
                before_last = last;
                last = last->next;
            }

            delAfterB(before_last);
        }
    }
}

void delAllB(list *L){
    if(countElementB(*L) != 0){
        int i;

        for(i = countElementB(*L); i >= 1; i--){
            delLastB(L);
        }
    }
}

// mulai dari sini semua program yang saya buat dan modifikasi

// untuk mencari elemen baris terakhir dari list
eBaris* lastBaris(eBaris *first){
    if(first != NULL){ // jika belum di ujung
        while(first->next != NULL){ // looping supaya di ujung
            first = first->next;
        }
    }
    return first; // pointer yang paling ujung di kembalikan
}

// untuk mencari elemen kolom sebelum elemen kolom yang di inginkan
eKolom* lastBeforeTarget(eBaris* base, eKolom* target){
    eKolom* before = base->col; // mulai dari baris awal kolom
    if(before != target){ // jika belum ketemu target maka looping sampai ketemu targer
        while(before->next_kol != target){
            before = before->next_kol;
        }
    }
    // ini di kembaliin pointer sebelum pointer yang ke target 
    // ada kemungkinan ini ngembaliin target itu sendiri karena targetnya ad adi paling awal
    return before; 
}

// prosedur untuk memindahkann bangsal ke bangsal lain di taro kayak addlast
void pindahBangsal(eBaris* nowB, eKolom* nowK, char target[], list *L){
    // cari bangsal tujuan yang akan di tempati
    eBaris* pencari = L->first;
    while(pencari->next != NULL && (strcmp(pencari->kontainer.namBang ,target) != 0)){
        pencari = pencari->next;
    }
    
    // cari elemn terakhir dari bangsalnya
    eKolom* pencariKolom = pencari->col;
    if(pencariKolom != NULL){
        while(pencariKolom->next_kol != NULL){
            pencariKolom = pencariKolom->next_kol;
        }
    }

    // printf(" ?%d? ", nowK->kontainer_kol.id);
    
    // mulai pindah
    if(pencariKolom != NULL){ // kalo kolom di barisnya udh ada
        pencariKolom->next_kol = nowK; // elemen terraakhir pegang elemen yang mau di pindah
        if(nowK == nowB->col){ // kalo elemen yang pindah ada di awal kolom
            if(nowK->next_kol != NULL){ // dan kalo ada elemen berikutnya maka di sambungkan dulu ke awal kolom
                nowB->col = nowK->next_kol;
            }else{
                nowB->col = NULL;
                // pencariKolom->next_kol = NULL;
            }
        }else if(nowK->next_kol != NULL){ // jika ada di tengah tengah
            eKolom* prev = lastBeforeTarget(nowB, nowK); // deklarasi prev sebelum elemen yang mau di pindah
            prev->next_kol = nowK->next_kol; // prev->next_kol nya di hubungkan dengan nowK->next_kolnya
        }else{ // kalo di ujung
            eKolom* prev = lastBeforeTarget(nowB, nowK); // deklarasi prev sebelum elemen yang mau di pindah
            prev->next_kol = NULL; // langsung null kan    
        }
        
        if(nowK->next_kol != NULL){
            nowK->next_kol = NULL; // langsung null kan
        }
    }else{ // kalo kolom di barisnya masih kosong
        pencari->col = nowK;
        if(nowK == nowB->col){ // kalo elemen yang pindah ada di awal kolom
            if(nowK->next_kol != NULL){ // dan kalo ada elemen berikutnya maka di sambungkan dulu ke awal kolom
                nowB->col = nowK->next_kol;
            }else{
                nowB->col = NULL;
                // pencari->col = NULL;
            }
        }else if(nowK->next_kol != NULL){ // jika ada di tengah tengah
            eKolom* prev = lastBeforeTarget(nowB, nowK); // deklarasi prev sebelum elemen yang mau di pindah
            prev->next_kol = nowK->next_kol; // prev->next_kol nya di hubungkan dengan nowK->next_kolnya
        }else{ // kalo di ujung
            eKolom* prev = lastBeforeTarget(nowB, nowK); // deklarasi prev sebelum elemen yang mau di pindah
            prev->next_kol = NULL; // langsung null kan
        }
        if(nowK->next_kol != NULL){
            nowK->next_kol = NULL; // langsung null kan
        }
    }
}

// untuk print bagian header rumah sakit
void printHead(){
    printf("=============================================\n");
    printf("   Rumah Sakit Lestari Medika: Data Pasien\n");
    printf("=============================================\n\n");
}

// prosedur untuk memulangkan dan memindahkan pasien
void prosesPulang(int banPasPul,int pasPul[], char pinPen[], char pinBan[], list *L){
    for(int i = 0; i < banPasPul; i++){ // looping sebnayak pasien yang ingin dipulangkan
        int stop = 0; // penanda ada tidaknya nama pasien dalam daftar
        eBaris* bantu = L->first; // pointer bantu untuk menelusuri baris
        while(bantu != NULL && stop != 1){ // loop jika belum sampai ujung dan belum ketemu dengan pasien yang di cari
            eKolom* help = bantu->col; // pointer help untuk menelusuri kolom 
            while(help != NULL && stop != 1){ // loop jika belum sampai ujung dan belum ketemu dengan pasien yang di cari
                if(pasPul[i] == help->kontainer_kol.id){ // jika id pasien ketemu
                    stop = 1; // tandai
                    printf(" >> [LOG] Pasien %s [ %d ] dipulangkan.\n", help->kontainer_kol.nama, help->kontainer_kol.id);
                    if(help != bantu->col){ // jika bukan di elemen pertama delafter
                        delAfterK(lastBeforeTarget(bantu, help));
                    }else{//jika di elemen pertama delfirst
                        delFirstK(bantu);
                    }
                }
                help = help->next_kol;
            }
            bantu = bantu->next;
        }
        if(stop != 1){ // jika sampai ujung beleum ketemu tampilkan error
            printf(" >> [ERROR] Pasien dengan ID [ %d ] tidak ditemukan.\n", pasPul[i]);
        }
    }
    
    int cekBang = 1; // penanda tidak adanya bangsal yang di cari
    eBaris* bantu = L->first; // bantu untuk menelusuri baris
    while(bantu != NULL){ // looping sampai ujung
        if(strcmp(bantu->kontainer.namBang, pinBan) == 0){ // jika ketemu bangsal yang di cari 
            cekBang = 0; // tandanya jadi ada
        }
        bantu = bantu->next;
    }
    
    int markPin = 0; // penanda ada tidaknya pasien yang harus dipindah
    bantu = L->first; // sama kayak yang di atas
    while(bantu != NULL && cekBang != 1){ // jika belum sampai ujung baris dan emang bangsalnya ada
        eKolom *help = bantu->col; // samam juga kayak yang diatas
        while(help != NULL && cekBang != 1){ // jika belum sampai ujung kolom dan emang bangsalnya ada
            // jika pasiennya ketemu dan emang bukan di bangsal yang mau dioindah maka di proses
            // printf("- %d", help->kontainer_kol.id);
            if((strcmp(pinPen, help->kontainer_kol.peny) == 0) && (strcmp(pinBan, bantu->kontainer.namBang) != 0)){
                // printf(" <> %d", help->kontainer_kol.id);
                printf(" >> [LOG] Pasien %s [ %d ] dipindah: Bangsal %s --> %s\n", 
                    help->kontainer_kol.nama, help->kontainer_kol.id, bantu->kontainer.namBang, pinBan);
                    markPin = 1; // ada yang pindah
                    // eBaris* tempBantu = bantu;
                    eKolom* tempHelp = help->next_kol;
                    pindahBangsal(bantu, help, pinBan, L); // pindahin pasiennya
                    // reset ulang biar balik lagi
                    // bantu = L->first;
                    help = tempHelp;
            }else{
                help = help->next_kol;
            }
            // printf(" | %d - %d\n", help->kontainer_kol.id, bantu->col->kontainer_kol.id);
        }
        bantu = bantu->next;
    }
    if(cekBang == 1){ // jika bangsal yang di cari nggak ada
        printf(" >> [ERROR] Ruang %s tidak terdaftar.\n", pinBan);
    }else{ 
        if(markPin == 0){ // bangsalnya ada tapi pasien yang mau dipindah nggak ada
            printf(" >> [LOG] Tidak ada pasien dengan penyakit %s yang perlu dipindah ke bangsal %s.\n", pinPen, pinBan);
        }
    }
}

// print elemen yang normal
void printElement(list L){
    if(L.first != NULL){
        printf("\n");
        eBaris* bantu = L.first; // bantu nelusuri baris
        
        while(bantu != NULL){ // loop sampai ujung
            printf("_________________________________________________\n");
            printf(" + Bangsal %s\n", bantu->kontainer.namBang); // print bangsal
            eKolom* help = bantu->col; // bnatu nelusuri kolom
            if(help != NULL){ // lop sampai ujung
                while(help != NULL){ // jika bangsalnya ada isinya print sesuai format
                    int space = 11;
                    printf("  - [ %d ] %s", help->kontainer_kol.id, help->kontainer_kol.nama);
                    if(space > strlen(help->kontainer_kol.nama)){
                        for(int i = 0; i < (space - strlen(help->kontainer_kol.nama)); i++){
                            printf(" ");
                        }
                    }
                    space = 15;
                    printf("| %s", help->kontainer_kol.peny);
                    if(space > strlen(help->kontainer_kol.peny)){
                        for(int i = 0; i < (space - strlen(help->kontainer_kol.peny)); i++){
                            printf(" ");
                        }
                    }
                    printf("| %d th\n", help->kontainer_kol.usia);
                    help = help->next_kol;
                }
            }else{ // kalo nggak ada
                printf("  - Bangsal Kosong.\n");
            }
            bantu = bantu->next;
        }
    }else{ // kayaknya nggak bakal kosong nggak sih
        // none
    }
}
