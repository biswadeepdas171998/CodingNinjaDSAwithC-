//Link:https://leetcode.com/problems/intersection-of-two-arrays/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> ans;
        int i=0,j=0;
        int size1=nums1.size(),size2=nums2.size();
        while(i<size1 && j<size2)
        {
            if(nums1[i]==nums2[j])
            {
                ans.push_back(nums1[i]);
                int previ=nums1[i];
                int prevj=nums2[j];
                
                while(i<size1 && nums1[i]==previ)i++;
                while(j<size2 && nums2[j]==prevj)j++;
            }
            else if(nums1[i]>nums2[j])
                j++;
            else
                i++;
        }
        
        return ans;
    }
};