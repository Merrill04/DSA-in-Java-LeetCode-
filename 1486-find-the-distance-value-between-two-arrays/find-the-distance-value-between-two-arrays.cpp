class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        sort(arr2.begin(), arr2.end());

        for(int i = 0; i < arr1.size(); i++){
            int left = 0;
            int right = arr2.size() - 1;

            while(left <= right){
                int mid = left + (right - left) / 2;

                if(arr2[mid] < arr1[i]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }

            bool valid = true;

            if(left < arr2.size() && abs(arr1[i] - arr2[left]) <= d){
                valid = false;
            }

            if(left > 0 && abs(arr1[i] - arr2[left - 1]) <= d){
                valid = false;
            }

            if(valid){
                res++;
            }
        }

        return res;
    }
};