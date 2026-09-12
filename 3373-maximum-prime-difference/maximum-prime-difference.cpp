class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int min = -1;
        int max = -1;
        int primecount = 0;

        for(int i = 0; i < nums.size(); i++){
            int n = nums[i];
            int count = 1;

            for(int j = 2; j * j <= n; j++){
                if(n % j == 0){
                    count++;
                }
            }

            if(count == 1 && n != 1){
                if(primecount < 1){
                    min = i;
                }else{
                    max = i;
                }
                primecount++;
            }
        }

        if(primecount < 2){
            return 0;
        }

        return max - min;
    }
};