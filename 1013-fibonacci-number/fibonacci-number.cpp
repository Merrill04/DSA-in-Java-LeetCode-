class Solution {
public:
    int fibo(int n, vector<int>& array){
        if(n <= 1){
            return n;
        }

        if(array[n] != -1){
            return array[n];
        }

        array[n] = fibo(n - 1, array) + fibo(n - 2, array);
        
        return array[n];
    }
    
    int fib(int n) {
        vector<int> array(n + 1, -1);

        int res = fibo(n, array);

        return res;
    }
};