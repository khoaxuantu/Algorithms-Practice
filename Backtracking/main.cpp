#include <bits/stdc++.h>

using namespace std;

#include "Solution.hpp"
#include "Header/TreeNode.hpp"

int main(int argc, char const *argv[])
{
    /* Start and end timing */
    clock_t start, end;
    
    /* Start timing */
    start = clock();

    /* Compiler switch */
    int _switch = 1;
    
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
    

    /* Print output */
    for (int i = 0; i < WordSearchInput.size(); i++) {
        WordSearch ws(WordSearchInput[i], WSword[i]);
        cout << boolalpha << ws.solve() << endl;
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
