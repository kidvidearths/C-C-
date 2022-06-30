#include <iostream>
using namespace std;
class bowbow{
    int rat, dog;
public:
    bowbow(int x, int y)
    {
        rat=x;
        dog=y;
    }
    bowbow(bowbow &x)
    {
        rat = x.rat;
        dog = x.dog;
    }
    void printah();
};
void bowbow::printah()
{
    cout<<rat<<endl;
    cout<<dog<<endl;
}
int main()
{
    bowbow adhabowli(22,55);
    bowbow nallakukka(adhabowli);
    nallakukka.printah();
}
