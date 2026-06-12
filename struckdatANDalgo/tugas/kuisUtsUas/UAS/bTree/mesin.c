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

void cariAkar(char posisi[], char namaParent[], nilai temp, simpul *root){
    // int stop = 0;
    if(strcmp(root->kontainer.namaSimpul, namaParent) == 0){
        // printf("%s\n", root->kontainer.namaSimpul);
        if(strcmp(posisi, "kanan") == 0){
            // stop = 1;
            addRight(temp, root);
        }else if(strcmp(posisi, "kiri") == 0){
            // stop = 1;
            addLeft(temp, root);
        }
    }else{
        // printf("%d", stop);
        if((strcmp(root->kontainer.namaSimpul, namaParent) != 0) && ((root->left != NULL))){
            cariAkar(posisi, namaParent, temp, root->left);
        }
        if((strcmp(root->kontainer.namaSimpul, namaParent) != 0) && (root->right != NULL)){
            cariAkar(posisi, namaParent, temp, root->right);
        }
    }
}

void cariAnak(int *countParent, int *sumTotal, simpul *root){
    // printf("%s - %d - %d\n", root->kontainer.namaSimpul, *countParent, *sumTotal);
    if(((root->left != NULL) && (root->right != NULL)) && (((root->left->left == NULL) && (root->left->right == NULL)) && ((root->right->left == NULL) && (root->right->right == NULL)))){
        *countParent = *countParent + 1;
        *sumTotal = *sumTotal + root->kontainer.bawaan;
        *sumTotal = *sumTotal + root->left->kontainer.bawaan;
        *sumTotal = *sumTotal + root->right->kontainer.bawaan;
    }else{
        if((root->left != NULL) && ((root->left->left == NULL) && (root->left->right == NULL))){
            *countParent = *countParent + 1;
            *sumTotal = *sumTotal + root->kontainer.bawaan;
            *sumTotal = *sumTotal + root->left->kontainer.bawaan;
        }
        if((root->right != NULL) && ((root->right->left == NULL) && (root->right->right == NULL))){
            *countParent = *countParent + 1;
            *sumTotal = *sumTotal + root->kontainer.bawaan;
            *sumTotal = *sumTotal + root->right->kontainer.bawaan;
        }
    }

    if(root->left != NULL){
        cariAnak(countParent, sumTotal, root->left);
    }
    if(root->right != NULL){
        cariAnak(countParent, sumTotal, root->right);
    }
}

void printTreePreOrder(simpul *root){
    if(root != NULL){
        // printf("%c", root->kontainer.konten);
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
        printf("%s", root->kontainer.namaSimpul);
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
        // printf("%c", root->kontainer.konten);
        
        
    }
}

// int isEqual(simpul *root1, simpul *root2){
//     int hasil = 1;

//     if((root1 != NULL) && (root2 != NULL)){
//         // ini nanti menyesuaikan isi dari kotennya 
//         if(root1->kontainer.konten != root2->kontainer.konten){
//             hasil = 0;
//         }else{
//             isEqual(root1->left, root2->left);
//             isEqual(root1->right, root2->right);
//         }
//     }else{
//         if((root1 != NULL) || root2 != NULL){
//             hasil = 0;
//         }
//     }

//     return hasil;
// }