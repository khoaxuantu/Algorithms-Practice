#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

/**
 * @brief Palindrome Permutation
 * 
 * @param str An input string
 * 
 * @return :boolean: whether or not a permutation of the string
 */
class PalindromePermutation
{
private:
    string str;
public:
    PalindromePermutation(string& str) : str(str) {}
    bool solve() {
        //* Record the freq of chars
        unordered_map<char, int> freq;
        for (char& c : str) {
            freq[c]++;
        }
        //* Validate the freq
            // If more than 2 chars are odd
        int odds = 1;
        for (auto entry : freq) {
            if (entry.second % 2 != 0) odds--;
            if (odds < 0) return false;
        }
        return true;
    }
};


/**
 * @brief Design Tic-tac-toe 
 * 
 * @param rows The row vectors of the nxn board. If rows[i] = n, 
 * the player will win
 * @param cols The col vectors of the nxn board. If cols[i] = n, 
 * the player will win 
 * @param diagonal The record number of cells in diagonal order which
 * the player has marked. If the diagonal = n, the player will win
 * @param antiDiagonal The record number of cells in anti diagonal order
 * which the player has marked/ If the anti diagonal = n, the player will
 * win
 */
class TicTacToe
{
public:
    //* TicTacToe class contains rows, cols, diagonal,
    //* and antiDiagonal to create a board.
    vector<int> rows;
    vector<int> cols;
    int diagonal;
    int antiDiagonal;
    int n;

    //* Constructor is used to create n * n tic - tac - toe board.
    TicTacToe(int n) {
        rows.assign(n, 0);
        cols.assign(n, 0);
        diagonal = 0;
        antiDiagonal = 0;
        this->n = n;
    }

    //* Move function will allow the players to play the game
    //* for given row and col.
    int Move(int row, int col, int player){
        //TODO: write your code here
        int currentPlayer = (player == 1) ? 1 : -1;
        //* Update rows and cols
        rows[row] += currentPlayer;
        cols[col] += currentPlayer;
        //* Update diagonal and antidiagonal
        if (row == col) {
            diagonal += currentPlayer;
        }
        else if (row == n - col - 1) {
            antiDiagonal += currentPlayer;
        }
        //* Check if there is a player winning
        if (abs(rows[row]) == n || abs(cols[col]) == n || abs(diagonal) == n || abs(antiDiagonal) == n) {
            return player;
        }
        return 0;
    }
};


/**
 * @brief Group Anagrams
 * 
 * @param strs A list of words or phrases
 * 
 * @return :vector<vector<string>>: group the words that are anagrams of each other.
 * An anagram is a word or a phrase formed from another word by rearranging them
 */
class GroupAnagrams
{
private:
    vector<string> strs;
    string encodeStr(string& s) {
        string tmp;
        for (int i = 0; i < 26; i++) tmp += '0';
        for (char& c : s) {
            int index = c - 'a';
            tmp[index]++;
        }
        return tmp;
    }
public:
    GroupAnagrams(vector<string>& input) : strs(input) {}
    vector<vector<string>> solve() {
        unordered_map<string, vector<string>> anagrams;
        //* Count the freq of each word
        string key;
        for (auto& s : strs) {
            key = encodeStr(s);
            //* Push to the map
            anagrams[key].push_back(s);
        }
        //* Get the ans
        vector<vector<string>> words;
        for (auto entry : anagrams) {
            words.push_back(entry.second);
        }
        return words;
    }
};


/**
 * @brief Maximum Frequency Stack
 * 
 * @details Design a stack-like data structure. You should able to push
 * elements to this data structure and pop elements with maximum frequency
 * 
 * @param freq Map the frequency of each element
 * @param st A hash table which store the freq keys map to the data
 * @param maxFreq Keep track the maximum frequency
 */
class FreqStack
{
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> st;
    int maxFreq = 0;
public:
    // Use constructor to initialize the maxFrequency
    FreqStack() {}

    // Use push function to push the data into the FreqStack
    void push(int data) {
        // TODO: Write your code here
        freq[data]++;
        st[freq[data]].push(data);
        maxFreq = max(maxFreq, freq[data]);
    }
    
    // Use the pop function to pop the data from the FreqStack
    int pop() {
        // TODO: Write your code here
        int tmp = st[maxFreq].top();
        st[maxFreq].pop();
        freq[tmp]--;
        if (st[maxFreq].empty()) maxFreq--;
        return tmp;
    }
};


/**
 * @brief First Unique Character in a String
 * 
 * @param s An input string of lowercase characters
 * 
 * @return :int: The first non-repeating character's index in the s.
 * Return -1 if there is no unique character 
 */
class FirstUniqueChar
{
private:
    string s;
public:
    FirstUniqueChar(string& s) : s(s) {}
    int solve() {
        unordered_map<char, int> freq;
        for (char& c : s) {
            if (c != ' ') freq[c]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i]] == 1) return i;
        }
        return -1;
    }
};


/**
 * @brief Find All Anagrams in a String
 * 
 * @param a The first input string
 * @param b The second input string
 * 
 * @return :vector<int>: An array of all start indices of b's anagrams in a.
 * We may return the answer in any order. An anagram is a word or phrase created
 * by arranging the letters of another word or phrase while utilizing each of 
 * the original letters exactly once. 
 */
class FindAllAnagrams
{
private:
    string a;
    string b;
public:
    FindAllAnagrams(string& a, string & b) : a(a), b(b) {}
    vector<int> solve() {
        //* Store the freq of b's chars
        vector<int> ans;
        if (b.size() == 0) return ans;
        unordered_map<char, int> freq;
        for (char& c : b) {
            freq[c]++;
        }        
        //* Sliding Window in a
        int start = 0, end = 0;
        int count = 0;
        while (end < a.size()) {
            if (freq.count(a[end]) > 0) {
                if (freq[a[end]] > 0) count++;
                freq[a[end]]--;
            }
            end++;
            if (count == b.size()) ans.push_back(start);
            if (end - start + 1 > b.size()) {
                if (freq.count(a[start]) > 0) {
                    if (freq[a[start]] >= 0) count--;
                    freq[a[start]]++;
                }
                start++;
            }
        }
        return ans;
    }
};


/**
 * @brief Ransom note 
 * 
 * @param ransomNote the "ransom note" input string
 * @param magazine the "magazine" input string
 * 
 * @return :boolean: check if the ransom note can be constructed using
 * the letters from the magazine string
 */
class RansomNote
{
private:
    string ransomNote;
    string magazine;
public:
    RansomNote(string& a, string& b) : ransomNote(a), magazine(b) {}
    bool solve() {
        //* chars in ransome note must have in magazine's
        //* chars freq is the same
        unordered_map<char, int> rnMap;
        unordered_map<char, int> mgMap;
        for (char& c : ransomNote) rnMap[c]++;
        for (char& c : magazine) mgMap[c]++;

        for (auto& entry : rnMap) {
            if (mgMap.count(entry.first) == 0) return false;
            else if (mgMap[entry.first] < entry.second) return false;
        }
        return true;
    }
};

#endif // SOLUTION_HPP
