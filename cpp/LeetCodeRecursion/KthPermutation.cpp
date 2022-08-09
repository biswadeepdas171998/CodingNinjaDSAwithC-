#include<string>
class Solution {
public:
    
    string getPermutation(int n, int k) {
        int num=0,fact=1;
        for(int i=1;i<n;i++)
        {
            fact=fact*i;
            num=num*10+i;
        }
        num=num*10+n;
        string str=to_string(num);
        string ans="";
        k=k-1;
        while(true)
        {
            ans=ans+(str[k/fact]);
            str.erase(k/fact,1);
            if(str.size()==0)
                break;
            k=k%fact;
            fact=fact/str.size();
        }
        return ans;
    }
};