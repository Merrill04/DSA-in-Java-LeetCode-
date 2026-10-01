class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }

        int max = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            int res = nums[i];
            if(res > max){
                max = res;
            }
            
            for(int j = i + 1; j < nums.size(); j++){
                res *= nums[j];

                if(res > max){
                    max = res;
                }
            }

            if(res > max){
                max = res;
            }
        }

        return max;
    }
};