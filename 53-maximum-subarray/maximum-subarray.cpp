class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = numeric_limits<int> :: min();
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            maximum = max(maximum, sum);

            if(sum < 0){
                sum = 0;
            }
        }

        return maximum;
    }
};