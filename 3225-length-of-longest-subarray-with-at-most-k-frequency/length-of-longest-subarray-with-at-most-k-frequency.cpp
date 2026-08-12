class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int, int> m;
        int max = -1;
        int j = 0;
        int total = 0;
        for(int i = 0; i < nums.size(); i++){
            if(m.find(nums[i]) != m.end()){
                if(m[nums[i]] < k){
                    m[nums[i]] += 1;
                    total++;
                }else{
                    while(j < nums.size() && m[nums[i]] == k){
                        m[nums[j]] -= 1;
                        total--;
                        j++;
                    }

                    m[nums[i]] += 1;
                    total++;
                }
            }else{
                m[nums[i]] = 1;
                total++;
            }

            if(max < total){
                max = total;
            }
        }

        return max;
    }
};