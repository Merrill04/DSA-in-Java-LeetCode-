class Solution {
public:
    int kthFactor(int n, int k) {
        if(k == 1){
            return 1;
        }

        int res = -1;

        for(int i = 1; i <= n / 2; i++){
            if(n % i == 0){
                k--;
            }

            if(k == 0){
                res = i;
                break;
            }
        }

        if(k == 1){
            res = n;
        }

        return res;
    }
};