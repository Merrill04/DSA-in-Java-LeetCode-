class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> v(26, 0);

        for(int i = 0; i < s.length(); i++){
            int t = s[i];
            v[t % 97]++;
        }

        string ans;

        if(s.length() % 2 == 0){
            for(int i = 0; i < v.size(); i++){
                if(v[i] != 0){
                    char m = (char) (97 + i);
                    int o = v[i] / 2;
                    while(o > 0){
                        ans += m;
                        o--;
                    }
                }
            }

            string temp = ans;
            for(int i = temp.size() - 1; i >= 0; i--){
                ans += temp[i];
            }
        }else{
            char a;
            for(int i = 0; i < v.size(); i++){
                if(v[i] != 0 && v[i] % 2 != 0){
                    a = (char) (97 + i);
                    v[i] -= 1;
                    break;
                }
            }

            for(int i = 0; i < v.size(); i++){
                if(v[i] != 0){
                    char m = (char) (97 + i);
                    int o = v[i] / 2;
                    while(o > 0){
                        ans += m;
                        o--;
                    }
                }
            }

            string temp = ans;
            ans += a;
            for(int i = temp.size() - 1; i >= 0; i--){
                ans += temp[i];
            }
        }

        return ans;
    }
};