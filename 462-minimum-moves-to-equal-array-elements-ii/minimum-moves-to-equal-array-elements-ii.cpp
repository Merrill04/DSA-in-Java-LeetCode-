class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int a = nums[nums.size() / 2];
        long long res = 0;

        for(int i = 0; i < nums.size(); i++){
            res += abs((long long)nums[i] - a);
        }

        return res;
    }
};