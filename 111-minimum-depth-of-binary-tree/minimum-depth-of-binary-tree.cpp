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
    void finddepth(TreeNode* root, int nodes, vector<int>& ans){
        if(root == nullptr){
            return;
        }

        if(root -> left == nullptr && root -> right == nullptr){
            ans[0] = min(ans[0], nodes);
        }

        finddepth(root -> left, nodes + 1, ans);
        finddepth(root -> right, nodes + 1, ans);
    }

    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        
        vector<int> ans(1, INT_MAX);
        finddepth(root, 1, ans);
        return ans[0];
    }
};