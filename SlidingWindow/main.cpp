#include <bits/stdc++.h>

using namespace std;

#include "Solution.hpp"

/* Inputs */
//* Maximum sum subarray of size K
vector<int> mssK {3,2};
vector<vector<int>> mssArr {
    {2, 1, 5, 1, 3, 2},
    {2, 3, 4, 1, 5}
};
//* Smalles subarray with a greater sum
vector<int> sswS {7,8,9};
vector<vector<int>> sswArr {
    {2,1,5,2,3,2},
    {3,4,1,1,6},
    {2,1,5,2,3,2}
};
//* Longest Substring with maximum K Distinct Characters
vector<string> LSWMKStr {
    "araaci", "araaci",
    "cbbebi", "cbbebi"
};
vector<int> LSWMKk {2,1,3,10};
//* Fruits into 2 Baskets
vector<vector<char>> fibChar {
    {'A', 'B', 'C', 'A', 'C'},
    {'A', 'B', 'C', 'B', 'B', 'C'}
};
//* Longest Substring with Distinct Characters
vector<string> lswdcStr {
    "acbcdaa", "abbbb", "abccde"
};
//* Longest Substring with Same Letters after Replacement
vector<string> lswslStr {
    "aabccbb", "abbcb", "abccde"
};
vector<int> lswslK {2,1,1};
//* Longest Subarray with Ones after Replacement
vector<vector<int>> lswoaArr {
    {0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1},
    {0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}
};
vector<int> lswoaK {2,3};

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
