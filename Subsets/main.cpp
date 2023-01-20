#include <bits/stdc++.h>

#include "../Header/TreeNode.hpp"
#include "Solution.hpp"

using namespace std;

//* Subsets
vector<vector<int>> SSArr {
    {1,3}, {1,5,3}
};
//* Subsets With Duplicates
vector<vector<int>> SWDArr {
    {1,3,3}, {1,5,3,3}
};
//* Permutations
vector<vector<int>> PArr {
    {1,2,3}, {1,3,5}
};
//* String Permutations by Changing Case 
vector<string> SPCCStrs {
    "ad52", "ab7c"
};
//* Balanced Parentheses
vector<int> BPNums {1,2,3};
//* Unique Generalized Abbreviations
vector<string> UGAStr {
    "BAT","code"
};
//* Evaluate Expression
vector<string> EEStr {
    "1+2*3", "2*3-4-5"
};
//* Structurally Unique Binary Search Trees
vector<int> SUBSTNums {2,3};

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
