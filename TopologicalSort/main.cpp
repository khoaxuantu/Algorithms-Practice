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
    int _switch = 0;
    
    /* Input */
    vector<vector<int>> vec = {{0, 1}, {1, 2}, {1, 3}, {2, 4}};
    vector<int> result = Solution::findTrees(5, vec);
    cout << "Roots of MHTs: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    vec = {{0, 1}, {0, 2}, {2, 3}};
    result = Solution::findTrees(4, vec);
    cout << "Roots of MHTs: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    vec = {{0, 1}, {1, 2}, {1, 3}};
    result = Solution::findTrees(4, vec);
    cout << "Roots of MHTs: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;
    
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