class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> m;

        for(int i = 0; i < nums.size(); i++){
            m[nums[i]] += 1;
        }

        vector<pair<int, int>> v(m.begin(), m.end());

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        for(int i = 0; i < k; i++){
            res.push_back(v[i].first);
        }

        return res;
    }
};