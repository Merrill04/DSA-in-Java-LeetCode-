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
    void reverse(vector<int>& v){
        int i = 0;
        int j = v.size() - 1;

        while(i < j){
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }

    void levelorder(TreeNode* root, vector<vector<int>>& v){
        if(root == NULL){
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int s = q.size();
            vector<int> t;

            for(int i = 0; i < s; i++){
                TreeNode* curr = q.front();
                q.pop();

                t.push_back(curr -> val);

                if(curr -> left != NULL){
                    q.push(curr -> left);
                }

                if(curr -> right != NULL){
                    q.push(curr -> right);
                }
            }

            v.push_back(t);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;

        levelorder(root, v);

        for(int i = 1; i < v.size(); i += 2){
            reverse(v[i]);
        }

        return v;
    }
};