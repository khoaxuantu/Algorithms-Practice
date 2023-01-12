#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

/**
 * @brief Search Suggestions System
 * 
 * @param products An array of strings representing products
 * @param word An input word to search
 * 
 * @return :vector<vector<string>>: The suggested products, which
 * will be a list of lists after each character of searched word is typed
 */
class SearchSuggestedTrie : public ITrie
{
private:
    TrieNode* root;
public:
    SearchSuggestedTrie() {
        this->root = new TrieNode();
    }
    void Insert(string& word) {
        TrieNode* runner = root;
        for (int i = 0; i < word.size(); i++) {
            if (runner->children.find(word[i]) == runner->children.end()) {
                runner->children[word[i]] = new TrieNode();
            }
            runner = runner->children[word[i]];
            runner->searchWords.push_back(word);
            if (runner->searchWords.size() > 3) runner->searchWords.pop_back();
        }
    }
    void StoreSuggest(string& word, vector<vector<string>>& list) {
        TrieNode* runner = root;
        for (char& c : word) {
            if (runner->children.find(c) != runner->children.end()) {
                runner = runner->children[c];
                list.push_back(runner->searchWords);
            }
            else {
                list.push_back({});
            }
        }
    }
};

class SearchSuggestedSys
{
private:
    vector<string> products;
    string searchWord;
public:
    SearchSuggestedSys(vector<string>& inputPro, string& inputWord) :
        products(inputPro), searchWord(inputWord) {}
    vector<vector<string>> solve() {
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        SearchSuggestedTrie ST;
        for (string& s : products) {
            ST.Insert(s);
        }
        ST.StoreSuggest(searchWord, ans);
        return ans;
    }
};


/**
 * @brief Replace Words
 * 
 * @param sentence An input sentence
 * @param dictionary A few words from the dictionary
 * 
 * @return :string: Find all the words in the sentence so that all or some initial part
 * of each identified word matches a complete word in the dictionary. Replace each 
 * identified word in the sentence with the shortest matching word from the dictionary.
 * Return the new sentence.
 */
class ReplaceWords
{
private:
    string sentence;
    vector<string> dictionary;
public:
    ReplaceWords(string& s, vector<string>& d) : sentence(s), dictionary(d) {}
    string solve() {
        string ans;
        TrieDefault trie;
        //* Add all words in the dictionary into trie
        for (auto s : dictionary) {
            trie.Insert(s);
        }
        //* Traverse the sentence
            // The word is not in the trie
            // Otherwise, concat the char until reach the trie's word ending
        int i = 0;
        TrieNode* runner = trie.getRoot();
        while (i < sentence.size()) {
            if (sentence[i] == ' ') {
                runner = trie.getRoot();
                i++;
                ans += ' ';
                continue;
            }
            if (runner->children.find(sentence[i]) == runner->children.end()) {
                while (i < sentence.size() && sentence[i] != ' ') {
                    ans += sentence[i];
                    i++;
                }
            }
            else {
                ans += sentence[i];
                runner = runner->children[sentence[i]];
                i++;
                if (runner->isWord) {
                    while (i < sentence.size() && sentence[i] != ' ') {
                        i++;
                    }
                }
            }
        }
        return ans;
    }
};


/**
 * @brief Design Add and Search Words Data Structure
 * 
 * 
 */
class WordDictionary // n: words    c: chars of each words
{
private:
    TrieDefault trie;
    vector<string> dict;
    bool dfs(TrieNode* node, string& word, int index) {
        //* Base case
        if (index >= word.size()) return node->isWord;
        //* Call to recursive func
        if (word[index] != '.') {
            if (node->children.count(word[index]) == 0) return false; 
            return dfs(node->children[word[index]], word, index+1);
        }
        else {
            for (auto entry : node->children) {
                if (dfs(node->children[entry.first], word, index+1)) return true;
            }
        }
        return false;
    }
public:
    WordDictionary(){
        // Initialize your variables here
    }

    vector<string> GetWords(){ // O(1) || O(nlogn) if sort needed
        // write your code here
        return dict;  
    }

    void AddWord(string& word){ // O(m)
        // wrote your code here
        trie.Insert(word);
        dict.push_back(word);
    }

    bool SearchWord(string& word){ // O(26^m)
        // write your code here
        return dfs(trie.getRoot(), word, 0);
    }
};


/**
 * @brief Word Search II
 * 
 * @param words A list of strings that needed to be found
 * @param grid A 2-d grid where we can find the strings
 * 
 * @return :vector<string>: The list of strings that were found in the grid
 */
class WordSearchII
{
private:
    vector<vector<char>> grid;
    vector<string> words;
    vector<int> offset {0, -1, 0, 1, 0};
    void search(int i, int j, TrieNode* node, vector<string>& ans, string& s) {
        //* Base case
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        // grid[i][j] = '.';
        //* Call to recursive func
        for (int k = 0; k < 4; k++) {
            int r = i + offset[k];
            int c = j + offset[k+1];
            if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() &&
                node->children.find(grid[r][c]) !=  node->children.end()) {
                s += grid[r][c];
                search(r, c, node->children[grid[r][c]], ans, s);
                s = s.substr(0, s.size() - 1);
            }
        }
        if (node->isWord) {
            if (find(ans.begin(), ans.end(), s) == ans.end()) {
                ans.push_back(s);
            }
            return;
        }
    }
public:
    WordSearchII(vector<vector<char>>& grid, vector<string>& words) :
        grid(grid), words(words) {}
    vector<string> solve() {
        vector<string> ans;
        //* Insert the words into a trie
        TrieDefault trie;
        for (auto& s : words) {
            trie.Insert(s);
        }
        TrieNode* runner = trie.getRoot();
        //* Search through the grid, if a char is in the root.children, call to search word
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (runner->children.find(grid[i][j]) != runner->children.end()) {
                    string tmp;
                    tmp += grid[i][j];
                    search(i, j, runner->children[grid[i][j]], ans, tmp);
                }
            }
        }
        return ans;
    }
};


/**
 * @brief Lexicographical Order
 * 
 * @param n An integer value 
 * 
 * @return :vector<int>: A list of all numbers in the range 1 to n 
 * in lexicographical order
 */
class LexiTrie : public ITrie
{
public:
    LexiTrie() {
        root = new TrieNode();
    }
    void Insert(string& word) {
        // write your code here
        TrieNode* runner = root;
        for (int i = 0; i < word.size(); i++) {
            if (runner->lexiNumChildren.find(word[i]) == runner->lexiNumChildren.end()) {
                runner->lexiNumChildren[word[i]] = new TrieNode();
            }
            runner = runner->lexiNumChildren[word[i]];
        }
        runner->isWord = true;
    } 
    TrieNode* getRoot() {
        return root;
    }
};
class LexicographicalOrder
{
private:
    int n;
    void addToList(vector<int>& ans, TrieNode* node, int num) {
        //* Call to recursive func
        int tmpNum;
        for (auto entry : node->lexiNumChildren) {
            tmpNum = num*10 + (entry.first - '0');
            ans.push_back(tmpNum);
            addToList(ans, node->lexiNumChildren[entry.first], tmpNum);
        }
    }
public:
    LexicographicalOrder(int n) : n(n) {}
    vector<int> solve() {
        vector<int> ans;
        //* Insert 1 .. n to the trie
        LexiTrie trie;
        string num;
        for (int i = 1; i <= n; i++) {
            num = to_string(i);
            trie.Insert(num);
        }
        TrieNode* root = trie.getRoot();
        //* Traverse the trie and append to the list in every node
        addToList(ans, root, 0);
        return ans;
    }
};

#endif // SOLUTION_HPP
