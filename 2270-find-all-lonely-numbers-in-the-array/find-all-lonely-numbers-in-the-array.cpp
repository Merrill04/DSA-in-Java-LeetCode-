class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        if(nums.size() == 1){
            return nums;
        }

        int n = nums.size();
        vector<int> res;
        sort(nums.begin(), nums.end());

        if(nums[0] != nums[1] && nums[0] + 1 != nums[1]){
            res.push_back(nums[0]);
        }

        for(int i = 1; i < n - 1; i++){
            if(nums[i] != nums[i - 1] && nums[i] != nums[i + 1]){
                if(nums[i] - 1 != nums[i - 1] && nums[i] + 1 != nums[i + 1]){
                    res.push_back(nums[i]);
                }
            }
        }

        if(nums[n - 1] != nums[n - 2] && nums[n - 1] != nums[n - 2] + 1){
            res.push_back(nums[n - 1]);
        }

        return res;
    }
};