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
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> t;

            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                t.push_back(curr -> val);

                if(curr -> left != nullptr){
                    q.push(curr -> left);
                }

                if(curr -> right != nullptr){
                    q.push(curr -> right);
                }
            }

            v.push_back(t);
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> v;

        bfs(root, v);

        return v[v.size() - 1][0];
    }
};