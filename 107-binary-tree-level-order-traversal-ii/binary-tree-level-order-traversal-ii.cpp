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
    void bfstraversal(TreeNode* root, vector<vector<int>>& bfs){
        if(root == nullptr){
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> v;

            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();

                v.push_back(curr -> val);

                if(curr -> left != nullptr){
                    q.push(curr -> left);
                }

                if(curr -> right != nullptr){
                    q.push(curr -> right);
                }
            }

            bfs.push_back(v);
        }
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> bfs;
        vector<vector<int>> res;

        bfstraversal(root, bfs);

        for(int i = bfs.size() - 1; i >= 0; i--){
            vector<int> t;

            for(int j = 0; j < bfs[i].size(); j++){
                t.push_back(bfs[i][j]);
            }

            res.push_back(t);
        }

        return res;
    }
};