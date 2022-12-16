#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    // A recursive function to find all combinations
    // num, sum, curIndex, memo
    // Base case: sum = 0, return 1
    //            curIndex is out of scope, return 0
    // Check if the problem has already processed
    // Call the func recursively for a negative sign (sum+num[curIndex])
    // Call the func recursively for a positive sign (sum-num[curIndex])
    // Return the total value
    int countComb(const vector<int>& num, int targetSum, int curIndex, vector<vector<int>>& memo)
    {
        if (curIndex == num.size() && targetSum == 0) return 1;
        if (curIndex >= num.size()) return 0;
        // Get the sumIndex for the memo first
        int memoHSize = memo[0].size();
        int sumIndex;
        if (targetSum < 0)
        {
            sumIndex = memoHSize/2 - targetSum;
        }
        else sumIndex = targetSum;

        if (memo[curIndex][sumIndex] == 0)
        {
            int ifNegVar = countComb(num, targetSum+num[curIndex], curIndex+1, memo);
            int ifPosVar = countComb(num, targetSum-num[curIndex], curIndex+1, memo);

            memo[curIndex][sumIndex] = ifNegVar + ifPosVar;
        }

        return memo[curIndex][sumIndex];
    }
      

public:
    int solve(const vector<int>& num, int sum)
    {
        // TODO: Write your code here
        // Cal the sum for all num
        int allSum = 0;
        for (auto n : num)
        {
            allSum += n;
        }
        // Cal targetSum
        int targetSum = (sum + allSum) / 2;
        // Initialize a memo
        vector<vector<int>> memo(num.size(), vector<int>(targetSum + 1, 0));

        // For the sum 0, memo is 1 for all num
        for (int i = 0; i < num.size(); i++)
        {
            memo[i][0] = 1;
        }
        // Traverse the memo, for each cap
        // In the num index 0, memo[0][num] = 1
        // Exclude the num
        // Include the num
        memo[0][num[0]] = 1;
        int valIfExcluded, valIfIncluded;
        for (int i = 1; i < num.size(); i++)
        {
            for (int j = 1; j < targetSum+1; j++)
            {
                valIfExcluded = memo[i-1][j];
                if (num[i] <= j) valIfIncluded = memo[i-1][j-num[i]];
                memo[i][j] += valIfExcluded + valIfIncluded;
            }
        }
        return memo[num.size()-1][targetSum];
    }
};

int main(int argc, char const *argv[])
{
    /* Start and end timing */
    clock_t start, end;
    
    /* Start timing */
    start = clock();
    
    Solution ts;
    vector<int> num = {1, 1, 2, 3};
    cout << ts.solve(num, 1) << endl;
    num = vector<int>{1, 2, 7, 1};
    cout << ts.solve(num, 9) << endl;
    
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
