//kadanes algorithm.......
#include <bits/stdc++.h>
using namespace std;
int main() {
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
int cursum=0;
int maxsum=0;
cursum=arr[0];
for(int i=0;i<n;i++)
{    cursum+=arr[i];
    if(cursum<0)
    {
        cursum=0;
        
    }
   
    if(maxsum<cursum)
    {
        maxsum=cursum;
    }
}
cout<<maxsum;
	return 0;
}
