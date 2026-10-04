class Solution {
public:
    bool validate(string s){
        stack<char> st;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }else{
                if(st.empty()){
                    return false;
                }else if(st.top() == '('){
                    st.pop();
                }
            }
        }

        return st.empty();
    }

    void generate(int len, string s, vector<string>& res){
        if(s.length() == len){
            if(validate(s)){
                res.push_back(s);
            }

            return;
        }

        s += '(';
        generate(len, s, res);
        s.pop_back();

        s += ')';
        generate(len, s, res);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";

        generate(n * 2, s, res);

        return res;
    }
};