#include <stdio.h>
#include <stdlib.h>

struct tree{
    int data;
    struct tree* left;
    struct tree* right;
};

int insert(struct tree* kk, int kat, int flag)
{
    if(flag==420 || flag==69)
    {
        struct tree *temp;
        temp=(struct tree*)malloc(sizeof(struct tree));
        if(flag==420)
        {
            kk->left=temp;
            temp->data=kat;
            temp->left=NULL;
            temp->right=NULL;
        }
        else
        {
            kk->right=temp;
            temp->data=kat;
            temp->left=NULL;
            temp->right=NULL;
        }
    }
    else
    {
        if(kk->data>kat)
        {
            if(kk->left==NULL)
            {
                insert(kk,kat,420);
            }
            else
            {
                insert(kk->left,kat,0);
            }
        }
        else
        {
            if(kk->right==NULL)
            {
                insert(kk,kat,69);
            }
            else
            {
                insert(kk->right,kat,0);
            }
        }
    }
}

int flag=0;
int smallest(struct tree* kk,int no)
{
    if(kk!=NULL)
    {
        smallest(kk->left, no);
        flag++;
        if (flag==no)
        {
            printf("%d",kk->data);
            return 0;
        }
        smallest(kk->right, no);
    }

}

int main()
{
    int numbah,king,small;
    printf("Enter the number of elements in your tree ");
    scanf("%d",&numbah);
    struct tree* one;
    one=(struct tree*)malloc(sizeof(struct tree));
    printf("Enter your %d elements\n",numbah);
    scanf("%d", &king);
    one->data=king;
    one->left=NULL;
    one->right=NULL;
    for(int i=0;i<numbah-1;i++)
    {
        int pp;
        scanf("%d",&pp);
        insert(one,pp,0);
    }
    printf("What's the k? ");
    scanf("%d",&small);
    printf("The %dth smallest element is ",small);
    smallest(one,small);
}
