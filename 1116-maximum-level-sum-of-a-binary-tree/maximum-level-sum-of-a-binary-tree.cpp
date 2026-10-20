/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void bfs(TreeNode* root, vector<vector<int>>& v){
        if(root == nullptr){
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int s = q.size();
            vector<int> lv;

            for(int i = 0; i < s; i++){
                TreeNode* curr = q.front();
                q.pop();

                lv.push_back(curr -> val);

                if(curr -> left != nullptr){
                    q.push(curr -> left);
                }

                if(curr -> right != nullptr){
                    q.push(curr -> right);
                }
            }

            v.push_back(lv);
        }
    }

    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> v;

        bfs(root, v);

        int level = -1;
        int max = INT_MIN;

        for(int i = 0; i < v.size(); i++){
            int sum = 0;

            for(int j = 0; j < v[i].size(); j++){
                sum += v[i][j];
            }

            if(sum > max){
                level = i + 1;
                max = sum;
            }
        }

        return level;
    }
};