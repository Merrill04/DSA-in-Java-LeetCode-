class Solution {
public:
    bool check(vector<vector<char>>& grid, int i, int j, vector<int> count, vector<vector<vector<int>>>& dp){

        if(count[0] < 0){
            return false;
        }

        if(i == grid.size() - 1 && j == grid[0].size() - 1){
            if(grid[i][j] == '('){
                count[0] += 1;
            }else{
                count[0] -= 1;
            }
            
            return count[0] == 0;
        }

        if(grid[i][j] == '('){
            count[0] += 1;
        }else{
            count[0] -= 1;
        }

        if (count[0] < 0) {
            return false;
        }

        if (dp[i][j][count[0]] != -1){
            return dp[i][j][count[0]];
        }

        bool one = false;
        bool two = false;

        if(i < grid.size() - 1 && j < grid[0].size() - 1){
            one = check(grid, i + 1, j, count, dp);
            two = check(grid, i, j + 1, count, dp);
        }else if(i == grid.size() - 1 && j < grid[0].size() - 1){
            two = check(grid, i, j + 1, count, dp);
        }else if(i < grid.size() - 1 && j == grid[0].size() - 1){
            one = check(grid, i + 1, j, count, dp);
        }

        return dp[i][j][count[0]] = one || two;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i = 0;
        int j = 0;
        vector<int> count(1, 0);
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(m + n + 1, -1)));

        if(grid[0][0] == ')' || grid[m - 1][n - 1] == '('){
            return false;
        }

        if((m + n - 1) % 2 == 1){
            return false;
        }

        return check(grid, i, j, count, dp);
    }
};