#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

#include "../Header/TerminalPrint.hpp"

/**
 * @brief 0/1 Knapsack Pattern
 * 
 */
class Knapsack01
{
private:
public:

};


/**
 * @brief Unbound Knapsack Pattern 
 * 
 */
class UnboundKnapsack
{
private:
    int recursiveKnap(const vector<int> &profits, const vector<int> &weights, 
                      int capacity, int curIndex, vector<vector<int>>& memo);
public:
    int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity);
    int solveRodCutting(const vector<int>& lengths, vector<int>& prices, int n);
    int countChange(const vector<int>& denominations, int total);
    int minCountChange(const vector<int>& denominations, int total);
    int countRibbonPieces(const vector<int>& ribbonLengths, int total);
};

/* Typical Unbound Knapsack */
int UnboundKnapsack::solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity)
{
    // TODO: Write your code here
    vector<vector<int>> memo (profits.size(), vector<int>(capacity+1, -1));

    /* Tabulation method */
    for (int i = 0; i < memo.size(); i++)
    {
        memo[i][0] = 0;
    }
    int profits1 = 0, profits2 = 0;
    for (int i = 0; i < memo.size(); i++)
    {
        for (int c = 1; c < memo[0].size(); c++)
        {
            if (i == 0)
            {
                memo[i][c] = profits[i] + memo[i][c-weights[i]]; 
                continue;
            }
            if (weights[i] <= c)
            {
                profits1 = profits[i] + memo[i][c-weights[i]];
            }
            else profits1 = 0;
            profits2 = memo[i-1][c];
            memo[i][c] = max(profits1, profits2);
        }
    }
    return memo[memo.size()-1][capacity];
    /* ----------------- */

    // Call to recurive func
    // return recursiveKnap(profits, weights, capacity, 0); // Brute force
    return recursiveKnap(profits, weights, capacity, 0, memo);
}

int UnboundKnapsack::recursiveKnap(const vector<int> &profits, const vector<int> &weights, 
                                   int capacity, int curIndex, vector<vector<int>>& memo)
{
    // Check base case
    if (capacity <= 0 || curIndex >= profits.size()) return 0;
    if (memo[curIndex][capacity] != -1) return memo[curIndex][capacity];
    // Call include-curIndex func
    int profits1 = 0, profits2 = 0;
    if (weights[curIndex] <= capacity)
    {
        profits1 = profits[curIndex] + 
                   recursiveKnap(profits, weights, capacity - weights[curIndex], curIndex, memo);
    }
    // Call exclude-curIndex func
    profits2 = recursiveKnap(profits, weights, capacity, curIndex+1, memo);
    // Return max of both set
    memo[curIndex][capacity] = max(profits1, profits2);
    return max(profits1, profits2);
}

/* Rod Cutting */
int UnboundKnapsack::solveRodCutting(const vector<int>& lengths, vector<int>& prices, int n)
{
    // TODO: Write your code here
    // Init a memo table[rodIndex][n]
    vector<vector<int>> memo(lengths.size(), vector<int> (n+1, 0));
    // Traverse the table
    // For each n
    // If rodIndex = 0, assign the profit directly
    // Else take the max profit between include or exclude rodIndex
    for (int i = 0; i < memo.size(); i++)
    {
        for (int c = 1; c < memo[0].size(); c++)
        {
            if (lengths[i] <= c && i == 0)
            {
                memo[i][c] = prices[i] + memo[i][c-lengths[i]];
                continue;
            }

            int profit1=0, profit2=0;
            if (lengths[i] <= c)
            {
                profit1 = prices[i] + memo[i][c-lengths[i]];
            }
            profit2 = memo[i-1][c];
            memo[i][c] = max(profit1, profit2);
        }
    }
    // for (auto i : memo)
    // {
    //     for (int c : i)
    //     {
    //         cout << c << " ";
    //     } cout<<endl;
    // }
    return memo[memo.size()-1][n];
}

/* Coin Change */
int UnboundKnapsack::countChange(const vector<int>& denominations, int total)
{
    // Init memo table memo[denominations][total]
    vector<vector<int>> memo(denominations.size(), vector<int>(total+1, 0));
    for (int i = 0; i < memo.size(); i++)
    {
        memo[i][0] = 1;
    }
    // Traverse the table
    for (int i = 0; i < memo.size(); i++)
    {
        for (int c = 1; c < memo[0].size(); c++)
        {
            int way1 = 0, way2 = 0;
            if (denominations[i] <= c)
            {
                way1 = memo[i][c - denominations[i]];
                if (i == 0)
                {
                    memo[i][c] = memo[i][c-denominations[i]];
                    continue;
                }
            }
            if (i > 0) way2 = memo[i-1][c];
            memo[i][c] = way1 + way2;
        }
    }
    for (auto i : memo) {
        for (int c : i) cout << c << " ";
        cout << endl;
    }
    return memo[memo.size()-1][total];
}

/* Minimum Coin Change */
int UnboundKnapsack::minCountChange(const vector<int>& denominations, int total)
{
    // Init a memo table memo[denominations][total]: min num of coins
    // In 0 capacity, store all 0
    vector<vector<int>> memo(denominations.size(), vector<int>(total+1, INT_MAX));
    for (int i = 0; i < memo.size(); i++) memo[i][0] = 0;
    // Traveset the memo, for each capa at each set of indices
    // If index = 0, memo = 1 + memo[i][c-deno[i]]
    // Else memo = min(exclude, include)
        // exclude: memo[i-1][c]
        // include: 1 + memo[i][c-deno[i]]
    for (int i = 0; i < memo.size(); i++)
    {
        for (int c = 1; c < memo[0].size(); c++)
        {
            if (i > 0) memo[i][c] = memo[i-1][c];
            if (denominations[i] <= c && memo[i][c-denominations[i]] != INT_MAX)
            {
                memo[i][c] = min(memo[i][c], 1 + memo[i][c-denominations[i]]);
            }
        }
    }
    for (auto i : memo) {
        for (int c : i) cout << c << " ";
        cout << endl;
    }
    if (memo[memo.size()-1][total] == INT_MAX) return -1;
    return memo[memo.size()-1][total];
}

/* Maximum Ribbon Cut */
int UnboundKnapsack::countRibbonPieces(const vector<int>& ribbonLengths, int total)
{
    // TODO: Write your code here
    // For each ribbon type, check every capacity in the total amount
    // Include the ribbon type to the set (deduct the capacity)
    // Exclude the ribbon type to the set (take the result from prev ribbon)
    // Tabula: count of ribbon pieces
    int n = ribbonLengths.size();
    // Init a memo table memo[ribbons][total]
    vector<vector<int>> memo(n, vector<int>(total+1, -2));
    // Take all 0 capacity to 0 value
    for (int i = 0; i < n; i++) memo[i][0] = 0;
    // Traverse the table, for each ribbon
        // If only the first ribbon, only include the ribbon
        // Exclude the ribbon (the ribbon index > 0)
        // Include the ribbon, ribbonLength <= capacity
    for (int i = 0; i < n; i++)
    {
        for (int c = 1; c < memo[0].size(); c++)
        {
            if (i > 0) memo[i][c] = memo[i-1][c];
            if (ribbonLengths[i] <= c && memo[i][c-ribbonLengths[i]] != -2)
            {
                memo[i][c] = max(memo[i][c], 1 + memo[i][c-ribbonLengths[i]]);
            }
        }
    }
    // for (auto i : memo) {
    //     for (int c : i) cout << c << " ";
    //     cout << endl;
    // }
    return (memo[n-1][total] == -2) ? -1 : memo[n-1][total];    
}

/**
 * @brief Fibonacci Numbers pattern
 * 
 */
class FibonacciNumbers {
private:
public:
    int CalculateFibonacci(int n);
    int CountWays(int n);
    int CountWays1(int n);
    int countMinJumps(const vector<int>& jumps);
    int recursiveCountMinJumps(const vector<int>& jumps, int index, vector<int>& memo);
    int findMinFee(const vector<int>& fee);
    int findMaxSteal(const vector<int>& wealth);
};

/* Typical fibonacci numbers problem */
int FibonacciNumbers::CalculateFibonacci(int n) {
    if (n < 2) return n;
    int a = 0;
    int b = 1;
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        ans = a + b;
        a = b;
        b = ans;
    }
    return ans;
}

/* Staircase */
int FibonacciNumbers::CountWays(int n) {
    // TODO: Write your code here
    // n=4 0 1 2 4 7
    // f(n) = f(n-1) + f(n-2) + f(n-3)
    // For n == 3, need a zero-index = 1
    if (n == 0) return 0;
    int index0 = 1;
    int n1 = 1, n2 = 2;
    if (n == 1) return n1;
    if (n == 2) return n2;
    int ans;
    // Traverse from 3 to n
    for (int i = 3; i <= n; i++)
    {
        ans = n1 + n2 + index0;
        index0 = n1;
        n1 = n2;
        n2 = ans;
    }
    return ans;
}

/* Number Factors */
int FibonacciNumbers::CountWays1(int n)
{
    // TODO: Write your code here
    // f(n) = f(n-1) + f(n-3) + f(n-4)
    if (n < 1) return 0;
    vector<int> memo (n+1);
    if (n == 1 || n == 2) return 1;
    if (n == 3) return 2;
    // Traverse from 4 to n
    for (int i = 0; i <= 2; i++)
    {
        memo[i] = 1;
    }
    memo[3] = 2;
    for (int i = 4; i <= n; i++)
    {
        memo[i] = memo[i-1] + memo[i-3] + memo[i-4];
    }
    return memo[n];
}

/* Minimum jump to reach the end */
int FibonacciNumbers::countMinJumps(const vector<int>& jumps) {
    // f(i) = f(i+1) || ... || f(i+jumps[i])
    // Call to the recursive func with index 0
    vector<int> memo (jumps.size(), -1);
    int ans = recursiveCountMinJumps(jumps, 0, memo);
    for (int m : memo) cout << m << " ";
    cout << endl;
    return ans;
}
int FibonacciNumbers::recursiveCountMinJumps(const vector<int>& jumps, int index, vector<int>& memo)
{
    // Base case
        // index == jumps.size - 1
    // If the subproblem is processed before, return val
    if (index >= jumps.size() - 1) return 0;
    if (jumps[index] == 0) return 0;
    if (memo[index] != -1) return memo[index];
    // Call to f(index+1) ... f(index+jumps[index])
    // After every call, update the min
    // Update the min to memo and return
    int minVal = INT_MAX;
    int tmp = 0;
    for (int i = 1; i <= jumps[index]; i++)
    {
        if (index + i < jumps.size()) tmp = 1 + recursiveCountMinJumps(jumps, index + i, memo);
        minVal = min(minVal, tmp);
    }
    memo[index] = minVal;
    return memo[index];
}

/* Minimum jumps with fee */
int FibonacciNumbers::findMinFee(const vector<int>& fee) {
    // Init a memo for every index (number of stairs)
    vector<int> memo (fee.size()+1, 0);
    // Assign fee[0] to the first 3 stairs
    for (int i = 1; i <= 3; i++) memo[i] = fee[0];
    // Traverse the memo from index 4 to n
        // For each index, min(f(i-1), f(i-2), f(i-3)) + fee[i]
        // Update the memo[i]
    for (int i = 4; i <= fee.size(); i++)
    {
        memo[i] = min(fee[i-1]+memo[i-1], fee[i-2]+memo[i-2]);
        memo[i] = min(fee[i-3]+memo[i-3], memo[i]);
    }
    for (int i : memo) cout << i << " ";
    cout << endl;
    return memo[memo.size()-1];
}

/* House Thief */
int FibonacciNumbers::findMaxSteal(const vector<int>& wealth) {
    // f(i) = max(f(i-2),...,f(0)) + wealth[i]
    vector<int> memo (wealth.size());

    memo[0] = wealth[0];
    memo[1] = max(wealth[0], wealth[1]);
    memo[2] = wealth[2] + memo[0];
    for (int i = 3; i < wealth.size(); i++)
    {
        memo[i] = max(memo[i-2] + wealth[i], max(memo[i], memo[i-3] + wealth[i]));
    }
    for (int i : memo) cout << i << " ";
    cout << endl;
    return max(memo[wealth.size()-1], memo[wealth.size()-2]);
}


/**
 * @brief Palindromic Subsequence Pattern
 * 
 */
class PalindromicSubsequence
{
public:
    /* Longest Palindromic Subsequence */
    int findLPSLength(const string& st) {
        // Init a memo[st.size()][st.size()]
        vector<vector<int>> memo (st.size(), vector<int>(st.size(), -1));
        /* Bottom-up method */
        int stLength = st.length();
        // Every sequence with 1 element is a palindrome length 1
        for (int i = 0; i < st.length(); i++) memo[i][i] = 1;
        // If memo != 0
            // If st[startIndex] = st[endIndex]
            // Else take max between skip startIndex and skip endIndex
        for (int i = stLength-1; i >= 0; i--)
        {
            for (int j = i + 1; j < st.length(); j++)
            {
                if (st[i] == st[j]) {
                    memo[i][j] = 2 + memo[i+1][j-1];
                }
                else {
                    memo[i][j] = max(memo[i+1][j], memo[i][j-1]);
                }
            }
        }
        for (auto arr : memo) {
            for (int n : arr) cout << n << " ";
            cout << endl;
        }
        return memo[0][stLength-1];
        /* Top-down method */
        // Call to the recursive func
        int ans = recursiveFindLPSLength(st, 0, st.size()-1, memo);
        return ans;
    }
    int recursiveFindLPSLength(const string& st, int startIndex, int endIndex,
                               vector<vector<int>>& memo) {
        // Base case
            // Start index > end index, return 0
        if (startIndex > endIndex) return 0;
        if (startIndex == endIndex) return 1;
        if (memo[startIndex][endIndex] != -1) return memo[startIndex][endIndex];
        // Start char = end char, return 2 + recursiveFunc
        if (st[startIndex] == st[endIndex])
        {
            memo[startIndex][endIndex] = 2 + recursiveFindLPSLength(st, startIndex+1, endIndex-1, memo);
            return memo[startIndex][endIndex];
        }
        // Skip the 1st char and call recursiveFunc
        // Skip the last char and call recursiveFunc
        // Return the max
        int skipFirst = recursiveFindLPSLength(st, startIndex+1, endIndex, memo);
        int skipLast = recursiveFindLPSLength(st, startIndex, endIndex-1, memo);
        memo[startIndex][endIndex] = max(skipFirst, skipLast);
        return memo[startIndex][endIndex];
    }

    /* Longest Palindromic Substring */
    int findLPStrLength(const string& st) {
        int length = st.length();
        vector<vector<int>> memo (length, vector<int> (length, -1));
        int ans = 1;
        /* Bottom-up solution */
        vector<vector<bool>> dp (length, vector<bool> (length, false)); // [startIndex][endIndex]
        // True if the substring is palindrome
        // Assign true to one char
        for (int i = 0; i < length; i++) dp[i][i] = true;
        // For each startIndex, try every substr (endIndex)
        for (int i = length-1; i >= 0; i--) {
            for (int j = i + 1; j < length; j++) {
                if (st[i] == st[j]) {
                    if (dp[i+1][j-1] || j - i == 1) {
                        dp[i][j] = dp[i+1][j-1];
                        ans = max(ans, j-i+1);
                    }
                }
            }
        }
        for (auto arr : dp) {
            for (bool i : arr) cout << i << " ";
            cout << endl;
        }
        return ans;
        /* Top-down solution */
        ans = recFindLPStrLength(st, 0, length-1, memo);
        return ans;
    }
    int recFindLPStrLength(const string& st, int startIndex, int endIndex,
                           vector<vector<int>>& memo) {
        // Base case
        if (startIndex > endIndex) return 0;
        if (startIndex == endIndex) {
            memo[startIndex][endIndex] = 1;
        }
        else if (memo[startIndex][endIndex] == -1) {
            if (st[startIndex] == st[endIndex]) {
                int remainingLength = endIndex - startIndex - 1;
                if (remainingLength == recFindLPStrLength(st, startIndex+1, endIndex-1, memo)) {
                    memo[startIndex][endIndex] = 2 + remainingLength;
                }
            }
            int valIfSkipStart = recFindLPStrLength(st, startIndex+1, endIndex, memo);
            int valIfSkipEnd = recFindLPStrLength(st, startIndex, endIndex-1, memo); 
            memo[startIndex][endIndex] = max(memo[startIndex][endIndex], max(valIfSkipEnd, valIfSkipStart));
        }
        return memo[startIndex][endIndex];
    }

    /* Count of Palindromic Substrings */
    int findCPS(const string& st) {
        int ans = 0;
        int size = st.size();
        /* Bottom-up solution */
        // Init the dp[st][st]
        vector<vector<bool>> dp (size, vector<bool> (size, false));
        // Assign every char as 1 palindromic substr
        for (int i = 0; i < size; i++) dp[i][i] = true;
        ans += size;
        // Traverse the arr
        for (int i = size - 1; i >= 0; i--) 
        {
            for (int j = i + 1; j < size; j++)
            {
                if (st[i] == st[j]) {
                    if (j - i == 1 || dp[i+1][j-1]) 
                    {
                        ans++;
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
            }
        }
        TerminalPrint<vector<vector<bool>>>::print2dArray(dp);
        return ans;
    }

    /* Minimum Deletions in a String to make it a Palindrome */
    int findMinimumDeletions(const string& st) {
        // Minimum deletion => longest subseq
        // Init a dp
        int size = st.size();
        vector<vector<int>> dp (size, vector<int>(size, 0));
        // Assign each char as 1 longest subseq
        for (int i = 0; i < size; i++) dp[i][i] = 1;
        // Traverse the dp
        for (int i = size-1; i >= 0; i--)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (dp[i][j] == 0) {
                    if (st[i] == st[j]) {
                        dp[i][j] = 2 + dp[i+1][j-1];
                    }
                    else {
                        int valIfSkipStart = dp[i+1][j];
                        int valIfSkipEnd = dp[i][j-1];
                        dp[i][j] = max(valIfSkipStart, valIfSkipEnd);
                    }
                }
            }
        }
        TerminalPrint<vector<vector<int>>>::print2dArray(dp);
        return size - dp[0][size-1];
    }

    /* Palindromic Partitioning */
    int findMPPCuts(const string& st) {
        // Call to recursive func
        return recurFindMPPCuts(st, 0, st.size()-1);
    }
    int recurFindMPPCuts(const string& st, int startIndex, int endIndex) {// Need a memo[start][end] (int)
        // Base case
            // startIndex > endIndex
            // The substr is palindrome
        if (startIndex >= endIndex || checkPalindrome(st, startIndex, endIndex)) return 0;
        // Traverse every char from startIndex
            // If substr(startIndex, i) is palindrome, update the minimum cut
        int minCuts = endIndex - startIndex;
        for (int i = startIndex; i <= endIndex; i++) {
            if (checkPalindrome(st, startIndex, i)) {
                minCuts = min(minCuts, 1 + recurFindMPPCuts(st, i+1, endIndex));
            }
        }
        return minCuts;
    }
    bool checkPalindrome(const string& st, int start, int end) { // Need a memo[start][end] (bool)
        while (start < end) {
            if (st[start] != st[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};

/**
 * @brief Longest Common Substring Pattern
 * 
 */
class LongestCommonSubstr
{
private:
    /* Longest Common Subsequence */
    int checkCommonSubseq(const string& text1, int i1, const string& text2, int i2,
                          vector<vector<int>>& memo) {
        // Base case
        // i1 or i2 exceed the text scope
        if (i1 >= text1.size() || i2 >= text2.size()) return 0;
        // Check if the subproblem has been reached
        if (memo[i1][i2] != -1) return memo[i1][i2];
        // Call to recursive func
        // If text1[i1] == text2[i2], call to f(i1+1, i2+1), otherwise
        // f(i1+1, i2)
        // f(i1, i2+1)
        int returnVal = 0;
        if (text1[i1] == text2[i2]) {
            returnVal = 1 + checkCommonSubseq(text1, i1+1, text2, i2+1, memo);
        }
        else {
            returnVal = max(returnVal, checkCommonSubseq(text1, i1+1, text2, i2, memo));
            returnVal = max(returnVal, checkCommonSubseq(text1, i1, text2, i2+1, memo));
        }
        // Update the memo table
        memo[i1][i2] = returnVal;
        // Return the maximum
        return returnVal;
    }
public:
    int findLCSLength(const string& s1, const string& s2) {
        return -1;
    }

    /* Longest Common Subsequence */
    int longestCommonSubsequence(const string& text1, const string& text2) {
        // Init a memo table [i1][i2]
        vector<vector<int>> memo (text1.size(), vector<int> (text2.size(), -1));
        // Check matching chars 
        // Call to the recursive func
        int ans = checkCommonSubseq(text1, 0, text2, 0, memo);
        return ans;
    }
};

#endif // SOLUTION_HPP
