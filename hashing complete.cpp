#include <bits/stdc++.h>
using namespace std;
template <typename t>
class node
{
    public:
    string key;
    t value;
    node<t> * next;
    node(string key,t v)
    {
        this->key=key;
        value = v;
    }
    ~node()
    {
        if(next!=NULL)
        {
            delete next;
        }
    }
};
template <typename t>
class hashtable
{
    int cs=0;
    int ts=0;
    node<t> ** bucket;// it is pointer to array of pointers
    //hashfuntion
    int hashfn(string key)
    {
        int ans=0 ;
        int p=1;
        int l=key.length();
        for(int i=0;i<l;i++)
        {
            ans+=key[l-i-1]*p;
            p=p*37;
            p%=ts;
            ans%=ts;
        }
        return ans;
    }
    public:
    hashtable(int ds=7)
    {
        ts=ds; //if no size given 7 will be the size
        bucket= new node<t> *[ts]; //make a new array whichwill hold head of nod
        for(int i=0;i<ts;i++)
        {
            bucket[i]=NULL;//make bucket null in starting
        }
    }
    void insert(string key,int value)
    {
        int i=hashfn(key);
        node<t> * temp=new node<t> (key,value);
        temp->next=bucket[i];
        bucket[i]=temp;
        cs++;
        
        //calculate load factor
        float load_factor=cs/ts;
        if(load_factor>0.7)
        {
            //cout<<"load factor:"<<load_factor;
            rehash();
        }
       // cout<<"error is here";
    }
    void rehash()
    {
        node <t>** oldbucket=bucket;
        int oldts=ts;
        ts=ts*2;
        bucket=new node<t>* [ts];
        for(int i=0;i<ts;i++)
        {
            bucket[i]=NULL;
        }
        // old table to new table.
        for(int i=0;i<oldts;i++)
        {   node<t>*temp=oldbucket[i];
            if(temp!=NULL)
            {
                while(temp!=NULL) // we need to traverse the ll also.
                {
                    insert(temp->key,temp->value);
                    temp=temp->next;
                }
            }
            delete oldbucket[i];
        }
        delete [] oldbucket;
    }
    t* search(string key) //we choose pointer data type so we return address of //any data  type
    {
        int i=hashfn(key);
       // cout<<i;
        node<t>* temp=bucket[i];
        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                //cout<<"match found:";
                return &(temp->value);
            }
            temp=temp->next;
        }
        return NULL;
    }
    void print()
    {
        node <t> * temp;
        for(int i=0;i<ts;i++)
        { temp=bucket[i];
            cout<<"At"<<i;
            while(temp!=NULL)
            {
                cout<<temp->key<<","<<temp->value<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    t& operator [](string key)
    {
        t * temp=search(key);
        if(temp==NULL)
        {
            t garbage;
            insert(key,garbage); //insert a garbage if empty.
            t* value=search(key);
            return *value;
        }
        return *temp;
    }
    t* erase(string key)
    {
        int i=hashfn(key);
        node<t> * temp=bucket[i];
        node<t> * prev=NULL;
        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                prev=temp->next;
                delete temp;
                break;
            }
            prev=temp;
            temp=temp->next;
            
        }
    }
};
int main() {
	hashtable<int> h;
	h.insert("mango",100);
	h.insert("orange",200);
	h.insert("aam",250);
	h.insert("guava",300);
	h.insert("banana",100);
	h.insert("pineapple",100);
	h.insert("papaya",100);
	h["litchi"]=100;
	
	h.print();
	
   // int * temp= h.search("mango");	
   // cout<<*temp;
	
	return 0;
}
