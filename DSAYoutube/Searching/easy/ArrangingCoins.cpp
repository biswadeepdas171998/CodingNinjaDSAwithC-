//Link:https://leetcode.com/problems/arranging-coins/
class Solution {
public:
    long sumN(long n)
    {
        return (n*(n+1))/2;
    }
        
    long arrangeCoins(long n,long left,long right)
    {
        if(left>right)
            return right;
        
        long mid=left+(right-left)/2;
        long sum=sumN(mid);
        if(sum==n)
            return mid;
        else if(sum<n)
            return arrangeCoins(n,mid+1,right);
        else
            return arrangeCoins(n,left,mid-1);
    }
    int arrangeCoins(int n) {
        return (int)arrangeCoins(n,1,n);
    }
};