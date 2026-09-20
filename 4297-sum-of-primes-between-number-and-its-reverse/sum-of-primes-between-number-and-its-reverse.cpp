class Solution {
public:
    int sumOfPrimesInRange(int n) {
        vector<bool> primes(1001, true);
        primes[0] = false;
        primes[1] = false;

        for(int i = 2; i <= 1000; i++){
            if(primes[i] == true && i * i <= 1000){
                for(int j = i * i; j <= 1000; j += i){
                    primes[j] = false;
                }
            }
        }

        int res = 0;

        int original = n;
        int r = 0;

        while(n > 0){
            r = (r * 10) + (n % 10);
            n /= 10;
        }

        int start = min(original, r);
        int end = max(original, r);

        for(int i = start; i <= end; i++){
            if(primes[i] == true){
                res += i;
            }
        }

        return res;
    }
};