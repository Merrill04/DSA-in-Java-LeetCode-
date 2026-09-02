class TrieNode {
public:
    TrieNode* children[26];
    bool isterminal;

    TrieNode() {
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }

        isterminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;

        for(int i = 0; i < word.length(); i++) {
            if(curr->children[word[i] - 'a'] == nullptr) {
                TrieNode* newnode = new TrieNode();
                curr->children[word[i] - 'a'] = newnode; 
            }

            curr = curr->children[word[i] - 'a'];
        }

        curr->isterminal = true;
    }

    bool search(string word) {
        TrieNode* curr = root;

        for(int i = 0; i < word.length(); i++) {
            if(curr->children[word[i] - 'a'] == nullptr) {
                return false;
            }

            curr = curr->children[word[i] - 'a'];
        }

        return curr->isterminal;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for(int i = 0; i < prefix.length(); i++) {
            if(curr->children[prefix[i] - 'a'] == nullptr) {
                return false;
            }

            curr = curr->children[prefix[i] - 'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */