#include <stdio.h>

int main()
{
    int count,t;
    scanf("%d",&count);
    int numbers[count];
    for(int i=0;i<count;i++)
    {
        scanf("%d",&numbers[i]);
    }
    scanf("%d",&t);
    t++;
    int matrix[count][t];
    for(int i=0;i<count;i++)
        matrix[i][0]=1;
    for(int i=1;i<t;i++)
    {
        if(numbers[0]==i)
        {
            matrix[0][i]=1;
        }
        else
        {
            matrix[0][i]=0;
        }

    }
    for(int i=1;i<count;i++)
    {
        for(int j=1;j<t;j++)
        {
            if(numbers[i]>j)
            {
                matrix[i][j]=matrix[i-1][j];
            }
            else if(matrix[i-1][j]==1 || matrix[i-1][j-numbers[i]]==1)
            {
                matrix[i][j]=1;
            }
            else
            {
                matrix[i][j]=0;
            }
        }
    }
    if(matrix[count-1][t-1]==1)
        printf("TRUE");
    else
        printf("FALSE");
}
