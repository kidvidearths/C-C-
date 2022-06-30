#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node *top=NULL;

int push(int k)
{
    struct node *temp;
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=k;
    if (top==NULL)
    {
        top=new;
        new->next=NULL;
    }
    else
    {
        temp=top;
        new->next=top;
        top=new;
    }
}

int pop()
{
    struct node *temp;
    temp=top;
    top=top->next;
    int kow=temp->data;
    free(temp);
    return kow;
}
int f=-1,r=-1;
int kat[50];
int enq(int k)
{
    if (f==r && f!=-1)
    {
        f=-1,r=-1;
        enq(k);
        return 0;
    }
    f++;
    kat[f]=k;
}
int deq()
{
    r++;
    return kat[r];
}
int display()
{
    for (int i=r+1;i<f+1;i++)
        printf("%d ",kat[i]);
}
int main()
{
    int comeinvideo;
    printf("How many integers in your array ");
    scanf("%d",&comeinvideo);
    printf("Enter your elements\n");

    for (int i=0;i<comeinvideo;i++)
    {
        int betterthannothing;
        scanf("%d",&betterthannothing);
        enq(betterthannothing);
    }
    printf("Enter the place till you want the list to be reversed ");
    int reversah;
    scanf("%d",&reversah);
    for (int i=0;i<reversah;i++)
    {
        push(deq());
    }
    for (int i=0;i<reversah;i++)
    {
        enq(pop());
    }
    for (int i=0;i<comeinvideo-reversah;i++)
    {
        int k;
        k=deq();
        enq(k);
    }
    display();
    for (int i=0;i<comeinvideo;i++)
    {
        deq();
    }
    enq(5);
    enq(12);
    enq(54);
    deq();
    printf("\n");
    printf("%d %d",f,r);
}
