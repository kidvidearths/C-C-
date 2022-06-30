#include <iostream>
using namespace std;

class A{
public:
    int a=20;
    void changer()
    {
        a=33;
        cout<<a<<endl;
    }
};

class B : virtual public A{
public:
    B()
    {
        a=10;
    }
    void nothing()
    {
        cout<<"1st one "<<a<<endl;
    }
};

class C : virtual public A{
public:
    C()
    {
        a=30;
    }
    void nothing()
    {
        cout<<"2nd one "<<a<<endl;
    }
};

class D: public B, public C{
public:
    void finah()
    {
        cout<<"ONE AND ONLY "<<a<<endl;
    }
};


int main()
{
    class D doggie;
    doggie.finah();
    doggie.changer();
}
