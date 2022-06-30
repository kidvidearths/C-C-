#include <iostream>
using namespace std;
class rectangle
{
    int length,breadth;
public:
    rectangle()
    {
        length=0;
        breadth=0;
        area();
    }
    rectangle(int q, int r)
    {
        length=q;
        breadth=r;
        area();
    }
    rectangle(int k)
    {
        length=k;
        breadth=k;
        area();
    }
    void area()
    {
        int cat;
        cat=length*breadth;
        cout<<cat<<endl;
    }
};
int main()
{
    int p;
    int r;
    cin>>p;
    cin>>r;
    rectangle a;
    rectangle b(p,r);
    rectangle c(p);
}