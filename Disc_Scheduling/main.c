#include <stdio.h>
#include <stdlib.h>

void fcfs(int count, int numbers[count], int position)
{
    int distance=0,counter=0;
    while (counter!=count)
    {
        distance=distance+abs(position-numbers[counter]);
        position=numbers[counter];
        counter++;
    }
    printf("%d",distance);
}

void sstf(int count, int numbers[count], int position)
{
    int over[count],distance=0,counter=0;
    while (counter!=count)
    {
        int min=1000,ind;
        for(int i=0;i<count;i++)
        {
            if(over[i]!=1)
            {
                if(abs(position-numbers[i])<min)
                {
                    min=abs(position-numbers[i]);
                    ind=i;
                }
            }
        }
        over[ind]=1;
        distance=distance+abs(position-numbers[ind]);
        position=numbers[ind];
        counter++;
    }
    printf("%d",distance);
}

void scan(int count, int numbers[count], int position)
{
    int end,min=1000,distance;
    printf("Where does your bus track end? ");
    scanf("%d",&end);
    for(int i=0;i<count;i++)
    {
        if(numbers[i]<min)
            min=numbers[i];
    }
    distance=(end-position)+(end-min);
    printf("%d",distance);
}

void cscan(int count, int numbers[count], int position)
{
    int begin,end,min=1000,distance;
    printf("Where does your bus track start? ");
    scanf("%d",&begin);
    printf("Where does your bus track end? ");
    scanf("%d",&end);
    for(int i=0;i<count;i++)
    {
        if(numbers[i]<min)
            min=numbers[i];
    }
    distance=(end-position)+(end-begin)+(min-begin);
    printf("%d",distance);
}

int main()
{
    printf("How many bus stop requests? ");
    int count,position,decider;
    scanf("%d",&count);
    printf("Enter the bus's position ");
    scanf("%d",&position);
    int numbers[count];
    printf("Enter the bus stop requests one by one\n");
    for(int i=0;i<count;i++)
    {
        scanf("%d",&numbers[i]);
    }
    printf("Enter 1 for FCFS\nEnter 2 for SSTF\nEnter 3 for SCAN\nEnter 4 for C-SCAN\n");
    scanf("%d",&decider);
    switch (decider)
    {
        case 1:
            fcfs(count,numbers,position);
            break;
        case 2:
            sstf(count,numbers,position);
            break;
        case 3:
            scan(count,numbers,position);
            break;
        case 4:
            cscan(count,numbers,position);
            break;
    }
}
