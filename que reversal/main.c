#include <stdio.h>
#include<stdlib.h>
struct node
{
    char data;
    struct node* next;
};
struct node *top=NULL;

int push(char k)
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
    printf("%c",temp->data);
    free(temp);
}

int main()
{
    char doggie[50];
    scanf("%s",&doggie);
    int i=0,countah=0;
    while (doggie[i]!='\0')
    {
        push(doggie[i]);
        i++;
        countah++;
    }
    for (int meow=0;meow<countah;meow++)
    {
        pop();
    }
}