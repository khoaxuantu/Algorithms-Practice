#include <bits/stdc++.h>

using namespace std;

#include "../Header/TreeNode.hpp"
#include "Solution.hpp"

/* Input */
// * N-Queens
vector<int> NQueenInput {1,2,3,4,5,6,7,8,9};
// * Word Search
vector<vector<vector<char>>> WordSearchInput {
    {{'E', 'D', 'X', 'I', 'W'},
     {'P', 'U', 'F', 'M', 'Q'},
     {'I', 'C', 'Q', 'R', 'F'},
     {'M', 'A', 'L', 'C', 'A'},
     {'J', 'T', 'I', 'V', 'E'}},

    {{'E', 'D', 'X', 'I', 'W'},
     {'P', 'U', 'F', 'M', 'Q'},
     {'I', 'C', 'Q', 'R', 'F'},
     {'M', 'A', 'L', 'C', 'A'},
     {'J', 'T', 'I', 'V', 'E'}},

    {{'H', 'E', 'C', 'M', 'L'},
     {'W', 'L', 'I', 'E', 'U'},
     {'A', 'R', 'R', 'S', 'N'},
     {'S', 'I', 'I', 'O', 'R'}},

    {{'C', 'Q', 'N', 'A'},
     {'P', 'S', 'E', 'I'},
     {'Z', 'A', 'P', 'E'},
     {'J', 'V', 'T', 'K'}},

    {{'O', 'Y', 'O', 'I'},
     {'B', 'I', 'E', 'M'},
     {'K', 'D', 'Y', 'R'},
     {'M', 'T', 'W', 'I'},
     {'Z', 'I', 'T', 'O'}}
};
vector<string> WSword {"EDUCATIVE", "", "WARRIOR", "SAVE", "DYNAMIC"};
// * House Robber III
vector<vector<int>> HRhouses {
    {3,5,25,10,12,3,1},
    {9,7,11,1,8,10,12},
    {5,3,8,2,4,6,10,1},
    {3}
};
//* Restore IP Addresses
vector<string> ripaS {
    "255255255255", "00000000", "010010",
    "201023", "12121212"
};
//* Sudoku Solver
vector<vector<char>> SSBoard {
    {'.','.','.','.','.','.','.','7','.'},
    {'2','7','5','.','.','.','3','1','4'},
    {'.','.','.','.','2','7','.','5','.'},
    {'9','8','.','.','.','.','.','3','1'},
    {'.','3','1','8','.','4','.','.','.'},
    {'.','.','.','1','.','.','8','.','5'},
    {'7','.','6','2','.','.','1','8','.'},
    {'.','9','.','7','.','.','.','.','.'},
    {'4','1','.','.','.','5','.','.','7'}
};


/**
 * @brief List of the classes corresponding to the problems:
 *      @param NQueenI N-Queens problem
 *      @param WordSearch Word search problem
 *      @param HouseRobberIII House robber problem - 3rd edition
*/
int main(int argc, char const *argv[])
{
    /* Start and end timing */
    clock_t start, end;
    
    /* Start timing */
    start = clock();

    /* Compiler switch */
    int _switch = 0;    

    /**
     * TODO: Modify input here 
     * TODO: Print the output
     */
    SudokuSolver SS(SSBoard);
    vector<vector<char>> result = SS.solve();
    for (auto row : result) {
        for (char& c : row) cout << c << " ";
        cout << endl;
    }
    
    /* End timing */
    end = clock();
    
    /* Print out time */
    double time_taken = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000;
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " ms " << endl;
    cout << endl;
    return 0;
}
