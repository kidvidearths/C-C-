#include <stdio.h>
int main()
{
    char dec;
    int a,b;
    scanf("%d\n",&a);
    scanf("%c\n",&dec);
    scanf("%d",&b);
    switch (dec)
    {
        case '*':
            printf("%d",a*b);
            break;
        case '+':
            printf("%d",a+b);
            break;
        case '/':
            printf("%d",a/b);
            break;
        case '%':
            printf("%d",a%b);
            break;
        case '-':
            printf("%d",a-b);
            break;
    }

}