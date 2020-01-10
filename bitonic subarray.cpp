//bitonic subarray.................
#include<iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        int inc[n]={};
        int dec[n]={};
        int res=0;
        inc[0]=1;
        dec[n-1]=1;
        for(int i=1;i<n;i++)
        {
            inc[i]=(arr[i]>arr[i-1]) ? inc[i-1]+1: 1;
            dec[n-i-1]=(arr[n-i-1]>arr[n-i]) ? dec[n-i]+1 : 1;
        }
        for(int i=0;i<n;i++)
        {
            res=max(res,(inc[i]+dec[i]-1));
           
        }
        cout<<res<<endl;
        
    }
	return 0;
}