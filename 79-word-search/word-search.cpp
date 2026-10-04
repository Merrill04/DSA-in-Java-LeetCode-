class Solution {
public:
    void check(int m, int n, int idx1, int idx2, string word, vector<vector<char>>& board, vector<bool>& result, vector<vector<bool>>& v){
        
        if(word.length() == 0){
            result.push_back(true);
            return;
        }

        if(idx1 >= m || idx1 < 0){
            return;
        }

        if(idx2 >= n || idx2 < 0){
            return;
        }

        if(board[idx1][idx2] != word[0]){
            return;
        }else if(board[idx1][idx2] == word[0] && v[idx1][idx2] == false){
            string t = word.substr(1, word.length());
            v[idx1][idx2] = true; 
            check(m, n, idx1 + 1, idx2, t, board, result, v);
            check(m, n, idx1 - 1, idx2, t, board, result, v);
            check(m, n, idx1, idx2 + 1, t, board, result, v);
            check(m, n, idx1, idx2 - 1, t, board, result, v);

            v[idx1][idx2] = false;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> index;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    index.push_back(temp); 
                }
            }
        }

        vector<bool> result;
        vector<vector<bool>> v(m, vector<bool>(n, false));

        for(int i = 0; i < index.size(); i++){
            check(m, n, index[i][0], index[i][1], word, board, result, v);
        }

        bool res = false;

        for(int i = 0; i < result.size(); i++){
            res = res || result[i];
        }

        return res;
    }
};