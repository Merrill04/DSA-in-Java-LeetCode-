class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddsum = 0;
        int evensum = 0;

        for(int i = 0; i < n; i++){
            oddsum += i + (i + 1);
            evensum += (i + 1) * 2;
        }

        int rem = 0;
        int ans = 1;

        while(true){
            rem = evensum % oddsum;
            if(rem == 0){
                break;
            }
            ans = rem;
            evensum = oddsum;
            oddsum = rem;
        }

        return ans;
    }
};