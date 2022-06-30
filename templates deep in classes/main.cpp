#include <iostream>
using namespace std;

template <class rando>
class A{
public:
    rando cambell;
    A(rando ssd)
    {
        cambell=ssd;
        cout<<cambell<<endl;
    }
    void changer(rando kk)
    {
        cambell=kk;
        cout<<cambell<<endl;
    }
};

template <class yolo>
class B : public A<yolo>
{
public:
    B(yolo something) : A<yolo>(something)
    {

    }
};

int main()
{

    B <float> test(28.235);
    test.changer(800.235);

}
