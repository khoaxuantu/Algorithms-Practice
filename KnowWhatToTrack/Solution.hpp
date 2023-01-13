#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

/**
 * @brief Palindrome Permutation
 * 
 * @param str An input string
 * 
 * @return :boolean: whether or not a permutation of the string
 */
class PalindromePermutation
{
private:
    string str;
public:
    PalindromePermutation(string& str) : str(str) {}
    bool solve() {
        //* Record the freq of chars
        unordered_map<char, int> freq;
        for (char& c : str) {
            freq[c]++;
        }
        //* Validate the freq
            // If more than 2 chars are odd
        int odds = 1;
        for (auto entry : freq) {
            if (entry.second % 2 != 0) odds--;
            if (odds < 0) return false;
        }
        return true;
    }
};

#endif // SOLUTION_HPP
