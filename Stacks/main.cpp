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
    for (auto s : BCStr) {
        BasicCalculator bc(s);
        cout << bc.solve() << endl;
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
