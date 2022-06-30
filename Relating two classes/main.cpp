#include <iostream>
using namespace std;

class gay{
public:
    int archa=22;
    void changer()
    {
        archa++;
        cout<<archa<<endl;
    }
};

class nohomo{
private:
void betterthannothing(class gay cat)
{
    cat.changer();
}
public:
    void therealworld(class gay cat)
    {
    betterthannothing(cat);
    }
};

int main()
{
    gay gay;
    nohomo cat;
    cat.therealworld(gay);
}
