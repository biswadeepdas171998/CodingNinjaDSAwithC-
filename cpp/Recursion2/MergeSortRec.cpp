#include <iostream>
using namespace std;


void merge(int input[],int si,int mid,int ei)
{
    int i=si,j=mid+1,k=0;
    int arr[1001];
    while(i<=mid && j<=ei)
    {
        if(input[i]<input[j])
            arr[k++]=input[i++];
        else
            arr[k++]=input[j++];
    }
    while(i<=mid)
        arr[k++]=input[i++];
    
    while(j<=ei)
        arr[k++]=input[j++];
    
    k=0;
    while(si<=ei)
        input[si++]=arr[k++];
}

void mergeSortRec(int input[],int si,int ei)
{
    if(si<ei)
    {
        int mid=si+((ei-si)/2);
        mergeSortRec(input,si,mid);
        mergeSortRec(input,mid+1,ei);
        merge(input,si,mid,ei);
    }
}

void mergeSort(int input[], int size){
	// Write your code here
      mergeSortRec(input,0,size-1);  
}


int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}