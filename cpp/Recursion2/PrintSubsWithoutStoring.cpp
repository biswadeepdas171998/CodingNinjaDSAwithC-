#include <iostream>
#include <string>
using namespace std;

void printSubSequences(string str,string output)
{
    if(str.size()==0)
    {
        cout<<output<<endl;
        return;
    }
        
    string rem=str.substr(1);
    string in=output+str.substr(0,1);
    printSubSequences(rem,in);
    printSubSequences(rem,output);
}

int main()
{
    printSubSequences("abc","");
    
    return 0;
}