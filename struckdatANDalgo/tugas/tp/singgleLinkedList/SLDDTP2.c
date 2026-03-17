#include "heaad.h"

/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Pratikum 2 dalam 
	mata kuliah Struktur Data dan Algoritma untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

int main() {
    list L1, L2;
    nilai temp;
    createList(&L1);
    createList(&L2);

    int bL1, bL2;

    scanf("%d", &bL1);
    for(int i = 0; i < bL1; i++){
        scanf("%s %s %d", temp.namPem, temp.rolPem, &temp.comScor);
        addLast(temp, &L1);
    }
    
    scanf("%d", &bL2);
    for(int i = 0; i < bL2; i++){
        scanf("%s %s %d", temp.namPem, temp.rolPem, &temp.comScor);
        addLast(temp, &L2);
    }

    char keadTemp1[17];
    scanf("%s", keadTemp1);
    char keadTemp2[17];
    scanf("%s", keadTemp2);

    int kead[2];// keadaan atau spesifikasinya sengaja saya buat jadi array supaya tidak perlu di compare susah di dalam mesinya
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
    sort(kead, &L2);
    mergeList(kead, &L1, &L2);
    printElemen(L1);
    return 0;
}