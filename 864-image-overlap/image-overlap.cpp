class Solution {
public:
    int getmax(vector<vector<int>> img1, vector<vector<int>> img2, int rowoff, int coloff){
        int n = img1.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int idx1 = i + rowoff;
                int idx2 = j + coloff;

                if(idx1 < 0 || idx1 >= n || idx2 < 0 || idx2 >= n){
                    continue;
                }else{
                    if(img1[i][j] == img2[idx1][idx2] && img1[i][j] == 1){
                        count++;
                    }
                }
            }
        }

        return count;   
    }

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int res = -1;
        int n = img1.size();

        for(int i = -n + 1; i < n; i++){
            for(int j = -n + 1; j < n; j++){
                int count = getmax(img1, img2, i, j);
                res = max(res, count);
            }
        }

        return res;
    }
};