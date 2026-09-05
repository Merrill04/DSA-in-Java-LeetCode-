class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> maxi;
        vector<int> mini(nums.size());
        int max = INT_MIN;
        int min = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max){
                max = nums[i];
            }

            maxi.push_back(max);
        }

        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] < min){
                min = nums[i];
            }

            mini[i] = min;
        }

        int idx = -1;

        for(int i = 0; i < nums.size(); i++){
            if(maxi[i] - mini[i] <= k){
                idx = i;
                break;
            }
        }

        return idx;
    }
};