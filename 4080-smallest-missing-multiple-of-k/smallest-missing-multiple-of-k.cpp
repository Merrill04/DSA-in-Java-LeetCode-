class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int max = INT_MIN;
        int res = -1;

        for(int i = 0; i < nums.size(); i++){
            m[nums[i]] = 1;

            if(nums[i] > max){
                max = nums[i];
            }
        }

        int c = 1;
        while((k * c) <= max){
            if(m.find(k * c) == m.end()){
                res = k * c;
                break;
            }else{
                c++;
            }
        }

        if(res == -1){
            res = k * c;
        }

        return res;
    }
};