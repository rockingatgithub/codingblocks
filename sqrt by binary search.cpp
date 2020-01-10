#include <bits/stdc++.h>
using namespace std;
void squareroot(int key ,int p)
{
    int s=0,e=key;
    int ans=0;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(mid*mid==key)
        {
            ans=mid;
            break;
        }
        if(mid*mid>key)
        {
            e=mid-1;
        }
        if(mid*mid<key)
        {
            ans=mid;
            s=mid+1;
        }
    }
    int j=1;
    float nans=ans;
    float  nnans=0;
    while(j<=p)
    {
        float inc=1/pow(10,j);
        
        nans+=inc;
        
        while(nans*nans<key)
        {   nnans=nans;
            nans+=inc;
        }
        nans=nnans;
        j++;
    }
    cout<<nnans;
}
int main() {
int n;
cin>>n;
int p;
cin>>p;
squareroot(n,p);


	return 0;
}
