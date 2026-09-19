class Solution {
public:
    unordered_map<int, vector<int>> m;

    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]].push_back(i);
        }    
    }
    
    int pick(int target) {
        int res = -1;
        int size = m[target].size();

        if(size == 1){
            return m[target][0];
        }else{
            int idx = rand() % size;
            res = m[target][idx];
        }

        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */