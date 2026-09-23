class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        int n = columnTitle.length();

        for(int i = 0; i < n; i++){
            int t = columnTitle[i] - 'A' + 1;
            int p = 1;

            for(int j = 0; j < n - i - 1; j++){
                p *= 26;
            }

            res += (t * p);
        }

        return res;
    }
};