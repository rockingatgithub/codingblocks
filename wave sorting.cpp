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
/////wave sorting;......
 
for(int i=0;i<n;i++)
{   
   
    if(i!=0&&arr[i]<arr[i-1])
    {
        int temp=0;
        temp=arr[i];
        arr[i]=arr[i-1];
        arr[i-1]=temp;
    }
    if(i!=n-1&&arr[i]<arr[i+1])
    {
        int temp=0;
        temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
    }
    i++;
}
for(int i=0;i<n;i++)
{
    cout<<arr[i]<<" ";
}
	return 0;
}
