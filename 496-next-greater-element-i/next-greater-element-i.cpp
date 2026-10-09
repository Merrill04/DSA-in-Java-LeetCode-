class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        for(int i = 0; i < nums1.size(); i++){
            int idx = -1;

            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    idx = j;
                    break;
                }
            }

            int t = nums2[idx];

            for(int j = idx + 1; j < nums2.size(); j++){
                if(nums2[j] > t){
                    t = nums2[j];
                    break;
                }
            }

            if(t == nums1[i]){
                res.push_back(-1);
            }else{
                res.push_back(t);
            }
        }

        return res;
    }
};