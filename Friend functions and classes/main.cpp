#include <iostream>
using namespace std;

class A{
    int a=11;
    int b=12;
    friend void changer(A*,int p, int q);
    friend class dog;
};
void changer(A* rr, int p, int q){
    rr->a=p;
    rr->b=q;
};
class dog{
    int k=250;
public:
    void kk(A cat)
    {
        int r=(cat.a+cat.b)/k;
        cout<<r<<endl;
    }
};
int main()
{
    class A cat;
    class dog bow;
    changer(&cat, 2000,500);
    bow.kk(cat);
}