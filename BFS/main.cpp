#include <bits/stdc++.h>

using namespace std;

#include "../Header/TreeNode.hpp"
#include "Solution.hpp"

//* Binary Tree Level Order Traversal
vector<vector<string>> NTLOTTrees {
    {"1","2","3","4","5","6","7"},
    {"12","7","1",".","9","10","5"}
};
//* Zigzag Traversal
vector<vector<string>> ZTTrees {
    {"1","2","3","4","5","6","7"},
    {"12","7","1",".","9","10","5",".",".","20","17"}
};
//* Level Averages in a Binary Tree
vector<vector<int>> LABTTrees {
    {1,2,3,4,5,6,7},
    {12,7,1,9,2,10,5}
};
//* Minimum Depth of a Binary Tree
vector<vector<string>> MDBTTrees {
    {"1","2","3","4","5"},
    {"12","7","1",".",".","10","5"},
    {"12","7","1",".","9","10","5",".",".","11"}
};
//* Level Order Successor
vector<vector<string>> LOSTrees {
    {"1","2","3","4","5"},
    {"12","7","1",".",".","10","5"},
    {"12","7","1",".",".","10","5"}
};
vector<int> LOSKeys {3,9,12};
//* Connect Level Order Siblings
vector<vector<string>> CLOSTrees {
    {"1","2","3","4","5","6","7"},
    {"12","7","1",".","9","10","5"}
};
//* Connect All Level Order Siblings
vector<vector<string>> CALOSTrees {
    {"1","2","3","4","5","6","7"},
    {"12","7","1",".","9","10","5"}
};
//* Right View of a Binary Tree
vector<vector<string>> RVBTTrees {
    {"1","2","3","4","5","6","7"},
    {"12","7","1",".","9","10","5","3"}
};

int main(int argc, char *argv[]) {
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