class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int i = 1;
        int sum = nums[0];

        while(i < nums.size()){
            if(nums[i] - nums[i - 1] == 1){
                sum += nums[i];
            }else{
                break;
            }

            i++;
        }

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            if(sum == nums[i]){
                sum++;
            }
        }

        return sum;
    }
};