class Solution {
public:
    string reverseWords(string s) {
        string res = "";

        for(int i = 0; i < s.length();){
            int j = i;
            string t = "";
            while(j < s.length() && s[j] != ' '){
                t += s[j];
                j++;
            }

            reverse(t.begin(), t.end());
            res += t;

            i = j + 1;

            if(i < s.length()){
                res += " ";
            }
        }

        return res;
    }
};