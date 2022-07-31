#include <iostream>
using namespace std;

// Change in the given string itself. So no need to return or print anything
void replacePi(char input[]) {
	// Write your code here
    int len=0;
	for(;input[len]!='\0';len++);
    
    if(len==0)
        return;
    if(input[0]=='p' && input[1]=='i')
    {
        char ch[201]="3.14";
        
        int k=4,i=2;
        for(;i<len;i++)
            ch[k++]=input[i];
        
        ch[k]='\0';
        k=0;
        for(;ch[k]!='\0';k++)
            input[k]=ch[k];
        input[k]='\0';
        
        
    }
    
    replacePi(input+1);
}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
