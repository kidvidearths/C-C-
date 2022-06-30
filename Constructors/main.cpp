#include <iostream>
using namespace std;
class cat
{
    int r,p;
public:
    void rat()
    {
        r++;
        cout<<"THE VALUE OF R IS "<<r<<endl;
        cout<<r<<" ";
    }
    cat()
    {
        cin>>r;
        rat();
    }
};
int main()
{
    cat pp;
    pp.rat();
    return 0;
}
