class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int res = INT_MIN;

        for(int i = 0; i < grid.size() - 2; i++){
            for(int j = 0; j < grid[0].size() - 2; j++){
                int sum = 0;

                for(int k = j; k < j + 3; k++){
                    sum += grid[i][k];
                }

                for(int k = j; k < j + 3; k++){
                    sum += grid[i + 2][k];
                }

                sum += grid[i + 1][j + 1];

                res = max(res, sum);
            }
        }

        return res;
    }
};