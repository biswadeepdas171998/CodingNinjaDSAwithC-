#include <iostream>
using namespace std;

int getCodes(string input,string output[10000],int *si,string res,char values[])
{
    if(input.size()==0)
    {
        output[*si]=res;
        *si=*si+1;
        return 1;
    }
    
    char oneLetter=values[stoi(input.substr(0,1))];
    
    
    int rightCount=0;
    int leftCount=getCodes(input.substr(1),output,si,res+oneLetter,values);
    if(input.size()>=2)
    {
        int temp=stoi(input.substr(0,2));
        if(temp<=26)
        {
        	char twoLetter=values[temp];
        	rightCount=getCodes(input.substr(2),output,si,res+twoLetter,values);
        }
       	
    }
    	
    
    return rightCount+leftCount;
    
    
}   

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    char values[27];
    int si=0;
    string res="";
    for(int i=1;i<27;i++)
        values[i]='a'+(i-1);
    
    return getCodes(input,output,&si,res,values);
    
}

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}