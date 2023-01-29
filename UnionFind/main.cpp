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
//* Minimum Malware Spread
vector<vector<vector<int>>> MMSGraph {
    {
        {0,0,1},{1,1,0},{1,0,1}
    },
    {
        {1,1,1,0,1},{1,1,1,0,1},{1,1,1,0,1},
        {1,1,1,0,1},{1,1,1,0,1}
    }
};
vector<vector<int>> MMSNode {
    {1,2}, {2,3}
};
//* Evaluate Division
vector<vector<vector<string>>> EDEquations {
    {
        {"a","b"},{"b","c"}
    },
    {
        {"a","b"}, {"b","c"}, {"c","d"}
    },
    {
        {"a","b"}
    },
    {
        {"a","b"}, {"b","c"}, {"bc","cd"}
    }
};
vector<vector<double>> EDValues {
    {0.5,2.5},
    {0.5,2.5,1.5},
    {1.5},
    {1.5,2.5,5.0}
};
vector<vector<vector<string>>> EDQueries {
    {
        {"a","c"},{"b","c"},{"a","e"},{"x","x"}
    },
    {
        {"a","d"},{"b","d"},{"d","e"}
    },
    {
        {"a","b"},{"c","b"},{"x","x"}
    },
    {
        {"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}
    }
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
    for (int i = 0; i < EDEquations.size(); i++) {
        EvaluateDivision* ed = new EvaluateDivision(EDEquations[i], EDValues[i], EDQueries[i]);
        for (auto n : ed->solve()) {
            cout << n << " ";
        } cout << endl;
        delete ed;
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
