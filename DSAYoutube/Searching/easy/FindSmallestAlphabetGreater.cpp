//Link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ans=-1;
        if(target>=letters[letters.size()-1])
            return letters[0];
        
        int i=0,j=letters.size()-1;
        
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            
            if(letters[mid]>target)
            {
                ans=mid;
                j=mid-1;
            }
            else
                i=mid+1;
        }
        return letters[ans];
    }
};