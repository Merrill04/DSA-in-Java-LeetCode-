class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> temp(nums.size(), 0);
        vector<int> res;

        for(int i = 0; i < nums.size(); i++){
            temp[nums[i] - 1] = nums[i];
        }

        for(int i = 0; i < nums.size(); i++){
            if(temp[i] == 0){
                res.push_back(i + 1);
            }
        }

        return res;
    }
};