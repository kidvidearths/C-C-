#include <iostream>

using namespace std;

class Pp
{
    int b;
    int c;
public:
    Pp()
    {
        b=82;
        c=40;
    }
    Pp(int ca, int da)
    {
        b=ca;
        c=da;
    }
    void operator -(Pp &kk)
    {
        kk.b=-kk.b;
        kk.c=-kk.c;
    }
    Pp operator >>(Pp &l)
    {
        b=l.c;
        return Pp;
    }
    void printer()
    {
        cout<<b<<"\n"<<c;
    }
};


int main()
{
    Pp small;
    Pp large(200,855);
    large>>small;
    large.printer();
}
