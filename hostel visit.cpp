#include <iostream>
#include<queue>
#include<vector>
using namespace std;

class hostel
{
    public:
    long long x;
    long long y;
    hostel(long long x,long long y)
    {
        this->x=x;
        this->y=y;
    }
    long long dist()
    {
        return x*x+y*y;
    }
    void print()
    {
        cout<<x*x+y*y<<endl;
    }
};
class mycompare
{
    public:
    bool operator()(hostel a,hostel b)
    {
        return a.dist()<b.dist();
    }
};
priority_queue<hostel,vector<hostel>,mycompare> pq;
void query_print(priority_queue<hostel,vector<hostel>,mycompare> pqq)
{
    
        hostel h=pqq.top();
        h.print();
    
}
int main() {
   
    long long q;
    long long k;
    int qtype;
    cin>>q>>k;
 //   long long cs=0;
    while(q!=0)
    {
        cin>>qtype;
         if(qtype==2)
        {
            query_print(pq);
        }
        else
        {
            if(qtype==1)
          {
            long long int x,y;
            cin>>x>>y;
            hostel h(x,y);
            
            if(pq.size()<k)
            {
            
            pq.push(h);
            
            }
            else
            { 
            hostel hn=pq.top();
            if(h.dist()<hn.dist())
            {
             pq.pop();
             pq.push(h);
            }
                
            }
            }
            
        }
        q--;
    }
	
	return 0;
}
