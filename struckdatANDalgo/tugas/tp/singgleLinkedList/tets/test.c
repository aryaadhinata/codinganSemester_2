#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
    char namPem[33], rolPem[33];
    int comScor;
}nilai;

typedef struct elmt* alamatelmt;
typedef struct elmt{
    nilai kontainer;
    alamatelmt next;
} elemen;

typedef struct{
    elemen* first;
}list;

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

void swap(list *L, elemen *prefP, elemen *p, elemen *q){
    if(p == L->first){
        L->first = q;
    }else{
        prefP->next = q;
    }

    p->next = q->next;
    q->next = p;
}

void sort(int kead[], list *L){
    elemen *prefP, *p, *q;
    int loop;
    do{
        loop = 0;

        p = L->first;
        prefP = NULL;
        q = p->next;
        while(q != NULL){
            int iter = 0;
            if(kead[0] == 1){ // score
                if(kead[1] == 1){ // ascending
                    if(p->kontainer.comScor > q->kontainer.comScor){
                        swap(L, prefP, p, q);
                        iter = 1;
                        loop = 1;
                    }
                }else if(kead[1] == 2){ // decending
                    if(p->kontainer.comScor < q->kontainer.comScor){
                        swap(L, prefP, p, q);
                        iter = 1;
                        loop = 1;
                    }
                }
            }else if(kead[0] == 2){ // nama
                if(kead[1] == 1){ // ascending
                    if(strcmp(p->kontainer.namPem, q->kontainer.namPem) > 0){
                        swap(L, prefP, p, q);
                        iter = 1;
                        loop = 1;
                    }
                }else if(kead[1] == 2){ // decending
                    if(strcmp(p->kontainer.namPem, q->kontainer.namPem) < 0){
                        swap(L, prefP, p, q);
                        iter = 1;
                        loop = 1;
                    }
                }
            }
            // bagian iterasi
            if(iter == 0){
                prefP = p;
                p = q;
                q = q->next;
            }else{
                prefP = q;
                q = p->next;
            }
        }
    }while(loop == 1);
    prefP = NULL;
    p = NULL;
    q = NULL;
}

void printElemen(list L){
    elemen *tunjuk = L.first;

    while(tunjuk != NULL){
        printf("%s\n", tunjuk->kontainer.namPem);
        tunjuk = tunjuk->next;
    }
}

int main() {
    list L1;
    nilai temp;
    createList(&L1);

    int bL1;

    scanf("%d", &bL1);
    for(int i = 0; i < bL1; i++){
        scanf("%s %s %d", temp.namPem, temp.rolPem, &temp.comScor);
        addLast(temp, &L1);
    }

    char keadTemp1[17];
    scanf("%s", keadTemp1);
    char keadTemp2[17];
    scanf("%s", keadTemp2);

    int kead[2];
    if(strcmp(keadTemp1, "score") == 0){
        kead[0] = 1;
        if(strcmp(keadTemp2, "ascending") == 0){
            kead[1] = 1;
        }else if(strcmp(keadTemp2, "descending") == 0){
            kead[1] = 2;
        }
    }else if(strcmp(keadTemp1, "nama") == 0){
        kead[0] = 2;
        if(strcmp(keadTemp2, "ascending") == 0){
            kead[1] = 1;
        }else if(strcmp(keadTemp2, "descending") == 0){
            kead[1] = 2;
        }
    }

    sort(kead, &L1);
    printElemen(L1);
    return 0;
}