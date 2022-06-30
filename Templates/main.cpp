#include <iostream>
using namespace std;

template <class rand>
class tester
{
    rand b1='2';
    rand b2='8';
public:
    void changer(rand c, rand d)
    {
        b1=c;
        b2=d;
        cout<<b1<<" "<<b2<<endl;
    }
    void printer()
    {
        cout<<b1<<" "<<b2<<endl;
    }
};

int main()
{
    tester <char> cat;
    cat.printer();
    cat.changer('c','d');
}