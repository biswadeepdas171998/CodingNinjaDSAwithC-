#include <iostream>
using namespace std;

int findLen(char input[])
{
    int len=0;
    for(;input[len]!='\0';len++);
    return len;
}
void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/
	int len=findLen(input);
    
    if(len==0)
        return;
    
    removeConsecutiveDuplicates(input+1);
    
    if(*(input-1)==*input)
    {
        int i=1;
        for(;input[i]!='\0';i++)
        	input[i-1]=input[i];
        input[i-1]=input[i];
    }

}

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}