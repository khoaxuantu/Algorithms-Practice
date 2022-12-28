#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

/** 
 * @brief N-Queens Problem
 * 
 * @param n represent nxn chess. It is also the required number of queens
 * 
 * @return :int: Number of ways
 */
class NQueenI
{
private:
    int n;
    int ans = 0;
    unordered_map<int, int> xSet;
    unordered_set<int> ySet;
    unordered_set<int> diagonal;
    bool checkCollided(int y, int x, int n) {
        if (xSet.find(x) != xSet.end() || ySet.find(y) != ySet.end()) return true;
        if (diagonal.find(x - y) != diagonal.end()) return true;
        // Check the top-right diagonal
        int tmpX = x + 1, tmpY = y - 1;
        while (tmpY >= 0 && tmpX < n) {
            if (xSet.find(tmpX) != xSet.end() && xSet[tmpX] == tmpY) return true;
            tmpX++;
            tmpY--;
        }
        
        return false;
    }
    void PlaceNQueens(int n, int y, int x) {
        //* Base case: y >= n
        if (y >= n) return;
        // If y == n-1, increment ans
        if (y == n - 1) {
            ans++;
            return;
        }
        // Insert x, y into xSet and ySet
        xSet[x] = y;
        ySet.insert(y);
        diagonal.insert(x-y);
        //* Check collision in every next index
        //* If not collided, call to recursive func 
        for (int i = 0; i < n; i++) {
            if (i == x) continue;
            if (!checkCollided(y+1, i, n)) {
                PlaceNQueens(n, y+1, i);
            }
        } 
        // cout << endl;
        xSet.erase(x);
        ySet.erase(y);
        diagonal.erase(x-y);
    }
public:
    NQueenI (int n) {
        this->n = n;
    }
    int solve() {
        if (n == 1) return 1;
        if (n == 2) return 0;
        // Traverse the 1st row, call to PlaceNQueens
        for (int x = 0; x < n; x++) {
            PlaceNQueens(n, 0, x);
        }

        return ans;
    }
};


/**
 * @brief Word Search Problem
 * 
 * @param word target word
 * @param grid 2-dimensional grid, target word will searched in this grid
 * 
 * @return true or false
*/
class WordSearch
{
private:
    
    int m, n;
    vector<vector<char>> grid;
    string word;
    bool dfs(vector<vector<int>>& visited, vector<vector<char>>& grid, 
             string& word, int wordIndex, int row, int col) {
        //* Base case
        // index is out of grid's scope
        // If we reach the last char of the word, return true
        // If the cell is marked or wordChar != cell, return false
        if (row < 0 || row >= m || col < 0 || col >= n) return false;
        if (wordIndex == word.size()-1 && grid[row][col] == word[wordIndex]) return true;
        if (visited[row][col] == 1 || word[wordIndex] != grid[row][col]) return false;
        // Mark the cell as visited
        visited[row][col] = 1;
        //* Call to recursive function in 4 grid's directions
        bool left, right, up, down;
        left = dfs(visited, grid, word, wordIndex+1, row, col-1);
        right = dfs(visited, grid, word, wordIndex+1, row, col+1);
        down = dfs(visited, grid, word, wordIndex+1, row+1, col);
        up = dfs(visited, grid, word, wordIndex+1, row-1, col);

        // Unmark the cell
        visited[row][col] = 0;
        return left || right || down || up;
    }
public:
    WordSearch (vector<vector<char>>& grid, string& word) {
        this->grid = grid;
        this->word = word;
    }
    bool solve() {
        bool ans;
        if (word.size() == 0) return false;
        m = grid.size(), n = grid[0].size();
        // Init a memo table to store visited cells
        vector<vector<int>> visited (m, vector<int> (n, 0));
        // Call to dfs starting from the first cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == word[0]) {
                    ans = dfs(visited, grid, word, 0, i, j);
                    if (ans) return ans;
                }
            }
        }
        return false;
    }
};


/** 
 * @brief House Robber Problem
 * 
 * @param root The root of the tree. The houses list is 
 * reorganized to a binary tree, and this problem take the 
 * tree as an input
 * 
 * @return The maximum profit that we can rob
*/
class HouseRobberIII
{
private:
    TreeNode* root;
    pair<int, int> dfs(TreeNode* node) {
        //* Base case
        if (!node) return {0,0};
        //* Call to recursive func
        // Cal the sum of the children nodes
        // Cal the sum of node and its grandchildren
        auto childLeft = dfs(node->left);
        auto childRight = dfs(node->right);

        int childSum = childLeft.first + childRight.first;
        int sumWithGrandchild = node->val + childLeft.second + childRight.second;
        int returnVal = max(childSum, sumWithGrandchild);

        return {returnVal, childSum};
    }
public:
    HouseRobberIII(TreeNode* tree) : root(tree) {}
    int solve() {
        //* DFS
        auto ans = dfs(root);
        return max(ans.first, ans.second);
    }
};


/**
 * @brief Restore IP Adresses
 * 
 * @param s input ip string
 * 
 * @return ip adresses
 */
class RestoreIPAdresses
{
private:
    string s;
    bool valid(string& segment) {
        if (segment.size() > 3) return false;
        if (segment[0] != '0') {
            return stoi(segment) <= 255;
        }
        else {
            return segment.size() == 1;
        }
        // return segment[0] != '0' ? stoi(segment) <= 255 : segment.size() == 1;
        return false;
    }
    void pushToAns(int curPos, vector<string>& segments, vector<string>& ans) {
        string finalSegment = s.substr(curPos + 1, s.size() - curPos - 1);
        if (valid(finalSegment)) {
            string ip;
            for (string& segment : segments) {
                ip += segment + '.';
            }
            ip += finalSegment;
            ans.push_back(ip);
        }
    }
    void checkAdresses(string& s, int prevPos, int dots, 
                       vector<string>& segments, vector<string>& ans) 
    {
        int size = s.size();
        int maxPos = min(size - 1, prevPos + 4);
        //* PrevPos => check the next 3 digits
        //* Get the segment, 
            // if the segment is valid
                // Push to segments
                // If all dots are placed, push to ans
                // Else move to the next segments
                // Backtrack
        for (int curPos = prevPos+1; curPos < maxPos; curPos++)
        {
            string segment = s.substr(prevPos+1, curPos - prevPos);
            if (valid(segment)) {
                segments.push_back(segment);
                if (dots - 1 == 0) {
                    pushToAns(curPos, segments, ans);
                }
                else {
                    checkAdresses(s, curPos, dots - 1, segments, ans);
                }
                segments.pop_back();
            }
        }
    }
public:
    RestoreIPAdresses(string input) : s(input) {}
    vector<string> solve() {
        vector<string> ans;
        vector<string> segments;
        //* Call to recursive func
        checkAdresses(s, -1, 3, segments, ans);
        return ans;
    }
    static void printAns(vector<string>& ans) {
        for (auto ip : ans) {
            cout << ip << " ";
        }
        cout << endl;
    }
};


/**
 * @brief Sudoku Solver
 * 
 * @param board A 9x9 sudoku board
 * 
 * @return :vector<vector<char>>: A complete board
 */
class SudokuSolver
{
private:
    vector<vector<char>> board;
    unordered_map<int, unordered_set<char>> row;
    unordered_map<int, unordered_set<char>> col;
    unordered_map<string, unordered_set<char>> box;
    bool validateRow(char num, int r) {
        return row[r].find(num) == row[r].end();
    }
    bool validateCol(char num, int c) {
        return col[c].find(num) == col[c].end();
    }
    bool validateBox(char num, string b) {
        return box[b].find(num) == box[b].end();
    }
    bool tryNum(vector<vector<char>>& board, int i, int j) {
        //* Base case
            // If board[i][j] is invalid
        if (i > 8 || j > 8) return false;
        string b = to_string(i/3) + to_string(j/3);
        if (!validateBox(board[i][j], b) || !validateCol(board[i][j], j) || 
            !validateRow(board[i][j], i)) return false;
        int curI = i, curJ = j;
        //* For each cell, try 1->9 recursively
            // Validate and add the number to row, col, box
        //* If reach the last cell, return board
        //* Otherwise move to the next cell
        //* Backtrack if the solution is not reached
        for (int n = 1; n <= 9; n++) {
            if (validateBox(n+'0', b) && validateCol(n+'0', curJ) && validateRow(n+'0', curI)) {
                board[curI][curJ] = n + '0';
                row[curI].insert(board[curI][curJ]);
                col[curJ].insert(board[curI][curJ]);
                box[b].insert(board[curI][curJ]);
                while (i < 9 && board[i][j] != '.') {
                    j++;
                    if (j > 8) {
                        i++;
                    }
                    j %= 9;
                }
                if (i >= 9) return true;
                if (tryNum(board, i, j)) return true;
                row[curI].erase(board[curI][curJ]);
                col[curJ].erase(board[curI][curJ]);
                box[b].erase(board[curI][curJ]);
            }
        }
        board[curI][curJ] = '.';
        return false;
    }
public:
    SudokuSolver(vector<vector<char>>& board) : board(board) {}
    vector<vector<char>> solve() {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    string b = to_string(i/3) + to_string(j/3);
                    box[b].insert(board[i][j]);
                    row[i].insert(board[i][j]);
                    col[j].insert(board[i][j]);
                }
            }
        }
        //* Iterate every cell in the board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    if (tryNum(board, i, j)) return board;
                }
            }
        }
        return board;
    }
};

#endif // SOLUTION_HPP
