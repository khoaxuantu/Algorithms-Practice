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
    for (int i = 0; i < SSSStr.size(); i++) {
        SearchSuggestedSys SSS(SSSStr[i], SSSWord[i]);
        for (auto v : SSS.solve()) {
            cout << "[ ";
            for (auto s : v) cout << s << " ";
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
