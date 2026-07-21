class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1'){
                ones++;
            }
        }

        int ans = ones;

        string t = "1" + s + "1";

        vector<pair<char,int>> runs;

        int i = 0;
        while(i < t.length()){
            char ch = t[i];
            int len = 0;

            while(i < t.size() && t[i] == ch){
                len++;
                i++;
            }

            runs.push_back({ch, len});
        }

        for(int i = 1; i + 1 < runs.size(); i++){
            if(runs[i].first == '1' && runs[i-1].first == '0' && runs[i+1].first == '0'){
                ans = max(ans, ones + runs[i-1].second + runs[i+1].second);
            }
        }

        return ans;
    }
};