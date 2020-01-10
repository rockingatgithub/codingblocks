#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
string mymax[50];
//multiply function
string multiply(string m1 ,string m2)
{
    //check size
    int n1=m1.length();
    int n2=m2.length();
    if(n1==0||n2==0)return "0";
    //recursive case
    vector<int> result(n1+n2 , 0);
    int i_n1=0;
    int i_n2=0;
    
    //iterate over num1.....
    for(int i=n1-1;i>=0;i--)
    {
        int carry=0;
        int n1=m1[i]-'0';
        
        i_n2=0;
        
        //iterate over num2.........
        for(int j=n2-1;j>=0;j--)
        {
            int n2=m2[j]-'0';
            int sum=n1*n2 + result[i_n1 + i_n2] + carry;
            //store carry....
            carry=sum/10;
            result[i_n1+i_n2]=sum%10;
            i_n2++;
        }
        if(carry>0)
        {
            result[i_n1+i_n2]+=carry;
        }
        i_n1++;
    }
    int i=result.size() -1;
    while(i>=0&&result[i]==0)
        i--;
        if(i==-1)return "0";
        string s="";
        while(i>=0)
        {
            s+=to_string(result[i--]);
        }
        return s;
}
//addtion function.......
string add(string s1,string s2)
{   
    string str="";
    if(s1.length()>s2.length()) //make sure num1 is small.....
    {
        swap(s1,s2);
    }
    int n1=s1.length();
    int n2=s2.length();
    reverse(s1.begin() , s1.end());
    reverse(s2.begin() , s2.end());
    //carry 
    int carry=0;
    
    for(int i=0;i<n1;i++)
    {
        int sum=(s1[i]-'0')+(s2[i]-'0')+carry;
        str.push_back(sum%10+'0');
        carry=sum/10;
    }
    //for larger number
    for(int i=n1;i<n2;i++)
    {
        int sum=(s2[i]-'0')+carry;
        str.push_back(sum%10+'0');
        carry=sum/10;
    }
    if(carry)
    {
        str.push_back(carry+'0');
    }
    reverse(str.begin() , str.end());
    return str;
}
string modfib(string t1,string t2,int n)
{   string z="0";
//base case
    if(mymax[n]!="-1")
    {
        return mymax[n];
    }
    //recursive case
    mymax[n]=add(modfib(t1,t2,n-2) , multiply(modfib(t1,t2,n-1) , modfib(t1,t2,n-1)));
    return mymax[n];
}
int main() {

string t1;
string t2;
int n;
cin>>t1;
cin>>t2;
cin>>n;
    for(int i=0;i<50;i++) mymax[i]="-1";
    mymax[0]="0";
    mymax[1]=t1;
    mymax[2]=t2;
    
cout<<modfib(t1,t2,n)<<endl;



	return 0;
}
