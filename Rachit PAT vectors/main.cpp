#include <iostream>

class vector
{
    int a,b,c;
public:
    vector()
    {
        std::cin>>a>>b>>c;
    }
    vector(int p,int q, int r)
    {
        a=p;
        b=q;
        c=r;
    }
    friend void operator +(vector,vector);
    friend void operator -(vector,vector);
};

void operator +(vector A, vector B)
{
    vector D(0,0,0);
    D.a=A.a+B.a;
    D.b=A.b+B.b;
    D.c=A.c+B.c;

    std::cout<<D.a<<"\n"<<D.b<<"\n"<<D.c;
}

void operator -(vector A, vector B)
{
    vector D;
    D.a=A.a-B.a;
    D.b=A.b-B.b;
    D.c=A.c-B.c;

    std::cout<<D.a<<"\n"<<D.b<<"\n"<<D.c;
}

int main()
{
    vector cat;
    vector dog;
    cat+dog;
    cat-dog;
}