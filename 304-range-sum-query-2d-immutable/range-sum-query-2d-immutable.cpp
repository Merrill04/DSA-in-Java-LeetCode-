class NumMatrix {
public:
    vector<vector<int>> prefixmatrix;

    NumMatrix(vector<vector<int>>& matrix) {
/*
//O(num of rows) time
        for(int i = 0; i < matrix.size(); i++){
            vector<int> t;
            int sum = 0;
            for(int j = 0; j < matrix[0].size(); j++){
                sum += matrix[i][j];
                t.push_back(sum);
            }

            prefixmatrix.push_back(t);
        }
*/

        prefixmatrix = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0 ; j < matrix[0].size(); j++){
                prefixmatrix[i][j] = matrix[i][j];

                if(i > 0){
                    prefixmatrix[i][j] += prefixmatrix[i - 1][j];
                }

                if(j > 0){
                    prefixmatrix[i][j] += prefixmatrix[i][j - 1];
                }

                if(i > 0 && j > 0){
                    prefixmatrix[i][j] -= prefixmatrix[i - 1][j - 1];
                }
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
/*
        int ans = 0;
        for(int i = row1; i <= row2; i++){
            if(col1 > 0){
                ans += prefixmatrix[i][col2] - prefixmatrix[i][col1 - 1];
            }else{
                ans += prefixmatrix[i][col2];
            }
        }

        return ans;
*/  
        int ans = 0;
        ans += prefixmatrix[row2][col2];
        if(row1 > 0){
            ans -= prefixmatrix[row1 - 1][col2];
        }

        if(col1 > 0){
            ans -= prefixmatrix[row2][col1 - 1];
        }

        if(row1 > 0 && col1 > 0){
            ans += prefixmatrix[row1 - 1][col1 - 1];
        }

        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */