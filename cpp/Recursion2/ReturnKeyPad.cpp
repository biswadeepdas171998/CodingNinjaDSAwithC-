#include <iostream>
#include <string>
using namespace std;

int helperKeypad(int num,string keys[],string output[])
{
    if(num==0)
    {
     	output[0]="";
        return 1;
    }
    
    int size=helperKeypad(num/10,keys,output);
    
    int n=num%10;
    string key=keys[n];
    int len=key.size();
	string *ans=new string[size*len];
    int k=0;
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<size;j++)
        {
            ans[k]=output[j]+key[i];
            k++;
        }
    }
    for(int i=0;i<size*len;i++)
        output[i]=ans[i];
    
    return size*len;
}
int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    string keys[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    return helperKeypad(num,keys,output);
    
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
