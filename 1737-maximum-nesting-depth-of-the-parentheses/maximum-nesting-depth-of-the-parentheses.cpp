class Solution {
public:
    int maxDepth(string s) {
        int max = INT_MIN;
        int count = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                count++;

                if(max < count){
                    max = count;
                }
            }else if(s[i] == ')'){
                count--;
            }
        }

        if(max == INT_MIN){
            max = 0;
        }

        return max;
    }
};