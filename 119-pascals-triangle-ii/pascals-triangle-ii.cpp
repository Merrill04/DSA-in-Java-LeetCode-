class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        vector<int> v1(1, 1);
        vector<int> v2(2, 1);
        ans.push_back(v1);
        ans.push_back(v2);

        for(int i = 2; i <= rowIndex; i++){
            vector<int> v(i+1);
            v[0] = 1;
            v[i] = 1;

            for(int j = 1; j < v.size() - 1; j++){
                v[j] = ans[i-1][j-1] + ans[i-1][j];
            }

            ans.push_back(v);
        }

        return ans[rowIndex];
    }
};