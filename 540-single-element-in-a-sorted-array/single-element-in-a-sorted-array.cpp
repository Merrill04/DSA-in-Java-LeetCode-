class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ele = -1;
        int i = 0;
        int j = nums.size() - 1;

        if(nums.size() == 1){
            return nums[0];
        }

        if(nums[0] != nums[1]){
            return nums[0];
        }

        if(nums[nums.size() - 2] != nums[nums.size() - 1]){
            return nums[nums.size() - 1];
        }

        while(i <= j){
            int mid = i + ((j - i) / 2);

            if(nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]){
                ele = nums[mid];
                break;
            }else if(nums[mid] != nums[mid + 1] && nums[mid] == nums[mid - 1]){
                if((nums.size() - mid - 1) % 2 == 0){
                    j = mid - 1;
                }else{
                    i = mid + 1;
                }
            }else{
                if((nums.size() - mid) % 2 == 0){
                    j = mid - 1;
                }else{
                    i = mid + 1;
                }
            }
        }

        return ele;
    }
};