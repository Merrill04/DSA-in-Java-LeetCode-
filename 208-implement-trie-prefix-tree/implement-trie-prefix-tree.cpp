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

        for(char c : word) {
            if(curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new TrieNode();
            }

            curr = curr->children[c - 'a'];
        }

        curr->isterminal = true;
    }

    bool search(string word) {
        TrieNode* curr = root;

        for(char c : word) {
            if(curr->children[c - 'a'] == nullptr) {
                return false;
            }

            curr = curr->children[c - 'a'];
        }

        return curr->isterminal;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for(char c : prefix) {
            if(curr->children[c - 'a'] == nullptr) {
                return false;
            }

            curr = curr->children[c - 'a'];
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