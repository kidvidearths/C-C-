#include <stdio.h>
#include <stdlib.h>

struct tree{
    int data;
    struct tree* left;
    struct tree* right;
};

struct tree* insert(int kat)
{
    if(kat!=0)
    {
        struct tree *temp;
        temp = (struct tree *) malloc(sizeof(struct tree));
        temp->data = kat;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
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

void input(struct tree* bowbow, int pp)
{
    if(pp!=0)
    {
        printf("Enter the left node of %d (0 to skip) ",bowbow->data);
        scanf("%d",&pp);
        bowbow->left=insert(pp);
        input(bowbow->left,pp);
        printf("Enter the right node of %d (0 to skip) ",bowbow->data);
        scanf("%d",&pp);
        bowbow->right=insert(pp);
        input(bowbow->right,pp);
    }
}

int main()
{
    struct tree* king;
    int bruh;
    printf("Enter your very first element ");
    scanf("%d",&bruh);
    king=insert(bruh);
    input(king,20);
    printf("INORDER\n");
    inorder(king);
    printf("\n");
    printf("PREORDER\n");
    preorder(king);
}
