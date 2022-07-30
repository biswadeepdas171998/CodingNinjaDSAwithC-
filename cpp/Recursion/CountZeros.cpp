#include <iostream>
using namespace std;

int countZeros(int n) {
    // Write your code here
    	
    if(n==0)
        return 1;
    if(n>=1 && n<=9)
        return 0;
    
    int count=countZeros(n/10);
    if(n%10==0)
        return count+1;
    else 
        return count;
}

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}