class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long ans = 0;
        vector<double> fractions;
        unordered_map<double, int> m;

        for(int i = 0; i < rectangles.size(); i++){
            double val = (double) rectangles[i][0] / rectangles[i][1];
            fractions.push_back(val);
        }

        for(int i = 0; i < fractions.size(); i++){
            m[fractions[i]] += 1;
        }

        for(auto &i : m){
            long long num = (long long) i.second - 1;
            long long res = (num * (num + 1)) / 2;
            ans += res;
        }

        return ans;
    }
};