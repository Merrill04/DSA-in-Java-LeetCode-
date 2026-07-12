class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        if(nums.length < 3){
            return 0;
        }

        int ans = 0;

        for(int i = 0; i <= nums.length - 3; i++){
            int j = i + 1;
            int diff = nums[j] - nums[j - 1];

            while(j < nums.length){
                if(nums[j] - nums[j - 1] == diff){
                    if(j - i + 1 >= 3){
                        ans++;
                    }
                    j++;
                }else{
                    break;
                }
            }
        }

        return ans;
    }
}