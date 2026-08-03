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
    void populate(TreeNode* root, vector<int>& v){
        if(root == nullptr || root == nullptr){
            return;
        }

        populate(root -> left, v);
        v.push_back(root -> val);
        populate(root -> right, v);
    }

    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        vector<int> v;
        populate(root, v);
        if(k > v.size()){
            return res;
        }

        res = v[k-1];
        return res;
    }
};