class Solution {
public:
    int maximum69Number (int num) {
        vector<int> v;

        int t = num;

        while(t > 0){
            v.push_back(t % 10);
            t /= 10;
        }

        reverse(v.begin(), v.end());

        for(int i = 0; i < v.size(); i++){
            if(v[i] == 6){
                v[i] = 9;
                break;
            }
        }

        int res = 0;

        for(int i = 0; i < v.size(); i++){
            res = v[i] + (10 * res);
        }

        return res;
    }
};