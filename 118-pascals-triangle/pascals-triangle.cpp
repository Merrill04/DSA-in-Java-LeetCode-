class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> v1(1, 1);
        vector<int> v2(2, 1);

        if(numRows == 1){
            ans.push_back(v1);
            return ans;
        }
        ans.push_back(v1);
        ans.push_back(v2);

        for(int i = 2; i < numRows; i++){
            vector<int> v(i+1);
            v[0] = 1;
            v[i] = 1;

            for(int j = 1; j < v.size() - 1; j++){
                v[j] = ans[i-1][j-1] + ans[i-1][j];
            }

            ans.push_back(v);
        }

        return ans;
    }
};