#include <bits/stdc++.h>
using namespace std;
char * mystrtok(char str[] , char delim)
{
    static char* input=NULL; //static is used to maintain position of pointer....
    if(str!=NULL)input=str;
    if(input==NULL)return NULL;
    char * output=new char[strlen(input)+1];//+1to store the null character.....
    int i;
    //loop to traverse over string......
    for(i=0;input[i]!='\0';i++)
    {
        if(input[i]!=delim)//till ifind a delimiter i will copy in dynamic output aray...
        {
            output[i]=input[i];
        }
        else
        {
            output[i]='\0'; // to print line properly store make a \0 at last.....
            input= input +i+1; //i is length and +1 to traverse the delimiter....
            return output;
        }
    }
    output[i]='\0'; //return last word even if delim is not there.....
    input=NULL;
    return output;
}
int main() {
char arr[]="hi,i am raja,student of coding blocks,c++";

char *ptr;
ptr=mystrtok(arr,',');

while(ptr!=NULL)
{
    cout<<ptr<<endl;
   ptr=mystrtok(NULL,',');
   
}

	return 0;
}
