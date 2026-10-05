class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> v;
        int score = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                v.push_back(score);
                score = 0;
            }else{
                if(s[i - 1] == '('){
                    score = v[v.size() - 1] + 1;
                }else{
                    score = v[v.size() - 1] + (2 * score);
                }
                
                v.pop_back();
            }
        }

        return score;
    }
};