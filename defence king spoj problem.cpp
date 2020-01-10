#include <bits/stdc++.h>
using namespace std;
int main() {
int n;
cin>>n;
int size=n;
int nn=n-1;
int sizen=nn;
int i=0;
int arrx[n];
int arry[n];
while(size!=0)
{
    int x;int y;
    cin>>x>>y;
    arrx[i]=x;
    arry[i]=y;
    i++;
    size--;
}
sort(arrx,arrx+n);
sort(arry,arry+n);
int diffx[nn];
int diffy[nn];
int j=0;
while(sizen!=0)
{
    int tempx=arrx[j]-arrx[j+1];
    diffx[j]=abs(tempx)-1;
    int tempy=arry[j]-arry[j+1];
    diffy[j]=abs(tempy)-1;
    j++;
    sizen--;
}
int nx= *max_element(diffx,diffx+nn);
int ny=*max_element(diffy,diffy+nn);


cout<<nx*ny;
	return 0;
}
