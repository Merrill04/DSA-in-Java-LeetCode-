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
    string preorder(TreeNode* root){
        string res = "";

        if(root == nullptr){
            return res;
        }

        res += to_string(root -> val);

        if(root -> left == nullptr && root -> right != nullptr){
            res += "()";
        }

        string left = "";
        string right = "";

        if(root -> left == nullptr){
            preorder(root -> left);
        }else{
            left += '(' + preorder(root -> left) + ')';
        }

        if(root -> right == nullptr){
            preorder(root -> right);
        }else{
            right += '(' + preorder(root -> right) + ')';
        }

        return res + left + right;
    }

    string tree2str(TreeNode* root) {
        string res = "";

        res += preorder(root);

        return res;
    }
};