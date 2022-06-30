#include <stdio.h>
#include <stdlib.h>

struct tree{
    int data;
    struct tree* left;
    struct tree* right;
};

int sum=0;
void printNodesAtLevel(struct tree* root, int currentLevel, int level) {

    if(root == NULL) {
        return;
    }
    if(currentLevel == level)
    {
        sum=sum+root->data;
        return;
    }

    printNodesAtLevel(root->left, currentLevel+1, level);
    printNodesAtLevel(root->right, currentLevel+1, level);
}

int range=0;

void level(struct tree* pp, int element)
{
    if(pp->data!=element)
    {
        range++;
        if(pp->data>element)
            level(pp->left,element);
        else
            level(pp->right,element);
    }
}

void insert(struct tree* kk, int kat, int flag)
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


int main()
{
    int softpp[]={58,51,62,22,80,10,36,65,90,29,71,25,34,68,75,36};
    int numbah=sizeof(softpp)/ sizeof(int);
    struct tree* one;
    one=(struct tree*)malloc(sizeof(struct tree));
    one->data=softpp[0];
    one->left=NULL;
    one->right=NULL;
    for(int i=1;i<numbah;i++)
    {
        insert(one,softpp[i],0);
    }
    level(one,36);
    printNodesAtLevel(one,0,range);
    printf("%d",sum);
}
