#include <iostream>
using namespace std;

class A
{
int a,b;
public:
    A()
    {
        scanf("%d %d",&a,&b);
    }

    void operator +(A &kat)
    {
        kat.a=a+kat.a;
        kat.b=b+kat.b;
    }
    void printer()
    {
        cout<<a<<"\n"<<b<<endl;
    }
};

int main()
{
    A pain,otherpain;
    pain+otherpain;
    pain.printer();
    otherpain.printer();
}
