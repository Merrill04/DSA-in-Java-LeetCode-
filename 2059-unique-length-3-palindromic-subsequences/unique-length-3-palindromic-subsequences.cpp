class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<int> lastoccurence(26, -1);
        int res = 0;

        for(int i = 0; i < s.length(); i++){
            freq[s[i] - 'a'] += 1;
            lastoccurence[s[i] - 'a'] = i;
        }

        for(int i = 0; i < s.length(); i++){
            if(freq[s[i] - 'a'] >= 2){
                unordered_map<char, int> m;

                for(int j = i + 1; j < lastoccurence[s[i] - 'a']; j++){
                    if(m.find(s[j]) == m.end()){
                        res++;
                    }
                    m[s[j]] += 1;
                }

                freq[s[i] - 'a'] = 0;
            }
        }

        return res;
    }
};