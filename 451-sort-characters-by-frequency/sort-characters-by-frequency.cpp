class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;

        for(int i = 0; i < s.length(); i++){
            m[s[i]] += 1;
        }

        vector<pair<char, int>> v(m.begin(), m.end());

        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        string ans;

        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[i].second; j++){
                ans += v[i].first;
            }
        }

        return ans;
    }
};