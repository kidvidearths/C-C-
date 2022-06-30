#include <stdio.h>
int prime(int k)
{
    int flag=0;
    for (int i=2;i<=k/2;i++)
        if (k%i==0)
        {
            flag=1;
            break;
        }
    if(flag==0)
        return 3;
    else
        return 2;
}
int length(int *k)
{
    int r=*k;
    int countah=0;
    while (r>0)
    {
        r=r/10;
        countah++;
    }
    return countah;
}
int powah(int r)
{
    int numbah=1;
    for (int i=0;i<r;i++)
        numbah=numbah*10;
    return numbah;
}
int rotater(int *k)
{
    int len=length(k);
    int r=*k/(powah(len-1));
    *k=*k-r*(powah(len-1));
    int p=(*k)%10;
    *k=(*k-p)/10;
    *k=*k+p*powah(len-1)+r*powah(len-2);
}
int main()
{
    int cat;
    scanf("%d",&cat);
    int *pain=&cat;
    int len=length(pain);
    int bowbow[len];
    for (int i=0;i<len;i++)
    {
        rotater(pain);
        bowbow[i]=cat;
    }
    int flag = 69;
    for (int i=0;i<len;i++)
    {
        if (prime(bowbow[i]) == 2)
        {
            flag = 420;
            break;
        }
    }
        if (flag==420)
            printf("NO");
        else
            printf("YEAH");
    }