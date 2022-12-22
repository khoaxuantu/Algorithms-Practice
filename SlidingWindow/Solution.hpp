#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

/**
 * @brief Maximum sum subarray of size K
 * 
 * @param k size K of the subarray
 * @param arr array
 * 
 * @return :int: Maximum subarray's sum of the array
 */
class MaxSumSubArrayOfSizeK
{
private:
    int k;
    vector<int> arr;
public:
    MaxSumSubArrayOfSizeK(int k, vector<int>& arr): k(k), arr(arr) {}
    int solve() {
        int maxSum = 0;
        // TODO: Write your code here
        int start = 0, end = 0;
        int sum = 0;
        while (end < arr.size())
        {
            sum += arr[end];
            cout << start << " " << end << " | " << sum << endl;
            if (end - start >= k - 1)
            {
                if (maxSum < sum) maxSum = sum;
                sum = sum - arr[start];
                start++;
            }
            
            end++;
        }
        cout << "-----------" << endl;
        return maxSum;
    }
};


/**
 * @brief Smallest subarray with a greater sum
 * 
 * @param S target number
 * @param arr an array of positive integers
 * 
 * @return :int: the length of the smallest contiguous subarray whose sum is >= S.
 * Return 0 if no such subarray exists
 */
class MinSizeSubArraySum
{
private:
    int S;
    vector<int> arr;
public:
    MinSizeSubArraySum(int S, vector<int>& arr) : S(S), arr(arr) {}
    int solve() {
        // TODO: Write your code here
        int start = 0;
        int end = 1;
        int sum = arr[start];
        int l = 1;
        int ans = INT_MAX;

        while (start < arr.size() || end < arr.size())
        {
        //* If sum is less than S
        if (sum < S)
        {
            if (end < arr.size()) 
            {
                sum += arr[end];
                l++;
                end++;
            }
            else
            {
                sum -= arr[start];
                start++;
            } 
        }
        //* If sum is larger than S
        if (sum >= S)
        {
            if (l < ans) ans = l;
            sum -= arr[start];
            l--;
            if (start < arr.size()) start++;
        }
        cout << "Ans: " << ans << " | Length: " << l;
        cout << " | Sum (" << start << ", " << end << "): " << sum << endl;
        }
        cout << "------------" << endl;
        return ans;
    }
};

/**
 * @brief Longest Substring with maximum K Distinct Characters
 * 
 * @param str input string
 * @param k K distinct characters
 * 
 * @return :int: the length of the longest substring with no more than
 * K distinct character
 */
class LongestSubstringKDistinct
{
private:
    string str;
    int k;
public:
    LongestSubstringKDistinct(string& s, int k) : str(s), k(k) {}
    int solve() {
        int maxLength = 0;
        // TODO: Write your code here
        //* Initialize a hashmap to store the char
        unordered_map<char, int> set;

        //* Traverse the string
        // If the hashmap has more than k elements then reset
            // Compare with maxLength
            // Reset the start point
        // Update the hashmap
        int start = 0, end = 0;

        while (end < str.size())
        {
            set[str[end]]++;
            cout << start << " " << end << " | ";
            cout << end - start << endl;
            
            while (set.size() > k)
            {
                cout << start << " " << end << " | ";
                cout << end - start << endl;
                set[str[start]]--;
                if (set[str[start]] == 0)
                {
                    set.erase(str[start]);
                }
                start++;
            }
            maxLength = max(maxLength, end-start+1);;
            end++;
        }
        cout << "-----------" << endl;
        return maxLength;
    }
};


/**
 * @brief Fruits into 2 Baskets
 * 
 * @param arr input array
 * 
 * @return :int: return the maximum number of fruits in both baskets
 */
class FruitsIntoBaskets
{
private:
    vector<int> arr;
public:
    FruitsIntoBaskets(vector<int>& array) : arr(array) {}
    int solve() {
        int maxLength = 0;
        // TODO: Write your code here
        //* Initialize a hashmap to store the char
        unordered_map<char, int> mp;

        //* Traverse the string
        // If the hashmap has more than k elements then reset
            // Compare with maxLength
            // Reset the start point
        // Update the hashmap
        int start = 0, end = 0;
        while (end < arr.size())
        {
            mp[arr[end]]++;

            while (mp.size() > 2)
            {
                mp[arr[start]]--;
                if (mp[arr[start]] == 0) mp.erase(arr[start]);
                start++;
            }

            maxLength = max(maxLength, end - start + 1);
            end++;
        }

        return maxLength;
    }
};


/**
 * @brief Longest Substring with Distinct Characters
 * 
 * @param str input string
 * 
 * @return :int: return the length of the longest substring
 */
class LongestSubstringWithDistinctChar
{
private:
    string str;
public:
    LongestSubstringWithDistinctChar(string& s) : str(s) {}
    int solve() {
        if (str.size() == 0) return 0;
        int maxLength = 1;
        // TODO: Write your code here aabccbb
        //* Initialize a hashmap to store character
        unordered_map<char, int> mp;
        //* Traverse the string
        // If a char is included in the hashset
        // Update the maxLength
        // Update the start
        // Increment end
        int i = 0;
        int start = 0, end = 0;
        while (end < str.size())
        {
            if (mp.count(str[end]) > 0)
            {
                maxLength = max(maxLength, end - start);
                start = max(start, mp[str[end]] + 1);
            }

            mp[str[end]] = end;
            cout << "Loop: "<< i << ": " << start << " " << end << " | Max length: " << maxLength << endl;
            end++;
            i++;
        }
        cout << "-------------" << endl;
        return maxLength;
    }
};


/**
 * @brief Longest Substring with Same Letters after Replacement
 * 
 * @param str input string
 * @param k K replacements
 * 
 * @return :int: the length of the longest substring 
 * having the same letters after replacement
 */
class CharacterReplacement
{
private:
    string str;
    int k;
public:
    CharacterReplacement(string& s, int k) : str(s), k(k) {}
    int solve() {
        int maxLength = 0;
        // TODO: Write your code here
        //* Initialize the hashmap to store letters' frequency
        unordered_map<char, int> mp;
        //* Traverse the string
        int charMaxCount = 0;
        int start = 0;
        for (int end = 0; end < str.size(); end++)
        {
            // Update the hashmap
            mp[str[end]]++;
            // Update the max count
            charMaxCount = max(charMaxCount, mp[str[end]]);
            // If the start to end of the char str[end] > max count + k
                // Reduce the first char
                // Update start
            if (end - start + 1 > charMaxCount + k)
            {
                mp[str[start]]--;
                start++;
            }
            // Update the maxLength
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};


/**
 * @brief Longest Subarray with Ones after Replacement
 * 
 * @param arr input array containing 0s and 1s
 * @param k maximum 0s that is allowed to replace with 1s
 * 
 * @return :int: the length of the longest contiguous subarray
 * haveing all 1s
 */
class ReplacingOnes
{
private:
    vector<int> arr;
    int k;
public:
    ReplacingOnes(vector<int>& arr, int k) : arr(arr), k(k) {}
    int solve() {
        int  maxLength = 0;
        // TODO: Write your code here
        // Initialize count 1
        int count1 = 0;
        // Traverse the arr
        int start = 0, end = 0;
        while (end < arr.size())
        {
            // If arr[end] is 1 then increment count1
            if (arr[end] == 1)
            {
                count1++;
            }
            // if end - start + 1 > count1 + k
                // if arr[start] is 1 then decrement count1
                // Update start
            if (end - start + 1 > count1 + k)
            {
                if (arr[start] == 1)
                {
                    count1--;
                }
                start++;
            }
            // Update maxLength
            maxLength = max(maxLength, count1 + k);

            end++;
        }
        return maxLength;
    }
};


/**
 * TODO: Rewrite the solution
 * @brief Permutation in a String
 * 
 * @param str the input string
 * @param pattern the pattern string
 * 
 * @return true or false - if the input string contains any permutation
 * of the pattern
 */
class StringPermutation
{
private:
    string str;
    string pattern;
public:
    StringPermutation(string& s, string& pattern) : str(s), 
                                                    pattern(pattern) {}
    bool solve() {
        int windowStart = 0, matched = 0;
        unordered_map<char, int> charFrequencyMap;
        for (auto chr : pattern) {
            charFrequencyMap[chr]++;
        }

        // our goal is to match all the characters from the 'charFrequencyMap' with the current window
        // try to extend the range [windowStart, windowEnd]
        for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
            char rightChar = str[windowEnd];
            if (charFrequencyMap.find(rightChar) != charFrequencyMap.end()) {
                // decrement the frequency of the matched character
                charFrequencyMap[rightChar]--;
                if (charFrequencyMap[rightChar] == 0) {  // character is completely matched
                    matched++;
                }
            }

            if (matched == (int)charFrequencyMap.size()) {
                return true;
            }

            if (windowEnd >= pattern.length() - 1) {  // shrink the window
                char leftChar = str[windowStart++];
                if (charFrequencyMap.find(leftChar) != charFrequencyMap.end()) {
                    if (charFrequencyMap[leftChar] == 0) {
                        matched--;  // before putting the character back, decrement the matched count
                    }
                    // put the character back for matching
                    charFrequencyMap[leftChar]++;
                }
            }
        }

        return false;
    }
};


/**
 * TODO: Rewire the solution
 * @brief String anagram
 * 
 * @param str the input string
 * @param pattern the pattern string
 * 
 * @return :vector<int>: A list of starting indices of the anagram
 * of the pattern in the given string
 */
class StringAnagrams
{
private:
    string str;
    string pattern;
public:
    StringAnagrams(string& s, string& pattern) : str(s),
                                                 pattern(pattern) {}
    vector<int> solve() {

    }
};


/**
 * @brief Smallest Window containing Substring
 * 
 * @param str the input string
 * @param pattern the pattern string
 * 
 * @return :string: the smallest substring in the given string 
 * which has all the characters occurences of the given patterns 
 */
class MinimumWindowSubstring 
{
private:
    string str;
    string pattern;
public:
    MinimumWindowSubstring(string& s, string& pattern) : str(s),
                                                         pattern(pattern) {}
    string solve() {

    }
};


/**
 * @brief Words Concatenation
 * 
 * @param str the input string
 * @param words the list of words
 * 
 * @return :vector<int>: All the starting indices of substrings in the given string
 * that are a concatenation of all the given words exactly once without any overlapping
 * of words
 */
class WordConcatenation 
{
private:
    string str;
    vector<string> words;
public:
    WordConcatenation(string& str, vector<string>& words) :
        str(str), words(words) {}
    vector<int> solve() {
        
    }
};

#endif // SOLUTION_HPP
