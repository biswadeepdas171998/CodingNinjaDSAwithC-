#include <iostream>
using namespace std;

void printSubsetOfArray(int input[],int size,int output[],int si,int en)
{
    if(size==0)
    {
        for(int i=si;i<en;i++)
            cout<<output[i]<<" ";
        
        cout<<endl;
        return;
    }
    
    printSubsetOfArray(input+1,size-1,output,si,en);
    
    output[en]=*input;
    printSubsetOfArray(input+1,size-1,output,si,en+1);
    
    
}
void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int output[100001];
    printSubsetOfArray(input,size,output,0,0);
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}