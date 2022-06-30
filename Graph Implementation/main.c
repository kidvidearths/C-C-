#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insert(struct node *kk)
{
    int pp;
    struct node* temp;
    scanf("%d",&pp);
    while (kk->next != NULL)
    {
        kk = kk->next;
    }
    temp = (struct node *) malloc(sizeof(struct node));
    kk->next = temp;
    temp->data = pp;
    temp->next=NULL;
}

void printah(struct node *kk,int rr)
{
    printf("The connections of %d are ",rr);
    while(kk->next!=NULL)
    {
        printf("%d ",kk->data);
        kk=kk->next;
    }
    printf("%d ",kk->data);
    printf("\n");
}

int main()
{
    int vertices;
    scanf("%d",&vertices);
    int acvertices[vertices];
    struct node* end[vertices];
    for (int i=0;i<vertices;i++)
    {
        int connections,temp;
        scanf("%d",&acvertices[i]);
        scanf("%d",&connections);
        end[i]=(struct node*)malloc(sizeof(struct node));
        end[i]->next=NULL;
        scanf("%d",&temp);
        end[i]->data=temp;
        for (int j=0;j<connections-1;j++)
        {
            insert(end[i]);
        }
    }
    for (int i=0;i<vertices;i++)
    {
        printah(end[i],acvertices[i]);
    }
}
