#include <stdio.h>

int main()
{
    int n=8;
    int kat[8]={3,5,77,22,105,752,999,1};
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
           int temp;
           if (kat[j]>kat[j+1])
           {
               temp=kat[j];
               kat[j]=kat[j+1];
               kat[j+1]=temp;
           }
        }
    }
    for (int i=0;i<n;i++)
    {
        printf("%d\n",kat[i]);
    }
}
