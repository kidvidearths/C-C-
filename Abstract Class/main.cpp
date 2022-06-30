#include <iostream>
using namespace std;

class A{
protected:
    int a,b;
public:
    void add()
    {
        cout<<a+b<<endl;
    }
    void subtract()
    {
        cout<<a-b<<endl;
    }
    virtual void setter(int k, int l)=0;
};

class B : public A{
public:
    void multiplier()
    {
        cout<<a*b<<endl;
    }
};

class C : public B{
public:
    void setter(int k, int l)
    {
        a=k;
        b=l;
    }
};

int main()
{
    class C dog;
    dog.setter(5,6);
    dog.add();
    dog.subtract();
    dog.multiplier();
}
