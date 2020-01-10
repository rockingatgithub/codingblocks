//calculate last index of key ...... start form back....
#include<iostream>
#define ll long long int
using namespace std;
int counter=-1;
int findnumber(ll *arr,ll m,int s,int n)
{
    int index=n;
    
   
    //base case.....
    if(m==arr[n])
    {
        return n;
    }
    if(n==s)
    {
        return -1;
    }
    //recursive case....
    findnumber(arr,m,s,n-1);
}
int main() {
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    ll m;
    cin>>m;
    cout<<findnumber(arr,m,0,n-1);
	return 0;
}
