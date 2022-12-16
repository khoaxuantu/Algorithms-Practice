#include <bits/stdc++.h>

#include "../Header/TreeNode.hpp"

using namespace std;

class AbbreviatedWord {
public:
    string str;
    int start = 0;
    int count = 0;

    AbbreviatedWord(string str, int start, int count) {
        this->str = str;
        this->start = start;
        this->count = count;
    }
};


class Solution {
private:


public:
    unordered_map<int, int> mp;
    int solve(const int& n)
    {
        int result = 0;
        // TODO: Write your code here
        // Check if the input is in the hash map
        if (mp.find(n) != mp.end())
        {
            return mp[n];
        }
        // Base case: If the num reaches its limit, return 1
        if (n <= 1) return 1;
        // Traverse every num in range input
        // For each num as root
            // Call the subtrees recursively
        for (int i = 1; i <= n; i++)
        {
            int leftCount = solve(i-1);
            int rightCount = solve(n - i);

            result += leftCount * rightCount;
        }
        
        // Update the hash map
        mp[n] = result;
        return result;
    }
};


int main(int argc, char const *argv[])
{
    /* Start and end timing */
    clock_t start, end;
    
    /* Start timing */
    start = clock();
    
    vector<int> input {
        2, 3, 19
    };

    int result;
    for (auto arr : input)
    {
        Solution solution;
        result = solution.solve(arr);
        cout << "Total trees: " << endl;
        // for (auto vec : result) {
        //     // cout << "{";
        //     // for (auto num : vec) {
        //     // cout << num;
        //     // }
        //     // cout << "} ";
        //     cout << vec << " ";
        // }
        cout << result;
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
}
