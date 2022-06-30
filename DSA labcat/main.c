#include <stdio.h>
#include <stdlib.h>

struct tree{
    int data;
    struct tree* left;
    struct tree* right;
};

struct tree* king;

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

int maxValue(struct tree *bow)
{
    while(bow->right!=NULL)
    {
        bow=bow->right;
    }
    return bow->data;
}

int minValue(struct tree *cat)
{
    while(cat->right!=NULL)
    {
        cat=cat->left;
    }
    return cat->data;
}


int isBST(struct tree* node)
{

    if (node == NULL)
        return 1;

    /* false if the max of the left is > than us */
    if (node->left!=NULL && maxValue(node->left) > node->data)
        return 0;

    /* false if the min of the right is <= than us */
    if (node->right!=NULL && minValue(node->right) < node->data)
        return 0;

    /* false if, recursively, the left or right is not a BST */
    if (!isBST(node->left) || !isBST(node->right))
        return 0;

    /* passing all that, it's a BST */
    return 1;
}

int flag=0;
void inorder(struct tree* kk)
{
    if(kk!=NULL)
    {
        inorder(kk->left);
        if(isBST(kk)==1 && kk->data!=king->data)
        {
            if(kk->left==NULL && kk->right==NULL)
            {
                ;
            }
            else
            {
                flag++;
            }

        }
        inorder(kk->right);
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
    int bruh;
    printf("Enter your very first element ");
    scanf("%d",&bruh);
    king=insert(bruh);
    input(king,20);
    inorder(king);
    if (flag==0)
        printf("-1");
    else
        printf("%d",flag);
}