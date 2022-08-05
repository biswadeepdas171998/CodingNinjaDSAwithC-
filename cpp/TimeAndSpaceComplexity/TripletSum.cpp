#include <iostream>
#include <algorithm>
using namespace std;

int tripletSum(int *arr, int n, int num)
{
	//Write your code here
    sort(arr,arr+n);
    int count=0;
    for(int i=0;i<n-1;i++)
    {
        int left=i+1;
        int right=n-1;
        while(left<right)
        {
            if(arr[i]+arr[left]+arr[right]<num)
                left++;
            else if(arr[i]+arr[left]+arr[right]>num)
                right--;
            else
            {
                int elemAtStart=arr[left];
                int elemAtEnd=arr[right];
                
                if(elemAtStart==elemAtEnd )
                {
                    int m=(right-left)+1;
                    
                    count+=m*(m-1)/2;
                    break;
                }
                
                int nextLeft=left+1;
                int nextRight=right-1;
                
                while(nextLeft<=nextRight && arr[nextLeft]==elemAtStart)
                    nextLeft++;
                
                while(nextRight>=nextLeft && arr[nextRight]==elemAtEnd)
                    nextRight--;
                
                int totalStart=nextLeft-left;
                int totalEnd=right-nextRight;
                
                count+=(totalStart*totalEnd);
             
                left=nextLeft;
                right=nextRight;
            }	
        }
        
    }
    return count;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;
        

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}