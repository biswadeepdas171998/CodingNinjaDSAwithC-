#include <iostream>
using namespace std;

int staircase(int n){
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    
    if(n==0)
        return 1;
    
    
    int count=0;
    
    for(int i=1;i<=3;i++)
        if(n-i>=0)
            count+=staircase(n-i);
    
    return count;
}

int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}