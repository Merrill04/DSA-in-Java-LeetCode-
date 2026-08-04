class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
/*
//Approach 1:
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
*/
//Approach 2 with constant space:
        sort(nums.begin(), nums.end());
        vector<int> ans;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - nums[i-1] > 1){
                int j = 1;
                while(j < nums[i] - nums[i-1]){
                    ans.push_back(nums[i-1] + j);
                    j++;
                }
            }
        }

        return ans;
    }
};