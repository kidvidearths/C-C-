#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}


int lcs(char m[],char n[],int p,int q)
{
    if(p==-1 || q==-1)
        return 0;
    int mx=0;
    if (m[p]==n[q])
    {
        mx++;
        mx=mx+lcs(m,n,p-1,q-1);
    }
    if(m[p]!=n[q])
    {
        int t1=lcs(m,n,p-1,q);
        int t2=lcs(m,n,p,q-1);
        mx=mx+max(t1,t2);
    }
    return mx;
}

int main()
{
    char m[20],n[20];
    scanf("%s",&m[0]);
    scanf("%s",&n[0]);
    int l1=strlen(m);
    int l2=strlen(n);
    printf("%d",lcs(m,n,l1-1,l2-1));
    return 0;
}
