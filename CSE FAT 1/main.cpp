#include <iostream>
#include <list>
using namespace std;

list <int> king[12];

bool flag;
class cordinate
{
public:
    int xstar, ystar, xend, yend;
    cordinate()
    {
        cin>>xstar>>ystar>>xend>>yend;
        if(xstar==xend)
        {
            if(ystar>yend)
            {
                int temp=yend;
                yend=ystar;
                ystar=temp;
            }
        }
        if(ystar==yend)
        {
            if(xstar>xend)
            {
                int temp=xend;
                xend=xstar;
                xstar=temp;
            }
        }
    }
    void comp(cordinate pp, int i)
    {
        flag=false;
        if(xend==pp.xstar && yend==pp.ystar)
        {
            king[i].push_back(pp.xend);
            king[i].push_back(pp.yend);
            flag=true;
        }
    }
};

int main()
{
    int n;
    cin>>n;
    cordinate evt[n];
    for (int i=0;i<n;i++)
    {
        evt[i];
    }
    for (int j=0;j<n;j++)
    {
        int rr=j;
        king[j].push_back(evt[j].xstar);
        king[j].push_back(evt[j].ystar);
        king[j].push_back(evt[j].xend);
        king[j].push_back(evt[j].yend);
        for (int i=j;i<n-1;i++)
        {
            evt[rr].comp(evt[i+1],j);
            if (flag==1)
            {
                rr=i+1;
            }
        }
    }
    list <int> ::iterator ss;

    int lodd=0;
    int para=0;

    for (int i=0;i<n;i++)
    {
        if(king[i].size()>lodd)
        {
            lodd=king[i].size();
            para=i;
        }
    }
    int useless=0;
    for(ss=king[para].begin();ss!=king[para].end();ss++)
    {
        if(useless%2==0)
        {
            cout<<*ss<<"\t";
        }
        else
        {
            cout<<*ss<<endl;
        }
        useless++;
    }
}
