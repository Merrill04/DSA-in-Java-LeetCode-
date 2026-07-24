class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> ans;
        unordered_set<int> v;
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                v.insert(nums[i] ^ nums[j]);
            }
        }

        for(int j : v){
            for(int &i : nums){
                ans.insert(i ^ j);
            }
        }

        return ans.size();
    }
};