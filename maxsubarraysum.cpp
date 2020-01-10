#include <bits/stdc++.h>
using namespace std;
int main() {
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)cin>>arr[i];
int csum=0;
int maxsum=0;
for(int i=0;i<n;i++)
{   
    for(int j=i;j<n;j++)
    {
        
        for(int k=i;k<=j;k++)
        {
            csum+=arr[k];
        }
        if(maxsum<csum)
        {
            maxsum=csum;
            
        }
        csum=0;
    }
   
}
cout<<maxsum;
	return 0;
}
