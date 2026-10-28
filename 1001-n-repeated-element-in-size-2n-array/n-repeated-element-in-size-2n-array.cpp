class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = -1;

        for(int i = 0; i < nums.size(); i++){
            m[nums[i]] += 1;
        }

        for(auto &i : m){
            if(i.second > 1){
                res = i.first;
                break;
            }
        }

        return res;
    }
};