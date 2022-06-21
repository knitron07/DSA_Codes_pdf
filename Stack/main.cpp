
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
//Adjacency list using hash map---------------------------------------------------------------------------------------------------------
#include <iostream>
#include <unordered_map>
#include <list>
#include <cstring>

using namespace std;

class Graph
{
    unordered_map<string ,list<pair<string,int>>> m;
    
public:
    void addEdge(string x,string y,int weight,bool bidir)
    {
        m[x].push_back(make_pair(y,weight));
        if(bidir)
        {
            m[y].push_back(make_pair(x,weight));
            }
        }
        
        
    void printAdjList()
    {
        for(auto p:m)
        {
            string city=p.first;
            list<pair<string,int>> nbrs=p.second;
            cout<<city<<"--> ";
            
            for(auto nbr:nbrs)
            {
                string nbr_city=nbr.first;
                int dist=nbr.second;
                cout<<nbr_city<<" "<<dist<<" , ";
                }
            cout<<endl;
            }
        }
    };
    
    
int main()
{
    Graph g;
    
    g.addEdge("A","B",20,true);
    g.addEdge("D","B",40,true);
    g.addEdge("A","C",10,true);
    g.addEdge("C","D",40,true);
    g.addEdge("A","D",50,false);
    g.printAdjList();

    return 0;
    }
//-------------------------------------------------------------------------------------------------------------------------------------------