#include <iostream>
using namespace std;

void kat(int x)
{
    cout<<x*x<<endl;
}

void kat(char x)
{
    cout<<"BRUH"<<endl;
}
void kat(int x, int y)
{
    cout<<x*y<<endl;
}
void kat(float x)
{
    cout<<x<<endl;
}
int main()
{
    kat(5);
    kat('b');
    kat(2,4);
}
