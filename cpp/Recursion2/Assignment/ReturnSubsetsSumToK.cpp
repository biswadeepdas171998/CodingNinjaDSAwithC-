#include <iostream>
using namespace std;

/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/
int subsetSumToK(int input[], int n, int output[][50], int k,int *sr,int en,int rowSize){
    
    if(k==0)
    {
        output[*sr][0]=rowSize;
        *sr=*sr+1;
        
        for(int i=1;i<en;i++)
        	output[*sr][i]=output[*sr-1][i];
        
        return 1;
    }
    
    if(n==0 || k<0)
        return 0;
    
    output[*sr][en]=*input;
    int leftN=subsetSumToK(input+1,n-1,output,k-*input,sr,en+1,rowSize+1);
    
    int rightN=subsetSumToK(input+1,n-1,output,k,sr,en,rowSize);
    
    return leftN+rightN;
}
int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
	int sr=0;
    int count=0;
    
     return subsetSumToK(input,n,output,k,&sr,1,0);
}


int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}