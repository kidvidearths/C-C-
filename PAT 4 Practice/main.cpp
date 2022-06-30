#include <iostream>
using namespace std;



template <class meow>
class test
{
    meow a,b;
public:
    test(meow dog, meow jj)
    {
        a=dog;
        b=jj;
    }
    void printer()
    {
        cout<<a<<" "<<b;
    }
};

template <class betterthannothing>
class derived:public test <betterthannothing>
{
public:
    derived(betterthannothing pp, betterthannothing rr):test<betterthannothing>(pp,rr)
    {

    }

};

template <class yoyo, class tatta>
void fn(yoyo a,tatta b)
{
    cout<<a<<" "<<b;
}

int main()
{
    derived<float> silk(85.55,22.333);
    fn(24.34543,'a');
}
