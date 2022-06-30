#include <stdio.h>


int main()
{
    char l[][20]={"BHAVANI RAO", "RAMA", "SATHVIK"};
    char b[]={"Reddi"};
    for (int i=0;i<3;i++)
    {
        printf("%s %s\n", l[i], b);
    }


}