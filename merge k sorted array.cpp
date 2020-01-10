#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
class Pair 
{
    public:
    ll data;
    ll name;
};
class mycompare
{
    public:
    bool operator ()(Pair p1,Pair p2)
    {
        return p1.data>p2.data;
    }
};
int main()
{
    priority_queue<Pair, vector<Pair>,mycompare> pq;
    ll n,k;
    cin>>k>>n;
    ll arr[k][n];
    for(ll i=0;i<k;i++)
    {
        for(ll j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    ll current[k]={0};
    vector <ll> v;
    ll totalsize=n*k;
    for(ll i=0;i<k;i++)
    {
        Pair p;
        p.name=i;
        p.data=arr[i][0];
        pq.push(p);
        current[i]++;
      //  cout<<p.name<<" "<<p.data<<" "<<current[i]<<endl;
    }
    while(totalsize--)
    {
        Pair p=pq.top();//this will p.name data we just increase p.data
        pq.pop();
        v.push_back(p.data);
        if(current[p.name]>=n)
        {   
            p.data=LLONG_MAX;
        }
        else
        {
            p.data=arr[p.name][current[p.name]];
        }
        pq.push(p);
        current[p.name]++;
        
    }
    for(ll i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}

