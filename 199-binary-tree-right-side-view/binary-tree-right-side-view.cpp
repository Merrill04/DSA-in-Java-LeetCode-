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
        if(root == NULL){
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size(); 
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if(curr->left != NULL) {
                    q.push(curr->left);
                }

                if(curr->right != NULL) {
                    q.push(curr->right);
                }
            }

            v.push_back(level);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> v;
        vector<int> res;

        bfs(root, v);

        for(int i = 0; i < v.size(); i++){
            res.push_back(v[i][v[i].size() - 1]);
        }

        return res;
    }
};