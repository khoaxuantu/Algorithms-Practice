#include <bits/stdc++.h>

using namespace std;

#include "../Header/TreeNode.hpp"
#include "Solution.hpp"

//* Binary Tree Path Sum
vector<vector<string>> BTPSTrees {
    {"1","2","3","4","5","6","7"},
    {"12","7","1",".","9","10","5"}
};
//* All Paths for a Sum
vector<vector<string>> APSTrees {
    {"1","2","3","4","5","6","7"},
    {"12","7","1",".","9","10","5"}
};
//* Sum of Path Numbers
vector<vector<string>> SPNTrees {
    {"1","7","9",".",".","2","9"},
    {"1","0","1",".","1","6","5"}
};
//* Path With Given Sequence
vector<vector<string>> PGSTrees {
    {"1","7","9",".",".","2","9"},
    {"1","0","1",".","1","6","5"}
};
//* Count Paths for a Sum
vector<vector<string>> CPSTrees {
    {"1","7","9","6","5","2","3"},
    {"12","7","1",".","4","10","5"}
};
//* Tree Diameter
vector<vector<string>> TDTrees {
    {"1","2","3",".","4","5","6"},
    {"1","2","3",".",".","5","6","7","8",".","9",".","10",".","11"}
};
//* Path with Maximum Sum
vector<vector<string>> PMSTrees {
    {"1","2","3",".","4","5","6"},
    {"1","2","3","1","3","5","6",".",".",".",".","7","8",".","9"}
};

int main(int argc, char const *argv[])
{
    /* Start and end timing */
    clock_t start, end;
    
    /* Start timing */
    start = clock();
    
    /* Compiler switch */
    int _switch = 1;
    
    /**
     * TODO: Modify input here
     * TODO: Print the output
     */
    
    
    /* End timing */
    end = clock();
    
    /* Print out time */
    double time_taken = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000;
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " ms " << endl;
    cout << endl;
}
