#include <iostream>
using namespace std;

// Change in the given string itself. So no need to return or print the changed string.
int findLen(char input[])
{
    int len=0;
    for(;input[len]!='\0';len++);
    return len;
}

void pairStar(char input[]) {
    // Write your code here
	int len=findLen(input);
    if(len==0)
        return;
    
    pairStar(input+1);
    
    if(*(input-1)==*(input))
    {
        len=findLen(input);
        int i=len-1;
        
        for(;i>=0;i--)
            input[i+1]=input[i];
        input[0]='*';
        input[len+1]='\0';
        
    }
}
int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
