class Solution {
    void combine(vector<string>& ans,string answer, string digits, string map[], int idx){
        if(idx > digits.length() - 1){
            ans.push_back(answer);
            return;
        }

        int a = digits[idx] - '0';
        string val = map[a];

        for(int i = 0; i < val.length(); i++){
            answer += val[i];
            combine(ans, answer, digits, map, idx+1);
            answer.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string answer;
        combine(ans, answer, digits, mapping, 0);
        return ans;
    }
};