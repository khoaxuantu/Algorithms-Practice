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
//* Replace Words II
vector<vector<vector<char>>> WSIIChar {
    {
        {'C','O','L','I','M'},
        {'I','N','L','M','O'},
        {'A','L','I','E','O'},
        {'R','T','A','S','N'},
        {'S','I','T','A','C'}
    }
};
vector<vector<string>> WSIIStr {
    {"REINDEER", "IN", "RAIN"}
};
//* Lexicographical Order
vector<int> LOArr {12, 11, 5};

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
    for (int i = 0; i < LOArr.size(); i++) {
        LexicographicalOrder lo(LOArr[i]);
        for (auto c : lo.solve()) {
            cout << c << " ";
        } cout << endl;
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
