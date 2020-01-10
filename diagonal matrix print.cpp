#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r,c;
    cin>>r>>c;
    int arr[r][c];
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
    cin>>arr[i][j];
    //first loop to print lines......
    for(int l=1;l<=r+c-1;l++)
    {
        //now about the start column.....
        int start_col=max(0,l-r);
        //now about count of loop......
        int count=min(min(l,r),c-start_col);
        ////now loop to print the elements.....
        for(int j=0;j<count;j++)
        {
            cout<<arr[min(l,r)-j-1][start_col+j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}