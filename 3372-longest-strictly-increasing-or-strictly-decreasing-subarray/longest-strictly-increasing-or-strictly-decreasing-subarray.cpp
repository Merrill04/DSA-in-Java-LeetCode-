class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 1;

        for(int i = 0; i < nums.size() - 1; i++){
            int len = 1;

            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j - 1] < nums[j]){
                    len++;
                }else{
                    break;
                }
            }

            res = max(res, len);
        }

        for(int i = 0; i < nums.size() - 1; i++){
            int len = 1;

            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j - 1] > nums[j]){
                    len++;
                }else{
                    break;
                }
            }

            res = max(res, len);
        }

        return res;
    }
};