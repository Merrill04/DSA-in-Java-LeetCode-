class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> m;
        string res = "";

        for(int i = 0; i < knowledge.size(); i++){
            m[knowledge[i][0]] = knowledge[i][1];
        }

        int i = 0;

        while(i < s.length()){
            if(s[i] == '('){
                int j = i + 1;
                string temp = "";

                while(j < s.length() && s[j] != ')'){
                    temp += s[j];
                    j++;
                }

                if(m.find(temp) != m.end()){
                    res += m[temp];
                }else{
                    res += '?';
                }

                i = j + 1;
            }else{
                res += s[i];
                i++;
            }
        }

        return res;
    }
};