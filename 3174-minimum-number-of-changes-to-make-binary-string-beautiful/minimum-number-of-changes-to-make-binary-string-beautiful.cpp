class Solution {
public:
    int minChanges(string s) {
        int min = 0;

        for(int i = 0; i < s.length(); i += 2){
            if(s[i] != s[i + 1]){
                min += 1;
            }
        }

        return min;
    }
};