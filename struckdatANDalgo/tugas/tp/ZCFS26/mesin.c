#include "head.h"

int indeks;
int panjangKata;
char cw[65];

void STARTWORD(char pita[]){
    indeks = 0;
    panjangKata = 0;
    while(pita[indeks] == ' '){
        indeks++;
    }

    while((pita[indeks] != ' ') && (pita[indeks] != ';')){
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
    while(pita[indeks] == ' '){
        indeks++;
    }
    
    while((pita[indeks] != ' ') && (pita[indeks] != ';')){
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
    if(pita[indeks] == ';'){
        return 1;
    }else{
        return 0;
    }
}

// membuat tree harus ada isinya langsung
void makeTree(nilai temp, tree *T){
    simpul *node;
    node = (simpul *) malloc (sizeof (simpul));
    node->kontainer = temp; // mengisi isi dari node di treenya
    // membuat bagian sibling dan child jadi NULL agar bisa di sambungkan nanti
    node->sibling = NULL;
    node->child = NULL;
    // jadi yang bisa kita akses adalah rootnya
    (*T).root = node;
}

void addChild(nilai temp, simpul *root){
    if(root != NULL){
        simpul *baru;
        baru = (simpul *) malloc (sizeof (simpul));
        baru->kontainer = temp;
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

void delChild(nilai temp, simpul *root){
    if(root != NULL){
        simpul *hapus = root->child;
        if(hapus != NULL){
            if(hapus->sibling == NULL){
                // jika ada banyak struck maka bandingkan semuanya
                if(strcmp(root->child->kontainer.node, temp.node) == 0){
                    delAll(root->child);
                    root->child = NULL;
                }else{
                    printf("tidak ada kontainer dengan yang sama dengan masukan\n");
                }
            }else{
                simpul *prev = NULL;
                int ketemu = 0;
                
                while((hapus->sibling != root->child) && (ketemu == 0)){
                    // jika ada banyak struck maka bandingkan semuanya
                    if(strcmp(hapus->kontainer.node, temp.node) == 0){
                        ketemu = 1;
                    }else{
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }
                
                // jika ada banyak struck maka bandingkan semuanya
                if((ketemu == 0) && (strcmp(hapus->kontainer.node, temp.node) == 0)){
                    ketemu = 1;
                }

                if(ketemu == 1){
                    simpul *last = root->child;
                    
                    while(last->sibling != root->child){                    
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
                    delAll(hapus);
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
        // jika ada banyak struck maka bandingkan semuanya
        if(strcmp(root->kontainer.node, temp)){
            hasil = root;
        }else{
            simpul *bantu = root->child;
            if(bantu != NULL){
                if(bantu->sibling == NULL){
                    // jika ada banyak struck maka bandingkan semuanya
                    if(strcmp(bantu->kontainer.node, temp)){
                        hasil = bantu;
                    }else{
                        hasil = findSimpul(temp, bantu);
                    }
                }else{
                    int ketemu = 0;
                    while((bantu->sibling != root->child) && (ketemu == 0)){
                        // jika ada banyak struck maka bandingkan semuanya
                        if(strcmp(bantu->kontainer.node, temp)){
                            hasil = bantu;
                            ketemu = 1;
                        }else{
                            hasil = findSimpul(temp, bantu);
                            bantu = bantu->sibling;
                            return hasil;
                        }
                    }

                    if(ketemu == 0){
                        // jika ada banyak struck maka bandingkan semuanya
                        if(strcmp(bantu->kontainer.node, temp)){
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

void printTreePreOrder(simpul *root){
    if(root != NULL){
        printf("%s ", root->kontainer.node);
        simpul *bantu = root->child;
        if(bantu != NULL){
            if(bantu->sibling == NULL){
                printTreePreOrder(bantu);
            }else{
                while(bantu->sibling != root->child){
                    printTreePreOrder(bantu);
                    bantu = bantu->sibling;
                }
                printTreePreOrder(bantu);
            }
        }
    }
}

void printTreePostOrder(simpul *root){
    if(root != NULL){
        simpul *bantu = root->child;
        
        if(bantu != NULL){
            if(bantu->sibling == NULL){
                printTreePostOrder(bantu);
            }else{
                while(bantu->sibling != root->child){
                    printTreePostOrder(bantu);
                    bantu = bantu->sibling;
                }

                printTreePostOrder(bantu);
            }
        }
        printf("%s ", root->kontainer.node);
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