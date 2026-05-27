#include "head.h"

int main() {
    tree T;
    nilai temp[13];
    
    for(int i = 0; i < 12; i++){
        scanf(" %s", &temp[i]);
    }
    
    makeTree(temp[0], &T);
    addChild(temp[1], T.root);
    addChild(temp[2], T.root);
    addChild(temp[3], T.root);
    addChild(temp[4], T.root->child);
    addChild(temp[5], T.root->child);
    addChild(temp[6], T.root->child->sibling);
    addChild(temp[7], T.root->child->sibling->sibling);
    addChild(temp[8], T.root->child->sibling->sibling);
    addChild(temp[9], T.root->child->child);
    addChild(temp[10], T.root->child->sibling->sibling->child);

    printf("Pre Order {=}->");
    printTreePreOrder(T.root);
    
    delChild(temp[2], T.root);
    printf("\nPre Order {=}->");
    printTreePreOrder(T.root);
    
    delChild(temp[7], T.root->child->sibling); // hapus anak ke-1 dari saudaranya anaknya root 
    printf("\nPre Order {=}->");
    printTreePreOrder(T.root);

    simpul *check = findSimpul(temp[11], T.root);
    if(check != NULL){
        printf("\nwadaww E ketemu nich!\n");
    }else{
        printf("\nhahhh kosonkk!\n");
    }

    delAll(T.root);
    printf("dannyapp tree pun habis dibabat\n");
    // print preorder dari T.root
    return 0;
}