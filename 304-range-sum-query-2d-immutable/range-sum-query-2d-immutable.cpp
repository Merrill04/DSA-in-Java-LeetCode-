class NumMatrix {
public:
    vector<vector<int>> prefixmatrix;

    NumMatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++){
            vector<int> t;
            int sum = 0;
            for(int j = 0; j < matrix[0].size(); j++){
                sum += matrix[i][j];
                t.push_back(sum);
            }

            prefixmatrix.push_back(t);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for(int i = row1; i <= row2; i++){
            if(col1 > 0){
                ans += prefixmatrix[i][col2] - prefixmatrix[i][col1 - 1];
            }else{
                ans += prefixmatrix[i][col2];
            }
        }

        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */