#include <iostream>
using namespace std;

bool checkPalindrome(char input[]) {
    // Write your code here
    int len=0;
	for(len=0;input[len]!='\0';len++);
    
    if(len==1 || len==0)
        return true;
    
    char ch=input[len-1];
    input[len-1]='\0';
    
    if(input[0]==ch && checkPalindrome(input+1))
    	return true;
    else
        return false;
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}