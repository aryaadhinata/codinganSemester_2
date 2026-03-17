#include "heaad.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Pratikum 2 dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

void createList(list *L){
    (*L).first = NULL;
}

int countElement(list L){
    int hasil = 0;
    if(L.first != NULL){
        elemen* tunjuk = L.first;
        while(tunjuk != NULL){
            hasil++;
            tunjuk = tunjuk->next;
        }
    }
    return hasil;
}

void addFirst(nilai temp, list *L){
    elemen* baru = (elemen*) malloc(sizeof(elemen));
    baru->kontainer = temp;

    if((*L).first == NULL){
        baru->next = NULL;
    } else {
            baru->next = (*L).first;
    }

    (*L).first = baru;
}

void addAfter(elemen* prev, nilai temp, list *L){
    if(prev != NULL){
        elemen* baru = (elemen*) malloc(sizeof(elemen));
        baru->kontainer = temp;

        if(prev->next == NULL){
            baru->next = NULL;
        } else {
            baru->next = prev->next;
        }

        prev->next = baru;
    }
}

void addLast(nilai temp, list *L){
    if((*L).first == NULL){
        addFirst(temp, L);
    } else {
        elemen* prev = (*L).first;
        while(prev->next != NULL){
            prev = prev->next;
        }
        addAfter(prev, temp, L);
    }
}

void delFirst(list *L){
    if((*L).first != NULL){
        elemen* hapus = (*L).first;

        if(countElement(*L) == 1){
            (*L).first = NULL;
        } else {
            (*L).first = (*L).first->next;
            hapus->next = NULL;
        }

        free(hapus);
    }
}

void delAfter(elemen* prev, list *L){
    if(prev != NULL && prev->next != NULL){
        elemen* hapus = prev->next;

        if(hapus->next == NULL){
            prev->next = NULL;
        } else {
            prev->next = hapus->next;
            hapus->next = NULL;
        }

        free(hapus);
    }
}

void delLast(list *L){
    if((*L).first != NULL){
        if(countElement(*L) == 1){
            delFirst(L);
        } else {
            elemen* last = (*L).first;
            elemen* prev;

            while(last->next != NULL){
                prev = last;
                last = last->next;
            }

            delAfter(prev, L);
        }
    }
}

void delAll(list *L){
    while((*L).first != NULL){
        delLast(L);
    }
}

// mulai dari sini adala semua kode yang saya buat sendiri

// prosedur unutk melakukan swap karena saya rasa terlalu berulanng jadi di buatkan prosedur
void swap(elemen *prefP, elemen *p, elemen *q, list *L){
    // first->p->q->... || ...->prefP->p->q->... bentuk awalnya
    
    if(p == L->first){ // ketika p nya berada di first maka firstnya langsung mengang nextnya yaitu q
        L->first = q;
    }else{ // jika p bukan yang pertama maka prefP memegang q
        prefP->next = q;
    }

    p->next = q->next; // pointer dari p->next megang ke q->next
    q->next = p; // pointer q->next pegang ke p
    
    
    // first->q->p->... || ...->prefP->q->p->... bentuk akhirnya
}

// prosedur untuk melakukan sorting buble sort
void sort(int kead[], list *L){
    elemen *prefP, *p, *q; // deklarasi pointer yang akan digunakan
    int loop; // penanda apakah ada pertukaran yang artinya list belum terurut
    
    //  do while nya dipakai untuk menandai apakah ada swap atau tidak jika masih ada maka akan looping terus
    // sampai tidak ada yang di swap
    do{
        loop = 0; // set nilai default setiap do while

        // set nilai default setiap do while
        p = L->first;
        prefP = NULL;
        q = p->next;

        // while digunakan untuk melakukan penelusuran dari head sampai nuul
        while(q != NULL){ // selama bukan list yang berisi saru kontainaer maka kita cek
            int iter = 0; // deklrasi dan nilai default apakah ada yang di swap agar urutan pointernya sama lagi

            if(kead[0] == 1){ // score
                if(kead[1] == 1){ // ascending
                    if(p->kontainer.comScor > q->kontainer.comScor){
                        swap(prefP, p, q, L);
                        iter = 1;
                        loop = 1;
                    }else if(p->kontainer.comScor == q->kontainer.comScor){
                        if(strcmp(p->kontainer.namPem, q->kontainer.namPem) > 0){
                            swap(prefP, p, q, L);
                            iter = 1;
                            loop = 1;
                        }
                    }
                }else if(kead[1] == 2){ // decending
                    if(p->kontainer.comScor < q->kontainer.comScor){
                        swap(prefP, p, q, L);
                        iter = 1;
                        loop = 1;
                    }else if(p->kontainer.comScor == q->kontainer.comScor){
                        if(strcmp(p->kontainer.namPem, q->kontainer.namPem) > 0){
                            swap(prefP, p, q, L);
                            iter = 1;
                            loop = 1;
                            
                        }
                    }
                }
            }else if(kead[0] == 2){ // nama
                if(kead[1] == 1){ // ascending
                    if(strcmp(p->kontainer.namPem, q->kontainer.namPem) > 0){
                        swap(prefP, p, q, L);
                        iter = 1;
                        loop = 1;
                    }else if(strcmp(p->kontainer.namPem, q->kontainer.namPem) == 0){
                        if(p->kontainer.comScor > q->kontainer.comScor){
                            swap(prefP, p, q, L);
                            iter = 1;
                            loop = 1;
                        }
                    }
                }else if(kead[1] == 2){ // decending
                    if(strcmp(p->kontainer.namPem, q->kontainer.namPem) < 0){
                        swap(prefP, p, q, L);
                        iter = 1;
                        loop = 1;
                    }else if(strcmp(p->kontainer.namPem, q->kontainer.namPem) == 0){
                        if(p->kontainer.comScor > q->kontainer.comScor){
                            swap(prefP, p, q, L);
                            iter = 1;
                            loop = 1;
                        }
                    }
                }
            }
            // bagian iterasi
            if(iter == 0){ // jika tidak ada yang di swap maka iterasinya sama aja
                prefP = p;
                p = q;
                q = q->next;
            }else{ // jika ada yang di tukah maka ada perubahann dikit agar
                // yang tadinya first->q->p->... | ...->prefP->q->p->... jadi kebentuk awalnya lagi
                prefP = q;
                q = p->next;
            }
        }
    }while(loop == 1); // tetep loop selama masih ada yang di ubah
    prefP = NULL;
    p = NULL;
    q = NULL;
}

// prosedur untuk menghubungkan bagian L2 ke L1
void kait(elemen *prefCek, elemen *cek, elemen *merge, list *L1, list *L2){
    L2->first = merge->next; // pindahin firstnya ke merge.nextnya
    if(prefCek == NULL){ // jika yang di hubungkan itu di bagian awal dari list 1
        merge->next = L1->first; // merge->nextnya hubungkan ke first L1
        L1->first = merge; // L1->first menyambung ke merge
    }else{ // selain itu sama aja cuma ganti bukan L1->first yang pindah tapi prefCek yang pindah
        merge->next = cek; // di hubungkan dengan cek 
        prefCek->next = merge;
    }
}

// prosedur untuk meMerge L2 ke L1
void mergeList(int kead[], list *L1, list *L2){
    elemen *prefCek, *cek, *merge; // pointer pointer yang digunakan
    merge = L2->first; // pointer merge dari L2 selalu di L2->first
    while(merge != NULL){ // selama merge tidak nuul atau data di L2 belum habis
        prefCek = NULL; // set nilai default setiap kali loop
        cek = L1->first;
        int sambung = 0;
        while(cek != NULL && sambung == 0){ // loop selama masih ada yang perlu disambung atau cek listnya belumm sampai ujung
            if(kead[0] == 1){
                if(kead[1] == 1){
                    if(cek->kontainer.comScor > merge->kontainer.comScor){
                        kait(prefCek, cek, merge, L1, L2);
                        sambung = 1;
                    }else if (cek->kontainer.comScor == merge->kontainer.comScor){
                        if(strcmp(cek->kontainer.namPem, merge->kontainer.namPem) > 0){
                            kait(prefCek, cek, merge, L1, L2);
                            sambung = 1;
                        }
                    }
                }else if(kead[1] == 2){
                    if(cek->kontainer.comScor < merge->kontainer.comScor){
                        kait(prefCek, cek, merge, L1, L2);
                        sambung = 1;
                    }else if (cek->kontainer.comScor == merge->kontainer.comScor){
                        if(strcmp(cek->kontainer.namPem, merge->kontainer.namPem) > 0){
                            kait(prefCek, cek, merge, L1, L2);
                            sambung = 1;
                        }
                    }
                }
            }else if(kead[0] == 2){
                if(kead[1] == 1){
                    if(strcmp(cek->kontainer.namPem, merge->kontainer.namPem) > 0){
                        kait(prefCek, cek, merge, L1, L2);
                        sambung = 1;
                    }else if(strcmp(cek->kontainer.namPem, merge->kontainer.namPem) == 0){
                        if(cek->kontainer.comScor > merge->kontainer.comScor){
                        kait(prefCek, cek, merge, L1, L2);
                        sambung = 1;
                        }
                    }
                }else if(kead[1] == 2){
                    if(strcmp(cek->kontainer.namPem, merge->kontainer.namPem) < 0){
                        kait(prefCek, cek, merge, L1, L2);
                        sambung = 1;
                    }else if(strcmp(cek->kontainer.namPem, merge->kontainer.namPem) == 0){
                        if(cek->kontainer.comScor > merge->kontainer.comScor){
                        kait(prefCek, cek, merge, L1, L2);
                        sambung = 1;
                        }
                    }
                }
            }
            if(sambung == 0){ // kalo belum ada yang nyambunng atau di merge ini iteraasinya
                prefCek = cek;
                cek = cek->next;
            }
        }
        if(sambung == 0){ // kalo sampai akhir nggak ada yang sesuai langsung add di belakanya aja
            kait(prefCek, cek, merge, L1, L2);
        }
        
        merge = L2->first; // mergenya pindah lagi ke L2->first
    }
    prefCek = NULL;
    cek = NULL;
    merge = NULL;
}

// fungsi untuk menghitung digit
int digLeng(int n){
	if(n == 0){
		return 1;
	}else{
		int count = 0;
		while(n != 0){
			n /= 10;
			count++;
		}
		return count;
	}
}

// prosedur untuk menampilkan
void printElemen(list L){
    elemen* tunjuk = L.first;
    int nama, role, score; // nilai konstan untuk spasi
    nama = 10;
    role = 17;
    score = 16;
    printf("+-----------+------------------+-----------------+\n");
    printf("| Nama      | Role             | Combat Score    |\n");
    printf("+-----------+------------------+-----------------+\n");
    while(tunjuk != NULL){
        printf("| %s", tunjuk->kontainer.namPem);
        if(strlen(tunjuk->kontainer.namPem) < nama){
            for(int i = 0; i < (nama - strlen(tunjuk->kontainer.namPem)); i++){
                printf(" ");
            }
        }
        printf("| %s", tunjuk->kontainer.rolPem);
        if(strlen(tunjuk->kontainer.rolPem) < role){
            for(int i = 0; i < (role - strlen(tunjuk->kontainer.rolPem)); i++){
                printf(" ");
            }
        }
        printf("| %d", tunjuk->kontainer.comScor);
        if(digLeng(tunjuk->kontainer.comScor) < score){
            for(int i = 0; i < (score - digLeng(tunjuk->kontainer.comScor)); i++){
                printf(" ");
            }
        }
        printf("|\n");
        
        tunjuk = tunjuk->next;
    }
    printf("+-----------+------------------+-----------------+\n");
    tunjuk = NULL;
}