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

#endif // SOLUTION_HPP
