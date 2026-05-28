#include "head.h"

int main(){
    tree T;
    nilai temp[8];

    for(int i = 0; i < 8; i++){
        scanf(" %c", &temp[i].konten);
    }

    makeTree(temp[0], &T);
    addLeft(temp[1], T.root);
    addRight(temp[2], T.root);
    addLeft(temp[3], T.root->left);
    addRight(temp[4], T.root->left);
    addLeft(temp[5], T.root->right);
    addRight(temp[6], T.root->right);
    addLeft(temp[7], T.root->right->left);
    // print preorder, inorder, dan postorder dari T.root
    printf("Pre Order  {=}-> ");printTreePreOrder(T.root);
    printf("\nIn Order   {=}-> ");printTreeInOrder(T.root);
    printf("\nPost Order {=}-> ");printTreePostOrder(T.root);
    
    printf("\n8ARNMqo7uXgU5NTweEmWn46Hvewjcp1PtqfXTKDZTj29\n");
    delLeft(T.root->right->left);
    // print preorder, inorder, dan postorder dari T.root
    printf("Pre Order  {=}-> ");printTreePreOrder(T.root);
    printf("\nIn Order   {=}-> ");printTreeInOrder(T.root);
    printf("\nPost Order {=}-> ");printTreePostOrder(T.root);
    
    
    printf("\nyRvuVex/1U/YeNJUwyLdcf5/w0r4FJZNpS6fT+E=\n");
    delRight(T.root->right);
    // print preorder, inorder, dan postorder dari T.root
    printf("Pre Order  {=}-> ");printTreePreOrder(T.root);
    printf("\nIn Order   {=}-> ");printTreeInOrder(T.root);
    printf("\nPost Order {=}-> ");printTreePostOrder(T.root);
    
    return 0;
}