#include <iostream>
using namespace std;

#include <string.h>
using namespace std;
void printAllPossibleCodes(string input,string res,char values[])
{
    if(input.size()==0)
    {
        cout<<res<<endl;
        return;
    }
    
    char oneLetter=values[stoi(input.substr(0,1))];
    
    
    int rightCount=0;
    printAllPossibleCodes(input.substr(1),res+oneLetter,values);
    
    
    if(input.size()>=2)
    {
        int temp=stoi(input.substr(0,2));
        if(temp<=26)
        {
        	char twoLetter=values[temp];
        	printAllPossibleCodes(input.substr(2),res+twoLetter,values);
        }
       	
    }
    	
}   

void printAllPossibleCodes(string input) {
    
    char values[27];
    int si=0;
    string res="";
    for(int i=1;i<27;i++)
        values[i]='a'+(i-1);
    
	 printAllPossibleCodes(input,res,values);
    
}


int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}