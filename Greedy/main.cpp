// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <iomanip>
#include <bits/stdc++.h>

using namespace std;

#include "Solution.hpp"

int main(int argc, char const *argv[])
{
    /* Start and end timing */
    clock_t start, end;
    
    /* Start timing */
    start = clock();
    
    /* Compiler switch */
    int _switch = 0;

    vector<vector<PAIR>> A = {{make_pair(10, 20), make_pair(30, 200), make_pair(400, 50), make_pair(30, 20)},
                              {make_pair(259, 770), make_pair(448, 54), make_pair(926, 667), make_pair(184, 139), make_pair(840, 118), make_pair(577, 469)},
                              {make_pair(515, 563), make_pair(451, 713), make_pair(537, 709), make_pair(343, 819), make_pair(855, 779), make_pair(457, 60), make_pair(650, 359), make_pair(631, 42)},
                              {make_pair(1, 2), make_pair(3, 4), make_pair(5, 6), make_pair(7, 8)},
                              {make_pair(1, 2), make_pair(1, 2), make_pair(1, 2), make_pair(1, 2)}};
    vector<vector<int>> jumps {
        {2,1,1,1,4}, {2,2,1,1,4},
        {2,3,1,1,9}, {3,2,1,1,4},
        {4,0,0,0,4}, {1,1}, {1}
    };
    Solution* solution = new Solution();
    for (int i = 0; i < jumps.size(); i++) {
        cout << solution->JumpGameTwo(jumps[i]) << endl;
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
