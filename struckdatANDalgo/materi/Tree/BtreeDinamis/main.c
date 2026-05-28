#include "head.h"

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