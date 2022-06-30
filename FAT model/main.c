#include <stdio.h>
#include <math.h>
int seq(int *arr[], int *x);
float getavg(int arr[], int size);
int main( )
{
    int n;
    int k,i;
    scanf("%d", &n);
    int ar[n], l1[n];
    for (i=0; i<n; i++)
    {
        scanf("%d", &ar[i]);
    }
    int lst[n][n];
    int m=n/2;
    for (k=1; k<n/2; k++)
    {
        int c=0;
        for(i=0;i<n;i++)
        {
            if (i>=k && i<n-k)
            {
                lst[k][c]=ar[i];
                c++;
            }
        }
    }
    float ag[m], diff, small;
    int n1=1, n2=2;
    for (i=1;i<=m; i++)
    {
        ag[i]=getavg(lst[i], (n-2*i));
    }
    small=fabs(ag[n1]-ag[n2]);
    for (i=1; i<m; i++)
    {
        for (int j=2; j<=m; j++)
        {
            if (i!=j)
            {
                diff=fabs(ag[i]-ag[j]);
                if (diff<small)
                {
                    small=diff;
                    n1=i;
                    n2=j;
                }
            }
        }
    }
    int big, notbig;
    if (n1>=n2)
    {
        big=n2;
        notbig=n2;
    }
    else
    {
        big=n2;
        notbig=n1;
    }
    for(int c=0; c<(n-2*notbig);c++)
    {
        printf("%d", lst[notbig][c]);
    }
    printf("\n");
    for (int c=0; c<(n-2*big); c++)
    {
        printf("%d", lst[big][c]);
    }
    return 0;
}
float getavg(int arr[], int size)
{
    int i;
    double avg, sum=0;
    for (i=0; i<size; i++)
    {
        sum+=arr[i];
    }
    avg=sum/size;
    return avg;
}
