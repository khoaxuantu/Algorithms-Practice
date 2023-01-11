#include <bits/stdc++.h>

using namespace std;

#include "../Header/Trie.hpp"
#include "Solution.hpp"

//* Search Suggestions System
vector<vector<string>> SSSStr {
    {"razer", "blade", "knife", "cutter", "games"},
    {"bags", "baggage", "banner", "box", "clothes"}   
};
vector<string> SSSWord {
    "game", "bags"
};
//* Replace Words
vector<string> RWStr {
    "the quick brown fox jumps over the lazy dog",
    "lets learn something new today",
    "for every action there is an equal but opposite reaction"
};
vector<vector<string>> RWDict {
    {"qui", "brow", "bro", "jum", "j", "la", "d", "do"},
    {"le", "some", "yes", "let"},
    {"ev", "eq", "th", "act", "e", "opp", "xy", "is"}
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
    for (int i = 0; i < RWStr.size(); i++) {
        ReplaceWords rw(RWStr[i], RWDict[i]);
        cout << rw.solve() << endl;
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
