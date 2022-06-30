#include <iostream>
#include <map>
#include <iterator>
#include <list>
using namespace std;

class Graph
{
public:
    map<int,list<int>> keeper;
    map<int,bool> tester;
    void insert(int k, int kay);
    void DFS(int ver);
};

void Graph::insert(int k, int kay)
{
    keeper[k].push_back(kay);
}

void Graph::DFS(int ver)
{
    tester[ver]=true;
    cout<<ver<< " ";

    list<int>::iterator pilli;
    for(pilli=keeper[ver].begin();pilli!=keeper[ver].end();pilli++)
    {
        if(!tester[*pilli])
            DFS(*pilli);
    }

}

int main()
{
    Graph mess;
    mess.insert(0, 1);
    mess.insert(0, 9);
    mess.insert(1, 2);
    mess.insert(2, 0);
    mess.insert(2, 3);
    mess.insert(9, 3);
    mess.DFS(2);
}