class Solution {
public:
    string smallestSubsequence(string s) {
        string ans;
        vector<int> indexes(26);
        vector<bool> visited(26, false);

        for(int i = 0; i < s.length(); i++){
            indexes[s[i] - 'a'] = i;
        }

        for(int i = 0; i < s.length(); i++){
            int idx = s[i] - 'a';

            if(visited[idx] == true){
                continue;
            }

            while(ans.length() > 0 && ans.back() > s[i] && indexes[ans.back() - 'a'] > i){
                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(s[i]);
            visited[idx] = true;
        }

        return ans;
    }
};