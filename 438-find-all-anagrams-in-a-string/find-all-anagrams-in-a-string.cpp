class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;

        if(p.length() > s.length()){
            return res;
        }

        vector<int> freq(26, 0);

        for(int i = 0; i < p.length(); i++){
            freq[p[i] - 97] += 1;
        }

        vector<int> window(26, 0);
        int k= p.length();

        for(int i = 0; i < k; i++){
            window[s[i] - 97] += 1;
        }

        if(window == freq){
            res.push_back(0);
        }

        for(int i = k; i < s.length(); i++){
            window[s[i - k] - 'a']--;
            window[s[i] - 'a']++;

            if(window == freq){
                res.push_back(i - k + 1);
            }
        }

        return res;
    }
};

