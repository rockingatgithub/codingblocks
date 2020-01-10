#include <bits/stdc++.h>
using namespace std;
int search_in(int arr[],int s,int e,int key)
{   
    int mid=(s+e)/2;
    if(s>e)
    {
        return -1;
    }
    if(arr[mid]==key)
    {
        return mid;
    }
    ///recursive case......
    ///if element is in upper part...
    if(arr[s]<=arr[mid])
    {
        if(arr[s]>=key&&arr[mid]<=key)
        {
           return search_in(arr,s,mid-1,key);
        }
        else
        {
          return  search_in(arr,mid+1,e,key);
        }
    }
    ///call on the lower part....
    if(key>=arr[mid] && key<=arr[e])
    {
      return  search_in(arr,mid+1,e,key);
    }
    return search_in(arr,s,mid-1,key);
}
int main() {
    int n;
    cin>>n;
int arr[n]={5,6,7,1,2,3,4};
int key;
cin>>key;
cout<<search_in(arr,0,n-1,key);


	return 0;
}
