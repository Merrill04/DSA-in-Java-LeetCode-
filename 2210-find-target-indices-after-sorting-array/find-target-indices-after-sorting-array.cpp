class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> res;
        int freq = 0;
        int n = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < target){
                n++;
            }

            if(nums[i] == target){
                freq++;
            }
        }

        for(int i = n + 1; i <= n + freq; i++){
            res.push_back(i - 1);
        }

        return res;
    }
};