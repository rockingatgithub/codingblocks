//https://hack.codingblocks.com/contests/c/52/104
#include <bits/stdc++.h>
using namespace std;
int main() {
int t;
cin>>t;
int c1,c2,c3,c4m,n;
int ricks[1005] ,cabss[1005];
while(t--)
{
    //we enter the cost of tickets......
    //here ....
    /*here c1 is price for one ricks or cab one time...
    c2 is price for any one ricks or cabs unlimited times
    c3 is all rickshaw or cabs unlimited times
    c4 is all rickshaw and cabs unlimited times.....*/
    cin>>c1>>c2>>c3>>c4; 
    //we enter number of rickshaw and cabs.....
    cin>>n>>m;
    int rickcost=0;
    int cabcost=0;
    //enter cost of rickshaw i no of times....
    for(int i=0;i<n;i++)cin>>ricks[i];
    for(int i=0;i<m;i++)cin>>cabss[i];
    // check if any rickshaw is less than c2....
    for(int i=0;i<n;i++)rickcost+=min(c1*ricks[i] , c2);
    //now check if we can take all ricksshaw unlimited times at lesss cost....
    rickcost=min(rickcost,c3);
    for(int i=0;i<m;i++)cabcost+=min(c1*cabss[i] , c2);
    cabcost=min(cabcost,c3);
    //to check if we can buy unlimited wala tickests.....
    int finalans=min(rickcost+cabcost , c4);
    cout<<finalans;
    
}


	return 0;
}
