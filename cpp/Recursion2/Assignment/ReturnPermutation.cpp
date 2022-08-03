#include <iostream>
#include <string>
using namespace std;

int returnPermutations(string input,string output[],string per,int *si)
{
    if(input.size()==0)
    {
        output[*si]=per;
        *si=*si+1;
        return 1;
    }
    int count=0;
    for(int i=0;i<input.size();i++)
    {
        char ch=input[i];
        
        string leftSub=input.substr(0,i);
        string rightSub=input.substr(i+1);
        string temp=leftSub+rightSub;
        count=count+returnPermutations(temp,output,per+ch,si);
    }
    return count;
    
}
int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    int si=0;
    string per="";
    return returnPermutations(input,output,per,&si);
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}