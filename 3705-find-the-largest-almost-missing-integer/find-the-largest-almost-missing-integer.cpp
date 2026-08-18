class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int ans = -1;

        if(k == nums.size()){
            int max = -1;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] > max){
                    max = nums[i];
                }
            }

            ans = max;
            return ans;
        }else if( k == 1){
            map<int, int, greater<int>> m;

            for(int i = 0; i < nums.size(); i++){
                m[nums[i]] += 1;
            }

            for(auto &i : m){
                if(i.second == 1){
                    ans = i.first;
                    break;
                }
            }

            return ans;
        }else{
            int c1 = 0;
            int c2 = 0;

            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == nums[0]){
                    c1++;
                }

                if(nums[i] == nums[nums.size() - 1]){
                    c2++;
                }
            }

            if(c1 == 1 && c2 == 1){
                ans = max(nums[0], nums[nums.size() - 1]);
            }else if(c1 == 1 && c2 > 1){
                ans = nums[0];
            }else if(c1 > 1 && c2 == 1){
                ans = nums[nums.size() - 1];
            }
        }

        return ans;
    }
};