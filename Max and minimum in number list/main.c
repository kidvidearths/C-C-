#include <stdio.h>
int main()
{
  int n;
  scanf("%d",&n);
  int tank[n];
    for (int i=0;i<n;i++)
  {
      scanf("%d",&tank[i]);
  }
    int high=tank[0];
    int low=tank[0];
    for (int i=0;i<n;i++)
    {
        if (high<tank[i])
            high=tank[i];
        else
            continue;
    }
    for (int i=0;i<n;i++)
    {
        if (low>tank[i])
            low=tank[i];
        else
            continue;
    }
    printf("high is %d\n", high);
    printf("low is %d", low);

}