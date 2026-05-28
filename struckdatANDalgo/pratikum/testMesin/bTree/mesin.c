#include "head.h"

void makeTree(nilai temp, tree *T){
    simpul* baru;
    baru = (simpul *) malloc (sizeof(simpul));
    baru->kontainer = temp;
    
    baru->right = NULL;
    baru->left = NULL;
    (*T).root = baru;
    baru = NULL;
}

void addRight(nilai temp, simpul *root){
    if(root->right == NULL){
        simpul *baru;
        baru = (simpul *) malloc (sizeof(simpul));
        baru->kontainer = temp;
        baru->right = NULL;
        baru->left = NULL;
        root->right = baru;
    }else{
        printf("sub pohon kanan telah terisi\n");
    }
}

void addLeft(nilai temp, simpul *root){
    if(root->left == NULL){
        simpul *baru;
        baru = (simpul *) malloc (sizeof(simpul));
        baru->kontainer = temp;
        baru->right = NULL;
        baru->left = NULL;
        root->left = baru;
    }else{
        printf("sub pohon kiri telah terisi\n");
    }
}

void delAll(simpul *root){
    if(root != NULL){
        delAll(root->left);
        delAll(root->right);
        free(root);
    }
}

void delRight(simpul *root){
    if(root != NULL){
        if(root->right != NULL){
            delAll(root->right);
            root->right = NULL;
        }
    }
}

void delLeft(simpul *root){
    if(root != NULL){
        if(root->left != NULL){
            delAll(root->left);
            root->left = NULL;
        }
    }
}

void printTreePreOrder(simpul *root){
    if(root != NULL){
        printf("%c", root->kontainer.konten);
        if(root->left != NULL){
            printf("-");
        }
        printTreePreOrder(root->left);
        if(root->right != NULL){
            printf("-");
        }
        printTreePreOrder(root->right);
    }
}

void printTreeInOrder(simpul *root){
    if(root != NULL){
        printTreeInOrder(root->left);
        if(root->left != NULL){
            printf("-");
        }
        printf("%c", root->kontainer.konten);
        if(root->right != NULL){
            printf("-");
        }
        printTreeInOrder(root->right);
    }
}

void printTreePostOrder(simpul *root){
    if(root != NULL){
        printTreePostOrder(root->left);
        if(root->left != NULL){
            printf("-");
        }
        printTreePostOrder(root->right);
        if(root->right != NULL){
            printf("-");
        }
        printf("%c", root->kontainer.konten);
        
        
    }
}

int isEqual(simpul *root1, simpul *root2){
    int hasil = 1;

    if((root1 != NULL) && (root2 != NULL)){
        // ini nanti menyesuaikan isi dari kotennya 
        if(root1->kontainer.konten != root2->kontainer.konten){
            hasil = 0;
        }else{
            isEqual(root1->left, root2->left);
            isEqual(root1->right, root2->right);
        }
    }else{
        if((root1 != NULL) || root2 != NULL){
            hasil = 0;
        }
    }

    return hasil;
}