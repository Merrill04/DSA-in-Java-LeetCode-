class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int, int> m;

        for(int i = 0; i < digits.size(); i++){
            for(int j = i + 1; j < digits.size(); j++){
                for(int k = j + 1; k < digits.size(); k++){
                    int num1 = digits[i] * 100 + digits[j] * 10 + digits[k];
                    int num2 = digits[j] * 100 + digits[i] * 10 + digits[k];
                    int num3 = digits[k] * 100 + digits[j] * 10 + digits[i];
                    int num4 = digits[i] * 100 + digits[k] * 10 + digits[j];
                    int num5 = digits[j] * 100 + digits[k] * 10 + digits[i];
                    int num6 = digits[k] * 100 + digits[i] * 10 + digits[j];

                    if(num1 >= 100 & num1 % 2 == 0){
                        m[num1] += 1;
                    }

                    if(num2 >= 100 & num2 % 2 == 0){
                        m[num2] += 1;
                    }

                    if(num3 >= 100 & num3 % 2 == 0){
                        m[num3] += 1;
                    }

                    if(num4 >= 100 & num4 % 2 == 0){
                        m[num4] += 1;
                    }

                    if(num5 >= 100 & num5 % 2 == 0){
                        m[num5] += 1;
                    }

                    if(num6 >= 100 & num6 % 2 == 0){
                        m[num6] += 1;
                    }
                }
            }
        }

        return m.size();
    }
};