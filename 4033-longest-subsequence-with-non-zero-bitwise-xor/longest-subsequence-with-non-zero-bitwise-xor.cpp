class Solution {
public:
    int longestSubsequence(vector<int>& nums){
        int ans = 0;
        int a = 0;
        for(int i = 0; i < nums.size(); i++){
            a ^= nums[i];
        }

        if(a != 0){
            ans = nums.size();
        }else{
            ans = nums.size() - 1;
        }

        int cz = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                cz++;
            }
        }

        if(cz == nums.size()){
            ans = 0;
        }

        return ans;
    }
};