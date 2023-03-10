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


/**
 * @brief Triplet Sum Close to Target
 * 
 * @param arr An array of unsorted number
 * @param targetSum A target number
 * 
 * @return :int: a sum of a triplet which is as close to 
 * the target number as possible
 */
class TripletSumCloseToTarget
{
private:
    vector<int> arr;
    int targetSum;
    pair<int, int> findClosetSum(vector<int>& arr, int index, int& targetSum) {
        int closet = INT_MAX;
        int closetSum = 0;
        // Run 2 pointer in start and end
        // If start or end are similar to the index, then increment or decrement appopriately 
        // Get curSum of 3 point, find the minimum closet with the abs(targetSum - curSum)
            // If get the closet which is larget than the cur one, end--
            // Else, update the closet and start++
            // 0 1 1 1
        int start = 0, end = arr.size() - 1;
        // cout << index << ": ";
        while (start < end)
        {
            // cout << start << " " << end << " : ";
            if (start == index)
            {
                start++;
            }
            else if (end == index)
            {
                end--;
            }
            else
            {
                int curSum = arr[start] + arr[end] + arr[index];
                if (abs(targetSum - curSum) < closet || 
                    abs(targetSum - curSum) == closet && targetSum - curSum > 0)
                {
                    closet = abs(targetSum - curSum);
                    closetSum = curSum;
                    start++;
                }
                else
                {
                    end--;
                }
            }
            // cout << closet << " " << closetSum << " | ";
        }
        return make_pair(closet, closetSum);
    }
public:
    TripletSumCloseToTarget(vector<int>& arr, int targetSum) :
        arr(arr), targetSum(targetSum) {}
    int solve() {
        // TODO: Write your code here
        pair<int, int> ans = {INT_MAX, INT_MIN};

        // Sort the array first
        sort(arr.begin(), arr.end());
        // Traverse the array
        // With each element, check the pair other than the element => Find the closet sum
        // If ans is 0, then break, else run to the end of arr
        for (int i = 0; i < arr.size(); i++)
        {
            if (ans.second == targetSum) break;
            pair<int, int> tmp = findClosetSum(arr, i, targetSum);
            // cout << tmp << endl;
            if (tmp.first <= ans.first)
            {
                ans = tmp;
            }
        }
        return ans.second;
    }
};


/**
 * @brief Triplets with Smaller Sum 
 * 
 * @param arr An array of unsorted number
 * @param targetSum A target number
 * 
 * @return :int: All triplets in the input array arr such that 
 * arr[i] + arr[j] +arr[k] < target where i, j, k are three 
 * different indices
 */
class TripletWithSmallerSum
{
private:
    vector<int> arr;
    int targetSum;
    int tripletsCount(vector<int>& arr, int index, int& targetSum)
    {
        int count = 0;
        //* Start (= index+1) and endpoint
        int start = index + 1, end = arr.size() - 1;
        //* Traverse the array
        // Get the sum = start + end + index
        // Compare the sum with the targetSum
            // If it is less than targetSum, increment start, count++
            // Else decrement end
        while (start < end)
        {
            int tmpSum = arr[start] + arr[end] + arr[index];

            if (tmpSum < targetSum)
            {
                count++;
                // cout << arr[index] << " " << arr[end] << " " << arr[start] << " | ";
            }
            end--;
            if (end == start) 
            {
                start++;
                end = arr.size() - 1;
            }
        }
        return count;
    }
public:
    TripletWithSmallerSum(vector<int>& arr, int targetSum) :
        arr(arr), targetSum(targetSum) {}
    int solve() {
        int ans = 0;
        //* Sort the array
        sort(arr.begin(), arr.end());
        //* Traverse the array
        // For each element, count the triplet including it whose summation is equal to targetSum
        for (int i = 0; i < arr.size() - 2; i++)
        {
            ans += tripletsCount(arr, i, targetSum);
        }
        return ans;
    }
};


/**
 * @brief Subarrays with Product Less than a Target
 * 
 * @param arr An array with positive numbers
 * @param target A positive target number
 * 
 * @return :vector<vector<int>>: All of arr's contiguous subarrays whose
 * product is less than the target number
 */
class SubarrayProductLessThanK
{
private:
    vector<int> arr;
    int target;
public:
    SubarrayProductLessThanK(vector<int>& arr, int target) :
        arr(arr), target(target) {}
    vector<vector<int>> solve() {
        vector<vector<int>> ans;
        //* Initialize 2 pointers at 0 and 1
        // Check whether the first 2 pointers larger than target
        // Else push into ans first
        int left = 0, right = 1;
        if (arr[left] < target) ans.push_back({arr[left]});
        //* Start shrinking window
        // Keep track the current product
        // Push [arr[left],arr[right]] to ans if its product is less than the target, and right++
            // current product *= arr[right]
        // If it is larger, left++
            // current product = current product / arr[left]
        int currPro = arr[left] == 0 ? 1 : arr[left];
        bool rightIncremented = false;
        while (right < arr.size())
        {
            while (arr[left] > target || arr[right] > target) 
            {
                if (arr[right] > target)
                {
                    left += 2;
                    right += 2;
                }
                else if (arr[left] > target)
                {
                    left++;
                    right++;
                }

                if (arr[left] < target)
                {
                    ans.push_back({arr[left]});
                }
                currPro = arr[left];
            }
            cout << left << " " << right << " | ";
            if (currPro * arr[right] < target)
            {
                if (arr[right] < target && right != left) ans.push_back({arr[right]});
                // deal with 0
                currPro *= (arr[right] == 0) ? 1 : arr[right];
                // Push to the ans
                vector<int> tmp;
                for (int i = left; i <= right; i++)
                {
                    tmp.push_back(arr[i]);
                }
                ans.push_back(tmp);
                right++;
            }
            else if (right == left)
            {
                right++;
            }
            else
            {
                currPro /= (arr[left] == 0) ? 1 : arr[left];
                left++;
            }
        }
        cout << endl << endl;
        return ans; 
    }
};


/**
 * @brief Dutch National Flag Problem
 * TODO: Rewrite the solution
 * 
 * @param arr An array containing 0s, 1s and 2s
 * 
 * @return :void: Sort the array in place. You should treat numbers of the
 * array as objects, hence, we can't count 0s, 1s, and 2s to recreate the 
 * array
 */
class DutchFlag 
{
public:
    void solve(vector<int> & arr) {
        // TODO: Write your code here

    }
};


/**
 * @brief Quadruple Sum to Target
 * 
 * @param arr An array of unsorted number 
 * @param target A target number
 * 
 * @return :vector<vector<int>>: All quadruplets in it, whose sum is equal
 * to the target number
 */
class QuadrupleSumToTarget
{
private:
    vector<int> arr;
    int target;
    int pair_sum(pair<int, int>& p, vector<int>& arr)
    {
        return arr[p.first] + arr[p.second];
    }
    void pushToAns(pair<int, int>& left, pair<int, int>& right, 
                   vector<vector<int>>& ans, vector<int>& arr)
    {
        ans.push_back({arr[left.first], arr[left.second], arr[right.first], arr[right.second]});
    }
public:
    QuadrupleSumToTarget(vector<int>& arr, int target) : arr(arr), target(target) {}
    vector<vector<int>> solve() {
        vector<vector<int>> ans;
        int endpoint = arr.size() - 1;
        // Sort the array
        sort(arr.begin(), arr.end());
        // Consider every elements of the array, for each element
            // Initialize 2 pointers of pair left and right. left.second = element; right = (arr - 1. arr)
            // sum(left) + sum(right) = target ?
            // left.second < right.first
                // If left.first = left.second or right.first = right,second, shift the pair toward the middle by 1
                // if curSum > target, decrement right.first
                    // If found a quadruplet, push to ans, then decrement right.second
                // if curSum < target, increment left.second
                    // If found a quadruplet, push to ans, then increment left.first
            pair<int, int> left (make_pair(0, 1));
            pair<int, int> right (make_pair(endpoint - 1, endpoint));

            while (left.second < right.first)
            {
                if (left.first == left.second)
                {
                    left.second++;                
                }
                if (right.first == right.second)
                {
                    right.first--;
                }

                int curSum = pair_sum(left, arr) + pair_sum(right, arr);
                if (curSum > target)
                {
                    right.first--;

                    if (pair_sum(left, arr) + pair_sum(right, arr) == target)
                    {
                        // cout << "call\n";
                        pushToAns(left, right, ans, arr);
                        right.second--;
                    }
                }
                else
                {
                    left.second++;
                    if (pair_sum(left, arr) + pair_sum(right, arr) == target)
                    {
                        pushToAns(left, right, ans, arr);
                        left.first++;
                    }
                }
            }
        return ans;
    }
};


/**
 * @brief Compare Strings containing Backspaces
 * TODO: Rewrite the solution
 * 
 * @param str1 The first input string
 * @param str2 The second input string
 * 
 * @return :boolean: If the two strings are equal
 */
class BackspaceCompare
{
private:
    string str1;
    string str2;
public:
    BackspaceCompare(string& str1, string& str2) : str1(str1), str2(str2) {}
    bool solve() {
        // TODO: Write your code here
        return false;
    }
};


/**
 * @brief Minimum Window Sort 
 * 
 * @param arr An array of unsorted numbers
 * 
 * @return :int: The length of the smallest subarray in it which when sorted
 * will sort the whole array
 */
class ShortestWindowSort
{
private:
    vector<int> arr;
public:
    ShortestWindowSort(vector<int>& arr) : arr(arr) {}
    int solve() {
        // TODO: Write your code here
        // Find unsorted min and unsorted max
        int left = 1, right = arr.size() - 2;
        // arr.push_back(INT_MIN);
        // arr.push_back(INT_MAX);
        int unsorted_min = INT_MAX, unsorted_max = INT_MIN;
        while (left < arr.size() && right >= 0)
        {
            if (arr[left] < arr[left-1])
            {
                unsorted_min = min(unsorted_min, arr[left]);
            }

            if (arr[right] > arr[right+1])
            {
                unsorted_max = max(unsorted_max, arr[right]);
            }
            left++;
            right--;
        }
        // cout << unsorted_min << " " << unsorted_max << endl;
        if (unsorted_min == INT_MAX || unsorted_max == INT_MIN)
        {
            return 0;
        }
        // Find indices which is less than the unsorted min 
        // and larger than the unsorted max
        left = 0;
        right = arr.size()-1;
        while (arr[left] < unsorted_min)
        {
            left++;
        }
        while (arr[right] > unsorted_max)
        {
            right--;
        }
        // cout << left << " " << right << " | ";
        return right - left + 1;
    }
};

#endif // SOLUTION_HPP
