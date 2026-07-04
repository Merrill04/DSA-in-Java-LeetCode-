class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if( k < 1){
            return 0;
        }
        
        int ans = 0;
        int left = 0;
        int a = 1;
        
        for(int i = 0; i < nums.length; i++){
            a = a * nums[i];

            while(a >= k){
                a = a / nums[left];
                left++;
            }

            ans += (i - left + 1);
        }

        return ans;
    }
}