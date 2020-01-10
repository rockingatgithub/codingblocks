// we need minimum steps to reduce any number to 1......
#include <bits/stdc++.h>
using namespace std;
const int inf=(int) 1e9;
int memo[1000];
int reduce_no(int n)
{   //base case
    if(n==1) return 0;
    if(!memo[n]==-1) //if not -1 then return value........
    return memo[n];
    int q1=inf,q2=inf,q3=inf;
    if(n%3==0) q1=1+reduce_no(n/3); //we can divide by 3
    if(n%2==0) q2=1+reduce_no(n/2); //we can divide by 2
    q3=1+reduce_no(n-1); //wecan substract 1.....
   // int ans =min(q1,min(q2,q3));
    memo[n]=min(q1,min(q2,q3)); //store the result to tackle overlapping subproblems......
    return memo[n];
    
}
int reduce_no_dp(int n)
{
    int dp[10000]={};
    dp[0]=0; dp[2]=1;
    dp[1]=0; dp[3]=1;
    int q1=inf,q2=inf,q3=inf;
    for(int i=4;i<=n;i++)
    {
        if(i%3==0) q1=1+reduce_no_dp(i/3);
        if(i%2==0) q2=1+reduce_no_dp(i/2);
        q3=1+reduce_no_dp(i-1);
        dp[i]=min(q1,min(q2,q3));
    }
    return dp[n];
}
int main() {
    
    int n;
    cin>>n;
  //  fill(memo ,memo+n+1,-1);//like for loop to set values....
    cout<<reduce_no_dp(n);

	return 0;
}
