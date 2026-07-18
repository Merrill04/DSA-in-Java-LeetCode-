class Solution {
public:
    int findGCD(vector<int>& nums) {
        int max = numeric_limits<int> :: min();
        int min = numeric_limits<int> :: max();

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max){
                max = nums[i];
            }

            if(nums[i] < min){
                min = nums[i];
            }
        }

        int ans = min;
        int rem = 0;
        while(true){
            rem = max % min;

            if(rem == 0){
                break;
            }

            max = min;
            min = rem;
            ans = rem;
        }

        return ans;
    }
};