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
    TreeNode* Input(vector<int>& nums, int left, int right){
        if(left > right){
            return NULL;
        }

        int mid = left + (right - left) / 2;
        TreeNode* r = new TreeNode(nums[mid]);

        r -> left = Input(nums, left, mid - 1);
        r -> right = Input(nums, mid + 1, right);

        return r;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size() - 1;
        return Input(nums, 0, n);
    }
};