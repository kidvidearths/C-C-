#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int vertices;
    list<int> *ar;
public:
    Graph(int lala);
    void insert(int p, int q);
    void BFS(int ss);
    void printer();
};

Graph::Graph(int lala)
{
    vertices=lala;
    ar=new list<int>[vertices];
}

void Graph::insert(int p, int q)
{
    ar[p].push_back(q);
    ar[q].push_back(p);
}

void Graph::BFS(int ss)
{
    list<int> queue;
    bool *tester=new bool[vertices];
    for (int i=0;i<vertices;i++)
    {
        tester[i]=false;
    }
    queue.push_back(ss);
    tester[ss]=true;
    list<int>::iterator bowbow;
    while(!queue.empty())
    {
        int i=queue.front();
        cout<<i<<" ";
        queue.pop_front();
        for(bowbow=ar[i].begin();bowbow!=ar[i].end();bowbow++)
        {
            int temp=*bowbow;
            if (!tester[temp])
            {
                tester[temp]=true;
                queue.push_back(temp);
            }
        }
    }
}

void Graph::printer()
{
    list<int>:: iterator cats;
    for(int k=0;k<vertices;k++)
    {
        for(cats=(*ar).begin();cats!=(*ar).end();cats++)
        {
            cout<<*cats<<" ";
        }
        ar++;
        printf("\n");
    }

}

int main()
{
    Graph t(4);
    t.insert(0,1);
    t.insert(1,2);
    t.insert(2,0);
    t.insert(2,3);
    t.insert(3,3);
    t.printer();
}
