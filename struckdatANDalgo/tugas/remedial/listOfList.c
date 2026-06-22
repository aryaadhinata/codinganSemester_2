#include "head.h"

int main(){
    list L;
    createList(&L);
    nilai tempB;
    nilaiSec tempK;
    
    int banPer;
    scanf("%d", &banPer);

    for(int i = 0; i < banPer; i++){
        scanf("%s %s", tempB.kodePer, tempB.perusahaan);
        addLastB(tempB, &L);
        int banBat;
        scanf("%d", &banBat);
        for(int j = 0; j < banBat; j++){
            scanf("%s %s %d %d %s", tempB.kodePer, tempK.obat, &tempK.bulan, &tempK.tahun, tempK.jenisObat);
            eBaris *cari = findBaris(tempB.kodePer, &L);
            addLastK(tempK, cari);
        }
    }

    int batasBulan, BatasTahun;
    scanf("%d %d", &batasBulan, &BatasTahun);

    strcpy(tempB.kodePer, "org");
    strcpy(tempB.perusahaan, "OrganisasiBerwenang");
    addLastB(tempB, &L);
    eBaris *cari = findBaris(tempB.kodePer, &L);
    // nggak jadi tadinya mau buat pindahin
    // eBaris* bantu = L.first;
    // while(bantu != cari){
    //     eKolom* help = bantu->col;
    //     while(help != NULL){
    //         if(help->kontainer_kol.tahun > BatasTahun){
    //             pindahElement(bantu, help, cari);
    //             // bantu = L.first;
    //             // help = bantu->col;
    //         }else if(help->kontainer_kol.tahun == BatasTahun){
    //             if(help->kontainer_kol.bulan >= batasBulan){
    //                 pindahElement(bantu, help, cari);
    //                 bantu = L.first;
    //                 help = bantu->col;
    //             }
    //         }
    //         help = help->next_kol;
    //     }
    //     bantu = bantu->next;
    // }

    printElementSesuai(L, cari, BatasTahun, batasBulan);
    printElementXSesuai(L, cari, BatasTahun, batasBulan);
    return 0;
}