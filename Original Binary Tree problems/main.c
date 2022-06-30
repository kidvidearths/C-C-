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

int power,flag=0;
void preorder(struct tree* kk, int randy)
{
    if (kk != NULL)
    {
        if (kk->data==randy)
        {
            flag=420;
            return;
        }
        preorder(kk->left, randy);
        if (flag==420)
        {
            power=kk->data;
            flag=20;
        }
        preorder(kk->right, randy);
        if (flag==420)
        {
            power=kk->data;
            flag=100;
        }
    }
}

struct tree *pointless;
void adress(struct tree* bruv, int dick)
{
    if(bruv!=NULL)
    {
        if (dick==bruv->data)
        {
            pointless=bruv;
            return;
        }
        adress(bruv->left,dick);
        adress(bruv->right,dick);
    }
}

void uncle(struct tree* kal, int element)
{
    flag=0;
    preorder(kal, element);
    preorder(kal,power);
    adress(kal,power);
    if (flag==20)
        printf("%d\n",pointless->right->data);
    else
        printf("%d\n",pointless->left->data);

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
    uncle(king,10);
}