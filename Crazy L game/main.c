#include <stdio.h>

int main()
{
    int row;
    int col;
    scanf("%d",&row);
    scanf("%d",&col);
    char everything[row][col];
    int flag=0;
    for (int i=0;i<row;i++)
    {
        for (int r = 0; r < col; r++)
        {
            scanf(" %c", &everything[i][r]);
        }
    }
    for (int p=0;p<row-1;p++)
    {
        for (int r=0;r<col-1;r++)
        {
            if (everything[p][r]==everything[p+1][r])
            {
                if (everything[p+1][r]==everything[p+1][r+1])
                {
                    flag=420;
                    break;
                }
            }
        }
    }
    if (flag==420)
        printf("YEP");
    else
        printf("HELL NO");
}
