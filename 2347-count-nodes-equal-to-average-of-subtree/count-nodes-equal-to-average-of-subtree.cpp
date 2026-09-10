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
    pair<int, int> getnodes(TreeNode* root, vector<int>& nodes){
        if(root == nullptr){
            return {0, 0};
        }

        pair<int, int> leftsum = getnodes(root -> left, nodes);
        pair<int, int> rightsum = getnodes(root -> right, nodes);

        int sum = leftsum.first + rightsum.first;
        int count = leftsum.second + rightsum.second;

        sum += root -> val;
        count += 1;

        if(root -> val == (sum / count)){
            nodes.push_back(root -> val);
        }

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        vector<int> nodes;
        getnodes(root, nodes);
        return nodes.size();
    }
};