#include <stdio.h>
#include <malloc.h>

typedef struct{
    char konten;
}nilai;

typedef struct smp *alamatSimpul;
typedef struct smp{
    nilai kontainer;
    alamatSimpul sibling;
    alamatSimpul child;
}simpul;

typedef struct{
    simpul *root;
}tree;

void makeTree(nilai temp, tree *T){
    simpul *node;
    node = (simpul *) malloc (sizeof (simpul));
    node->kontainer = temp;
    node->sibling = NULL;
    node->child = NULL;
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
                    delAll(proses);
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
                if(root->child->kontainer.konten == temp.konten){
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
                    if(hapus->kontainer.konten == temp.konten){
                        ketemu = 1;
                    }else{
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }
                
                // jika ada banyak struck maka bandingkan semuanya
                if((ketemu == 0) && (hapus->kontainer.konten == temp.konten)){
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

simpul* findSimpul(nilai temp, simpul *root){
    simpul *hasil = NULL;
    if(root != NULL){
        // jika ada banyak struck maka bandingkan semuanya
        if(root->kontainer.konten == temp.konten){
            hasil = root;
        }else{
            simpul *bantu = root->child;
            if(bantu != NULL){
                if(bantu->sibling == NULL){
                    // jika ada banyak struck maka bandingkan semuanya
                    if(bantu->kontainer.konten == temp.konten){
                        hasil = bantu;
                    }else{
                        hasil = findSimpul(temp, bantu);
                    }
                }else{
                    int ketemu = 0;
                    while((bantu->sibling != root->child) && (ketemu == 0)){
                        // jika ada banyak struck maka bandingkan semuanya
                        if(bantu->kontainer.konten == temp.konten){
                            hasil = bantu;
                            ketemu = 1;
                        }else{
                            hasil = findSimpul(temp, bantu);
                            bantu = bantu->sibling;
                        }
                    }

                    if(ketemu == 0){
                        // jika ada banyak struck maka bandingkan semuanya
                        if(bantu->kontainer.konten == temp.konten){
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
        printf(" %c ", root->kontainer.konten);
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
        printf(" %c ", root->kontainer.konten);
    }
}

int isEqual(simpul *root1, simpul *root2){
    int hasil = 1;
    if((root1 != NULL) && (root2 != NULL)){
        // jika ada banyak struck maka bandingkan semuanya
        if(root1->kontainer.konten != root2->kontainer.konten){
            hasil = 0;
        }else{
            if((root1->child != NULL) && (root2->child != NULL)){
                if(root1->child->sibling == NULL){
                    hasil = isEqual(root1->child, root2->child);
                }else{
                    simpul *bantu1 = root1->child;
                    simpul *bantu2 = root2->child;

                    while(bantu1->sibling != root1->sibling){
                        if((bantu1 != NULL) && bantu2 != NULL){
                            hasil = isEqual(bantu1, bantu2);
                            bantu1 = bantu1->sibling;
                            bantu2 = bantu2->sibling;
                        }else{
                            hasil = 0;
                            break;
                        }
                    }
                    hasil = isEqual(bantu1, bantu2);
                }
            }
        }
    }else{
        if((root1 != NULL) && (root2 != NULL)){
            hasil = 0;
        }
    }

    return hasil;
}

int main() {
    tree T;
    nilai temp;

    temp.konten = 'A';
    makeTree(temp, &T);
    temp.konten = 'B';
    addChild(temp, T.root);
    temp.konten = 'C';
    addChild(temp, T.root);
    temp.konten = 'D';
    addChild(temp, T.root);
    
    temp.konten = 'B';
    simpul *node = findSimpul(temp, T.root);
    if(node != NULL){
        temp.konten = 'E';
        addChild(temp, node);
        temp.konten = 'F';
        addChild(temp, node);
    }
    
    temp.konten = 'C';
    node = findSimpul(temp, T.root);
    if(node != NULL){
        temp.konten = 'G';
        addChild(temp, node);
    }
    
    temp.konten = 'D';
    node = findSimpul(temp, T.root);
    if(node != NULL){
        temp.konten = 'H';
        addChild(temp, node);
        temp.konten = 'I';
        addChild(temp, node);
        temp.konten = 'J';
        addChild(temp, node);
    }

    temp.konten = 'J';
    node = findSimpul(temp, T.root);
    if(node != NULL){
        temp.konten = 'K';
        addChild(temp, node);
        temp.konten = 'L';
        addChild(temp, node);
        temp.konten = 'M';
        addChild(temp, node);
    }
    
    printf("=================\n");
    printf("preOrder\n");
    printTreePreOrder(T.root);
    printf("\n=================\n");
    printf("postOrder\n");
    printTreePostOrder(T.root);
    printf("\n=================\n");
    
    tree T2;
    if(isEqual(T.root, T2.root) == 1){
        printf("pohon sama\n");
    }else{
        printf("pohon tidak sama\n");
    }
    
    temp.konten = 'J';
    node = findSimpul(temp, T.root);
    if(node != NULL){
        temp.konten = 'K';
        delChild(temp, node);
        temp.konten = 'L';
        delChild(temp, node);
        temp.konten = 'M';
        delChild(temp, node);
    }


    printf("=================\n");
    printf("preOrder setelah dihapus\n");
    printTreePreOrder(T.root);
    printf("\n=================\n");
    return 0;
}