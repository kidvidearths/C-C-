#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int min(int a, int b)
{
    if(a>b)
        return b;
    else
        return a;
}


int main()
{
    char m[20],n[20],final[7];
    scanf("%s", &m[0]);
    scanf("%s",&n[0]);
    int l1=strlen(m),max[3];
    int l2=strlen(n);
    int la[l1+1][l2+1];
    for(int i=0;i<l1+1;i++)
    {
        for(int j=0;j<l2+1;j++)
        {
            la[i][j]=0;
        }
    }
    for(int i=0;i<l1;i++)
    {
        for(int j=0;j<l2;j++)
        {
            if(m[i]==n[j])
            {
                la[i+1][j+1]=la[i][j]+1;
            }
            else
            {
                ;
            }
        }
    }
    max[0]=0;
    for(int i=0;i<l1+1;i++)
    {
        for(int j=0;j<l2+1;j++)
        {
            if(la[i][j]>max[0])
            {
                max[0]=la[i][j];
                max[1]=i;
                max[2]=j;
            }
        }
    }

    for(int i=0;i<l1+1;i++)
    {
        for(int j=0;j<l2+1;j++)
        {
            printf("%d ",la[i][j]);
        }
        printf("\n");
    }
    int wow=max[0];
    int temp=max[0];
    int i=max[1],j=max[2];
    while (temp!=0)
    {
        i--;
        j--;
        final[max[0]-1]=m[i];
        max[0]--;
        temp=la[i][j];
    }
    for(int i=0;i<wow;i++)
    {
        printf("%c",final[i]);
    }
}