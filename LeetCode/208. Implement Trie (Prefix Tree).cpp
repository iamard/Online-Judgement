class Trie {
    class Node {
    public:
        Node() {
            isWord = false;
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }

        bool isWord;
        Node *child[26];
    };

    Node *root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        for (int i = 0; i < word.length(); i++) {
            int value = word[i] - 'a';
             if (node->child[value] == nullptr) {
                 node->child[value] = new Node();
             }
            node = node->child[value];
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *node = root;
        for (int i = 0; i < word.length(); i++) {
            int value = word[i] - 'a';
            if (node->child[value] == nullptr)
                return false;
            node = node->child[value];
        }
        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++) {
            int value = prefix[i] - 'a';
            if (node->child[value] == nullptr)
                return false;
            node = node->child[value];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */