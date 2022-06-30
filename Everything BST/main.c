#include <stdio.h>
#include <stdlib.h>
struct tree* one;
struct tree{
    int data;
    struct tree* left;
    struct tree* right;
};
int indi=0;
struct tree* search(struct tree* rr, int key)
{
    int flag=-1;
    struct tree* arr[20];
    while(rr!=NULL && rr->data!=key)
    {
        if (key>rr->data)
        {
            flag++;
            arr[flag]=rr;
            rr=rr->right;
            indi=420;
        }
        else
        {
            flag++;
            arr[flag]=rr;
            rr=rr->left;
            indi=69;
        }
    }
    rr=arr[flag];
    return rr;
}

int smallest(struct tree* kk)
{
    kk=kk->right;
    if (kk->left==NULL)
        return kk->data;
    else
    {
        while(kk->left!=NULL)
        {
            kk=kk->left;
        }
        return kk->data;
    }
}

int flag=0;
void no_nodes(struct tree *randy)
{
    if (randy!=NULL)
    {
        flag++;
        no_nodes(randy->left);
        no_nodes(randy->right);
    }
}

void no_int_nodes(struct tree *randy)
{
    if (randy!=NULL)
    {
        if(randy->left!=NULL || randy->right!=NULL)
            flag++;
        no_int_nodes(randy->left);
        no_int_nodes(randy->right);
    }
}

void node_printer(int k)
{
    flag=0;
    switch (k)
    {
        case 1:
            no_nodes(one);
            printf("Number of nodes are %d\n",flag);
            break;
        case 2:
            no_int_nodes(one);
            printf("Number of internal nodes are %d\n",flag);
            break;
    }
}

void delete(int key)
{
    struct tree *temp=search(one,key);
    struct tree *op;
    if(indi==69)
        op=temp->left;
    else
        op=temp->right;
    if(op->left==NULL && op->right==NULL)
    {
        free(op);
        if(indi==69)
            temp->left=NULL;
        else
            temp->right=NULL;
    }
    else if(op->left==NULL || op->right==NULL)
    {
        if(indi==69)
        {
            if(op->left==NULL)
            {
                temp->left=op->right;
                free(op);
                if(indi==69)
                    temp->left=NULL;
                else
                    temp->right=NULL;
            }
            else
            {
                temp->left=op->left;
                free(op);
                if(indi==69)
                    temp->left=NULL;
                else
                    temp->right=NULL;
            }
        }
        else
        {
            if(op->left==NULL)
            {
                temp->right=op->right;
                free(op);
                if(indi==69)
                    temp->left=NULL;
                else
                    temp->right=NULL;
            }
            else
            {
                temp->right=op->left;
                free(op);
                if(indi==69)
                    temp->left=NULL;
                else
                    temp->right=NULL;
            }
        }
    }
    else
    {
        int rant;
        rant=smallest(op);
        delete(smallest(op));
        op->data=rant;
    }
}

struct tree* insert(struct tree* rr, int key)
{
    if (rr==NULL)
    {
        struct tree* rat=(struct tree*)malloc(sizeof(struct tree));
        rat->left=NULL;
        rat->right=NULL;
        rat->data=key;
        return rat;
    }
    if (key>rr->data)
        rr->right=insert(rr->right,key);
    else
        rr->left=insert(rr->left,key);
    return rr;
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

int main()
{
    int numbah,king;
    printf("Enter the number of elements in your tree ");
    scanf("%d",&numbah);
    one=(struct tree*)malloc(sizeof(struct tree));
    printf("Enter your %d elements\n",numbah);
    scanf("%d", &king);
    one->data=king;
    one->left=NULL;
    one->right=NULL;
    for(int i=0;i<numbah-1;i++)
    {
        int taytay;
        scanf("%d",&taytay);
        insert(one,taytay);
    }
    delete(33);
    node_printer(1);
    delete(55);
    delete(24);
    node_printer(1);
    inorder(one);
}