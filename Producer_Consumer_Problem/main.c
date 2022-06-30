#include <stdio.h>

int flag[2];
char turn='p';
int numbah=0;

void produce()
{
    turn='p';
    flag[0]=1;
    while(turn=='c' && flag[1]==1)
    {
        ;
    }
    flag[0]=0;
    numbah++;
}

void consumer()
{
    turn='c';
    flag[1]=1;
    while(turn=='p' && flag[0]==1)
    {
        ;
    }
    flag[1]=0;
    numbah--;
}


int main()
{
    while(1)
    {
        printf("1.I want to produce\n2.I want to consume\n3.I want to quit\n");
        int decider;
        scanf("%d",&decider);
        if(decider==1)
        {
            produce();
        }
        else if(decider==2)
        {
            if(numbah<=0)
            {
                printf("There is nothing available to consume");
            }
            else
                consumer();
        }
        else
        {
            break;
        }
    }
}
