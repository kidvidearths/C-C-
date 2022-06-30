#include <stdio.h>

void merger(int buffalo[],int start, int mid, int end)
{
    int babybuffalo[10];
    int i=start,j=mid+1;
    int normal=0;
    while (i<=mid && j<=end)
    {
        if (buffalo[i]<buffalo[j])
        {
            babybuffalo[normal]=buffalo[i];
            i++;
            normal++;
        }
        else
        {
            babybuffalo[normal]=buffalo[j];
            j++;
            normal++;
        }
    }
    while (i<=mid)
    {
        babybuffalo[normal]=buffalo[i];
        i++;
        normal++;
    }
    while (j<=end)
    {
        babybuffalo[normal]=buffalo[j];
        j++;
        normal++;
    }
    int k=0;
    for (int t=start;t<end+1;t++)
    {
        buffalo[t]=babybuffalo[k];
        k++;
    }
}
void mergesort(int buffalo[],int low, int high)
{
    if (high>low)
    {
        int mid=(low+high)/2;
        mergesort(buffalo,low,mid);
        mergesort(buffalo,mid+1,high);
        merger(buffalo,low,mid,high);
    }

}
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

    mergesort(kat,0,j-1);
    for (int t=0;t<j;t++)
    {
        printf("%d ",kat[t]);
    }
}