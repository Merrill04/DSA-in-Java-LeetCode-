class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for(int i = 1; i < n; i++){
            string t = "";
            int j = 0;

            while(j < s.length()){
                int len = 1;
                int k = j;

                while(k < s.length() - 1 && s[k] == s[k + 1]){
                    len++;
                    k++;
                }

                char a = '0' + len;
                t += a;
                t += s[k];
                j = k + 1;
            }

            s = t;
        }

        return s;
    }
};