#include <bits/stdc++.h>

using namespace std;

#include "Solution.hpp"

//* Redundant Connection
vector<vector<vector<int>>> RCEdges {
    {{1,2},{2,3},{1,3}},
    {{1,2},{2,3},{3,4},{1,4},{1,5}},
    {{1,2},{2,3},{2,4},{2,5},{3,5}}
};
//* Number of Islands
vector<vector<vector<char>>> NIGrids {
    {
        {'1','1','1'},
        {'0','1','0'},
        {'1','0','0'},
        {'1','0','1'}
    },
    {
        {'0','1','0'},
        {'1','0','1'},
        {'0','1','0'}
    },
    {
        {'1','0','0','0'},
        {'0','1','0','0'},
        {'0','0','1','0'},
        {'0','0','0','1'}
    }
};
//* Last Day Where You Can Still Cross
vector<vector<vector<int>>> LDWYCSCCells {
    {
        {1,2},{2,1},{3,3},{2,2},{1,1},{1,3},{2,3},{3,2},{3,1}
    },
    {
        {2,1},{3,3},{1,1},{1,3},{3,4},{3,1},{1,2},{3,2},{2,2},{1,4},{2,3},{2,4}
    },
    {
        {3,2},{1,3},{2,2},{3,1},{1,1},{1,2},{2,3},{3,3},{2,1}
    },
    {
        {1,2},{1,4},{2,1},{1,1},{2,4},{1,3},{2,3},{2,2}
    },
    {
        {2,3},{1,1},{2,1},{4,3},{3,3},{4,1},{4,2},{1,3},{3,2},{1,2},{2,2},{3,1}
    }
};
vector<pair<int,int>> LDWYCSCSize {
    {3,3},{3,4},{3,3},{2,4},{4,3}
};
//* Regions Cut by Slashes
vector<vector<string>> RCSStr {
    {"/\\", "\\/"}, {" /", "  "},
    {" //", " \\/", "//\\"},
    {"/ /\\", "//\\/", "  /\\", "\\\\/\\"}
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
    for (auto s : RCSStr) {
        RegionsBySlashes rbs(s);
        cout << rbs.solve() << endl;
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
