class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";

        int i = num1.length() - 1;
        int j = num2.length() - 1;

        int carry = 0;

        while(i >= 0 && j >= 0){
            int a = num1[i] - '0';
            int b = num2[j] - '0';
            int n = carry + a + b;
            
            if(n > 9){
                carry = n / 10;
                res += (n % 10) + '0';
            }else{
                carry = 0;
                res += n + '0';
            }

            i--;
            j--;
        }

        while(i >= 0){
            int a = num1[i] - '0';
            int n = carry + a;
            
            if(n > 9){
                carry = n / 10;
                res += (n % 10) + '0';
            }else{
                carry = 0;
                res += n + '0';
            }

            i--;
        }

        while(j >= 0){
            int b = num2[j] - '0';
            int n = carry + b;
            
            if(n > 9){
                carry = n / 10;
                res += (n % 10) + '0';
            }else{
                carry = 0;
                res += n + '0';
            }

            j--;
        }

        if(carry != 0){
            res += carry + '0';
        }

        reverse(res.begin(), res.end());

        return res;
    }
};