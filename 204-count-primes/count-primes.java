class Solution {
    public int countPrimes(int n) {
        if(n < 2){
            return 0;
        }

        int count = 0;

        boolean[] primes = new boolean[n];

        for(int i = 0; i < n; i++){
            primes[i] = true;
        }

        for (int p = 2; p * p < n; p++){
            if (primes[p]){
                for (int i = p * p; i < n; i += p){
                    primes[i] = false;
                }
            }
        }

        primes[0] = false;
        primes[1] = false;

        for(int i = 0; i < n; i++){
            if(primes[i] == true){
                count++;
            }
        }

        return count;
    }
}