class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;

        for(int i = 0; i < words.size() - 1; i++){
            vector<bool> v(26, false);

            for(int j = 0; j < words[i].length(); j++){
                v[words[i][j] - 'a'] = true;
            }

            for(int j = i + 1; j < words.size(); j++){
                bool flag = false;

                for(int k = 0; k < words[j].length(); k++){
                    if(v[words[j][k] - 'a'] == true){
                        flag = true;
                        break;
                    }
                }

                if(flag == false){
                    int s = words[i].length() * words[j].length();
                    res = max(res, s);
                }
            }
        }

        return res;
    }
};