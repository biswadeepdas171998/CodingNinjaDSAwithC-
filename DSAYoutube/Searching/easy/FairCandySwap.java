//Link:https://leetcode.com/problems/fair-candy-swap/
class Solution {
    public int[] fairCandySwap(int[] aliceSizes, int[] bobSizes) {
        Arrays.sort(aliceSizes);
        Arrays.sort(bobSizes);
        
        int aliceSum=0,bobSum=0;
        int ans[]=new int[2];
        
        for(int i=0;i<aliceSizes.length;i++)
            aliceSum+=aliceSizes[i];
        
        for(int j=0;j<bobSizes.length;j++)
            bobSum+=bobSizes[j];
        
        int left=0,right=0;
        
        while(left<aliceSizes.length && right<bobSizes.length)
        {
            int aliceDif=aliceSum-aliceSizes[left]+bobSizes[right];
            int bobDif=bobSum-bobSizes[right]+aliceSizes[left];
            
            if(aliceDif==bobDif)
            {
                ans[0]=aliceSizes[left];
                ans[1]=bobSizes[right];
                break;
            }
            else if(aliceDif>bobDif)
                left++;
            else
                right++;
        }
        return ans;
    }
}