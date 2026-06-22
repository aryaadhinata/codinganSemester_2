#include "head.h"

int indeks;
int panjangKata;
char cw[65];

void STARTWORD(char pita[]){
    indeks = 0;
    panjangKata = 0;
    while(pita[indeks] == '#'){
        indeks++;
    }

    while((pita[indeks] != '#') && (pita[indeks] != ' ')){
        cw[panjangKata] = pita[indeks];
        indeks++;
        panjangKata++;
    }
    
    cw[panjangKata] = '\0';
}

void RESETWORD(){
    panjangKata = 0;
    cw[panjangKata] = '\0';
}


void INCWORD(char pita[]){
    panjangKata = 0;
    while(pita[indeks] == '#'){
        indeks++;
    }
    
    while((pita[indeks] != '#') && (pita[indeks] != ' ')){
        cw[panjangKata] = pita[indeks];
        indeks++;
        panjangKata++;
    }
    
    cw[panjangKata] = '\0';
}

char* GETWORD(){
    return cw;
}

int GETPANJANGKATA(){
    return panjangKata;
}

int EOPWORD(char pita[]){
    if(pita[indeks] == ' '){
        return 1;
    }else{
        return 0;
    }
}

void makeTree(nilai temp, tree *T){
    simpul *node;
    node = (simpul *) malloc (sizeof (simpul));
    node->kontainer = temp;
    // set awal
    node->kontainer.layer = 0;
    node->kontainer.visit = 0;
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

void addChild(nilai temp, simpul *root){
    if(root != NULL){
        simpul *baru;
        baru = (simpul *) malloc (sizeof (simpul));
        baru->kontainer = temp;
        // set awal
        baru->kontainer.layer = root->kontainer.layer + 1;
        baru->kontainer.visit = 0;
        baru->child = NULL;

        if(root->child == NULL){
            baru->sibling = NULL;
            root->child = baru;
        }else{
            if(root->child->sibling == NULL){
                baru->sibling = root->child;
                root->child->sibling = baru;
            }else{
                simpul *last = root->child;
                while(last->sibling != root->child){
                    last = last->sibling;
                }
                baru->sibling = root->child;
                last->sibling = baru;
            }
        }
    }
}

void delAll(simpul *root){
    if(root != NULL){
        if(root->child != NULL){
            if(root->child->sibling == NULL){
                delAll(root->child);
                free(root);
            }else{
                simpul *bantu;
                simpul *proses;
                bantu = root->child;

                while(bantu->sibling != root->child){
                    proses = bantu;
                    bantu = bantu->sibling;
                    delAll(proses);
                }

                if(bantu != NULL){
                    delAll(bantu);
                }
                free(root);
            }
        }
    }else{
        free(root);
    }
}

void delChild(simpul *root){
    if(root != NULL){
        simpul *hapus = root->child;
        if(hapus != NULL){
            if(hapus->sibling == NULL){
                if(root->child->kontainer.visit == 0){ // cuma hapus yang nggak di visit
                    delAll(root->child);
                    root->child = NULL;
                }else{
                    // printf("tidak ada kontainer dengan yang sama dengan masukan\n");
                }
            }else{
                simpul *prev = NULL;
                int ketemu = 0;
                
                while((hapus->sibling != root->child) && (ketemu == 0)){
                    if(hapus->kontainer.visit == 0){ // yang ngak di visit yang di hapus
                        ketemu = 1;
                    }else{
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }
                
                if((ketemu == 0) && (hapus->kontainer.visit == 0)){ // hapus nggak di visit
                    ketemu = 1;
                }

                if(ketemu == 1){
                    simpul *last = root->child;
                    
                    while((last->sibling != root->child) && (last->sibling != NULL)){                    
                        last = last->sibling;   
                    }

                    if(prev == NULL){
                        if((hapus->sibling == last) && (last->sibling == root->child)){
                            root->child = last;
                            last->sibling = NULL;
                        }else{
                            root->child = hapus->sibling;
                            last->sibling = root->child;
                        }
                    }else{
                        if((prev == root->child) && (hapus->sibling == root->child)){
                            root->child->sibling = NULL;
                        }else{
                            prev->sibling = hapus->sibling;
                            hapus->sibling = NULL;
                        }
                    }
                    if(hapus->kontainer.visit == 0){ // nggak visit?? hapus
                        delAll(hapus);
                    }
                }else{
                    printf("tidak ada simpul anak yang sama dengan kontainer masukan\n");
                }   
            }
        }
    }
}

simpul* findSimpul(char temp[], simpul *root){
    simpul *hasil = NULL;
    if(root != NULL){
        if(strcmp(root->kontainer.node, temp) == 0){
            hasil = root;
        }else{
            simpul *bantu = root->child;
            if(bantu != NULL){
                if(bantu->sibling == NULL){
                    if(strcmp(bantu->kontainer.node, temp) == 0){
                        hasil = bantu;
                    }else{
                        hasil = findSimpul(temp, bantu);
                    }
                }else{
                    int ketemu = 0;
                    while((bantu->sibling != root->child) && (ketemu == 0)){
                        if(strcmp(bantu->kontainer.node, temp) == 0){
                            hasil = bantu;
                            ketemu = 1;
                        }else{
                            hasil = findSimpul(temp, bantu);
                            if(hasil != NULL){
                                return hasil;
                            }
                            bantu = bantu->sibling;
                        }
                    }

                    if(ketemu == 0){
                        if(strcmp(bantu->kontainer.node, temp) == 0){
                            hasil = bantu;
                        }else{
                            hasil = findSimpul(temp, bantu);
                        }
                    }
                }
            }
        }
    }
    return hasil;
}

// rekursif cari nilai yang paling gede kalo ketemuu simpen dan return konsepnya kayak post-order
int countLayer(simpul *root){    
    if(root != NULL){
        int maxLayer = root->kontainer.layer; // yang jadi batas terbesar sekarang
        int bandingLayer; // buat nanti ada yang bisa di banding, yang di rekursif sama yang sekarang
        
        simpul *bantu = root->child;
        if(bantu != NULL){
            if(bantu != NULL){
                if(bantu->sibling == NULL){
                    bandingLayer = countLayer(bantu); // isi banding secara rekursif nanti jadi dari bawah ke atas
                    if(bandingLayer > maxLayer){ // bandingin simpen yang gede
                        maxLayer = bandingLayer;
                    }
                }else{
                    while(bantu->sibling != root->child){
                        bandingLayer = countLayer(bantu); // sama di banding, DFS masuk->balik
                        if(bandingLayer > maxLayer){ // simpen yang gede
                            maxLayer = bandingLayer;
                        }
                        bantu = bantu->sibling;
                    }
                }
            }
        }
        return maxLayer; // balikin yang paling gede
    }
}

// sama seperti countLayer cuma di ubah dikit
int cariSpasi(int layer, simpul *root){
    if(root != NULL){
        int maxSpasi = 0;
        if(root->kontainer.layer == layer){
            maxSpasi = strlen(root->kontainer.node) + countDigit(root->kontainer.poin) + 3; // ini panjang di nama node + point + spasinya
            for(int i = 0; i < root->kontainer.banyakPeluang; i++){
                if(maxSpasi < strlen(root->kontainer.peluang[i]) + 2){ // bandingin sama poin yang ada di dalam nodenya simpan yang besar
                    maxSpasi = strlen(root->kontainer.peluang[i]) + 2;
                }
            }
        }
        int bandingSpasi; // yh buat di bandingin kayak sebelumnya di countLayer
        simpul *bantu = root->child;
        if(bantu != NULL){
            if(bantu->sibling == NULL){
                bandingSpasi = cariSpasi(layer, bantu); // masuk kedalem dulu jadi nilainya nanti kayak ngeback
                if(((bandingSpasi > maxSpasi) && (bantu->kontainer.layer == layer)) || (maxSpasi == 0)){ // layernya harus sama kalo di bandingin dan simpen kalo emang lebih gede
                    maxSpasi = bandingSpasi;
                }
            }else{
                do{
                    bandingSpasi = cariSpasi(layer, bantu);
                    if(((bandingSpasi > maxSpasi) && (bantu->kontainer.layer == layer)) || (maxSpasi == 0)){ // layer sama, simpen yang paling gede
                        maxSpasi = bandingSpasi;
                    }
                    bantu = bantu->sibling;
                }while(bantu != root->child);
            }
        }
        return maxSpasi; // ini yang paling gede di iterasi rekursif itu
    }
}

// sama kayak sebelum sebelumnya masuk kedalem dulu baru naik nanti si valuenya buat di banding kalo nggak ada ya cek sodaranya masuk lagi terus balik
simpul *findPeluang(char temp[], simpul *root){
    simpul *hasil = NULL; // nilai awal
    if(root != NULL){ 
        if(strcmp(root->kontainer.node, temp) == 0){ // udh ketemu blom kalo udh tandain terus langsung return si hasil
            root->kontainer.visit = 1;
            hasil = root;
            return hasil;
        }
        if(root->child != NULL){
            simpul *bantu = root->child;
            if(bantu != NULL){
                do{ // kenapa pake do karena kan pas masuk bantu == root->child jadi biar maju aja dulu
                    hasil = findPeluang(temp, bantu); // kedalem baru keluar
                    if(hasil != NULL){ // kalo ada tandain terus return
                        root->kontainer.visit = 1;  
                        while((bantu->kontainer.visit != 1) && (bantu!= root->child)){
                            bantu = bantu->sibling;
                        }
                        root->child = bantu;
                        return hasil;
                    }
                    
                    bantu = bantu->sibling; // cek sodaranya sekalian
                }while((bantu != root->child) && (bantu != NULL));
            }
        }
    }
    return hasil; // ini kalo nggak ketemu harusnya null di sini
}

// rekursif setiap layer kalo anaknya nggak ada yang di visit langsung hapus, kalo ada masuk lagi buat cek sodaranya
void hapusTidakVisit(simpul *root){
    if(root != NULL){
        if(root->kontainer.visit == 0){ // kalo nggak di visit langsung haous aja
            delChild(root);
        }
        simpul *bantu = root->child;
        if(bantu != NULL){
            do{ // kenapa pake do karena kan pas masuk bantu == root->child jadi biar maju aja dulu
                hapusTidakVisit(bantu); // sisa yang di visit cek ulang anak anaknya
                simpul *next = bantu->sibling; // simpen dulu takut ke hapus
                // printf(" - %s",bantu->kontainer.node);
                if(bantu->kontainer.visit == 0){ // anaknya ada yang nggak di visit hapus
                    // if(next->kontainer.visit == 1){
                    // }
                    // printf(" xX%sXx ", root->kontainer.node);
                    delChild(root); // karena root parentnya yang hapus anaknya
                }
                bantu = next; // jaid aman kalo si bantu->siblingnya di hapus
                // printf(" | %s\n",bantu->kontainer.node);
            }while((bantu != root->child) && (bantu != NULL));
        }
    }
}

// yah selayaknya pre order print dulu baru masuk ke dalem di ubah buat di sesuakan dengan yang di inginkan
void printTreePreOrder(int spasi[], int banyakLayer, simpul *root){
    if(root != NULL){
        for(int i = 0; i <= banyakLayer; i++){
            if(i == root->kontainer.layer){
                for(int j = 0; j < spasi[i]; j++){
                    printf(" ");
                }
            }
        }
        printf("%s - %d\n", root->kontainer.node, root->kontainer.poin);
        for(int i = 0; i < root->kontainer.banyakPeluang; i++){
            for(int j = 0; j <= banyakLayer; j++){
                if(j == root->kontainer.layer){
                    for(int k = 0; k < spasi[j]; k++){
                        printf(" ");
                    }
                }
            }
            printf("[%s]\n", root->kontainer.peluang[i]);
        }
        printf("\n");
        simpul *bantu = root->child;
        if(bantu != NULL){
            if(bantu->sibling == NULL){
                printTreePreOrder(spasi, banyakLayer, bantu);
            }else{
                while(bantu->sibling != root->child){
                    printTreePreOrder(spasi, banyakLayer, bantu);
                    bantu = bantu->sibling;
                }
                printTreePreOrder(spasi, banyakLayer, bantu);
            }
        }
    }
}

// terimakasih postOrder jadi kepikiran masuk dulu baru banding terus di balikin lagi
void printTreePostOrder(int spasi[], int banyakLayer, simpul *root){
    if(root != NULL){
        simpul *bantu = root->child;
        
        if(bantu != NULL){
            if(bantu->sibling == NULL){
                printTreePostOrder(spasi, banyakLayer, bantu);
            }else{
                while(bantu->sibling != root->child){
                    printTreePostOrder(spasi, banyakLayer, bantu);
                    bantu = bantu->sibling;
                }
                printTreePostOrder(spasi, banyakLayer, bantu);
            }
        }
        for(int i = 0; i < banyakLayer + 1; i++){
            if(i == root->kontainer.layer){
                for(int j = 0; j < spasi[i]; j++){
                    printf(" ");
                }
            }
        }
        printf("%s - %d [%d]\n", root->kontainer.node, root->kontainer.poin, root->kontainer.visit);
        for(int i = 0; i < root->kontainer.banyakPeluang; i++){
            for(int j = 0; j < banyakLayer + 1; j++){
                if(j == root->kontainer.layer){
                    for(int k = 0; k < spasi[j]; k++){
                        printf(" ");
                    }
                }
            }
            printf("[%s] \n", root->kontainer.peluang[i]);
        }
        printf("\n");
    }
}

// hitunh poin yang ada di tree sekarang yah sama juga masuk dulu baru di count dari bawah
int countPoin(int hasil, simpul *root){
    int simpan = root->kontainer.poin;
    if(root != NULL){
        simpul *bantu = root->child;
        if(bantu != NULL){
            if(bantu->sibling == NULL){
                simpan += countPoin(hasil, bantu);
            }else{
                while(bantu->sibling != root->child){
                    simpan += countPoin(hasil, bantu);
                    bantu = bantu->sibling;
                }
                simpan += countPoin(hasil, bantu);
            }
        }
    }
    return simpan;
}

// ini print preorder tapi cuma peluangnya aja
void printPeluang(simpul *root){
    if(root != NULL){
    for(int i = 0; i < root->kontainer.banyakPeluang; i++){
        printf("[%s]\n", root->kontainer.peluang[i]);
    }
    simpul *bantu = root->child;
        if(bantu != NULL){
            if(bantu->sibling == NULL){
                printPeluang(bantu);
            }else{
                while(bantu->sibling != root->child){
                    printPeluang(bantu);
                    bantu = bantu->sibling;
                }
                printPeluang(bantu);
            }
        }
    }
}

// ini konversinya biar si poin bisa di jumlahin yah konsep basis 10 kan gitu konutasinya kan a * 10^n + b *10^n-1
// semisal 12 = 1 * 10^1 + 2 * 10^0
int convers(char str[]){
    int digit = strlen(str);
    int simpan[digit];

    for(int i = 0; i < digit; i++){
        switch(str[i]){
            case '1':{
                simpan[i] = 1 * pow(10, (digit-1)-i);
                break;
            }
            case '2':{
                simpan[i] = 2 * pow(10, (digit-1)-i);
                break;
            }
            case '3':{
                simpan[i] = 3 * pow(10, (digit-1)-i);
                break;
            }
            case '4':{
                simpan[i] = 4 * pow(10, (digit-1)-i);
                break;
            }
            case '5':{
                simpan[i] = 5 * pow(10, (digit-1)-i);
                break;
            }
            case '6':{
                simpan[i] = 6 * pow(10, (digit-1)-i);
                break;
            }
            case '7':{
                simpan[i] = 7 * pow(10, (digit-1)-i);
                break;
            }
            case '8':{
                simpan[i] = 8 * pow(10, (digit-1)-i);
                break;
            }
            case '9':{
                simpan[i] = 9 * pow(10, (digit-1)-i);
                break;
            }
            default :{
                simpan[i] = 0;
                break;
            }
        }
    }

    // jumlahin semua yang udh di simpen di array
    int hasil = 0;
    for(int i = 0; i < digit; i++){
        hasil += simpan[i];
    }

    return hasil;
}

// hitung banyak digitnya buat poin juga sih, ngehitung banyak spasi yang diperluin
// sesuai sama konsep sebelumnya tapi sekarang di bagi karena di balik
// semisal 12 :
//  12/10  = 2
//  2/10 = 0
// karena ada duakali pembagian sepuluh ya berarti
int countDigit(int n){
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

// int isEqual(simpul *root1, simpul *root2){ // nggak jalan
//     int hasil = 1;
//     if((root1 != NULL) && (root2 != NULL)){
//         // jika ada banyak struck maka bandingkan semuanya
//         if(root1->kontainer.str != root2->kontainer.str){
//             hasil = 0;
//         }else{
//             if((root1->child != NULL) && (root2->child != NULL)){
//                 if(root1->child->sibling == NULL){
//                     hasil = isEqual(root1->child, root2->child);
//                 }else{
//                     simpul *bantu1 = root1->child;
//                     simpul *bantu2 = root2->child;

//                     while(bantu1->sibling != root1->sibling){
//                         if((bantu1 != NULL) && bantu2 != NULL){
//                             hasil = isEqual(bantu1, bantu2);
//                             bantu1 = bantu1->sibling;
//                             bantu2 = bantu2->sibling;
//                         }else{
//                             hasil = 0;
//                             break;
//                         }
//                     }
//                     hasil = isEqual(bantu1, bantu2);
//                 }
//             }
//         }
//     }else{
//         if((root1 != NULL) && (root2 != NULL)){
//             hasil = 0;
//         }
//     }

//     return hasil;
// }