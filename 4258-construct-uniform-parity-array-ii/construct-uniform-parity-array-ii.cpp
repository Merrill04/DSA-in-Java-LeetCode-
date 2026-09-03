class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int counteven = 0;
        int countodd = 0;

        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i] % 2 == 0){
                counteven++;
            }else{
                countodd++;
            }
        }

        if(counteven > 0 && countodd > 0){
            int odd = INT_MAX;

            for(int i = 0; i < nums1.size(); i++){
                if(nums1[i] % 2 != 0 && nums1[i] < odd){
                    odd = nums1[i];
                }
            }

            for(int i = 0; i < nums1.size(); i++){
                if(nums1[i] % 2 == 0 && nums1[i] <= odd){
                    return false;
                }
            }
        }

        return true;
    }
};