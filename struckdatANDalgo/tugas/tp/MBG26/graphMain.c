#include "headGraph.h"

int main(){
    graph G;
    int banyak;
    scanf("%d", &banyak);
    nilai temp;
    char tujuan[65];
    int bobot;

    createEmpty(&G);
    simpul *cari;
    for(int i = 0; i < banyak; i++){
        scanf("%s %s %d", temp.namaSimpul, tujuan, &bobot);
        cari = findSimpul(temp.namaSimpul, G);
        if(cari == NULL){
            addSimpul(temp.namaSimpul, &G);
        }
        cari = findSimpul(tujuan, G);
        if(cari == NULL){
            addSimpul(tujuan, &G);
        }
        simpul *begin;
        simpul *end;
        begin = findSimpul(temp.namaSimpul, G);
        end = findSimpul(tujuan, G);
        addJalur(begin, end, bobot);
    }

    char begin[65], end[65];
    scanf("%s %s", begin, end);

    simpul *beginSearch = findSimpul(begin, G);
    simpul *endSearch = findSimpul(end, G);
    int uang;
    scanf("%d", &uang);
    
    int ceks = tandaiVisit(0, beginSearch, endSearch); // berarti ceks itu adalah berapa banyak jalur berbedanya
    tandaiDegre(beginSearch, endSearch);
    hapusTidakVisit(beginSearch); // ngebersihhin dulu dari simpul dan jalur yang nggak kepake
    
    int iter = 0, uangSimpan[ceks]; // nyimpen banyak itersi dan juga masing masing pengeluaran tiap perjalanan
    while(ceks != 0){ // kalo masih ada kombinasi lain lanjutin
        uangSimpan[iter] = printGraph(beginSearch, endSearch);
        refreshGraph(beginSearch, endSearch); // ngurangin yang udah ke visit
        hapusTidakVisit(beginSearch); // hapus biar bisa milih jalan yang berbeda
        iter++;
        ceks--;
    }
    
    printf("---\n");
    
    // nyari uang min buat perjalanan
    int uangMin = uangSimpan[0];
    if(iter > 1){
        for(int i = 1; i < iter; i++){
            if(uangMin > uangSimpan[i]){
                uangMin = uangSimpan[i];
            }
        }
    }

    if(uang - uangMin >= 0){
        printf("Lort Theo Bersykur Dompetnya Tidak Kering\n");
        printf("Sisa Uang: Rp. %d.\n", uang-uangMin);
    }else{
        printf("Lort Theo Harus Ngutang\n");
        printf("Sisa Uang: Rp. 0.\n");
    }

    return 0;
}