class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<string>> v(m, vector<string>(n, "#"));
        vector<string> res;

        for(int i = 0; i < n; i++){
            v[0][i] = ".";
        }

        for(int i = 1; i < m; i++){
            v[i][n - 1] = ".";
        }

        for(int i = 0; i < m; i++){
            string s = "";
            for(int j = 0; j < n; j++){
                s += v[i][j];
            }

            res.push_back(s);
        }

        return res;
    }
};