#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

#define pairMatrix pair<int, pair<int,int>>  // <nums, maximum avail sum<nums2Index, sum>>

/**
 * @brief Merge K Sorted Lists
 * 
 * @param lists A list of sorted linked list
 * 
 * @return :ListNode: Merging into one sorted list
 */
class MergeKSortedLists
{
private:
    vector<ListNode*> lists;
public:
    MergeKSortedLists(vector<ListNode*>& lists) : lists(lists) {}
    ListNode* solve() {
        ListNode *resultHead = nullptr;
        // TODO: Write your code here
        // Init a heap to store all the element in sorted order 
        // Data type: pair<num, listIndex>
        auto custCmp = [](const ListNode* x, const ListNode* y){
            return x->value > y->value;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(custCmp)>
            minHeap(custCmp);
        // Push the first element in all the lists to the heap
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode* nodePtr = lists[i];
            minHeap.push(nodePtr);
        }
        // Start traverse the heap
        // For each element
            // Pop the element out and connect to the final list
            // Push another from the same list to the heap
        ListNode* curNode = minHeap.top();
        minHeap.pop();
        if (curNode->next) minHeap.push(curNode->next);
        resultHead = curNode;
        ListNode* runner = resultHead;
        while (!minHeap.empty())
        {
            curNode = minHeap.top();
            minHeap.pop();

            runner->next = curNode;
            runner = runner->next;
            if(curNode->next) minHeap.push(curNode->next);
        }
        return resultHead;
    }
};


/**
 * @brief Kth Smallest Number in M Sorted Lists
 * 
 * @param lists A list of sorted arrays
 * @param k An input K variable
 * 
 * @return :int: K'th smallest number among all the arrays in the list
 */
class KthSmallestInMSortedArrays
{
private:
    vector<vector<int>> lists;
    int k;
public:
    KthSmallestInMSortedArrays(vector<vector<int>>& lists, int k) :
        lists(lists), k(k) {}
    int solve() {
        int result = -1;
        // TODO: Write your code here
        // Init a min heap to keep track the smallest num of all lists
        priority_queue<int> minHeap;
        // For each index
        // Add entries of all lists to the heap
        // If k = 0, assign the result and return
        int heapSize = k;
        for (int i = 0; i < lists[0].size(); i++) // 2 3 3 6 6 8  
        {
            for (int n = 0; n < lists.size(); n++)
            {
                if (i >= lists[n].size()) continue;

                minHeap.push(lists[n][i]);
                if (minHeap.size() > heapSize)
                {
                    minHeap.pop();
                }
            }
        }
        result = minHeap.top();
        return result;
    }
};


/**
 * @brief Kth Smallest Number in a Sorted Matrix 
 * 
 * @param matrix An nxn matrix where each row and column is sorted
 * in ascending order
 * @param k An input K variable
 * 
 * @return :int: The k smallest element in the matrix
 */
class KthSmallestInSortedMatrix
{
private:
    vector<vector<int>> matrix;
    int k;
public:
    KthSmallestInSortedMatrix(vector<vector<int>>& matrix, int k) :
        matrix(matrix), k(k) {}
    int solve() {
        int result = -1;
        // TODO: Write your code here
        // Init a min heap to keep track the smallest num
        auto custCmp = [](const pairMatrix& x, const pairMatrix& y){
            return x.first > y.first;
        };
        priority_queue<pairMatrix, vector<pairMatrix>, decltype(custCmp)> minHeap(custCmp);
        // Add first elements in every row to the heap
        for (int i = 0; i < matrix.size(); i++)
        {
            minHeap.push(make_pair(matrix[i][0], make_pair(i, 0)));
        }
        // For each num, pop the num out the heap
        // Keap track the result
        // If the iter reach to k, break
        // Push the next matrix's row num to the heap
        int iter = 0;
        while (!minHeap.empty())
        {
            pairMatrix curNum = minHeap.top();  // 7 9 11 
            minHeap.pop();
            
            if (++iter == k)
            {
                result = curNum.first;
                break;
            }

            curNum.second.second++;
            if (curNum.second.second >= matrix[0].size()) continue;
            minHeap.push(make_pair(matrix[curNum.second.first][curNum.second.second],
                         make_pair(curNum.second.first, curNum.second.second)));
        }
        return result;
    }
};


/**
 * @brief Smallest Number Range
 * 
 * @param lists A list of sorted arrays
 * 
 * @return :pair<int,int>: The smallest range that includes 
 * at least one number from each of the lists
 */
class SmallestRange
{
private:
    vector<vector<int>> lists;
public:
    SmallestRange(vector<vector<int>>& lists) : lists(lists) {}
    pair<int,int> solve() {
        pair<int, int> result (-1, -1);
        // Init a minHeap to keep the nums being sorted in ascending order
        auto custCmp = [](const pairMatrix& x, const pairMatrix& y){
            return x.first > y.first;
        };
        priority_queue<pairMatrix, vector<pairMatrix>, decltype(custCmp)> minHeap(custCmp);
        // Add the first element in every list to the heap
        // Store the maxVal, minval
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        for (int i = 0; i < lists.size(); i++)
        {
            minHeap.push(make_pair(lists[i][0], make_pair(i, 0)));
            minVal = min(minVal, lists[i][0]);
            maxVal = max(maxVal, lists[i][0]);
        }
        result.first = minVal;
        result.second = maxVal;
        // Traverse the heap
        // For each num, pop the num out
        // Increment curNum to the nextNum
        // If the listIndex < listSize
            // If the num = minVal, update the minVal to the next num in list
            // The same with the maxVal
            // Push the curNum back to the heap
        // Update the minimum range
        while (!minHeap.empty()) // 8 10 12
        {
            pairMatrix curNum = minHeap.top();
            minHeap.pop();

            curNum.second.second++;
            if (curNum.second.second < lists[curNum.second.first].size())
            {
                curNum.first = lists[curNum.second.first][curNum.second.second];
                minHeap.push(curNum);
                minVal = minHeap.top().first;
                if (curNum.first > maxVal)
                {
                    maxVal = curNum.first;
                }
            }
            if (minHeap.size() == lists.size() && 
                abs(maxVal-minVal) < abs(result.first-result.second))
            {
                result.first = minVal;
                result.second = maxVal;
            }
        }
        return result;
    }
};


/**
 * @brief K Pairs With Largest Sum 
 * 
 * @param nums1 The first input array
 * @param nums2 Then secon input array
 * @param k An input K variable
 * 
 * @return :vector<pair<int,int>>: K pairs with the largest sum where
 * each pair consists of numbers from both the arrays
 */
class LargestPairs
{
private:
    vector<int> nums1;
    vector<int> nums2;
    int k;
public:
    LargestPairs(vector<int>& nums1, vector<int>& nums2, int k) :
        nums1(nums1), nums2(nums2), k(k) {}
    vector<pair<int,int>> solve() {
        vector<pair<int, int>> result;
        // TODO: Write your code here
        // Init a maxHeap to keep track the nums <nums, maximum avail sum<nums2Index, sum>>
        // Only push element from nums1 to the heap
        // Keep track the maximum avail sum for each num
        auto custCmp = [](const pairMatrix& x, const pairMatrix& y){
            return x.second.second < y.second.second;
        };
        priority_queue<pairMatrix, vector<pairMatrix>, decltype(custCmp)> maxHeap(custCmp);
        // Add the elements of the nums1 list // 9 8 2       
        for (auto n : nums1)
        {
            maxHeap.push(make_pair(n, make_pair(0, n + nums2[0])));
        }
        // Traverse the heap
        // For each num, pop out of the heap
        // Push to the result
        // nums2Index++
        // If nums2Index < nums2 size, push back to the heap
        while (!maxHeap.empty())
        {
            auto curSum = maxHeap.top();
            maxHeap.pop();
            result.push_back(make_pair(curSum.first, nums2[curSum.second.first]));
            k--;
            if (k == 0) break;

            curSum.second.first++;
            int nums2Index = curSum.second.first;
            if (nums2Index < nums2.size())
            {
                curSum.second.second = curSum.first + nums2[nums2Index];
                maxHeap.push(curSum);
            }
        }
        return result;
    }
};

#endif // SOLUTION_HPP
