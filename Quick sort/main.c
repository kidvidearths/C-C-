#include <stdio.h>

int quickie(int a[],int front,int rear)
{
    int pivot=a[front];
    int i=front;
    front++;
    while(rear>=front)
    {
      while (a[front]<pivot && rear>=front)
          front++;
      while (a[rear]>pivot && rear>=front)
          rear--;
      if(rear>=front)
      {
          int temp;
          temp=a[front];
          a[front]=a[rear];
          a[rear]=temp;
      }
    }
    while (i<=rear-1)
    {
        a[i]=a[i+1];
        i++;
    }
    a[rear]=pivot;
    return rear;
}
int quicksort(int buffalo[],int low, int high)
{
    if (high>low)
    {
        int r=quickie(buffalo,low,high);
        quicksort(buffalo,low,r-1);
        quicksort(buffalo,r+1,high);
    }

}
int main()
{
    printf("Number of elements in your array ");
    int j;
    scanf("%d",&j);
    int kat[j];
    for (int i=0;i<j;i++)
    {
        scanf("%d",&kat[i]);
    }
    quicksort(kat,0,j-1);
    for (int i=0;i<j;i++)
        printf("%d ",kat[i]);
}