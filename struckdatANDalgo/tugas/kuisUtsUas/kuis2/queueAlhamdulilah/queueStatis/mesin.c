#include "head.h"

void createEmpty(queue *Q){
    (*Q).first = -1;
    (*Q).last = -1;
}

int isEmpty(queue Q){
    int hasil = 0;
    if(Q.first == -1){
        hasil = 1;
    }
    return hasil;
}

int isFull(queue Q){
    int hasil = 0;
    if(Q.last == 64){
        hasil = 1;
    }
return hasil;
}

void add(nilai temp, queue *Q ){
    if(isEmpty(*Q) == 1){
        /* jika queue kosong */
        (*Q).first = 0;
        (*Q).last = 0;
        (*Q).data[0] = temp;
    }else{
        /* jika queue tidak kosong */
        if(isFull(*Q) != 1){
            (*Q).last = (*Q).last + 1;
            (*Q).data[(*Q).last] = temp;
        }else{
            printf("queue penuh\n");
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

void addPriority(nilai temp, queue *Q ){ // menambahkan prioritas
    if(isEmpty(*Q) == 1){
        /* jika queue kosong */
        (*Q).first = 0;
        (*Q).last = 0;
        (*Q).data[0] = temp;
    }else{
        /* jika queue tidak kosong */
        if(isFull(*Q) != 1){
            // cek apakah banyak elemennya memenuhi untuk di terapkan perioritasnya
            (*Q).last = (*Q).last + 1;
            if((*Q).last >= temp.prior){ // jika iya
                int bantu = (*Q).last; // mulai dari ujung
                while(bantu >= temp.prior){ // shifting
                    (*Q).data[bantu] = (*Q).data[bantu-1];
                    bantu--; 
                }
                (*Q).data[bantu] = temp; // maksukin data baru ke tempatnya
            }else{ // jika tidak langsung saja isi belakang
                (*Q).data[(*Q).last] = temp;
            }
        }else{
            // printf("queue penuh\n");
        }
    }
}

void cek(int batas, queue *Q, queue *R, queue *S){ // cek berapa dan pisahkan queue sesuai dengan yang dibatasi
    int bantu = (*Q).first;
    int count = 0;
    while(bantu <= (*Q).last){ // belum di ujung
        if(batas > count){ // belumm habis
            add((*Q).data[bantu], R);
            count++;
        }else{
            add((*Q).data[bantu], S);
        }
        bantu++;
    }
}

void printQueue(queue Q, queue R){
    printf("Skala prioritas:\n");
    if(Q.first != -1){
        for(int i = Q.first; i <= Q.last; i++){
            printf("%s %s %d %d %d\n", Q.data[i].nama, Q.data[i].negara, Q.data[i].progres, Q.data[i].tahun, Q.data[i].prior);
        }
    }else{
        /* proses jika queue kosong */
        printf("kosong\n");
    }
    
    printf("\nBukan skala prioritas:\n");
    if(R.first != -1){
        for(int i = R.first; i <= R.last; i++){
            printf("%s %s %d %d %d\n", R.data[i].nama, R.data[i].negara, R.data[i].progres, R.data[i].tahun, R.data[i].prior);
        }
    }else{
        /* proses jika queue kosong */
        printf("kosong\n");
    }
}