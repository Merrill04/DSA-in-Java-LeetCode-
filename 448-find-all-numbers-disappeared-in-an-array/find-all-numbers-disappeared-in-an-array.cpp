class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> res;

        for(int i = 0; i < nums.size(); i++){
            m[nums[i]] += 1;
        }

        for(int i = 1; i <= nums.size(); i++){
            if(m.find(i) == m.end()){
                res.push_back(i);
            }
        }

        return res;
    }
};