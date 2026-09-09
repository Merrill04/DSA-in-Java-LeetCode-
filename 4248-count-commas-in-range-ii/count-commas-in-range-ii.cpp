class Solution {
public:
    long long countCommas(long long n) {
        if(n < 999){
            return 0;
        }

        long long res = 0;
        
        if(n > 999 && n < 1000000){
            res += n - 999;
        }else if(n > 999999 && n < 1000000000){
            long long t1 = 999999 - 999;
            long long t2 = (n - 999999) * 2;
            res += t1 + t2;
        }else if(n > 999999999 && n < 1000000000000){
            long long t1 = 999999 - 999;
            long long t2 = (999999999 - 999999) * 2;
            long long t3 = (n - 999999999) * 3;
            res += t1 + t2 + t3;
        }else if(n > 999999999999 && n <= 1000000000000000){
            long long t1 = 999999 - 999;
            long long t2 = (999999999 - 999999) * 2;
            long long t3 = (999999999999 - 999999999) * 3;
            long long t4 = (n - 999999999999) * 4;
            res += t1 + t2 + t3 + t4;
            if(n == 1000000000000000){
                res += 1;
            }
        }

        return res;
    }
};