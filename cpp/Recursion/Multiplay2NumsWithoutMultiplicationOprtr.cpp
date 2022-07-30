#include <iostream>
using namespace std;
int multiplyNumbers(int m, int n) {
    // Write your code here
	if(n==1)
        return m;
    
    int multi=multiplyNumbers(m,n-1);
    return m+multi;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}