class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int min = 101;
        int max = 0;
        map<int, int> m;

        for(int i = 0; i < nums.size(); i++){
            if(min > nums[i]){
                min = nums[i];
            }

            if(max < nums[i]){
                max = nums[i];
            }

            m[nums[i]] = i;
        }

        for(int i = 1; i < max - min; i++){
            if(m.find(min + i) == m.end()){
                ans.push_back(min + i);
            }
        }

        return ans;
    }
};