#include<algorithm>

class Solution {
public:
    int minimumDeletions(vector<int>& nums){
        if(nums.size() == 1){
            return 1;
        }

        int res = 0;
        int minidx = -1;
        int maxidx = -1;
        int minele = INT_MAX;
        int maxele = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > maxele){
                maxele = nums[i];
                maxidx = i;
            }

            if(nums[i] < minele){
                minele = nums[i];
                minidx = i;
            }
        }

        if(minidx >= maxidx){
            int d1 = minidx + 1;
            int d2 = nums.size() - maxidx;
            int d3 = maxidx + 1 + (nums.size() - minidx);
            res = min({d1, d2, d3});
        }else{
            int d1 = maxidx + 1;
            int d2 = nums.size() - minidx;
            int d3 = minidx + 1 + (nums.size() - maxidx);
            res = min({d1, d2, d3});
        }

        return res;
    }
};