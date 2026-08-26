class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int count = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1'){
                count++;
            }
        }

        if(s.length() < k || count < k){
            return "";
        }else if(count == k){
            int i = 0;
            while(s[i] != '1'){
                i++;
            }

            int j = s.length() - 1;
            while(s[j] != '1'){
                j--;
            }

            return s.substr(i, j - i + 1);
        }

        string res = "";

        for(int i = 0; i < s.length(); i++){
            int t = k;
            int j = i;

            while(j < s.length() && t > 0){
                if(s[j] == '1'){
                    t--;
                }
                j++;
            }

            if(t <= 0){
                string temp = s.substr(i, j - i);
                if(res == ""){
                    res = temp;
                }else if(res.length() > temp.length()){
                    res = temp;
                }else if(res.length() == temp.length()){
                    for(int i = 0; i < res.length(); i++){
                        if(res[i] == '1' && temp[i] == '0'){
                            res = temp;
                            break;
                        }else if(res[i] == '0' && temp[i] == '1'){
                            break;
                        }
                    }
                } 
            }
        }

        return res;
    }
};