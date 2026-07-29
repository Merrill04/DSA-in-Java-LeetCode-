class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> sorted;
        
        for(int i = 0; i < strs.size(); i++){
            vector<char> temp;
            string s;
            for(int j = 0; j < strs[i].length(); j++){
                temp.push_back(strs[i][j]);
            }

            sort(temp.begin(), temp.end());

            for(int j = 0; j < temp.size(); j++){
                s += temp[j];
            }

            sorted.push_back(s);
        }

        unordered_map<string, vector<string>> m;

        for(int i = 0; i < sorted.size(); i++){
            m[sorted[i]].push_back(strs[i]);
        }

        for(auto &p : m){
            res.push_back(p.second);
        }

        return res;
    }
};