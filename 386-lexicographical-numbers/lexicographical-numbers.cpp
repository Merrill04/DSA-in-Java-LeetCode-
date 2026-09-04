class Trie{
    public:

    Trie* child[10];
    bool isterminal;

    Trie(){
        for(int i = 0; i < 10; i++){
            child[i] = nullptr;
        }

        isterminal = false;
    }
};

void insert(Trie* root, string num, int i){
    if(i == num.length()){
        root -> isterminal = true;
        return;
    }

    if(root -> child[num[i] - '0'] == nullptr){
        Trie* newnode = new Trie();
        root -> child[num[i] - '0'] = newnode; 
    }

    insert(root -> child[num[i] - '0'], num, i+1);
}

void formnum(Trie* root, int curr, int num, vector<int>& ans){
    if(root->child[curr] == nullptr){
        return;
    }

    Trie* node = root->child[curr];

    num = (10 * num) + curr;

    if(node->isterminal){
        ans.push_back(num);
    }

    for(int i = 0; i < 10; i++){
        if(node->child[i] != nullptr){
            formnum(node, i, num, ans);
        }
    }
}

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        Trie* root = new Trie();

        for(int i = 1; i <= n; i++){
            string t = to_string(i);
            insert(root, t, 0);
        }

        vector<int> ans;

        for(int i = 0; i < 10; i++){
            formnum(root, i, 0, ans);
        }

        return ans;
    }
};