#include "headUndoApay.h"

void createEmptyQueue(queue *Q){
    (*Q).first = -1;
    (*Q).last = -1;
}

int isEmptyQueue(queue Q){
    int hasil = 0;
    if(Q.first == -1){
        hasil = 1;
    }
    return hasil;
}

int isFullQueue(queue Q){
    int hasil = 0;
    if(Q.last == 128){
        hasil = 1;
    }
    return hasil;
}

int countQueue(queue Q){
    int hasil = 0;
    int bantu = Q.first;
    while(bantu <= Q.last){
        hasil++;
        bantu = bantu + 1;
    }

    return hasil;
}

void addPrior(nilai temp, queue *Q ){
    if(isEmptyQueue(*Q) == 1){
        /* jika queue kosong */
        (*Q).first = 0;
        (*Q).last = 0;
        (*Q).data[0] = temp;
    }else{
        /* jika queue tidak kosong */
        if(isFullQueue(*Q) != 1){
            // cek apakah banyak elemennya memenuhi untuk di terapkan perioritasnya
            if(countQueue(*Q) >= temp.prior){ // jika iya
                (*Q).last = (*Q).last + 1; // geser batas ujungnya
                int bantu = (*Q).last; // mulai dari ujung
                while(bantu >= temp.prior){ // shifting
                    (*Q).data[bantu] = (*Q).data[bantu-1];
                    bantu--; 
                }
                (*Q).data[bantu] = temp; // maksukin data baru ke tempatnya
            }else{ // jika tidak langsung saja isi belakang
                (*Q).last = (*Q).last + 1;
                (*Q).data[(*Q).last] = temp;
            }
        }else{
            // printf("queue penuh\n");
        }
    }
}

void del(queue *Q){
    if((*Q).last == 0){
        (*Q).first = -1;
        (*Q).last = -1;
    }else{
        /*menggeser elemen ke depan*/
        int i;
        for(i=((*Q).first + 1);i<=(*Q).last;i++){
            (*Q).data[i-1] = (*Q).data[i];
        }
        (*Q).last = (*Q).last - 1;
    }
}

void addTo(nilai temp, queue *Q ){ // add biasa
    if(isEmptyQueue(*Q) == 1){
        /* jika queue kosong */
        (*Q).first = 0;
        (*Q).last = 0;
        (*Q).data[0] = temp;
    }else{
        /* jika queue tidak kosong */
        if(isFullQueue(*Q) != 1){
            (*Q).last = (*Q).last + 1;
            (*Q).data[(*Q).last] = temp;
        }else{
            // printf("queue penuh\n");
        }
    }
}

void move(queue *Q, queue *R){ // mindahin data dari queue Q ke R
    if(isEmptyQueue(*Q) != 1){
        addTo((*Q).data[(*Q).first], R);
        del(Q);
    }
}

void createEmpty(stack *S){
    (*S).top = -1;
}

int isEmpty(stack S){
    int hasil = 0;
    if(S.top == -1){
        hasil = 1;
    }
    return hasil;
}

int isFull(stack S){
    int hasil = 0;
    if(S.top == 128){
        hasil = 1;
    }
    return hasil;
}

void push(nilai temp, stack *S ){
    if(isFull(*S) == 1){
        /*jika stack penuh*/
        // printf("stack penuh\n");
    }else{
        if(isEmpty(*S) == 1){
            // printf("masuk\n");
            /* jika stack kosong */
            (*S).top = 0;
            (*S).data[0] = temp;
        }else{
            /* jika stack tidak kosong */
            (*S).top = (*S).top + 1;
            (*S).data[(*S).top] = temp;
        }
        // printf("- %s\n", (*S).data[(*S).top].namTug);
    }
}

// mindahin stack yang sesuai sama syaratnya ke stack yang lain
void popTo(int banCek, nilai cek[], stack *S, stack *T){
    if((*S).top == 0){ // kalo cuma ada satu elemen
        /*jika stack berisi satu elemen*/
        int i = 0, stop = 0;
        while((i != banCek) && (stop != 1)){ // loop buat cocokin sama syratnya
            if(strcmp(cek[i].namTug, (*S).data[(*S).top].namTug) == 0){
                push((*S).data[(*S).top], T);
                (*S).top = -1;
                stop = 1;
            }
            i++;
        }
    }else{
        if((*S).top != -1){
            /*jika stack tidak kosong*/
            int bantu = (*S).top;
            int ketemu = 0;
            // loop jika belum ketemu semua dan belum jelajah sampai akhir
            while((bantu >= 0) && (ketemu < banCek)){
                int cari = 0, stop = 0; // buat nyocokin syrat dan indakator stop
                // loop kalo belum ngecek semua
                while((ketemu < banCek) && (cari < banCek) && (stop != 1)){
                    if(bantu == (*S).top){ // kalo lagi ngecek yang di atas
                        if(strcmp(cek[cari].namTug, (*S).data[(*S).top].namTug) == 0){
                            push((*S).data[(*S).top], T);
                            int moving = bantu;
                            while(moving < (*S).top){ // ngeshifting
                                (*S).data[moving] = (*S).data[moving+1];
                                moving = moving + 1;
                            }
                            (*S).top = (*S).top - 1;
                            ketemu++;
                            stop = 1;
                        }
                    }else{
                        // kalo ngecek yang lagi nggak di atas
                        if(strcmp(cek[cari].namTug, (*S).data[bantu].namTug) == 0){
                            push((*S).data[bantu], T);
                            int moving = bantu;
                            while(moving < (*S).top){ // ngeshifting
                                (*S).data[moving] = (*S).data[moving+1];
                                moving = moving + 1;
                            }
                            (*S).top = (*S).top - 1;
                            ketemu++;
                            stop = 1;
                        }
                    }
                    cari++;
                }
                bantu = bantu - 1;
            }
        }
    }
}

// udah lh yh bagian bawah ini yang buat ngeprint ngeprin
void printQueueAwal(queue Q){
    printf("Daftar Task Awal:\n");
    printf("==================================\n");
    if(isEmptyQueue(Q) != 1){
        int bantu = Q.first;
        while(bantu <= Q.last){
            printf("%s %s %d\n", Q.data[bantu].namTug, Q.data[bantu].jenTug, Q.data[bantu].prior);
            bantu = bantu + 1;
        }
    }else{
        printf("> listnya kosong, kaya dompetlu, yahahaha\n");
    }
    printf("==================================\n\n");
}

void printExecute(queue Q, queue R){
    printf("Daftar Sisa Task yang Belum Dieksekusi:\n");
    printf("==================================\n");
    if(isEmptyQueue(Q) != 1){
        int bantu = Q.first;
        while(bantu <= Q.last){
            printf("%s %s %d\n", Q.data[bantu].namTug, Q.data[bantu].jenTug, Q.data[bantu].prior);
            bantu = bantu + 1;
        }
    }else{
        printf("> listnya kosong, kaya dompetlu, yahahaha\n");
    }
    printf("==================================\n\n");
    
    printf("Log Task yang Dieksekusi:\n");
    printf("==================================\n");
    if(isEmptyQueue(R) != 1){
        int bantu = R.first;
        while(bantu <= R.last){
            printf("%s %s %d\n", R.data[bantu].namTug, R.data[bantu].jenTug, R.data[bantu].prior);
            bantu = bantu + 1;
        }
    }else{
        printf("> listnya kosong, kaya dompetlu, yahahaha\n");
    }
    printf("==================================\n\n");
}

void printStackUndoBefore(stack S){
    printf("Daftar Task yang Bisa Di-Undo:\n");
    printf("==================================\n");
    if(isEmpty(S) != 1){
        int bantu = S.top;
        while(bantu >= 0){
            printf("%s %s %d\n", S.data[bantu].namTug, S.data[bantu].jenTug, S.data[bantu].prior);
            bantu = bantu - 1;
        }
    }else{
        printf("> listnya kosong, kaya dompetlu, yahahaha\n");
    }
    printf("==================================\n\n");
}

void printStackUndoAfter(stack S){
    printf("Daftar Task yang Sudah Di-Undo:\n");
    printf("==================================\n");
    if(isEmpty(S) != 1){
        int bantu = S.top;
        while(bantu >= 0){
            printf("%s %s %d\n", S.data[bantu].namTug, S.data[bantu].jenTug, S.data[bantu].prior);
            bantu = bantu - 1;
        }
    }else{
        printf("> listnya kosong, kaya dompetlu, yahahaha\n");
    }
    printf("==================================\n");
}