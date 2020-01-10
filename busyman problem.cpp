#include <bits/stdc++.h>
using namespace std;
bool compare(const pair<int,int> &a,const pair <int,int> &b)
{
    return (a.second<b.second);
}
void func(vector <pair <int,int>> &vp)
{
    sort(vp.begin(),vp.end(),compare);
   /* for(int i=0;i<vp.size();i++)
    {
        cout<<vp[i].first<<","<<vp[i].second<<endl;
    }*/
    int size=vp.size();
    int count=1;
    int temp=vp[0].second;
   // int i=1;
    int j=1;
   for(int i=1;i<size;i++)
   {
       if(temp<=vp[i].first)
       {
           count++;
           temp=vp[i].second;
          // j++;
       }
      
   }
   cout<<count<<endl;
    
}
int main() {
int t; //testcases
cin>>t;
while(t!=0)
{
    int n; //no. of works
    cin>>n;
    vector <pair <int,int>> vp;
    
    for(int i=0;i<n;i++)
    {
    int starttime=0;
    int endtime=0;
    cin>>starttime>>endtime;
    vp.push_back(make_pair(starttime,endtime));
    }
    func(vp);
    t--;
}

	return 0;
}
