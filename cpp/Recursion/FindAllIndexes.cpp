#include<iostream>
using namespace std;

//Can be simplified using Backward Approach
int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
    
     if(size==0) // when size is 0 that means array has ended so return 0
         return 0;
    
    int ans=allIndexes(input+1,size-1,x,output);// assuming we have our output array containing values which return len of output array
    for(int i=0;i<ans;i++)// adding 1 to the output array for the current 0th element.
        output[i]++;
    
    if(input[0]==x)// if we find the ele at 0th index we will shift the output array and put the element at 0th index;
    {
        for(int i=ans;i>=0;i--)
            output[i+1]=output[i];
        
        output[0]=0;
        return ans+1; // as we have added a new element in output array so len will be increased by 1
    }
    else
        return ans; // if we cant find len will remain same.
    
        
}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}


