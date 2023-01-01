#include <bits/stdc++.h>

using namespace std;

#include "Solution.hpp"

//* Pair with Target Sum
vector<vector<int>> PWTSArr {
    {1, 2, 3, 4, 6},
    {2, 5, 9, 11}
};
vector<int> PWTTarget {6, 11};
//* Remove Duplicates
vector<vector<int>> RDArr {
    {2, 3, 3, 3, 6, 9, 9},
    {2,2,2,11}
};
//* Squaring a Sorted Array
vector<vector<int>> SSAArr {
    {-2, -1, 0, 2, 3},
    {-3, -1, 0, 1, 2}
};
//* Triplet Sum to Zero
vector<vector<int>> TSTZARR {
    {-3, 0, 1, 2, -1, 1, -2},
    {-5, 2, -1, -2, 3}
};
//* Triplet Sum Close to Target
vector<vector<int>> TSCTArr {
    {-2, 0, 1, 2},
    {-3, -1, 1, 2},
    {1, 0, 1, 1}
};
vector<int> TSCTTargetSum {2,1,100};
//* Triplet with Smaller Sum
vector<vector<int>> TSSArr {
    {-1, 0, 2, 3},
    {-1, 4, 2, 1, 3}
};
vector<int> TSSTargetSum {3,5};
//* Subarrays with Product Less than a Target
vector<vector<int>> SPLTArr {
    {2, 5, 3, 40, 10},
    {8, 2, 6, 5}
};
vector<int> SPLTTarget {30,50};
//* Dutch National Flag Problem
vector<vector<int>> DNFArr {
    {1, 0, 2, 1, 0},
    {2, 2, 0, 1, 2, 0}
};
//* Quadruple Sum to Target
vector<vector<int>> QSTArr {
    {4, 1, 2, -1, 1, -3},
    {2, 0, -1, 1, -2, 2}
};
vector<int> QSTTarget {1,2};
//* Comparing Strings containing Backspaces
vector<string> CSBStr1 {
    "xy#z", "xy#z", "xp#", "xywrrmp"
};
vector<string> CBStr2 {
    "xzz#", "xyz#", "xyz##", "xywrrmu#p"
};
//* Minimum Window Sort
vector<vector<int>> MWSArr {
    {1, 2, 5, 3, 7, 10, 9, 12},
    {1, 3, 2, 0, -1, 7, 10},
    {1, 2, 3},
    {3,2,1}
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
    return 0;
}

