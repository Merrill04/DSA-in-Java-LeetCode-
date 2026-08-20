class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(k == arr.size()){
            return arr;
        }

        vector<int> res;

        if(x <= arr[0]){
            for(int i = 0; i < k; i++){
                res.push_back(arr[i]);
            }
        }else if(x >= arr[arr.size() - 1]){
            for(int i = arr.size() - 1; i >= arr.size() - k; i--){
                res.push_back(arr[i]);
            }

            reverse(res.begin(), res.end());
        }else{
            int idx = -1;
            int left = 0;
            int right = arr.size() - 1;

            while(left <= right){
                int mid = left + ((right -left) / 2);

                if(arr[mid] >= x){
                    idx = mid;
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }

            int start = -1;
            int end = -1;

            if(idx > 0){
                if(abs(x - arr[idx]) < abs(x - arr[idx - 1])){
                    start = idx;
                    end = idx + 1;
                }else{
                    start = idx - 1;
                    end = idx;
                }
            }else{
                start = idx;
                end = idx + 1;
            }

            while(k > 0){
                if(start >= 0 && end < arr.size()){ 
                    if(abs(arr[start] - x) <= abs(arr[end] - x)){
                        start--;
                    }else{
                        end++;
                    }
                }else if(start < 0){
                    end++;
                }else{
                    start--;
                }

                k--;
            }

            start += 1;

            for(int i = start; i < end; i++){
                res.push_back(arr[i]);
            }
        }

        return res;
    }
};