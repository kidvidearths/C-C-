#include <iostream>
using namespace std;

class A{
public:
    int a=44;
    int b=22;
    void printah(A)
    {
        cout<<a<<" "<<A::b<<endl;
    }
    void operator +( A &lol)
    {
        lol.a=a+lol.b;
        lol.b=b+lol.a;
    }
};


int main()
{
    A cat;
    A rat;
    cat+rat;
    rat.printah(rat);
}
