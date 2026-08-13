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
    int getleftheight(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        return 1 + getleftheight(root -> left);
    }

    int getrightheight(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        return 1 + getrightheight(root -> right);
    }

    int count(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int leftheight = getleftheight(root);
        int rightheight = getrightheight(root);

        if(leftheight == rightheight){
            int ans = 1;
            for(int i = 0; i < leftheight; i++){
                ans *= 2;
            }

            return ans - 1;
        }

        return count(root -> left) + count(root -> right) + 1;
    }

    int countNodes(TreeNode* root) {
        return count(root);
    }
};