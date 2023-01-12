#if !defined(TRIE_HPP)
#define TRIE_HPP

class TrieNode
{
public:
    std::unordered_map<char, TrieNode*> children;
    bool isWord;
    //* For the search suggestions system
    std::vector<std::string> searchWords;
    //* For lexicographical numeric order
    std::map<char, TrieNode*> lexiNumChildren;

    TrieNode() {
        this->isWord = false;
    }
};


class ITrie
{
public:
    TrieNode* root;
    virtual void Insert(string& word) = 0;
    // searching for a string
    bool Search(string& word){
        // write your code here
        TrieNode* runner = root;
        for (char& c : word) {
            if (runner->children.find(c) == runner->children.end()) return false;
            runner = runner->children[c];
        }
        return runner->isWord;
    }
    // searching for a prefix
    bool SearchPrefix(string& prefix){
        // write your code here
        TrieNode* runner = root;
        for (char& c : prefix) {
            if (runner->children.find(c) == runner->children.end()) return false;
            runner = runner->children[c];
        }
        return true;
    }
};


class TrieDefault : public ITrie
{
private:
    // TrieNode* root;
public:
    TrieDefault(){
        // constructor
        root = new TrieNode();
    }
    // inserting string in trie
    void Insert(string& word){
        // write your code here
        TrieNode* runner = root;
        for (int i = 0; i < word.size(); i++) {
            if (runner->children.find(word[i]) == runner->children.end()) {
                runner->children[word[i]] = new TrieNode();
            }
            runner = runner->children[word[i]];
        }
        runner->isWord = true;
    }

    TrieNode* getRoot() {
        return root;
    }
};

#endif // TRIE_HPP
