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
    void bfs(TreeNode* root, vector<int>& res){
        if(root == nullptr){
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> v;

            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                q.pop();

                v.push_back(temp -> val);

                if(temp -> left != nullptr){
                    q.push(temp -> left);
                }

                if(temp -> right != nullptr){
                    q.push(temp -> right);
                }
            }

            int max = INT_MIN;

            for(int i = 0; i < v.size(); i++){
                if(v[i] > max){
                    max = v[i];
                }
            }

            res.push_back(max);
        }
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> res;

        bfs(root, res);

        return res;
    }
};