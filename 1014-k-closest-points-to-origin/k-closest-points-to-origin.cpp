class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<int, vector<int>> m;
        vector<vector<int>> ans;

        for(int i = 0; i < points.size(); i++){
            int val = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            m[val].push_back(i);
        }

        for(auto &i : m){
            if(k <= 0){
                break;
            }

            for(int j = 0; j < i.second.size(); j++){
                if(k <= 0){
                    break;
                }

                vector<int> t;

                int a = i.second[j];

                t.push_back(points[a][0]);
                t.push_back(points[a][1]);

                ans.push_back(t);
                k--;
            }
        }

        return ans;
    }
};