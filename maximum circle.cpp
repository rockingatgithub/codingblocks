#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool compare(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    return a.second<b.second;
}
void func(vector <pair<ll,ll>> &vp)
{
    sort(vp.begin(),vp.end(),compare); //sort according to first end points
    int count =1;
    int size=vp.size()-1;
    ll temp=vp[0].second;
    int i=1;
    while(size!=0)
    {   
        
        if(temp<=vp[i].first)
        {
            count++;
            temp=vp[i].second;
            
        }
        size--;
        i++;
    }
    cout<<vp.size()-count;
}
int main() {
int n; //no of circles.
cin>>n;
vector <pair <ll,ll>> vp;
for(int i=0;i<n;i++)
{
    ll c,r;
    cin>>c>>r;
    vp.push_back(make_pair(c-r , c+r)); //pair stores end points of circumferenc
}
func(vp);

	return 0;
}
