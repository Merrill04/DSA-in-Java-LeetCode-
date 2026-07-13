class Solution {
    public void moveZeroes(int[] nums) {
        int i = 0;
        while(i < nums.length){
            if(nums[i] == 0){
                int j = i;
                int t = i+1;
                while(j < nums.length-1 && t < nums.length){
                    if(nums[t] != 0){
                        nums[j] = nums[t];
                        nums[t] = 0;
                        j = t;
                    }
                
                    t++;    
                }
            }
            
            i++;
        }
    }
}