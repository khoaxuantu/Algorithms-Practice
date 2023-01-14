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

#endif // SOLUTION_HPP
