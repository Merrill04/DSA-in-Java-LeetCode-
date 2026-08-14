class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = -1;
        unordered_map<char, int> m;
        int j = 0;
        int total = 0;
        for(int i = 0; i < s.length(); i++){
            if(m.find(s[i]) != m.end()){
                if(m[s[i]] >= 2){
                    while(j < s.length() && m[s[i]] >= 2){
                        m[s[j]] -= 1;
                        total--;
                        j++;
                    }
                    m[s[i]] += 1;
                    total++;
                }else{
                    m[s[i]] += 1;
                    total++;
                }
            }else{
                m[s[i]] = 1;
                total++;
            }

            ans = max(ans, total);
        }

        ans = max(ans, total);

        return ans;
    }
};