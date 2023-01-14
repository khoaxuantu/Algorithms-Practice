#include <bits/stdc++.h>

using namespace std;

#include "Solution.hpp"

//* Palindrome Permutation
vector<string> PPStr {
    "aba", "acb", "abb", "axbk"
};
//* Group Anagrams
vector<vector<string>> GAStrs {
    {"duel", "dule", "speed", "spede", "deul", "cars"}
};

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
    for (auto s : GAStrs) {
        GroupAnagrams ga(s);
        for (auto arr : ga.solve()) {
            cout << "[ ";
            for (auto w : arr) {
                cout << w << " ";
            }
            cout << "] ";
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
