#include <iostream>
using namespace std;
class addamount
{
    int amount=50;
public:
    addamount()
    {
        display();
    }
    addamount(int r)
    {
        amount=amount+r;
        display();
    }
    int display()
    {
        cout<<amount<<endl;
    }
};
int main()
{
    int q;
    cin>>q;
    addamount r;
    addamount t(q);
    return 0;
}