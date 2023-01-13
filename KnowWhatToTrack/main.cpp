#include <bits/stdc++.h>

using namespace std;

#include "Solution.hpp"

//* Palindrome Permutation
vector<string> PPStr {
    "aba", "acb", "abb", "axbk"
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
    for (auto s : PPStr) {
        PalindromePermutation pp(s);
        cout << boolalpha << pp.solve() << endl;
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
