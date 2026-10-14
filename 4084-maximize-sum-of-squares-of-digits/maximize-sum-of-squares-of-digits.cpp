class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9 * num < sum){
            return "";
        }

        string res = "";

        while(sum > 9){
            res += "9";
            sum -= 9;
            num--;
        }

        res += char ('0' + sum);
        num--;

        while(num > 0){
            res += "0";
            num--;
        }

        return res;
    }
};