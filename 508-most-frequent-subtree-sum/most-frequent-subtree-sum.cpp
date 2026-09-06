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
    void postorder(TreeNode* root, vector<int>& temp){
        if(root == nullptr){
            return;
        }

        postorder(root -> left, temp);
        postorder(root -> right, temp);

        if(root -> left == nullptr && root -> right == nullptr){
            temp.push_back(root -> val);
        }else if(root -> left != nullptr && root -> right != nullptr){
            temp.push_back(root -> val + root -> left -> val + root -> right -> val);
            root -> val = root -> val + root -> left -> val + root -> right -> val;
        }else if(root -> left != nullptr && root -> right == nullptr){
            temp.push_back(root -> val + root -> left -> val);
            root -> val = root -> val + root -> left -> val;
        }else if(root -> left == nullptr && root -> right != nullptr){
            temp.push_back(root -> val + root -> right -> val);
            root -> val = root -> val + root -> right -> val;
        }
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> temp;

        postorder(root, temp);

        unordered_map<int, int> m;

        for(int i = 0; i < temp.size(); i++){
            m[temp[i]] += 1;
        }

        bool flag = true;

        for(auto &i : m){
            if(i.second > 1){
                flag = false;
                break;
            }
        }

        if(flag == true){
            return temp;
        }

        vector<int> res;

        int max = -1;

        for(auto &i : m){
            if(i.second > max){
                max = i.second;
            }
        }

        for(auto &i : m){
            if(i.second == max){
                res.push_back(i.first);
            }
        }

        return res;
    }
};