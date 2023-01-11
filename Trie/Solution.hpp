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

#endif // SOLUTION_HPP
