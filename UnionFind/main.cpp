#include <bits/stdc++.h>

using namespace std;

#include "Solution.hpp"

//* Redundant Connection
vector<vector<vector<int>>> RCEdges {
    {{1,2},{2,3},{1,3}},
    {{1,2},{2,3},{3,4},{1,4},{1,5}},
    {{1,2},{2,3},{2,4},{2,5},{3,5}}
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
    for (auto edges : RCEdges) {
        RedundantConnection rc(edges);
        for (auto e : rc.solve()) {
            cout << e << " ";
        }
        cout << endl;
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
