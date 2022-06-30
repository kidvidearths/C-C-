#include <stdio.h>

int sarch(int rey[],int low,int high,int key)
{
    if (high>=low)
    {
        int mid=(low+high)/2;
        if (rey[mid]==key)
        {
            printf("FOUND");
            return 0;
        }
        else if (rey[mid]>key)
        {
            sarch(rey,low,mid-1,key);
        }
        else
        {
            sarch(rey,mid+1,high,key);
        }
    }
    else
    {
        printf("BRUH");
        return 0;
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
    printf("What's the element you are looking for? ");
    int mys;
    scanf("%d",&mys);
    sarch(kat,0,j,mys);
}
