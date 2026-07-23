class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size() < 3){
            return nums.size();
        }

        int ans = 1;
        int n = nums.size();

        while(ans <= n){
            ans *= 2;
        }

        return ans;
    }
};