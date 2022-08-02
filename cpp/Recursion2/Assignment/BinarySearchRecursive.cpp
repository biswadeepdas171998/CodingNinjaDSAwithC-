#include <iostream>
using namespace std;

// input - input array
// size - length of input array
// element - value to be searched
int binarySearch(int input[],int size,int si,int element)
{
    int mid=(si+size)/2;
    
    if(size==0 || mid<si)
        return -1;
    
    if(input[mid]==element)
        return mid;
    else if(element<input[mid])
        return binarySearch(input,mid-1,si,element);
    else
        return binarySearch(input,size,mid+1,element);
        
}
int binarySearch(int input[], int size, int element) {
    // Write your code here
	return binarySearch(input,size-1,0,element);
}


int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}