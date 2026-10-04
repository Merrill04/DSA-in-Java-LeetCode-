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

    void generate(int len, string s, vector<string>& res, vector<int> opencount){
        if(s.length() == len){
            if(validate(s)){
                res.push_back(s);
            }

            return;
        }

        if(opencount[0] < ((len / 2) + 1)){
            s += '(';
            opencount[0] += 1;
            generate(len, s, res, opencount);
            opencount[0] -= 1;
            s.pop_back();
        }else{
            return;
        }

        if(opencount[0] > 0){
            s += ')';
            opencount[0] -= 1;
            generate(len, s, res, opencount);
        }else{
            return;
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        vector<int> opencount(1, 0);

        generate(n * 2, s, res, opencount);

        return res;
    }
};