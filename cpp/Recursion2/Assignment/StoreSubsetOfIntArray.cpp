#include <iostream>
using namespace std;

int subset(int input[],int n,int output[][20],int *sr,int en,int rowSize)
{
    if(n==0)
    {
        output[*sr][0]=rowSize;
        *sr=*sr+1;
        return 1;
    }
    output[*sr][en]=*input;
    int rightN=subset(input+1,n-1,output,sr,en+1,rowSize+1);
    
    for(int i=1;i<en;i++)
        output[*sr][i]=output[*sr-1][i];
    
    int leftN=subset(input+1,n-1,output,sr,en,rowSize);
    
    return leftN+rightN;
}

int subset(int input[], int n, int output[][20]) {
    // Write your code here
    int sr=0;
    return subset(input,n,output,&sr,1,0);
}

int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
