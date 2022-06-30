#include <stdio.h>

int main()
{
   int cat;
   int meow[10];
   scanf("%d",&cat);
   int power=0;
   for (int i=0;i<cat;i++)
   {
       int j=0;
       int flag=420;
       int temp;
       scanf("%d",&temp);
       while(j<cat)
       {
           if (temp==meow[j])
               flag=69;
           j++;
       }
       if (flag==420)
       {
           meow[power] = temp;
           power++;
       }
   }
    for (int i=0;i<power;i++)
    {
        printf("%d\n",meow[i]);
    }
}
