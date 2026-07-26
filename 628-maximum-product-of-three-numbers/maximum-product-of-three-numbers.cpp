class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size() < 3){
            return 0;
        }

        vector<int> temp(nums);

        int ans = 1;
        int idx = 0;
        int max1 = -1001;
        int max2 = -1001;
        int max3 = -1001;
        int min1 = 1001;
        int min2 = 1001;
        for(int i = 0; i < temp.size(); i++){
            if(temp[i] < min1){
                min1 = temp[i];
                idx = i;
            }
        }

        temp[idx] = 1001;
        idx = 0;

        for(int i = 0; i < temp.size(); i++){
            if(temp[i] < min2){
                min2 = temp[i];
                idx = i;
            }
        }

        idx = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max1){
                max1 = nums[i];
                idx = i;
            }
        }

        nums[idx] = -1001;
        idx = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max2){
                max2 = nums[i];
                idx = i;
            }
        }

        nums[idx] = -1001;
        idx = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max3){
                max3 = nums[i];
                idx = i;
            }
        }

        ans = max1 * max2 * max3;

        if(min1 < 0 && min2 < 0){
            int t = abs(min1) * abs(min2) * max1;
            if(t > ans){
                ans = t;
            }
        }

        return ans;
    }
};