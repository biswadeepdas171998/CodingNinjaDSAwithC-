#include <iostream>
using namespace std;

int findLen(char input[])
{
    int len=0;
    for(;input[len]!='\0';len++);
    return len;
}
bool helperCheckAB(char input[])
{
    int len=findLen(input);
    
    if(len==0)
        return true;
	
    if(*(input-1)=='a')
    {
        if(*(input)=='a')
            return helperCheckAB(input+1);
        else if(*(input)=='b' && *(input+1)!='\0' && *(input+1)=='b')
            return helperCheckAB(input+2);
        else
            return false;
    }
    else if(*(input-1)=='b' && *(input)=='a')
        return helperCheckAB(input+1);
    else
        return false;
        
}
bool checkAB(char input[]) {
	// Write your code here
    
    if(input[0]=='a')
        return helperCheckAB(input+1);
    else
		return false;
}

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
