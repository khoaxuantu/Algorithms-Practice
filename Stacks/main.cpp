#include <bits/stdc++.h>

using namespace std;

#include "Solution.hpp"

//* Basic Calculator
vector<string> BCStr {
    "12 - (6 + 2) + 5",
    "(8 + 100) + (13 - 8 - (2 + 1))",
    "40 - 25 - 5",
    "(27 + (7 + 5) - 3) + (6 + 10)"
};
//* Remove All Adjacent Duplicates in String
vector<string> RAADSStr {
    "g",
    "aaa",
    "abbaaca",
    "sadkkdassa",
    "xyyxxzx",
    "sadyydassa"
};
//* Minimum Remove to Make Valid Parentheses
vector<string> MRMVPStr {
    "m)no(q)rs(",
    ")((yz)())(",
    "ab)cca(spo)(sc(s)("
};
//* Exclusive Execution Time of Functions
vector<vector<string>> EETFStr {
    {"0:start:0","1:start:5", "1:end:9","4:start:10","2:start:13", "2:end:15", "3:start:16", "3:end:18", "4:end:21", "0:end:22"},
    {"0:start:0","1:start:2","1:end:3","2:start:4","2:end:7","0:end:8"},
    {"0:start:0","0:start:2","0:end:5","1:start:5","1:end:6","0:end:7"},
    {"0:start:0","1:start:6","1:end:6","0:end:7"},  
    {"0:start:0","1:start:3","1:end:6","0:end:10"}
};
vector<int> EETFN {5,3,2,2,2};

int main(int argc, char const *argv[])
{
    /* Start and end timing */
    clock_t start, end;
    
    /* Start timing */
    start = clock();
    
    /* Compiler switch */
    int _switch = 0;
    
    /**
     * TODO: Modify input here
     * TODO: Print the output
     */
    for (int i = 0; i < EETFN.size(); i++) {
        ExclusiveTime ET(EETFN[i], EETFStr[i]);
        for (auto n : ET.solve()) {
            cout << n << " ";
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
