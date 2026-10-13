class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long res = 0;

        for(int i = 0; i < nums.size(); i++){
            nums[i] = abs(nums[i]);
        }

        sort(nums.begin(), nums.end(), greater<int>());

        if(nums.size() % 2 == 0){
            for(int i = 0; i < (nums.size() / 2); i++){
                res += (nums[i] * nums[i]);
            }

            for(int i = (nums.size() / 2); i < nums.size(); i++){
                res -= (nums[i] * nums[i]);
            }
        }else{
            for(int i = 0; i <= (nums.size() / 2); i++){
                res += (nums[i] * nums[i]);
            }

            for(int i = (nums.size() / 2) + 1; i < nums.size(); i++){
                res -= (nums[i] * nums[i]);
            }
        }

        return res;
    }
};