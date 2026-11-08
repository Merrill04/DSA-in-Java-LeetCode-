class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int res = 0;

        for(int i = 0; i < grid.size(); i++){
            int count = 0;

            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }

            if(count > 1){
                res += count;

                for(int j = 0; j < grid[i].size(); j++){
                    if(grid[i][j] == 1){
                        grid[i][j] = 2;
                    }
                }
            }
        }

        for(int i = 0; i < grid[0].size(); i++){
            int count = 0;

            for(int j = 0; j < grid.size(); j++){
                if(grid[j][i] == 1 || grid[j][i] == 2){
                    count++;
                }
            }

            if(count > 1){
                for(int j = 0; j < grid.size(); j++){
                    if(grid[j][i] == 1){
                        res += 1;
                    }
                }
            }
        }

        return res;
    }
};