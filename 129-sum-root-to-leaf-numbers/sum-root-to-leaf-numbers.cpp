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
    void preorder(TreeNode* root, vector<int>& v, int num){
        if(root == NULL){
            return;
        }

        num = ((num * 10) + root -> val);

        if(root -> left == NULL && root -> right == NULL){
            v.push_back(num);
            return;
        }
        
        if(root -> left != NULL){
            preorder(root -> left, v, num);
        }
        if(root -> right != NULL){
            preorder(root -> right, v, num);
        }
    }

    int sumNumbers(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        vector<int> v;
        preorder(root, v, 0);
        int res = 0;

        for(int i = 0; i < v.size(); i++){
            res += v[i];
        }

        return res;
    }
};