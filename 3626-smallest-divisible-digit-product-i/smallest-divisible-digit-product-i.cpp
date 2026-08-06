class Solution {
public:
    int smallestNumber(int n, int t) {
        if(n == 100){
            return n;
        }

        int ans = -1;
        for(int i = n; i <= 100; i++){
            int temp = i;
            int a = temp % 10;
            temp = temp / 10;
            int b = 0;
            if(temp > 0){
                b = temp % 10;

                if((a * b) % t == 0){
                    ans = i;
                    break;
                }
            }else{
                if(a % t == 0){
                    ans = i;
                    break;
                }
            }
        }

        return ans;
    }
};