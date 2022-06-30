#include <iostream>
using namespace std;

class A{
    int a=25;
    void increasah()
    {
        a++;
        cout<<a<<endl;
    }
protected:
    void love()
    {
        increasah();
    }
};
class B : private A{
protected:
    int b=11;
public:
    void Callah()
    {
        love();
        cout<<b<<endl;
    }
};
class C : private B{
    public:
    void trust()
    {
        b++;
        Callah();
    }
};
int main()
{
    class C cat;
    cat.trust();
}
