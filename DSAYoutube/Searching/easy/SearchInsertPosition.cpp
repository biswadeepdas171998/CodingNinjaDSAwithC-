//Link: https://leetcode.com/problems/search-insert-position/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size=nums.size();
        int left=0,right=size-1;
        
        
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                left=mid+1;
            else
                right=mid-1;
        }
        
        return right+1;
    }
};