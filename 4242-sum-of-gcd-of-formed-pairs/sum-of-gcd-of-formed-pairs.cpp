class Solution {
public:
    int getgcd(int a, int b){
        int gcd = 1;
        int rem = 0;

        if(a == b){
            return a;
        }else if(a % b == 0){
            return b;
        }else{
            while(true){
                rem = a % b;
                if(rem == 0){
                    break;
                }
                gcd = rem;
                a = b;
                b = rem;
            }
        }

        return gcd;
    }

    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int max = -1;
        for(int i = 0; i < nums.size(); i++){
            if(max < nums[i]){
                max = nums[i];
            }

            prefixGcd.push_back(getgcd(max, nums[i]));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int left = 0;
        int right = prefixGcd.size() - 1;
        long long sum = 0;

        while(left < right){
            sum += getgcd(prefixGcd[right], prefixGcd[left]);
            left++;
            right--;
        }

        return sum;
    }
};