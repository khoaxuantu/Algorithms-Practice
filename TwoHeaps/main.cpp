#include <bits/stdc++.h>

#include "../Header/Interval.hpp"
#include "Solution.hpp"

// Macro
#define pairInt pair<int, int>
#define pairIvInt pair<Interval, int>

using namespace std;

//* Sliding Window Median
vector<vector<int>> SWMTrees {
    {1,2,-1,3,5},
    {1,2,-1,3,5}
};
vector<int> SWMk {2,3};
//* Maximize Capital
vector<vector<int>> MCCapitals {
    {0,1,2}, {0,1,2,3}
};
vector<vector<int>> MCProjects {
    {1,2,3}, {1,2,3,5}
};
vector<int> MCNoProjects {2,3};
vector<int> MCInitCapital {1,0};
//* Next Interval
vector<vector<Interval>> NIIntervals {
    {{2,3},{3,4},{5,6}},
    {{3,4},{1,5},{4,6}}
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
