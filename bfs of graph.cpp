//generic data type graph representation
//we use map so we get sorted data
#include <bits/stdc++.h>
using namespace std;
template <typename t>
class graph
{
    int v;
    map<t,list <t> > adjlist;
    public:
    graph()
    {
    }
    
    void addedge(t u,t v, bool bidir=true)
    {
        adjlist[u].push_back(v);
        if(bidir)
        {
            adjlist[v].push_back(u);
        }
    }
    void printlist()
    {
        for(auto i:adjlist)
        {
            cout<<i.first<<"->";
            for(auto v:i.second)
            {
                cout<<v<<",";
            }
            cout<<endl;
        }
    }
    // bfs traversal of graph
    void bfs(t src)
    {
        queue<t> q;
        map<t , int> dist;
        map<t,t> parent;
        //all distances in begining are infinite
        for(auto i: adjlist)
        {
            dist[i.first]=INT_MAX;
        }
        //push the source to queue
        q.push(src); //push first node
        dist[src]=0;//make distance 0
        parent[src]=src;
        while(!q.empty())
        {
            t node= q.front();
            cout<<node<<" ";
            q.pop();
            //traverse child of popped node
            for(int neighbour:adjlist[node])
            {
                if(dist[neighbour]==INT_MAX) //we are coming to node first time
                {
                    q.push(neighbour);
                    dist[neighbour]=dist[node]+1;
                    parent[neighbour]=node;
                }
            }   
        }
        for(auto i:adjlist)
        {
            t node= i.first;
            cout<<"distance of"<< node<<" from "<<src<<"is"<<dist[node]<<endl;
        }
    }
};
int main() {
    graph<int> g;
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(0,4);
    g.addedge(2,4);
    g.addedge(2,3);
    g.addedge(3,5);
    g.addedge(3,4);
   // g.printlist();
    g.bfs(0);
	return 0;
}
