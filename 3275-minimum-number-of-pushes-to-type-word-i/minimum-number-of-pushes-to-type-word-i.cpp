class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        int len = word.length();

        if(len <= 8){
            ans = len;
        }else if(len > 8 && len <= 16){
            ans = 8 + (2 * (len - 8));
        }else if(len > 16 && len <= 24){
            ans = 24 + (3 * (len - 16));
        }else{
            ans = 48 + (4 * (len - 24));
        }

        return ans;
    }
};