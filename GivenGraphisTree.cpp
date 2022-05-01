#include<iostream>
#include <list>
#include <limits.h>
using namespace std;

class Graph{
    int v;
    list<int>*adj;
    bool isCyclicUtil(int v, bool visited[], int parent);
    public:
        Graph(int v);
        void addEdge(int v, int w);
        bool isTree();
}

Graph::Graph(int v){
    this->v=v;
    adj=new list<int>[v];
}
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}
bool Graph::isCyclicUtil(int v, bool visited[], int parent){
    visite[v] = true;
    list<int>:: iterator i;
    for(i=adj[v].begin();i!=adj[v].end;i++)
    {
        if(!visited[*i])
        {
            if(isCyclicUtil(*i, visited,v))
                return true;
        }
        else if(*i!=parent)
            return true;
    }
    return false;
}
bool Graph:: isTree()
{
    bool *visited = new bool[v];
    for(int i=0;i<v;i++)
        visited[i]=false;
    if(isCyclicUtil(0,visited,-1))
        return false;
    for(int u-0;u<v;i++)
        if(!visited[u])
            return false;
    return true;
}
int main()
{
    Graph g = new Graph(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
    if(g.isTree())
        cout<<"Tree";
    else
        cout<<"Not a Tree";
    return 0;
}
