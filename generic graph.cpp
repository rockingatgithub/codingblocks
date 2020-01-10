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
};
int main() {
    graph<string> g;
    g.addedge("putin","trump",false);
    g.addedge("putin","modi",false);
    g.addedge("putin","pope",false);
    g.addedge("putin","trump",false);
    g.addedge("modi","trump",true);
    g.addedge("yogi","prabhu",false);
    g.addedge("prabhu","modi",false);
    g.printlist();

	return 0;
}
