class TrieNode{
    public: 
        TrieNode* children[26];
        bool isterminal;

        TrieNode(){
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }

            isterminal = false;
        }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();    
    }
    
    void addWord(string word) {
        TrieNode* curr = root;

        for(int i = 0; i < word.length(); i++){
            if(curr -> children[word[i] - 'a'] == nullptr){
                TrieNode* newnode = new TrieNode();
                curr -> children[word[i] - 'a'] = newnode;
            }

            curr = curr -> children[word[i] - 'a'];
        }

        curr -> isterminal = true;
    }
    
    bool search(string word) {
        int idx = 0;
        return searchintrie(root, word, idx);
    }

    bool searchintrie(TrieNode* root, string word, int idx){
        if(idx == word.length()){
            return root->isterminal;
        }

        if(word[idx] == '.'){
            for(int i = 0; i < 26; i++){
                if(root->children[i] != nullptr){
                    if(searchintrie(root->children[i], word, idx + 1) == true){
                        return true;
                    }
                }
            }

            return false;
        }

        int child = word[idx] - 'a';

        if(root->children[child] == nullptr){
            return false;
        }

        return searchintrie(root->children[child], word, idx + 1);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */