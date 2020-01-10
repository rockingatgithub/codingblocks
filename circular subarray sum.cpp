//kadanes max subarray sum.........
#include <bits/stdc++.h>
using namespace std;
int main() {
int t;
cin>>t;
while(t--)
{
    //find maxsumby kadane.....
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
int cumsum=0;
int maxsum=arr[0];
int arrsum=0;
for(int i=0;i<n;i++)
{   
    arrsum+=arr[i];
   cumsum+=arr[i];
   if(cumsum<=0)
   {
       cumsum=0;
   }
   if(cumsum>maxsum)
   {
       maxsum=cumsum;
   }
}
int kmaxsum=maxsum;
//cout<<kmaxsum;
//maxsum=0;
//check circular subarray......
//now invert the array and again find kadanes....
int ikmaxsum;
for(int i=0;i<n;i++)
{
    arr[i]=-arr[i];
}

 cumsum=0;
 maxsum=arr[0];
for(int i=0;i<n;i++)
{
   cumsum+=arr[i];
   if(cumsum<=0)
   {
       cumsum=0;
   }
   if(cumsum>maxsum)
   {
       maxsum=cumsum;
   }
}
ikmaxsum=maxsum;
//add with sum......
ikmaxsum=ikmaxsum+arrsum;
//find max...
int ans=max(ikmaxsum,kmaxsum);
cout<<ans;
cout<<endl;
}
	return 0;
}
