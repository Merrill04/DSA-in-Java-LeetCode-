class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> m;
        vector<int> res;

        for(int i = 0; i < s.length(); i++){
            m[s[i]] = i;
        }

        int max = -1;
        int sum = 0;
        int i = 0;

        while(i < s.length()){
            int left = i;
            max = m[s[left]];
            left++;
            while(left <= max){
                if(m[s[left]] > max){
                    max = m[s[left]];
                }
                left++;
            }

            if(res.empty()){
                res.push_back(left);
                sum += left;
            }else{
                res.push_back(left - sum);
                sum += res[res.size() - 1];
            }
            i = left;
        }

        return res;
    }
};