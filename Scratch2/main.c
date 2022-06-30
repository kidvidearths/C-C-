#include <stdio.h>
#include <string.h>

int main()
{
    char a[16], b[16];
    char sum[16], complement[16], temp[16], rsum[16], rcomp[16],te[16], carry = '0';
    int i, f=0;
    printf("\nSender's Side:\n");
    printf("Enter first binary string\n");
    scanf("%s", a);
    printf("Enter second binary string\n");
    scanf("%s", b);
    printf("\n%d\n", strlen(a));
    printf("\n%d\n", strlen(b));
    if (strlen(a) == strlen(b))
    {

        for (i = strlen(a) - 1; i >= 0; i--)
        {
            if (a[i] == '0' && b[i] == '0' && carry == '0')
            {
                temp[i] = '0';
                carry = '0';
            }
            else if (a[i] == '0' && b[i] == '0' && carry == '1')
            {
                temp[i] = '1';
                carry = '0';
            }
            else if (a[i] == '0' && b[i] == '1' && carry == '0')
            {
                temp[i] = '1';
                carry = '0';
            }
            else if (a[i] == '0' && b[i] == '1' && carry == '1')
            {
                temp[i] = '0';
                carry = '1';
            }
            else if (a[i] == '1' && b[i] == '0' && carry == '0')
            {
                temp[i] = '1';
                carry = '0';
            }
            else if (a[i] == '1' && b[i] == '0' && carry == '1')
            {
                temp[i] = '0';
                carry = '1';
            }
            else if (a[i] == '1' && b[i] == '1' && carry == '0')
            {
                temp[i] = '0';
                carry = '1';
            }
            else if (a[i] == '1' && b[i] == '1' && carry == '1')
            {
                temp[i] = '1';
                carry = '1';
            }
        }
        // printf("\nSum=%s", sum);
        printf("\nSum= ");
        for (i = 0; i < strlen(a); i++)
        {
            sum[i] = temp[i];
            printf("%c", sum[i]);
        }

        for (i = 0; i < strlen(a); i++)
        {
            if (sum[i] == '0')
                complement[i] = '1';
            else
                complement[i] = '0';
        }

        if (carry == '1')
            carry = '0';
        else
            carry = '1';

        printf("\nChecksum=");
        for (i = 0; i < strlen(a); i++)
        {
            printf("%c", complement[i]);
        }
    }
    else
    {
        printf("\nWrong input strings");
    }
    printf("\nData to be transmitted:%s %s ", a, b);
    for (i = 0; i < strlen(a); i++)
    {
        printf("%c", complement[i]);
    }

    printf("\nReceivers side's Side:\n");
    printf("\nData to be transmitted:%s %s ", a, b);
    for (i = 0; i < strlen(a); i++)
    {
        printf("%c", complement[i]);
    }
    carry=0;
    for (i = strlen(a) - 1; i >= 0; i--)
    {
        printf("\nsum[%d]=%c and complement[%d]=%c",i,sum[i],i,complement[i]);
        if (sum[i] == '0' && complement[i] == '0' && carry == '0')
        {
            rsum[i] = '0';
            carry = '0';
        }
        else if (sum[i] == '0' && complement[i] == '0' && carry == '1')
        {
            rsum[i] = '1';
            carry = '0';
        }
        else if (sum[i] == '0' && complement[i] == '1' && carry == '0')
        {
            rsum[i] = '1';
            carry = '0';
        }
        else if (sum[i] == '0' && complement[i] == '1' && carry == '1')
        {
            rsum[i] = '0';
            carry = '1';
        }
        else if (sum[i] == '1' && complement[i] == '0' && carry == '0')
        {
            rsum[i] = '1';
            carry = '0';
        }
        else if (sum[i] == '1' && complement[i] == '0' && carry == '1')
        {
            rsum[i] = '0';
            carry = '1';
        }
        else if (sum[i] == '1' && complement[i] == '1' && carry == '0')
        {
            rsum[i] = '0';
            carry = '1';
        }
        else if (sum[i] == '1' && complement[i] == '1' && carry == '1')
        {
            rsum[i] = '1';
            carry = '1';
        }

        printf("\nrsum[%d]=%c",i,rsum[i]);
    }
    printf("\nSum= ");
    for (i = 0; i < strlen(a); i++)
    {
        printf("%c", rsum[i]);
    }
    for (i = 0; i < strlen(a); i++)
    {
        if (rsum[i] == '0')
            rcomp[i] = '1';
        else
            rcomp[i] = '0';
    }

    if (carry == '1')
        carry = '0';
    else
        carry = '1';
    printf("\nComplement=");
    for (i = 0; i < strlen(a); i++)
    {
        printf("%c", rcomp[i]);
    }
    for (i = 0; i < strlen(a); i++)
    {
        if(rcomp[i]=0)
        {
            f=0;
        }
        else
        {
            f=1;
        }

    }
    if(f==0)
    {
        printf("\nThe data has received correctly!!!\n");
    }
    else
    {
        printf("\nThe data  received is incorrect.\n");
    }

    return 0;
}

/*
10101001
00111001
*/