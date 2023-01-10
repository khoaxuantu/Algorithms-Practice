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
            sort(runner->searchWords.begin(), runner->searchWords.end());
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
        SearchSuggestedTrie ST;
        for (string& s : products) {
            ST.Insert(s);
        }
        ST.StoreSuggest(searchWord, ans);
        return ans;
    }
};

#endif // SOLUTION_HPP
