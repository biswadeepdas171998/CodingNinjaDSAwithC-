#include <iostream>
#include <string>
using namespace std;

void printPermutations(string input,string per)
{
    if(input.size()==0)
    {
        cout<<per<<endl;
        return;
    }
    int count=0;
    for(int i=0;i<input.size();i++)
    {
        char ch=input[i];
        
        string leftSub=input.substr(0,i);
        string rightSub=input.substr(i+1);
        string temp=leftSub+rightSub;
        printPermutations(temp,per+ch);
    }
}
    
void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    string per="";
    printPermutations(input,per);
}

int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}