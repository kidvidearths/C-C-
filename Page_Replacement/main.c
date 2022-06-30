#include <stdio.h>

int something[20],frame[7],m,n,count=0;

int exsist(int kk)
{
    int flag=0;
    for(int i=0;i<m;i++)
    {
        if(kk==frame[i])
            flag=1;
    }
    if(flag==1)
        return 3;
    else
        return 0;
}

int optimal()
{
    int indice_frame[m],k=0;
    while(k<n)
    {
        if(k<=m-1)
        {
            frame[k]=something[k];
            indice_frame[k]=1000;
        }
        else if(exsist(something[k])==3)
        {
            count++;
        }
        else
        {
            for (int j=0;j<m;j++)
            {
                for (int i=k+1;i<n;i++)
                {
                    if(frame[j]==something[i])
                    {
                        indice_frame[j]=i;
                        break;
                    }
                }
            }
            int ind=-1,greatest=0;
            for(int i=0;i<m;i++)
            {
                if(indice_frame[i]>greatest)
                {
                    ind=i;
                    greatest=indice_frame[i];
                }

            }
            frame[ind]=something[k];
            for (int i=0;i<m;i++)
            {
                indice_frame[i]=1000;
            }
        }
        k++;
        for (int i=0;i<m;i++)
        {
            printf("%d ",frame[i]);
        }
        printf("\n");
    }
}

int lru()
{
    int indice_frame[m],k=0;
    while(k<n)
    {
        if(k<=m-1)
        {
            frame[k]=something[k];
            indice_frame[k]=k;
        }
        else if(exsist(something[k])==3)
        {
            int ind=0;
            for(int i=0;i<m;i++)
            {
                if(something[k]==frame[i])
                    ind=i;
            }
            indice_frame[ind]=k;
            count++;
        }
        else
        {
            int ind=0,least=1000;
            for(int i=0;i<m;i++)
            {
                if(indice_frame[i]<least)
                {
                    ind=i;
                    least=indice_frame[i];
                }

            }
            indice_frame[ind]=k;
            frame[ind]=something[k];
        }
        k++;
        for (int i=0;i<m;i++)
        {
            printf("%d ",frame[i]);
        }
        printf("\n");
    }
}

int fifo()
{
    int k=0,pa=0;
    while(k<n)
    {
        if(k<=m-1)
        {
            frame[k]=something[k];
        }
        else if(exsist(something[k])==3)
        {
            pa--;
            count++;
        }
        else
        {
           frame[pa]=something[k];
        }
        k++;
        pa++;
        if(pa==m)
            pa=0;
        for (int i=0;i<m;i++)
        {
            printf("%d ",frame[i]);
        }
        printf("\n");
    }
}

int main()
{
    printf("Enter the frame size ");
    scanf("%d",&m);
    printf("Enter the string size ");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&something[i]);
    }
    int selector;
    printf("Press 1 for FIFO\nPress 2 for LRU\nPress 3 for Optimal\n");
    scanf("%d",&selector);
    switch (selector)
    {
        case 1:
            fifo();
            break;
        case 2:
            lru();
            break;
        case 3:
            optimal();
            break;
    }
    printf("Page faults are %d\n",n-count);
    printf("Page hits are %d\n",count);
    printf("Page replacements are %d",n-count-m);
}
