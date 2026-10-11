class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        unordered_map<int, char> m;

        m[1] = 'I';
        m[5] = 'V';
        m[10] = 'X';
        m[50] = 'L';
        m[100] = 'C';
        m[500] = 'D';
        m[1000] = 'M';

        int count = 0;

        while(num > 0){
            int t = 0;
            int t1 = 1;
 
            for(int i = 0; i < count; i++){
                t1 *= 10;
            }

            count += 1;

            int c = num % 10;
            t = t1 * (num % 10);
            num /= 10;

            if(c == 1 || c == 5){
                res += m[t];
            }else if(c != 0){
                if(c == 4){
                    int x = 5 * t1;
                    res += m[x];
                    res += m[t1];
                }else if(c == 9){
                    int x = 10 * t1;
                    res += m[x];
                    res += m[t1];
                }else{
                    if(c > 5){
                        int x = 5 * t1;
                        int a1 = x;

                        while(x < t){
                            res += m[t1];
                            x += t1;
                        }

                        res += m[a1];
                    }else{
                        int x = t1;
                        int a1 = x;

                        while(x < t){
                            res += m[t1];
                            x += t1;
                        }

                        res += m[a1];
                    }
                }
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};