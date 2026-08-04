/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* traversal(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr){
            return nullptr;
        }

        TreeNode* ans;

        if(p -> val <= root -> val && q -> val >= root -> val){
            return root;
        }else if(p -> val >= root -> val && q -> val <= root -> val){
            return root;
        }else if(p -> val <= root -> val && q -> val <= root -> val){
            ans = traversal(root -> left, p, q);
        }else{
            ans = traversal(root -> right, p, q);
        }

        return ans;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traversal(root, p, q);
    }
};