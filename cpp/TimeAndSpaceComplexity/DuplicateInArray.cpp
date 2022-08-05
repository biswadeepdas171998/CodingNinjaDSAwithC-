#include <iostream>
using namespace std;

int findDuplicate(int *arr, int n)
{
    //Write your code here
    int ans=0;
    for(int i=0;i<n;i++)
    {
    	int pos=arr[i]<0?arr[i]*-1:arr[i];
        
        if(arr[pos]<0)
        {
            ans=pos;
            break;
        }
        arr[pos]=arr[pos]*-1;
    }
    return ans;
}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}