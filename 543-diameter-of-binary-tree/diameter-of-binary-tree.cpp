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
/*
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = height(root -> left);
        int right = height(root -> right);

        return max(left, right) + 1;
    }

    int diameter(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int one = diameter(root -> left);
        int two = diameter(root -> right);
        int three = height(root -> left) + height(root -> right);

        return max(one, max(two, three));
    }
*/
    pair<int, int>  diameter(TreeNode* root){
        if(root == NULL){
            pair<int, int> p = {0, 0};
            return p;
        }

        pair<int, int> left = diameter(root -> left);
        pair<int, int> right = diameter(root -> right);

        int opt1 = left.first;
        int opt2 = right.first;
        int opt3 = left.second + right.second;

        pair<int, int> ans;
        ans.first = max(opt1, max(opt2, opt3));
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        pair<int, int> ans = diameter(root);
        return ans.first;
    }
};