#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

/**
 * @brief Pair with Target Sum 
 * 
 * @param arr an array of sorted numbers
 * @param targetSum the target sum
 * 
 * @return :pair<int,int>: the indices of the two numbers such that
 * they add up to the given target <1st index, 2nd index>
 */
class PairWithTargetSum
{
private:
    vector<int> arr;
    int targetSum;
public:
    PairWithTargetSum(vector<int>& arr, int targetSum) 
        : arr(arr), targetSum(targetSum) {}
    pair<int, int> solve() {
        pair<int, int> ans (-1, -1);
        // TODO: Write your code here
        // Traverse the arr 
        // If arr[start] + arr[end] = target, return ans
        // If > target, end--
        // If < target, start++
        int start = 0, end = arr.size() - 1;
        while (start < end)
        {
            if (arr[start] + arr[end] == targetSum)
            {
                ans = make_pair(start, end);
                break;
            }
            else if (arr[start] + arr[end] > targetSum)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
        return ans;
    }
};

#endif // SOLUTION_HPP
