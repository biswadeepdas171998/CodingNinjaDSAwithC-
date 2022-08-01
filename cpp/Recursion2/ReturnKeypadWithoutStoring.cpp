#include <iostream>
#include <string>
using namespace std;

void helperPrintKeypad(int num,string keys[],string output)
{
    if(num==0)
    {
        cout<<output<<endl;
        return;
    }
    
    
    string key=keys[num%10];
    int len=key.size();
    
    for(int i=0;i<len;i++)
    	helperPrintKeypad(num/10,keys,key[i]+output);
}


void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string keys[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string output="";
    helperPrintKeypad(num,keys,output);
    
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}