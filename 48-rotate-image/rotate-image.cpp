class Solution {
public:
    void transpose(vector<vector<int>>& m){
        for(int i = 0; i < m.size() - 1; i++){
            for(int j = i + 1; j < m[0].size(); j++){
                int temp = m[i][j];
                m[i][j] = m[j][i];
                m[j][i] = temp;
            }
        }
    }

    void reverse(vector<vector<int>>& m){
        for(int i = 0; i < m.size(); i++){
            int left = 0;
            int right = m[0].size() - 1;

            while(left < right){
                int t = m[i][left];
                m[i][left] = m[i][right];
                m[i][right] = t;
                left++;
                right--;
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);//take transpose
        reverse(matrix);//reverse each row
    }
};