#include <iostream>
using namespace std;
int findLen(char input[])
{
    int len=0;
    for(;input[len]!='\0';len++);
    return len;
}
int power(int x)
{
    int ans=1;
    for(int i=1;i<=x;i++)
        ans=ans*10;
    
    return ans;
}
int stringToNumber(char input[]) {
    // Write your code here
    int len=findLen(input);
    
	if(len==0)
        return 0;
    
    int later=stringToNumber(input+1);
    int curr=((int)(input[0]-'0'))*power(len-1)+later;
    return curr;
    
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
