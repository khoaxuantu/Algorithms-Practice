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


/**
 * @brief Remove Duplicates
 * 
 * @param arr An array of sorted number
 * 
 * @return :int: the length of subarray that has no duplicate in it
 */
class RemoveDuplicates
{
private:
    vector<int> arr;
public:
    RemoveDuplicates(vector<int>& arr) : arr(arr) {}
    int solve() {
        // TODO: Write your code here
        int ans = 1;
        int firstrun = 0, secondrun = 0;
        // Traverse the arr
        int cur = arr[0];
        while (secondrun < arr.size())
        {
            if (arr[secondrun] != arr[firstrun])
            {
                firstrun = secondrun;
                ans++;
            }
            secondrun++;
        }
        return ans;
    }
};


/**
 * @brief Squaring a Sorted array
 * 
 * @param arr An array of sorted number
 * 
 * @return :vector<int>: a new array containing squares of all
 * the numbers of the input array in the sorted order
 */
class SortedArraySquares
{
private:
    vector<int> arr;
public:
    SortedArraySquares(vector<int>& arr) : arr(arr) {}
    vector<int> solve() {
        int n = arr.size();
        vector<int> squares (n);
        // TODO: Write your code here
        int i = n - 1;
        int start = 0, end = n - 1;
        int s, e;
        while (start <= end)
        {
            s = arr[start] * arr[start];
            e = arr[end] * arr[end];
            if (s >= e) {
                squares[i] = s;
                start++;
            }
            else if (e > s) {
                squares[i] = e;
                end--;
            }
            i--;
        }
        return squares;
    }
};


/**
 * @brief Triplet Sum to Zero
 * 
 * @param arr An array of unsorted number
 * 
 * @return :vetor<vector<int>>: All unique triplets in it that
 * add up to zero 
 */
class TripletSumToZero
{
public:
    vector<int> arr;
    void findTriplets(vector<int>& arr, int index, vector<vector<int>>& ans) // target => -1| arr[-3,-2,-1,0,1,1,2]
    {
        // 2 pointer at start and end
        // start + end == -target, then create a triplet and push to the ans
        // If it is less than -target, increment start
        // If it is larger, decrement end
        int start = index+1, end = arr.size() - 1;
        while (start < end)
        {
            if (arr[start] + arr[end] == -arr[index])
            {
                ans.push_back({arr[index], arr[start], arr[end]});
                start++;
                end--;

                while (arr[start] == arr[start-1])
                {
                    start++;
                }

                while (arr[end] == arr[end+1])
                {
                    end--;
                }
            }
            else if (arr[start] + arr[end] < -arr[index])
            {
                start++;
            }
            else end--;
        }
        return;
    }
private:
    TripletSumToZero(vector<int>& arr) : arr(arr) {}
    vector<vector<int>> solve() {
        vector<vector<int>> ans;
        //* Sort the arr
        sort(arr.begin(),arr.end());
        //* Traverse the arr until 0
            // findtriplet(arr, i)
        int i = 0;
        while (i < arr.size() - 2)
        {   
            if (i > 0 && arr[i-1] == arr[i]) continue;
            findTriplets(arr, i, ans);
            i++;
        }

        return ans;
    }
};

#endif // SOLUTION_HPP
