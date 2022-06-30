#include <iostream>
using namespace std;

int main()
{
    int cats;
    cin>>cats;
    int *pp;
    pp=new int[cats];
    for (int i=0;i<cats;i++)
    {
        cin>>*(pp+i);
    }
    for (int i=0;i<cats;i++)
    {
        cout<<*(pp+i);
    }

}
