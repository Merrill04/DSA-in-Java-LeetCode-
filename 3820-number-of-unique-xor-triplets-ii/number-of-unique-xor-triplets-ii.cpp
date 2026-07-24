class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
/*      
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
*/
        int max = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max){
                max = nums[i];
            }
        }

        int vsize = 1;
        while(vsize <= max){
            vsize *= 2;
        }

        vector<bool> one(vsize, false);
        vector<bool> two(vsize, false);

        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                one[nums[i] ^ nums[j]] = true;
            }
        }

        for(int i = 0; i < one.size(); i++){
            if(one[i] == true){
                for(int j = 0; j < nums.size(); j++){
                    two[i ^ nums[j]] = true;
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < two.size(); i++){
            if(two[i] == true){
                ans++;
            }
        }

        return ans;
    }
};