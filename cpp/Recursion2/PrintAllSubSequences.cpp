#include <iostream>

using namespace std;
int printSubs(string str,string* output)
{
    if(str.size()==0)
    {
        output[0]="";
        return 1;
    }
    string sub=str.substr(1);
    int size=printSubs(sub,output);
    for(int i=0;i<size;i++)
    {
        output[i+size]=str[0]+output[i];
    }
    return 2*size;
}
int main()
{
    string str;
    cin>> str;
    string* output=new string[1000];
    
    int size=printSubs(str,output);
    
    for(int i=0;i<size;i++)
        cout<<output[i]<<endl;

    return 0;
}