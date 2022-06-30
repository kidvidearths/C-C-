#include <stdio.h>

int main()
{
    printf("Number of elements in your array ");
    int j;
    scanf("%d",&j);
    int kat[j];
    for (int i=0;i<j;i++)
    {
        scanf("%d",&kat[i]);
    }
    for (int i=1;i<j;i++)
    {
        int k=i-1;
        int temp=kat[k+1];
        while (k>=0 && temp<kat[k])
        {
            kat[k+1]=kat[k];
            k--;
        }
        kat[k+1]=temp;
    }
    for (int i=0;i<j;i++)
    {
        printf("%d\n",kat[i]);
    }
}
