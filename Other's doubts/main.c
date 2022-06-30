#include <stdio.h>

int elements,no_pts,great=0,uncomp=0,greater_data[100][2],comparable_data[100][2], point_set[20][20];

int allokay(int index,int outer_rotater,int inner_rotater)
{
    if(inner_rotater>=2)
    {
        int flag=0;
        for(int i=0;i<inner_rotater;i++)
        {
            for(int j=0;j<great;j++)
            {
                if(comparable_data[j][0]==point_set[outer_rotater][i] && comparable_data[j][1]==index)
                    break;
            }
            flag=1;
        }
        if(flag==0)
            return 3;
    }
    else
    {
        for(int j=0;j<great;j++)
        {
            if(comparable_data[j][0]==point_set[outer_rotater][0] && comparable_data[j][1]==index)
                return 3;
        }
    }
    return 0;

}

int filler_1(int data [][elements], int p, int q)
{
    int flag=0,pp=0;
    for (int i=0;i<elements;i++)
    {
        if(data[p][i]<=data[q][i])
        {
            pp++;
            if(data[p][i]<data[q][i])
            {
                flag=1;
            }
        }
    }
    if(flag==1 && pp==elements)
    {
        return 0;
    }
    else
    {
        comparable_data[uncomp][0]=p;
        comparable_data[uncomp][1]=q;
        uncomp++;
        return 2;
    }
}

int filler(int data [][elements], int p, int q)
{
    if(p==q)
        return 0;
    int flag=0,pp=0;
    for (int i=0;i<elements;i++)
    {
        if(data[p][i]>=data[q][i])
        {
            pp++;
            if(data[p][i]>data[q][i])
            {
                flag=1;
            }
        }
    }
    if(flag==1 && pp==elements)
    {
        greater_data[great][0]=p;
        greater_data[great][1]=q;
        great++;
        return 3;
    }
    else
    {
        if(filler_1(data,p,q)==2)
        {
            return 2;
        }
    }
    return 0;
}

int main()
{
    printf("Enter the total number of points: ");
    scanf("%d",&no_pts);
    printf("Enter the number of elements in each point: ");
    scanf("%d",&elements);
    int data[no_pts][elements],greatest[no_pts];
    for (int i=0;i<no_pts;i++)
    {
        for(int j=0;j<elements;j++)
            scanf("%d",&data[i][j]);
    }
    for (int i=0;i<no_pts;i++)
    {
        int flag=0;
        for(int j=0;j<no_pts;j++)
        {
            if(filler(data,i,j)==3)
            {
                flag++;
            }
        }
        greatest[i]=flag;
    }
    int outer_rotater=0,index,point_count=0,inner_rotater=0,index_track[no_pts],pain=0;
    while(point_count<no_pts)
    {
        int max=-1;
        for (int i=0;i<no_pts;i++)
        {
            if(greatest[i]>max)
            {
                max=greatest[i];
                index=i;
            }
        }
        greatest[index]=-100;
        if(inner_rotater==0)
        {
            point_set[outer_rotater][inner_rotater]=index;
            inner_rotater++;
            point_count++;
        }
        else
        {
            if(allokay(index,outer_rotater,inner_rotater)==3)
            {
                point_set[outer_rotater][inner_rotater]=index;
                inner_rotater++;
                point_count++;
            }
            else
            {
                index_track[outer_rotater]=inner_rotater;
                pain++;
                outer_rotater++;
                inner_rotater=0;
                point_set[outer_rotater][inner_rotater]=index;
                inner_rotater++;
                point_count++;
            }
        }

    }
    index_track[outer_rotater]=inner_rotater;
    point_set[outer_rotater][inner_rotater]=point_count;


printf("\n");

    for(int i=0;i<pain+1;i++)
    {
        for(int j=0;j<index_track[i];j++)
        {
            printf("%d ",point_set[i][j]);
        }
        printf("\n");
    }
}