class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1'){
                ones++;
            }
        }

        int ans = ones;

        if(ans == 0){
            return ans;
        }

        vector<int> splits;

        int i = 0;
        while(i < s.length()){
            if(s[i] == '0'){
                int j = i;
                int count = 0;
                while(j < s.length() && s[j] == '0'){
                    count++;
                    j++;
                }
                splits.push_back(count);
                i = j;
            }else{
                int j = i;
                while(j < s.length() && s[j] == '1'){
                    j++;
                }

                i = j;
            }
        }

        for(int k = 1; k < splits.size(); k++){
            int res = splits[k] + splits[k - 1];
            ans = max(ans, res + ones);
        }

        return ans;
    }
};