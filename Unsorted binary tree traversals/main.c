#include <stdio.h>
#include <stdlib.h>

struct tree{
    int data;
    struct tree* left;
    struct tree* right;
};

struct tree* insert(int kat)
{
    struct tree *temp;
    temp=(struct tree*)malloc(sizeof(struct tree));
    temp->data=kat;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void inorder(struct tree* kk)
{
    if(kk!=NULL)
    {
        inorder(kk->left);
        printf("%d ",kk->data);
        inorder(kk->right);
    }
}

void preorder(struct tree* kk)
{
    if (kk != NULL)
    {
        printf("%d ", kk->data);
        preorder(kk->left);
        preorder(kk->right);
    }
}

int main()
{
    struct tree* king;
    king=insert(25);
    king->left = insert(15);
    king->right = insert(50);
    king->left->left = insert(10);
    king->left->right = insert(22);
    king->left->left->left = insert(4);
    king->left->left->right = insert(12);
    king->left->right->left = insert(18);
    king->left->right->right = insert(24);
    king->right->right = insert(70);
    king->right->left = insert(35);
    king->right->left->left = insert(31);
    king->right->left->right = insert(44);
    king->right->right->left = insert(66);
    king->right->right->right = insert(90);
    printf("INORDER\n");
    inorder(king);
    printf("\n");
    printf("PREORDER\n");
    preorder(king);
}