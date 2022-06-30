#include <stdio.h>
#include <string.h>
#include <math.h>

int ba(int a, int b, int carry, int* c)
{
    if(a==1 && b==1 && carry==1)
    {
        *c=1;
        return 1;
    }
    else if(a+b+carry>1)
    {
        *c=0;
        return 1;
    }
    else
        *c=a+b+carry;
    return 0;
}

int inverter(int c[], int lol)
{
    for(int i=0;i<lol;i++)
    {
        if(c[i]==0)
            c[i]=1;
        else
            c[i]=0;
    }
    int sum=0,j=lol-1;
    for(int i=0;i<lol;i++)
    {
        sum=sum+c[i]*(int)(pow(10,j));
        j--;
    }
    return sum;
}

int checksum(char numbers[], int i1)
{

    int intl_len= (int)strlen(numbers),gg= i1 - intl_len % i1;
    if(intl_len%i1==0)
        gg=0;
    int length= (int)(intl_len) + gg;
    for(int i=0;i<gg;i++)
    {
        numbers[intl_len+i]='0';
    }
    int final[length];
    for(int i=0;i<length;i++)
    {
        if(numbers[i]=='0')
            final[i]=0;
        else
            final[i]=1;
    }
    int trans[i1],overflow[i1];
    for(int i=0;i<i1;i++)
    {
        trans[i]=0;
        overflow[i]=0;
    }
    for (int i=0;i<length/i1;i++)
    {
        int a=0,l=0;
        for(int j=i*i1;j<i*i1+i1;j++)
        {
            a=ba(final[j],trans[l],a,&trans[l]);
            l++;
        }
        if(a==1)
        {
            for(int j=0;j<i1;j++)
            {
                a=ba(trans[j],overflow[j],a,&trans[j]);
            }
        }
    }
    return inverter(trans,i1);
}

int checkrecieve(char numbers[], int i1, int n)
{
    int here= checksum(numbers,i1);
    if(here==n)
        printf("ACCEPTED");
    else
        printf("REJECTED");
}

int binary(int p)
{
    int counter=0,final=0,normal=0;
    int pp[20];
    while(p!=0)
    {
        pp[counter]=p%2;
        counter++;
        p=p/2;
    }
    for(int i=0;i<counter;i++)
    {
        if(pp[i]==1)
            return i;
    }
}

char xor(char a, char b)
{
    if(a==b)
        return '0';
    else
        return '1';
}

char binery(int p, int r)
{
    int counter=0,final=0,normal=0;
    int pp[20];
    while(p!=0)
    {
        pp[counter]=p%2;
        counter++;
        p=p/2;
    }
    if(pp[r]==1)
        return '1';
    else
        return '0';
}

int hamming_sender(char lol[])
{
    int k= (int)strlen(lol);
    int flag=0,required_bits=0;
    while(1)
    {
        if((int)(pow(2, flag))>k+flag+1)
            break;
        flag++;
    }
    flag--;
    required_bits=k+flag;
    char final[required_bits];
    int index=0;
    for(int i=0;i<required_bits;i++)
    {
        int lel=0;
        for(int j=0;j<flag;j++)
        {
            if(i==(int)(pow(2,j))-1)
            {
                lel=1;
            }
        }
        if(lel==1)
            continue;
        final[i]=lol[index];
        index++;
    }
    for(int i=0;i<flag;i++)
    {
        int wow=(int) pow(2,i);
        int catcher=binary(wow);
        int first=0;
        for(int j=wow+1;j<required_bits+1;j++)
        {
            if(binery(j,catcher)=='1')
            {
                if(first==0)
                {
                    final[wow-1]= final[j-1];
                    first=1;
                }
                else
                    final[wow-1]= xor(final[wow-1],final[j-1]);
            }
        }
    }
    for(int i=0;i<required_bits;i++)
        printf("%c",final[i]);
    return flag;
}

void hamming_reciever(char receve[], int flag)
{
    char hehe[10];
    int q=0;
    for(int i=0;i<flag;i++)
    {
        int wow=(int) pow(2,i);
        wow--;
        hehe[q]=receve[wow];
        q++;
    }
    for(int i=0;i<flag;i++)
    {
        int wow=(int) pow(2,i);
        int catcher=binary(wow);
        int first=0;
        for(int j=wow+1;j< strlen(receve)+1;j++)
        {
            if(binery(j,catcher)=='1')
            {
                if(first==0)
                {
                    receve[wow-1]= receve[j-1];
                    first=1;
                }
                else
                    receve[wow-1]= xor(receve[wow-1],receve[j-1]);
            }
        }
    }
    int pep=(int)strlen(receve);
    for(int i=0;i< pep;i++)
        printf("%c",receve[i]);
    printf("\n");
    int decider=0,sum=0;
    for(int i=0;i<flag;i++)
    {
        if(receve[(int)(pow(2,i))-1]!=hehe[i])
        {
            decider=1;
            break;
        }
    }
    if(decider==0)
    {
        printf("No Error found");
        return;
    }

    else
    {
        for(int i=0;i<flag;i++)
        {
            if(receve[(int)(pow(2,i))-1]!=hehe[i])
            {
                receve[(int)(pow(2,i))-1]=hehe[i];
                sum=sum+(int)(pow(2,i));
            }
        }
    }
    sum--;
    if(receve[sum]=='0')
        receve[sum]='1';
    else
        receve[sum]='0';
    printf("The corrected thing is ");
    for(int i=0;i<pep;i++)
        printf("%c",receve[i]);

}




void crc_sender(char divisor[])
{
    char numbers[20];
    scanf("%s",numbers);
    int gg= (int)strlen(divisor)-1, length= (int)strlen(numbers);
    char remainder[gg+1];
    for(int i=0;i<gg+1;i++)
    {
        remainder[i]=numbers[i];
    }
    for(int i=0;i<gg+1;i++)
    {
        numbers[length+i]='0';
    }
    for(int i=0;i<length;i++)
    {
        for(int p=0;p<gg+1;p++)
            printf("%c",remainder[p]);
        printf("\n");
        if(remainder[0]=='0')
        {
            for(int j=0;j<gg+1;j++)
            {
                remainder[j-1]= xor(remainder[j],'0');
            }
        }
        else
        {
            for(int j=0;j<gg+1;j++)
            {
                remainder[j-1]= xor(remainder[j],divisor[j]);
            }
        }
        remainder[gg]=numbers[i+gg+1];
    }
    for(int p=0;p<gg;p++)
        printf("%c",remainder[p]);
}

void crc_verifier(char divisor[])
{
    char numbers[20];
    scanf("%s",numbers);
    int gg= (int)strlen(divisor)-1, length= (int)strlen(numbers);
    length=length-gg;
    char remainder[gg+1];
    for(int i=0;i<gg+1;i++)
    {
        remainder[i]=numbers[i];
    }
    for(int i=0;i<length;i++)
    {
        for(int p=0;p<gg+1;p++)
            printf("%c",remainder[p]);
        printf("\n");
        if(remainder[0]=='0')
        {
            for(int j=0;j<gg+1;j++)
            {
                remainder[j-1]= xor(remainder[j],'0');
            }
        }
        else
        {
            for(int j=0;j<gg+1;j++)
            {
                remainder[j-1]= xor(remainder[j],divisor[j]);
            }
        }
        remainder[gg]=numbers[i+gg+1];
    }
    for(int p=0;p<gg;p++)
        printf("%c",remainder[p]);
}

void stop_recieve(int n, int lol, int peww)
{
    char haha[20];
    printf("Enter the recieved code ");
    scanf("%s",haha);
    int kekw= checksum(haha,n/2);
    if(lol==kekw)
        return;
    while(1)
    {
        printf("Error, sending frame %d again\n",peww);
        printf("Enter the recieved code ");
        scanf("%s",haha);
        kekw= checksum(haha,n/2);
        if(lol==kekw)
            return;
    }
}


void stop_wait()
{
    int n;
    scanf("%d",&n);
    char p[30];
    scanf("%s",p);

    for(int i=0;i< strlen(p)/n;i++)
    {
        char rr[n];
        for(int j=0;j<n;j++)
            rr[j]=p[i*n+j];
        int lol=checksum(rr,n/2);
        printf("Frame%d %s %d\n",i,rr,lol);
        stop_recieve(n,lol,i);
    }
}


int main()
{
    int x;
    scanf("%d",&x);
    switch (x)
    {
        case 1:
            stop_wait();
            break;
        case 2:
            printf("How many bits in the checksum? ");
            int r;
            scanf("%d",&r);
            printf("Enter the input string ");
            char wow[30];
            scanf("%s",wow);
            int pp=checksum(wow,r);
            printf("Enter the received string ");
            scanf("%s",wow);
            checkrecieve(wow,r,pp);
            break;
        case 3:
            printf("Enter the divisor ");
            char devisor[10];
            scanf("%s",devisor);
            crc_sender(devisor);
            printf("\nEnter the recieved string ");
            crc_verifier(devisor);
            break;
        case 4:
            printf("Enter the string ");
            char sala[20];
            scanf("%s",sala);
            int flag=hamming_sender(sala);
            printf("\nEnter the recieved string ");
            scanf("%s",sala);
            hamming_reciever(sala,flag);
    }
}
