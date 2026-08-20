class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> result;
        vector<int> idx;
        result.push_back(nums[0]);
        idx.push_back(1);
        int left = 0;
        int right = 1;

        for(int i = 2; i < nums.size(); i++){
            if(nums[left] > nums[right]){
                result.push_back(nums[i]);
                left = i;
            }else{
                idx.push_back(i);
                right = i;
            }
        }

        for(int i = 0; i < idx.size(); i++){
            result.push_back(nums[idx[i]]);
        }

        return result;
    }
};