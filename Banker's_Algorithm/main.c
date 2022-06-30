#include <stdio.h>

int count=0;
struct track
{
    int a,b,c,decider;
}total,avilable;

int allokay(struct track *pain)
{
    if(pain->a>=0 && pain->b>=0 && pain->c>=0)
    {
        return 2;
    }
    else
    {
        printf("System unsafe, DEADLOCK detected");
    }
}

int doer(struct track *pain,struct track *suffer)
{
    if(avilable.a>=pain->a && avilable.b>=pain->b && avilable.c>=pain->c)
    {
        avilable.a=avilable.a+suffer->a;
        avilable.b=avilable.b+suffer->b;
        avilable.c=avilable.c+suffer->c;
        pain->decider=1;
        count++;
        return 5;
    }
}

void filler(struct track *pain)
{
    printf("Enter the number of A instances: ");
    scanf("%d",&pain->a);
    printf("Enter the number of B instances: ");
    scanf("%d",&pain->b);
    printf("Enter the number of C instances: ");
    scanf("%d",&pain->c);
}

int main()
{
    int cat;
    printf("Please enter the number of processes: ");
    scanf("%d",&cat);
    struct track alloc[cat],need[cat];
    printf("Please enter the instances available\n");
    filler(&total);
    for(int i=0;i<cat;i++)
    {
        printf("Enter allocated for process %d\n",i+1);
        filler(&alloc[i]);
        printf("Enter need for process %d\n",i+1);
        filler(&need[i]);
        need[i].decider=0;
    }
    avilable.a=total.a,avilable.b=total.b,avilable.c=total.c;
    for(int i=0;i<cat;i++)
    {
        avilable.a=avilable.a-alloc[i].a;
        avilable.b=avilable.b-alloc[i].b;
        avilable.c=avilable.c-alloc[i].c;
    }
    printf("\n");
    if(allokay(&avilable)==2)
    {
        while (count<cat)
        {
            for(int i=0;i<cat;i++)
            {
                if(need[i].decider!=1)
                {
                    if(doer(&need[i],&alloc[i])==5)
                    {
                        printf("Process %d completed\n",i);
                    }
                }
            }
        }
    }
}
