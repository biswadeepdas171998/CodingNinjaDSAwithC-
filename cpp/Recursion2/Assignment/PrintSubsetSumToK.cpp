#include <iostream>
using namespace std;

void printSubsetSumToK(int input[], int size, int k,int output[],int en)
{
    if(k==0)
    {
        
        for(int i=0;i<en;i++)
            cout<<output[i]<<" ";
        
        cout<<endl;
        return;
    }
    
    if(size==0 || k<0)
        return;
    
    output[en]=*input;
    printSubsetSumToK(input+1,size-1,k-*input,output,en+1);
    printSubsetSumToK(input+1,size-1,k,output,en);
    
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int output[100001];
    printSubsetSumToK(input,size,k,output,0);
}


int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}