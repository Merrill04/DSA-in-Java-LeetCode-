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
    void bfs(TreeNode* root, vector<int>& level, vector<int>& max){
        if(root == nullptr){
            return;
        }

        queue<TreeNode*> q;
        int lv = 0;
        q.push(root);

        while(!q.empty()){
            int s = q.size();
            int sum = 0;

            for(int i = 0; i < s; i++){
                TreeNode* curr = q.front();
                q.pop();

                sum += curr -> val;

                if(curr -> left != nullptr){
                    q.push(curr -> left);
                }

                if(curr -> right != nullptr){
                    q.push(curr -> right);
                }
            }

            lv++;

            if(sum > max[0]){
                max[0] = sum;
                level[0] = lv;
            }
        }
    }

    int maxLevelSum(TreeNode* root) {
        vector<int> level(1, -1);
        vector<int> max(1, INT_MIN);

        bfs(root, level, max);

        return level[0];
    }
};