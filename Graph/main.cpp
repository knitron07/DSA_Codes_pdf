
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
//Weighted graph-------------------------------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------------------------
// BFS Trav  of graph
#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;
template<typename T>
class Graph
{
    map <T,list<T>> m;
    
public:
    void addEdge(T x,T y)
    {
        m[x].push_back(y);
        m[y].push_back(x);
        }
        
    void bfs(T src)
    {
        map <T,bool> visited;
        queue<T> q;
        
        q.push(src);
        visited[src]=true;
        
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            cout<<node<<" ";
            for(auto nbr: m[node] )
            {
                if(visited[nbr]==false)
                {
                    q.push(nbr);
                    visited[nbr]=true;
                    }
                }
            }
        }
    };
int main()
{
    
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.bfs(0);

    return 0;
    }

// BFS shortest path------------------------------------------
#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <climits>
using namespace std;
template<typename T>
class Graph
{
    map <T,list<T>> m;
    
public:
    void addEdge(T x,T y)
    {
        m[x].push_back(y);
        m[y].push_back(x);
        }
        
    void bfs(T src)
    {
        map <T,int> dist;
        queue<T> q;
        
        for(auto node_pair: m)
        {
            T node=node_pair.first;
            dist[node]=INT_MAX;
            }
        q.push(src);
        dist[src]=0;
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            for(auto nbr: m[node] )
            {
                if(dist[nbr]==INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr]=dist[node]+1;
                    }
                }
            }
        for(auto node_pair:m)
        {
            T node =node_pair.first;
            int distance=dist[node];
            cout<<"Distance of "<<node<<" from "<<src<<" is "<<distance<<endl;
            }
        }
        
        
    };
int main()
{
    
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.bfs(0);

    return 0;
    }
//snake sssd------------------------------------------------------------
#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <climits>
using namespace std;
template<typename T>
class Graph
{
    map <T,list<T>> m;
    
public:
    void addEdge(T x,T y)
    {
        m[x].push_back(y);
        }
        
    int  bfs(T src,T dest)
    {
        map <T,int> dist;
        map <T,T> parent;
        queue<T> q;
        
        for(auto node_pair: m)
        {
            T node=node_pair.first;
            dist[node]=INT_MAX;
            }
        q.push(src);
        dist[src]=0;
        parent[src]=src;
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            for(auto nbr: m[node] )
            {
                if(dist[nbr]==INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr]=dist[node]+1;
                    parent[nbr]=node;
                    }
                }
            }
        for(auto node_pair:m)
        {
            T node =node_pair.first;
            int distance=dist[node];
            cout<<"Distance of "<<node<<" from "<<src<<" is "<<distance<<endl;
            }
            cout<<endl;
            
            T temp=dest;
            while(temp!=src)
            {
                cout<<temp<<"<--";
                temp=parent[temp];
                }
                cout<<src;
                
            cout<<endl;
        return dist[dest];
        }
    };
int main()
{
    
    Graph<int> g;
    
    int board[50]{0};
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=10;
    board[20]=20;
    board[20]=20;
    board[20]=20;
    board[32]=-2;
    board[34]=-22;

    for(int i=0;i<=36;i++)
    {
        for(int dice=1;dice<=6;dice++)
        {
            int j=i+dice;
            j+=board[j];
            if(j<=36)
            {
                g.addEdge(i,j);
                }
            }
        }
    g.addEdge(36,36);
   cout<< g.bfs(1,36);

    return 0;
    }
//DFS TRAV-----------------------------------------------------------------------
#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;
template<typename T>
class Graph
{
    map <T,list<T>> m;
public:
    void addEdge(T x,T y)
    {
        m[x].push_back(y);
        m[y].push_back(x);
        }
        
        
    void dfs_helper(T node,map <T,bool> &visited)
    {
        cout<<node<<" ";
        visited[node]=true;
        
        for(auto nbr:m[node])
        {
            if(visited[nbr]==false)
            {
                dfs_helper(nbr,visited);
                }
            }
            
        return;
        }
    void dfs(T src)
    {
        map <T,bool> visited;
        //marking all node as not visited
        for(auto node_pair:m)
        {
            T node=node_pair.first;
            visited[node]=false;
            }
            
        // calling recursion function
        dfs_helper(src,visited);
        }
    };
int main()
{
    
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.dfs(0);

    return 0;
    }
//connected components using dfs--------------------------------------------------
#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;
template<typename T>
class Graph
{
    map <T,list<T>> m;
public:
    void addEdge(T x,T y)
    {
        m[x].push_back(y);
        m[y].push_back(x);
        }
        
        
    void dfs_helper(T node,map <T,bool> &visited)
    {
        cout<<node<<" ";
        visited[node]=true;
        
        for(auto nbr:m[node])
        {
            if(visited[nbr]==false)
            {
                dfs_helper(nbr,visited);
                }
            }
            
        return;
        }
    void dfs(T src)
    {
        map <T,bool> visited;
        //marking all node as not visited
        for(auto node_pair:m)
        {
            T node=node_pair.first;
            visited[node]=false;
            }
            
        // for finding connected component
        int count{1};
        for(auto node_pair:m)
        {
            T node=node_pair.first;
              if(visited[node]==false)
              {
                  cout<<"Component "<<count<<" -> ";
                  dfs_helper(node,visited);
                  cout<<endl;
                  count++;
                  }
            }
       cout<<count<<endl;
        }
    };
int main()
{
    
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(8,8);


    g.dfs(0);

    return 0;
    }
//topological sort----------------------------------------------------------------------------
#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <string>
using namespace std;
template<typename T>
class Graph
{
    map <T,list<T>> m;
public:
    void addEdge(T x,T y)
    {
        m[x].push_back(y);
        }
        
        
    void dfs_helper(T node,map <T,bool> &visited, list<T>&ordering)
    {
        visited[node]=true;
        
        for(auto nbr:m[node])
        {
            if(visited[nbr]==false)
            {
                dfs_helper(nbr,visited,ordering);
                }
            }
            
        ordering.push_front(node);
        return;
        }
    void dfs(T src)
    {
        map <T,bool> visited;
        list<T> ordering;
        //marking all node as not visited
        for(auto node_pair:m)
        {
            T node=node_pair.first;
            visited[node]=false;
            }
            

        for(auto node_pair:m)
        {
            T node=node_pair.first;
              if(visited[node]==false)
              {
                  dfs_helper(node,visited,ordering);
                  
              }
            }
       
       for(auto node : ordering)
           cout<<node<<"-->";
        cout<<endl;
        }
    };
int main()
{
    
    Graph<string> g;
    g.addEdge("python","data processing");
    g.addEdge("python","pytorch");
    g.addEdge("python","ML basics");
    g.addEdge("pytorch","DL");
    g.addEdge("ML basics","DL");
    g.addEdge("DL","Face Recognititon");
    g.addEdge("Data Set","Face Recognititon");
//g.add_edge(1,2);
//     g.add_edge(1,3);
//      g.add_edge(1,4);
//       g.add_edge(2,3);
//        g.add_edge(3,5);
//         g.add_edge(4,5);
//          g.add_edge(5,7);
//           g.add_edge(6,7);

    g.dfs("python");

    return 0;
    }
//topological sort using bfs indegree concept---------------------------------------------------------------------------------
#include <iostream>
#include <map>
#include <list>
#include <queue>

using namespace std;
template<typename T>
class Graph
{
    T v;
    list<T>* l;
    
public:
    Graph(int V)
    {
        v=V;
        l=new list<T>[v];
        }
        
    void addEdge(T x,T y)
    {
        l[x].push_back(y);
        }
        
    void bfs()
    {
        T *indegree=new T[v];
        for(int i=0;i<v;i++)
        {
            indegree[i]=0;
            }
            
        // making count of node's indegree
        for(int i=0;i<v;i++)
        {
            for(auto nbr:l[i])
            {
                indegree[nbr]++;
                }
            }
            
        // calling bfs when indegree is 0
        
        queue<int> q;
        //step 1.  pushing element whose indegree is zero;
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
                q.push(i);
            }
            
        //step2 . moving to there nbr
        while(!q.empty())
        {
            int node =q.front();
            q.pop();
            cout<<node<<" ";
            for(auto nbr: l[node])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                {
                    q.push(nbr);
                    }
                }
            }
        
        }
    };


int main()
{
    Graph <int> g(6);
    g.addEdge(0,2);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.bfs();
    return 0;
    }
//cycle detection in directed graph using stack------------------------------------------------------------------------------
#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph
{
    list<int> *l;
    int V;
    
public:
    Graph(int v)
    {
        V=v;
        l=new list<int>[V];
        }
        
    void addEdge(int x,int y)
    {
        l[x].push_back(y);
        }
        
    
bool cycle_helper(int node,bool*visited,bool *stack)
{
    visited[node]=true;
    stack[node]=true;
    
    for(auto nbr:l[node])
    {
        // two case
        if(stack[nbr]==true)
        {
            return true;
            }
        else if(visited[nbr]==false)
        {
            bool cycle_mila=cycle_helper(nbr,visited,stack);
            if(cycle_mila)
                return true;
            }
        }
        
        //leave a node 
        stack[node]=false;
        return false;
    } 

bool contain_cycle()
{
    bool *visited=new bool[V];
    bool *stack=new bool[V];
    
    for(int i=0;i<V;i++)
    {
        visited[i]=stack[i]=0;
        }
        
    return cycle_helper(0,visited,stack);
    }

    };
    
    
int main()    
{
    Graph g(7);
    
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(4,2);
    g.addEdge(5,6);
    g.addEdge(1,5);

    if(g.contain_cycle())
        cout<<"cycle found"<<endl;
    else
        cout<<"cycle not forund"<<endl;
    return 0;
    }
//Dijkistra algo (shortest path from single sources)-----------------------------------------------------------------------------
#include <iostream>
#include <list>
#include <unordered_map>
#include <set>
#include <utility>
#include <string>
#include <climits>

using namespace std;
template<typename T>
class Graph
{                          //<city,list of pair having nbr city and distance>
    unordered_map <T,list<pair<T,int>>> m;
    
public:
    
    void addEdge(T u,T v,int dist,bool bidir=true)
    {
        if(bidir)
        {
            m[u].push_back(make_pair(v,dist));
            m[v].push_back(make_pair(u,dist));
            }
        else
        {
            m[u].push_back(make_pair(v,dist));
            }
        }
        
    void printadjlist()
    {
        for(auto node:m)
        {
            T city=node.first;
            cout<<city<<"->";
            for(auto nbr:node.second)
            {
                cout<<" ("<<nbr.first<<" "<<nbr.second<<") ,";
                }
            cout<<endl;
            }
        }
        
    void dijkstra_sssp(T src)
    {
        unordered_map<T,int> dist;
        //making all distance of nodes to infinity
        for(auto node:m)
        {
            T city=node.first;
            dist[city]=INT_MAX;
            }
            
        set<pair<int ,T>> s;
        dist[src]=0;
        s.insert(make_pair(0,src));
        
        while(s.empty()==false)
        {
            pair<int,T> p=*(s.begin());
            T node=p.second;
            int node_dist=p.first;
            s.erase(s.begin());
            for(auto nbr:m[node])
            {
                if(node_dist+nbr.second<dist[nbr.first])
                {
                    T dest=nbr.first;
                     auto f=s.find(make_pair(dist[dest],dest));
                     if(f!=s.end())
                     {
                         s.erase(f);
                         }
                         dist[dest]=node_dist+nbr.second;
                         s.insert(make_pair(dist[dest],dest));
                    
                    }
                }
            }
            
        for(auto x:dist)
        {
            cout<<x.first<<" "<<x.second<<endl;;
            }
        }
    };

int main()
{
    Graph<string> g;
    g.addEdge("delhi","alwar",4);
    g.addEdge("delhi","jaipur",8);
    g.addEdge("delhi","lucknow",20);
    g.addEdge("alwar","jaipur",4);
    g.addEdge("alwar","lucknow",24);
    g.addEdge("alwar","kanpur",16);
    g.dijkstra_sssp("delhi");

    
    return 0;
    }
//DSU conatin cycle----------------------------------------------------------------------------------------
#include <iostream>
#include <list>
using namespace std;

class Graph{
    int V;
    list<pair<int,int>> l;
public:
    Graph(int V){
        this->V=V;
    }
    
    void addEdge(int u,int v){
        l.push_back({u,v});
    }
    
    int findSet(int i,int parent[]){
        if(parent[i]==-1)
        return i;
        
        //return findSet(parent[i],parent);  //-----for simple 
        return parent[i]=findSet(parent[i],parent); //--------for path compression
    }
    
    void union_set(int x,int y,int parent[]){
        int s1=findSet(x,parent);
        int s2=findSet(y,parent);
        
        if(s1!=s2)
        {
            parent[s1]=s2;
        }
    }
    
    bool contain_cycle(){
        int *parent=new int[V];
        for(int i=0;i<V;i++)
        {
            parent[i]=-1;
        }
        
        for(auto edge:l)
        {
            int i=edge.first;
            int j=edge.second;
            
            int s1=findSet(i,parent);
            int s2=findSet(j,parent);
            
            if(s1!=s2)
            union_set(s1,s2,parent);
            else
            return true;
        }
        delete [] parent;
        return false;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    //g.addEdge(3,0);
    
    cout<<g.contain_cycle()<<endl;

    return 0;
}
// DSU cycle detection using path compression and rank---------------------------------------------------------------------------
#include <iostream>
#include <list>
using namespace std;

class Graph{
    int V;
    list<pair<int,int>> l;
public:
    Graph(int V){
        this->V=V;
    }
    
    void addEdge(int u,int v){
        l.push_back({u,v});
    }
    
    int findSet(int i,int parent[]){
        if(parent[i]==-1)
        return i;
        
        return parent[i]=findSet(parent[i],parent);
    }
    
    void union_set(int x,int y,int parent[],int rank[]){
        int s1=findSet(x,parent);
        int s2=findSet(y,parent);
        
        if(s1!=s2)
        {
            if(rank[s1]<rank[s2])
            {
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }else{
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }
    }
    
    bool contain_cycle(){
        int *parent=new int[V];
        int *rank =new int[V];
        for(int i=0;i<V;i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }
        
        for(auto edge:l)
        {
            int i=edge.first;
            int j=edge.second;
            
            int s1=findSet(i,parent);
            int s2=findSet(j,parent);
            
            if(s1!=s2)
            union_set(s1,s2,parent,rank);
            else
            return true;
        }
        
        for(int i=0;i<V;i++)
        cout<<parent[i]<<" ";
        cout<<endl;
        
        for(int i=0;i<V;i++)
        cout<<rank[i]<<" ";
        cout<<endl;
        
        delete [] parent;
        return false;
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,4);
    g.addEdge(5,6);
    g.addEdge(2,5);
    g.addEdge(2,6);
    
    cout<<g.contain_cycle()<<endl;

    return 0;
}
