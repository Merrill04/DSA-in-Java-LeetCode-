class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }

        vector<vector<char>> v(numRows, vector<char>(s.length(), '_'));
        string res = "";
        int count = 0;
        int identifier = 0;

        for(int i = 0; i < v[0].size(); i++){
            if(count < s.length()){
                if(identifier == 0){
                    for(int j = 0; j < v.size(); j++){
                        if(count < s.length()){
                            v[j][i] = s[count];
                            count++;
                        }else{
                            break;
                        }
                    }
                    identifier += numRows - 2;
                }else{
                    v[identifier][i] = s[count];
                    count++;
                    identifier--;
                }
            }else{
                break;
            }
        }

        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[0].size(); j++){
                if(v[i][j] != '_'){
                    res += v[i][j];
                }
            }
        }

        return res;
    }
};