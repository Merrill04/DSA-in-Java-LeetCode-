class Solution {
public:
    vector<string> createGrid(int m, int n) {
/*
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
*/
        vector<string> res;

        string s1 = "";
        string s2 = "";

        for(int i = 0; i < n; i++){
            s1 += ".";
        }

        for(int i = 0; i < n - 1; i++){
            s2 += "#";
        }
        
        s2 += ".";

        res.push_back(s1);

        for(int i = 1; i < m; i++){
            res.push_back(s2);
        }

        return res;
    }
};