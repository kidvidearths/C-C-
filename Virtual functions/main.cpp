#include <iostream>
using namespace std;

class A{
public:
    virtual void incresah()
    {
        cout<<"BRUH"<<endl;
    }
};

class B : public A{
public:
    void incresah()
    {
        cout<<"LMAO"<<endl;
    }
};

class C : public B{
public:
    void incresah()
    {
        cout<<"UH OH"<<endl;
    }
};

int main()
{
    class A* pp;
    class C koja;
    pp=& koja;
    pp->incresah();
}
