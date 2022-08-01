#include<iostream>
using namespace std;

/*
	To apply the method explained in the hint video, we have to add two more parameters in the function call. This can be done by calling a helper function from given function. The helper function can have three parameters: array, start index, end index.  
	
	Skeleton code to achieve this:
	#include <iostream>
	using namespace std;
	
	void quickSort(int input[], int start, int end)
	{
    		// your code goes here 
	}
	void quickSort(int input[], int size)
	{
    		quickSort(input, 0, size - 1);
	}
		
*/
void swap(int input[],int pos1,int pos2)
{
    int temp=input[pos1];
    input[pos1]=input[pos2];
    input[pos2]=temp;
}
int partition(int input[],int si,int ei)
{
    
    int pivot=si;
    int count_Small=0;
    for(int i=si+1;i<=ei;i++)
        if(input[pivot]>=input[i])count_Small++;
    
    swap(input,pivot,pivot+count_Small);
    
    pivot=pivot+count_Small;
    int i=si,j=ei;
    
    while(i<pivot && j>pivot)
    {
        while(input[i]<=input[pivot])i++;
        
        while(input[j]>input[pivot])j--;
        
        if(i<pivot && j>pivot)
        {
            swap(input,i,j);
        	i++;j--;
        }
        
    }
    return pivot;
}
void quickSort(int input[],int si,int ei)
{
 	if(si>=ei)
        return;
    
        int pivot=partition(input,si,ei);
        quickSort(input,si,pivot-1);
        quickSort(input,pivot+1,ei);
    
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
	quickSort(input,0,size-1);
    
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


