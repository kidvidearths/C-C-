#include <stdio.h>


void Haming_cycle(int tester, int depth, int no_vert, int adj_mat[][no_vert], int* count, int (*answer)[][no_vert], int used[no_vert])
{
    if(depth==no_vert)
    {
        if(adj_mat[tester][0]==1)
        {
            *count=*count+1;
            for (int i=0;i<no_vert;i++)
            {
                (*answer)[*count][i]=(*answer)[*count-1][i];
            }
            return;
        }
    }
    int rotator=1;
    while(rotator<no_vert)
    {
        int k=used[rotator];
        int p=adj_mat[tester][rotator];
        if(p==1 && k!=1)
        {
            used[rotator]=1;
            (*answer)[*count][depth]=rotator;
            Haming_cycle(rotator,depth+1, no_vert, adj_mat,count,answer,used);
            used[rotator]=100;
            rotator++;
        }
        else
            rotator++;
    }
}

int main()
{
    int no_vert,count=0;
    printf("Enter the number of vertices in your graph ");
    scanf("%d",&no_vert);
    int adj_mat[no_vert][no_vert];
    for (int i=0;i<no_vert;i++)
    {
        printf("Enter row %d of your matrix\n",i+1);
        for(int j=0;j<no_vert;j++)
        {
            scanf("%d",&adj_mat[i][j]);
        }
    }
    int dyn_array[no_vert],used[no_vert],answer[20][no_vert];
    dyn_array[0]=0;
    used[0]=1;
    Haming_cycle(0,1,no_vert,adj_mat,&count,&answer,used);
    if(count==0)
        printf("PAIN, no hamming cycle was found");
    else
    {
        printf("The hamming cycles found are\n");
        for (int i=0;i<count;i++)
        {
            for(int j=0;j<no_vert;j++)
            {
                if(j==0)
                    printf("%d ",1);
                else
                    printf("%d ",answer[i][j]+1);
            }
            printf("\n");
        }
    }
}