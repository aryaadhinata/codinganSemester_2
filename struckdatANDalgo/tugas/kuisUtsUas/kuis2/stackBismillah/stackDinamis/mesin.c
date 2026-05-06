#include "head.h"

void createEmpty(stack *S){
    (*S).top = NULL;
}

int isEmpty(stack S){
    int hasil = 0;
    if(S.top == NULL){
        hasil = 1;
    }
    return hasil;
}

int countElement(stack S){
    int hasil = 0;

    if(S.top != NULL){
        /* stack tidak kosong */

        elemen* bantu;

        /* inisialisasi */
        bantu = S.top;

        while(bantu != NULL){
            /* proses */
            hasil= hasil + 1;
            /* iterasi */
            bantu = bantu->next;
            }
        }
    return hasil;
}

void push(nilai temp, stack *S ){
    elemen* baru;
    baru = (elemen *) malloc (sizeof (elemen));
    baru->kontainer = temp;
    if((*S).top == NULL){
        //jika stack kosong
        baru->next = NULL;
    }else{
        //jika stack tidak kosong
        baru->next = (*S).top;
    }
    (*S).top = baru;
    baru = NULL;
}

void pop(stack *S){
    if((*S).top != NULL){
        /*jika stack bukan list kosong*/
        elemen *hapus = (*S).top;
        
        if(countElement(*S) == 1){
            (*S).top = NULL;
        }else{
            (*S).top = (*S).top->next;
        }
        hapus->next = NULL;
        free(hapus);
    }else{
        // printf("stack kosong");
    }
}

void popTo(elemen* pindah, stack *S, stack *T){
    if(pindah == (*S).top){ // kalo ada di atas
        S->top = S->top->next; // urus stack pertama
        pindah->next = T->top; // pindahkan
        T->top = pindah;
    }else{ // nggak di atas
        elemen *prev = (*S).top;
        while(prev->next != pindah){ // cari pointer sebelumnya
            prev = prev->next;
        }

        if(pindah->next == NULL){ // jika setelah yang di pindah nggak ada lagi
            prev->next = NULL;
        }else{
            prev->next = pindah->next;
        }
        //pindahkan
        pindah->next = T->top;
        T->top = pindah;
        // printf("stek is emti\n");
    }
}

int sumScore(elemen* S){ // untuk menghitung rerata scorenya
    int hasil = S->kontainer.skorKompe + S->kontainer.skorBah +
                S->kontainer.hardSkill + S->kontainer.teswan;
    hasil = (int) hasil/4;
    return hasil;
}

void move(int batas, stack *S, stack *T, stack *U){ // untuk memindahkan stacknya
    elemen* bantu = (*S).top;
    while(bantu != NULL){
        if(sumScore(bantu) <= batas){ // jika sesuai dengan syrat lakukan
            popTo(bantu, S, T);
            bantu = S->top; // karena sekara s->top sudah berubah gunakan s->top yang baru
        }else{
            bantu = bantu->next;
        }
    }

    // karena katanya kebalik ywdah di balikin aja
    bantu = (*S).top;
    if(S->top != NULL){
        while(bantu != NULL){
            push(bantu->kontainer, U);
            bantu = bantu->next;
        }
    }
}

void printStack(stack S){
    printf("stack Utama:\n");
    if(S.top != NULL){
        elemen* bantu = S.top;

        while(bantu != NULL){
            printf("%s %s %d %d %d %d\n", bantu->kontainer.id, bantu->kontainer.nama, bantu->kontainer.skorKompe, bantu->kontainer.skorBah, bantu->kontainer.hardSkill, bantu->kontainer.teswan);
            bantu = bantu->next;   
        }
    }else{
        /* proses jika stack kosong */
        // printf("stack kosong\n");
    }
}

void printStackDua(stack S, stack T){
    printf("\nstack Negara A:\n");
    if(S.top != NULL){
        elemen* bantu = S.top;
    
        while(bantu != NULL){
            printf("%s %s %d %d %d %d\n", bantu->kontainer.id, bantu->kontainer.nama, bantu->kontainer.skorKompe, bantu->kontainer.skorBah, bantu->kontainer.hardSkill, bantu->kontainer.teswan);
            bantu = bantu->next;   
        }
    }else{
        printf("kosong\n");
    }
    
    printf("\nstack Negara B:\n");
    if(T.top != NULL){
        elemen* bantu = T.top;
        
        while(bantu != NULL){
            printf("%s %s %d %d %d %d\n", bantu->kontainer.id, bantu->kontainer.nama, bantu->kontainer.skorKompe, bantu->kontainer.skorBah, bantu->kontainer.hardSkill, bantu->kontainer.teswan);
            bantu = bantu->next;   
        }
    }else{
        printf("kosong\n");
    }
}