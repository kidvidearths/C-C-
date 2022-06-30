#include <stdio.h>

void add(int* ka,int* pa,int* stor, int numbah)
{
    for(int i=0;i<(numbah*numbah);i++)
    {
        *(stor+i)=*(ka+i)+*(pa+i);
    }
}

void sub(int* ka,int* pa,int* stor, int numbah)
{
    for(int i=0;i<(numbah*numbah);i++)
    {
        *(stor+i)=*(ka+i)-*(pa+i);
    }
}

void combinah(int *pa, int* da, int* stor,int numbah)
{
    for(int i=0;i<(numbah*numbah);i++)
    {
        *(stor+i)=*(pa+i);
    }
    int k=0;
    for(int i=(numbah*numbah);i<2*(numbah*numbah);i++)
    {
        *(stor+i)=*(da+k);
        k++;
    }
}

void finaliser(int numbah,int* lala, int* f1, int* f2,int* f3,int* f4)
{
    int k=0;
    int l=0,r=1;
    for (int asta=0;asta<numbah;asta++)
    {
        for(int i=l*numbah;i<r*numbah;i++)
        {
            *(lala+i)=*(f1+k);
            k=k+1;
        }
        l=l+2,r=r+2;
    }
    k=0,l=1,r=2;
    for (int asta=0;asta<numbah;asta++)
    {
        for(int i=l*numbah;i<r*numbah;i++)
        {
            *(lala+i)=*(f2+k);
            k=k+1;
        }
        l=l+2,r=r+2;
    }
    k=0,l=2*numbah,r=l+1;
    for (int asta=0;asta<numbah;asta++)
    {
        for(int i=l*numbah;i<r*numbah;i++)
        {
            *(lala+i)=*(f3+k);
            k=k+1;
        }
        l=l+2,r=r+2;
    }
    k=0,l=(2*numbah)+1,r=l+1;
    for (int asta=0;asta<numbah;asta++)
    {
        for(int i=l*numbah;i<r*numbah;i++)
        {
            *(lala+i)=*(f4+k);
            k=k+1;
        }
        l=l+2,r=r+2;
    }
}

void add4(int *ka, int* pa, int* la, int* sa, int* stor, int numbah)
{
    for(int i=0;i<(numbah*numbah);i++)
    {
        *(stor+i)=*(ka+i)+*(pa+i)-*(la+i)+*(sa+i);
    }
}
void sub2(int *ka, int* pa, int* la, int* sa, int* stor, int numbah)
{
    for(int i=0;i<(numbah*numbah);i++)
    {
        *(stor+i)=*(ka+i)+*(pa+i)-*(la+i)-*(sa+i);
    }
}

void splitter(int numbah,int* lala, int* a, int* b,int* c,int* d,int* e,int* f,int* g,int* h)
{
    for (int countah=0;countah<2;countah++)
    {
        int k=0;
        if(countah==1)
        {
            a=e,b=f,c=g,d=h;
            lala=lala+(4*numbah*numbah);
        }
        int l=0,r=1;
        for (int asta=0;asta<numbah;asta++)
        {
            for(int i=l*numbah;i<r*numbah;i++)
            {
                *(a+k)=*(lala+i);
                k=k+1;
            }
            l=l+2,r=r+2;
        }
        k=0,l=1,r=2;
        for (int asta=0;asta<numbah;asta++)
        {
            for(int i=l*numbah;i<r*numbah;i++)
            {
                *(b+k)=*(lala+i);
                k=k+1;
            }
            l=l+2,r=r+2;
        }
        k=0,l=2*numbah,r=l+1;
        for (int asta=0;asta<numbah;asta++)
        {
            for(int i=l*numbah;i<r*numbah;i++)
            {
                *(c+k)=*(lala+i);
                k=k+1;
            }
            l=l+2,r=r+2;
        }
        k=0,l=(2*numbah)+1,r=l+1;
        for (int asta=0;asta<numbah;asta++)
        {
            for(int i=l*numbah;i<r*numbah;i++)
            {
                *(d+k)=*(lala+i);
                k=k+1;
            }
            l=l+2,r=r+2;
        }
    }
}



void mu(int numbah,int* lala, int* onlyfornow)
{
    if(numbah==2)
    {
        int a,b,c,d,e,f,g,h,p1,p2,p3,p4,p5,p6,p7;
        a=*lala;
        b=*(lala+1);
        c=*(lala+2);
        d=*(lala+3);
        e=*(lala+4);
        f=*(lala+5);
        g=*(lala+6);
        h=*(lala+7);
        p1=a*(f-h);
        p2=(a+b)*h;
        p3=(c+d)*e;
        p4=d*(g-e);
        p5=(a+d)*(e+h);
        p6=(b-d)*(g+h);
        p7=(a-c)*(e+f);
        *(onlyfornow)=p5+p4-p2+p6;
        *(onlyfornow+1)=p1+p2;
        *(onlyfornow+2)=p3+p4;
        *(onlyfornow+3)=p1+p5-p3-p7;
    }
    else
    {
        numbah=numbah/2;
        int a[numbah][numbah],b[numbah][numbah],c[numbah][numbah],d[numbah][numbah],e[numbah][numbah],f[numbah][numbah],g[numbah][numbah],h[numbah][numbah];
        int p1[numbah][numbah],p2[numbah][numbah],p3[numbah][numbah],p4[numbah][numbah],p5[numbah][numbah],p6[numbah][numbah],p7[numbah][numbah];
        int f1[numbah][numbah],f2[numbah][numbah],f3[numbah][numbah],f4[numbah][numbah], t1[numbah][numbah], t2[numbah][numbah],temp[2][numbah][numbah];
        splitter(numbah,lala,&a[0][0],&b[0][0],&c[0][0],&d[0][0],&e[0][0],&f[0][0],&g[0][0],&h[0][0]);


        sub(&f[0][0],&h[0][0],&t1[0][0],numbah);
        combinah(&a[0][0],&t1[0][0],&temp[0][0][0],numbah);
        mu(numbah,&temp[0][0][0],&p1[0][0]);
        add(&a[0][0],&b[0][0],&t2[0][0],numbah);
        combinah(&t2[0][0],&h[0][0],&temp[0][0][0],numbah);
        mu(numbah,&temp[0][0][0],&p2[0][0]);
        add(&c[0][0],&d[0][0],&t2[0][0],numbah);
        combinah(&t2[0][0],&e[0][0],&temp[0][0][0],numbah);
        mu(numbah,&temp[0][0][0],&p3[0][0]);
        sub(&g[0][0],&e[0][0],&t1[0][0],numbah);
        combinah(&d[0][0],&t1[0][0],&temp[0][0][0],numbah);
        mu(numbah,&temp[0][0][0],&p4[0][0]);
        add(&a[0][0],&d[0][0],&t1[0][0],numbah);
        add(&e[0][0],&h[0][0],&t2[0][0],numbah);
        combinah(&t1[0][0],&t2[0][0],&temp[0][0][0],numbah);
        mu(numbah,&temp[0][0][0],&p5[0][0]);
        sub(&b[0][0],&d[0][0],&t1[0][0],numbah);
        add(&g[0][0],&h[0][0],&t2[0][0],numbah);
        combinah(&t1[0][0],&t2[0][0],&temp[0][0][0],numbah);
        mu(numbah,&temp[0][0][0],&p6[0][0]);
        sub(&a[0][0],&c[0][0],&t1[0][0],numbah);
        add(&e[0][0],&f[0][0],&t2[0][0],numbah);
        combinah(&t1[0][0],&t2[0][0],&temp[0][0][0],numbah);
        mu(numbah,&temp[0][0][0],&p7[0][0]);
        add4(&p5[0][0],&p4[0][0],&p2[0][0],&p6[0][0],&f1[0][0],numbah);
        add(&p1[0][0],&p2[0][0],&f2[0][0],numbah);
        add(&p3[0][0],&p4[0][0],&f3[0][0],numbah);
        sub2(&p1[0][0],&p5[0][0],&p3[0][0],&p7[0][0],&f4[0][0],numbah);
        finaliser(numbah,onlyfornow,&f1[0][0],&f2[0][0],&f3[0][0],&f4[0][0]);
    }
}

int main()
{
    int starter;
    scanf("%d",&starter);
    int holder[2][starter][starter];
    int final[starter][starter];
    for (int kar=0;kar<2;kar++)
    {
        for(int i=0;i<starter;i++)
        {
            for(int j=0;j<starter;j++)
                scanf("%d",&holder[kar][i][j]);
        }
    }
    mu(starter,&holder[0][0][0],&final[0][0]);
    for(int i=0;i<starter*starter;i++)
        printf("%d\n",*(&final[0][0]+i));
}