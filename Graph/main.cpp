
//Adjacency list---------------------------------------------------------------------------------------------------------
#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *l;
    
public:
    
    Graph(int v)
    {
        V=v;
        l=new list<int>[V];
        }
        
    void addEdges(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
        }
        
    void printAdjlist()
    {
        for(int i=0;i<V;i++)
        {
            cout<<"Vertex "<<i<<" --> ";
            for(auto x:l[i])
            {
                cout<<x<<" , ";
                }
            cout<<endl;
            }
        }
    };

int main()
{
    Graph g(4);
    g.addEdges(1,2);
    g.addEdges(0,2);
    g.addEdges(2,3);
    g.addEdges(0,1);
    
    g.printAdjlist();
    return 0;
    }

//---------------------------------------------------------------------------------------------------------------------------//