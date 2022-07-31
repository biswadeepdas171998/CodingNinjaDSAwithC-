#include <iostream>
using namespace std;

// Change in the given string itself. So no need to return or print anything
int findLen(char input[]){
    int len=0;
    for(;input[len]!='\0';len++);
    return len;
}

void removeX(char input[]) {
    // Write your code here
	int len=findLen(input);
    
    if(len==0)
        return;
    
    removeX(input+1);
    
    if(input[0]=='x')
    {
        int i=0;
        for(;i<len;i++)
            input[i]=input[i+1];
        
        input[i]='\0';
    }
    
    
}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
