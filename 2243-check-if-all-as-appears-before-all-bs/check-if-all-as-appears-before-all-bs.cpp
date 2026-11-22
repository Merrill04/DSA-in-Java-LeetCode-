class Solution {
public:
    bool checkString(string s) {
        int fb = s.length();

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'b'){
                fb = i;
                break;
            }
        }

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a' && i > fb){
                return false;
            }
        }

        return true;
    }
};