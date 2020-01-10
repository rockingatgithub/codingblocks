//chewbaacaa and number............
#include <bits/stdc++.h>
using namespace std;
int main() {
string s;
cin>>s;
int i;
if(s[0]==(9-'0'))i=1; // if first digit is 9 dont make  it 0.....

for( i;i<s.length();i++)
{   
    int j=s[i]-'0';
    
    if(j>=5)
    {
        s[i]=9-j+'0';
    }
}
cout<<s;

	return 0;
}
