class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> max;
        vector<int> min(nums.size());

        int ma = INT_MIN;
        int mi = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > ma){
                ma = nums[i];
            }

            max.push_back(ma);
        }

        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] < mi){
                mi = nums[i];
            }

            min[i] = mi;
        }

        int ans = INT_MAX;
        int idx = -1;

        for(int i = 0; i < nums.size(); i++){
            if(max[i] - min[i] <= k){
                if(max[i] - min[i] < ans){
                    ans = max[i] - min[i];
                }
                idx = i;
                break;
            }
        }

        return idx;
    }
};