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
//* First Unique Character in String
vector<string> FUCSStr {
    "happy anniversary", "good morning", "aowihsfdwsoidhad",
    "baefeab", 
    "aabbcc", 
    "dajhfiuebdafsdhdgaj", 
    "xyurtwxwtryua", 
    "aeiouqwertyauieotweryqq", 
    "awsjuhfajwfnkag"
};
//* Find All Anagrams in a String
vector<string> FAASa1 {
    "hello", "hello", "hello", "abab", "cbaebabacd"
};
vector<string> FAASa2 {
    "hell", "ol", "ll", "ab", "abc"
};
//* Ransome Note
vector<string> RNStr1 {
    "baad", "bad", "code", "program",
    "youareagreathuman",
    "problemsolving",
    "youhaveakindheart",
    "codinginterviewquestions"
};
vector<string> RNStr2 {
    "abcd", "abcd", "abcodf", "rpgoarm",
    "eaartygamomneltrrouean",
    "adsoptendroblemfemopvinxtbml",
    "abecdefghiavjklmaonopqhrtuvweaxyz",
    "aboincsdefoetingvqtniewonoregessnutins"
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
    for (int i = 0; i < RNStr1.size(); i++)
    {
        RansomNote rn(RNStr1[i], RNStr2[i]);
        cout << boolalpha << rn.solve() << endl;
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
