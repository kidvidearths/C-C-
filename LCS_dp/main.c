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
    char m[20],n[20];
    scanf("%s", &m[0]);
    scanf("%s",&n[0]);
    int l1=strlen(m);
    int l2=strlen(n);
    int la[l1+1][l2+1];
    for (int i=0;i<l2+1;i++)
    {
        la[0][i]=0;
    }
    for (int i=0;i<l1+1;i++)
    {
        la[i][0]=0;
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
                la[i+1][j+1]=max(la[i][j+1],la[i+1][j]);
            }
        }
    }
    if(la[l1][l2]==min(l1,l2))
        printf("YES");
    else
        printf("NO");
    return 0;
}
