class Solution {
public:
    void reverse(vector<int>& array, int i, int j){
        while(i < j){
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> arr;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                arr.push_back(grid[i][j]);
            }
        }

        k = k % arr.size();

        reverse(arr, 0, arr.size()-1);
        reverse(arr, 0, k-1);
        reverse(arr, k, arr.size()-1);
        int count = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                grid[i][j] = arr[count];
                count++;
            }
        }

        return grid;
    }
};