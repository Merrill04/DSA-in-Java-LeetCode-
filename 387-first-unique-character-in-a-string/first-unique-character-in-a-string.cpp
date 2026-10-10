class Solution {
public:
    int firstUniqChar(string s) {
        int idx = -1;
        vector<int> v(26, 0);
        int n = s.length();

        for(int i = 0; i < n; i++){
            v[s[i] - 'a'] += 1; 
        }

        for(int i = 0; i < n; i++){
            if(v[s[i] - 'a'] == 1){
                return i;
            }
        }

        return idx;
    }
};