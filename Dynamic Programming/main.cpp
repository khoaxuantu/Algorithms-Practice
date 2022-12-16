#include <bits/stdc++.h>

using namespace std;

#include "Solution.hpp"

int main(int argc, char const *argv[])
{
    /* Start and end timing */
    clock_t start, end;
    
    /* Start timing */
    start = clock();

    /* Switch to compile */
    int _sw = 1;
    /* Input */
    LongestCommonSubstr *lcs = new LongestCommonSubstr();
    // cout << lcs->longestCommonSubsequence("abdca", "cbda") << endl;
    cout << lcs->longestCommonSubsequence("passport", "ppsspt") << endl;

    delete lcs;

    
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
