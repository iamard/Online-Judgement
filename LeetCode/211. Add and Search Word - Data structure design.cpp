class WordDictionary {
    class TrieNode {
    public:
        TrieNode() {
            isWord = false;
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    
        bool     isWord;
        TrieNode *child[26];
    };

    TrieNode root;
    
    bool search(string &word, int pos, TrieNode *node) {
        if (pos == word.length()) {
            return node->isWord;
        } else if (word[pos] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->child[i]) {
                    bool status = search(word, pos + 1, node->child[i]);
                    if (status)
                        return true;
                }
            }
            return false;
        } else {
            int value = word[pos] - 'a';
            if (node->child[value]) {
                return search(word, pos + 1, node->child[value]);
            } else {
                return false;
            }
        }
    }
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *node = &root;
        for (int i = 0; i < word.length(); i++) {
            int value = word[i] - 'a';
            if (node->child[value] == nullptr)
                node->child[value] = new TrieNode();
            node = node->child[value];
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, &root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */