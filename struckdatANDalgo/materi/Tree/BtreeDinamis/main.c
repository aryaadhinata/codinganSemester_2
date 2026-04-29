#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
    char konten;
}nilai;

typedef struct smp *alamatSimpul;
typedef struct smp{
    nilai kontainer;
    alamatSimpul right;
    alamatSimpul left;
}simpul;

typedef struct{
    simpul* root;
}tree;

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
        printf(" %c ", root->kontainer.konten);
        printTreePreOrder(root->left);
        printTreePreOrder(root->right);
    }
}

void printTreeInOrder(simpul *root){
    if(root != NULL){
        printTreeInOrder(root->left);
        printf(" %c ", root->kontainer.konten);
        printTreeInOrder(root->right);
    }
}

void printTreePostOrder(simpul *root){
    if(root != NULL){
        printTreePostOrder(root->left);
        printTreePostOrder(root->right);
        printf(" %c ", root->kontainer.konten);
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

int main(){
    tree T;
    nilai temp;
    temp.konten = 'A';
    makeTree(temp, &T);
    temp.konten = 'B';
    addLeft(temp, T.root);
    temp.konten = 'C';
    addRight(temp, T.root);
    temp.konten = 'D';
    addLeft(temp, T.root->left);
    temp.konten = 'E';
    addRight(temp, T.root->left);
    temp.konten = 'F';
    addRight(temp, T.root->right);

    printf("=================\n");
    printf("preOrder\n");
    printTreePreOrder(T.root);
    printf("\n=================\n");
    printf("inOrder\n");
    printTreeInOrder(T.root);
    printf("\n=================\n");
    printf("postOrder\n");
    printTreePostOrder(T.root);
    printf("\n=================\n");

    tree T2;
    if(isEqual(T.root, T2.root) == 1){
    printf("pohon sama\n");
    }
    else{
    printf("pohon tidak sama\n");
    }

    delRight(T.root->left);
    delLeft(T.root->left);
    printf("=================\n");
    printf("preOrder setelah dihapus\n");
    printTreePreOrder(T.root);
    printf("\n=================\n");
    return 0;
}