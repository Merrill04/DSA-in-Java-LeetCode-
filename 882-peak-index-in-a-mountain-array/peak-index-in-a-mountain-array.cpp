class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int idx = -1;
        int left = 0;
        int right = arr.size() - 1;

        while(left <= right){
            int mid = left + ((right - left) / 2);

            if(mid != 0 && arr[mid] < arr[mid - 1]){
                right = mid - 1;
            }else{
                idx = mid;
                left = mid + 1;
            }
        }

        return idx;
    }
};