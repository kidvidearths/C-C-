#include <stdio.h>
int row(int a, int b, int d[50][50]);
int sum(int a, int b, int d[50][50]);
int main()
{
    int a,b,c,d[50][50],e;
    scanf("%d", &a);
    scanf("%d", &b);
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            scanf("%d", &d[i][j]);
        }
    }
    scanf("%d", &e);
    switch(e)
    {
        case 1:
            row(a,b,d);
            break;
        case 2:
            sum(a,b,d);
            break;
        default:
            printf("Enter the right option");
            break;
    }
}
int row(int a, int b, int d[50][50])
{
    for (int i=0; i<a; i++)
    {
        int total=0;
        for (int j=0; j<b; j++)
        {
            total=total+d[i][j];
        }
        printf("%d\n", total);
    }
}
int sum(int a, int b, int d[50][50])
{
    int dia=0;
    for (int i=0; i<a; i++)
    {
        for (int j=0; j<b; j++)
        {
            if(i==j)
                dia=dia+d[i][j];
        }
    }
    printf("%d", dia);
}
