#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

/**
 * @brief Top K Elements
 * 
 * @param nums An unsorted array of numbers
 * @param k An input number representing k largest numbers
 * 
 * @return :vector<int>: the 'K' largest number
 */
class KLargestNumbers
{
private:
    vector<int> nums;
    int k;
public:
    KLargestNumbers(vector<int>& nums, int k) : nums(nums), k(k) {}
    vector<int> solve() {
        vector<int> result;
        // TODO: Write your code here
        priority_queue<int> pq;
        for (auto n : nums)
        {
            pq.push(n);
        }
        while (k > 0)
        {
            result.push_back(pq.top());
            pq.pop();
            k--;
        }
        return result;
    }
};


/**
 * @brief Kth Smallest Number
 * 
 * @param nums An unsorted array of numbers
 * @param k An input number representing the kth smallest numbers
 * 
 * @return :int: Kth smallest number in the nums
 */
class KthSmallestNumber
{
private:
    vector<int> nums;
    int k;
public:
    KthSmallestNumber(vector<int>& nums, int k) : nums(nums), k(k) {}
    int solve() {
        // TODO: Write your code here
        priority_queue<int> pq;
        for (auto n : nums)
        {
            if (pq.size() == k)
            {
                if (n < pq.top())
                {
                    pq.pop();
                    pq.push(n);
                }
            }
            else pq.push(n);
        }
        return pq.top(); // -1 5 11 
    }
};


/**
 * @brief K Closet Point to the Origin
 * 
 * @param points An array of points in the 2D plane
 * @param k An input number
 * 
 * @return :vector<Point>: the K closet points to the origin (0,0)
 */
class KClosestPointsToOrigin
{
private:
    vector<Point> points;
    int k;
public:
    KClosestPointsToOrigin(vector<Point>& points, int k) : points(points), k(k) {}
    vector<Point> solve() {
        vector<Point> result;
        // TODO: Write your code here
        auto custCmp = [](Point& a, Point& b){
            return a.distFromOrigin() < b.distFromOrigin();
        };
        priority_queue<Point, vector<Point>, decltype(custCmp)> pq(custCmp);

        for (auto p : points)
        {
            if (pq.size() == k)
            {
                if (p.distFromOrigin() < pq.top().distFromOrigin())
                {
                    pq.pop();
                    pq.push(p);
                }
            }
            else pq.push(p);
        }
        while (!pq.empty())
        {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};


/**
 * @brief Connect Ropes
 * 
 * @param ropeLengths N ropes with different lengths
 * 
 * @return :int: The minimum cost to connect the ropes
 * into one big rope
 */
class ConnectRopes
{
private:
    vector<int> ropeLengths;
public:
    ConnectRopes(vector<int>& ropes) : ropeLengths(ropes) {}
    int solve() {
        int result = 0;
        // TODO: Write your code here
        // Push all in a heap
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int rope : ropeLengths)
        {
            minHeap.push(rope);
        }
        // Connect each rope per time
        while (!minHeap.empty())
        {
            int connection = minHeap.top();
            minHeap.pop();

            if (!minHeap.empty())
            {
                connection += minHeap.top();
                minHeap.pop();
            }
            minHeap.push(connection);
            result += connection;
            if (minHeap.size() == 1)
            {
                minHeap.pop();
            }
        }
        return result;
    }
};


/**
 * @brief Top K Frequent Numbers
 * 
 * @param nums An unsorted array of numbers
 * @param k An input number
 * 
 * @return :vector<int>: The top K frequently ocurring numbers in the nums
 */
class TopKFrequentNumbers
{
private:
    vector<int> nums;
    int k;
    struct valueCompare {
        char operator()(const pair<int, int> &x, const pair<int, int> &y) {
            return x.second > y.second;
        }
    };
public:
    TopKFrequentNumbers(vector<int>& nums, int k) : nums(nums), k(k) {}
    vector<int> solve() {
        vector<int> topNumbers;
        // TODO: Write your code here
        unordered_map<int, int> freq;
        for (int n : nums) {
            freq[n]++;
        }
        // Init a maxHeap to store top K freq num
        priority_queue<pair<int,int>, vector<pair<int,int>>, valueCompare> maxHeap;
        for (auto key : freq)
        {
            if (maxHeap.size() == k)
            {
                if (key.second > maxHeap.top().second)
                {
                    maxHeap.pop();
                    maxHeap.push(make_pair(key.first, key.second));
                }
            }
            else maxHeap.push(make_pair(key.first, key.second));
        }
        while (!maxHeap.empty())
        {
            topNumbers.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        return topNumbers;
    }
};


/**
 * @brief Frequenct Sort 
 * 
 * @param str An input string
 * 
 * @return :string: The string after being sorted
 * based on the decreasing frequency of characters
 */
class FrequencySort
{
private:
    string str;
public:
    FrequencySort(string& str) : str(str) {}
    string solve() {
        string sortedString = "";
        // TODO: Write your code here
        unordered_map<char, int> freq;
        for (char c : str)
        {
            freq[c]++;
        }

        auto custCmp = [](pair<char, int>& x, pair<char, int>& y){
            return x.second < y.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(custCmp)> maxHeap(custCmp);

        for (auto entry : freq)
        {
            maxHeap.push(make_pair(entry.first, entry.second));
        }
        
        while (!maxHeap.empty())
        {
            for (int i = 0; i < maxHeap.top().second; i++)
            {
                sortedString += maxHeap.top().first;
            }
            maxHeap.pop();
        }
        return sortedString;
    }
};


/**
 * @brief Kth Largest Number in a Stream
 * 
 * @param nums An unsorted array of numbers
 * @param k An input number
 * 
 * @details Design a class to efficiently find 
 * the Kth largest element in a stream of numbers
 */
class KthLargestNumberInStream {
private:
    priority_queue<int> mainQ; // MaxHeap
    priority_queue<int, vector<int>, greater<int>> subQ; // MinHeap
public:
    KthLargestNumberInStream(const vector<int> &nums, int k) {
        // TODO: Write your code here
        // Push all nums to the mainQ
        for (auto n : nums)
        {
            mainQ.push(n);
        }
        // Push k-1 nums to the subQ => the mainQ top is the kth largest element
        while (k > 1)
        {
            subQ.push(mainQ.top());
            mainQ.pop();
            k--;
        }
    }

    virtual int add(int num) {
        // TODO: Write your code here
        // If num > mainQ top and > subQ top, pop subQ top to mainQ then add num to subQ
        if (num > mainQ.top() && num > subQ.top())
        {
            mainQ.push(subQ.top());
            subQ.pop();
            subQ.push(num);
        }
        // If num < mainQ top, push num to mainQ
        else
        {
            mainQ.push(num);
        }
        return mainQ.top();
    }
};


/**
 * @brief K Closet Numbers
 * 
 * @param arr A sorted number array
 * @param K An input integer k
 * @param X An input integer x 
 * 
 * @return :vector<int>: K closet numbers to X in the array.
 * Return the numbers in the sorted order
 */
class KClosestElements
{
private:
    vector<int> arr;
    int K;
    int X;
    struct numCompare {
        bool operator()(const pair<int, int> &x, const pair<int, int> &y) { return x.first > y.first; }
    };
public:
    KClosestElements(vector<int>& arr, int k, int x) : arr(arr), K(k), X(x) {}
    vector<int> solve() {
        vector<int> result;
        // TODO: Write your code here
        // Store a min heap by index for closet num to X
        // Keep the heap in K size
            // If the num dis < heap top, pop the heap top out
        priority_queue<pair<int,int>, vector<pair<int,int>>, numCompare> minHeap;
        for (auto n : arr)
        {
            if (minHeap.size() == K)
            {
                if (abs(X-n) < minHeap.top().second)
                {
                    minHeap.pop();
                    minHeap.push(make_pair(n, abs(X-n)));
                }
            }
            else minHeap.push(make_pair(n, abs(X-n)));
        }  

        while (!minHeap.empty())
        {
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }
        return result;
    }
};


/**
 * @brief Maximum Distinct Elements
 * 
 * @param nums An unsorted array of numbers
 * @param k An input number. We need to remove K numbers
 * from the array such that we are left with maximum distinct
 * numbers
 * 
 * @return :int: The removed number 
 */
class MaximumDistinctElements
{
private:
    vector<int> nums;
    int k;
public:
    MaximumDistinctElements(vector<int>& nums, int k) : nums(nums), k(k) {}
    int solve() {
        int distinctElementsCount = 0;
        // TODO: Write your code here
        unordered_map<int, int> freq;
        for (auto n : nums)
        {
            freq[n]++;
        }
        // Push to heap the most freq nums
        auto custCmp = [](pair<int,int>& x, pair<int,int>& y){
            return x.first > y.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(custCmp)> minHeap (custCmp);
        for (auto entry : freq)
        {
            if (entry.second > 1) minHeap.push(make_pair(entry.second, entry.first));
        }
        int distinctNum = freq.size() - minHeap.size();
        // Pop each minimum freq 
            // Deducted by k
            // If diffValue = -1, increment distinctNum and k = 0
            // If diffValue < -1, break
            // Else k = abs(diffValue)
            
        while (!minHeap.empty()) // 2 3    k=2
        {
            int entry = minHeap.top().first;
            minHeap.pop();

            k = k - entry+1;
            if (k >= 0)
            {
                distinctNum++;
            }
        }
        // If k > 0, decrement the distinctNum until k = 0
        if (k > 0)
        {
            distinctNum-=k;
        }
        return distinctNum;
    }
};


/**
 * @brief Sum of Elements
 * 
 * @param nums An unsorted array of numbers
 * @param k1 An input number K1
 * @param k2 An input number K2
 * 
 * @return :int: The sum of all numbers between K1'th and
 * K2'th smallest elements of the nums
 */
class SumOfElements
{
private:
    vector<int> nums;
    int k1;
    int k2;
public:
    SumOfElements(vector<int>& nums, int k1, int k2) : nums(nums), k1(k1), k2(k2) {}
    int solve() {
        int result = 0;
        // TODO: Write your code here
        // Classify k1 and k2 what is larger and smaller
        // Push all larger-1'th smallest num into a maxHeap
        int smaller = min(k1, k2);
        int larger = max(k1, k2);
        priority_queue<int> maxHeap;
        for (auto n : nums)
        {
            maxHeap.push(n);
            if (maxHeap.size() > k2-1) maxHeap.pop();
        }
        // Traverse the heap, track the ith smallest num
        // i < larger-smaller-1, cal result
        int i = 0;
        while (i < larger - smaller - 1)
        {
            result += maxHeap.top();
            maxHeap.pop();
            cout << result << " ";
            i++;
        }
        return result;
    }
};


/**
 * @brief Rearrange String
 * 
 * @param str An input string
 * 
 * @return :string: A new string rearranged from the str such that
 * no two same characters come next to each other. If the str cannot
 * be rearranged. return ""
 */
class RearrangeString 
{
private:
    string str;
public:
    RearrangeString(string& s) : str(s) {}
    string solve() {
        // TODO: Write your code here
        string ans = "";
        // Store freq of each char into a map
        unordered_map<char, int> freq;
        for (char c : str)
        {
            freq[c]++;
        }
        // Push the freq to a min heap
        auto custCmp = [](pair<int,char>& x, pair<int,char>& y){
            return x.first < y.first;
        };
        priority_queue<pair<int,char>, vector<pair<int,char>>, decltype(custCmp)> minHeap(custCmp);

        for (auto entry : freq)
        {
            minHeap.push(make_pair(entry.second, entry.first));
        }
        pair<int, char> prevEntry (-1, -1);
        while (!minHeap.empty())
        {
            pair<int,char> curChar = minHeap.top();
            minHeap.pop();

            if (prevEntry.first > 0)
            {
                minHeap.push(prevEntry);
            }

            ans += curChar.second;
            curChar.first--;
            prevEntry = curChar;
        }
        if (ans.length() != str.length()) return "";
        return ans;
    }
};


/**
 * @brief Rearrange String K Distance Apart
 * 
 * @param str An input string
 * @param k An input number K
 * 
 * @return :string: A rearranged string such that the same characters
 * are at least K distance apart from each other
 */
class RearrangeStringKDistanceApart
{
private:
    string str;
    int k;
public:
    RearrangeStringKDistanceApart(string& s, int k) : str(s), k(k) {}
    string solve() {
        // TODO: Write your code here
        string ans = "";
        // Store the freq of each char into a map
        unordered_map<char, int> freq;
        for (char c : str)
        {
            freq[c]++;
        }
        // Max heap: 
        // Store all char in the max heap
        auto custCmp = [](pair<char,int>& x, pair<char,int>& y){
            return x.second < y.second;
        };
        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(custCmp)> maxHeap(custCmp);
        for (auto entry : freq)
        {
            maxHeap.push(make_pair(entry.first, entry.second));
        }
        // Traverse the max heap again
        // For each char add to the ans, store the char in another queue
            // If the queue size is equal to k, add the front element back to the heap
        queue<pair<char,int>> cache;
        while (!maxHeap.empty())
        {
            pair<char, int> curChar = maxHeap.top();
            maxHeap.pop();

            ans += curChar.first;
            curChar.second--;

            cache.push(curChar);
            if (cache.size() == k)
            {
                if(cache.front().second > 0) maxHeap.push(cache.front());
                cache.pop();
            }
        }
        if (ans.length() != str.length()) return "";
        return ans;
    }
}; 


/**
 * @brief Scheduling Tasks
 * 
 * @param tasks A list of tasks that need to be run in any order
 * @param k Cooling periods for all tasks
 * 
 * @return :int: The minimum number of CPU intervals that the 
 * server needs to finish all tasks
 */
class SchedulingTasks
{
private:
    vector<char> tasks;
    int k;
public:
    SchedulingTasks(vector<char>& tasks, int k) : tasks(tasks), k(k) {}
    int solve() {
        int intervalCount = 0;
        // TODO: Write your code here
        // Store the freq of each task into a map
        unordered_map<char, int> freq;
        for (char c : tasks)
        {
            freq[c]++;
        }
        // Push the tasks to a max heap (pair<task, freq>)
        auto custCmp = [](pair<char, int>& x, pair<char, int>& y){
            return x.second < y.second;
        };
        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(custCmp)> maxHeap(custCmp);
        for (auto entry : freq)
        {
            maxHeap.push(make_pair(entry.first, entry.second));
        }
        // Init a queue for cooldown
        queue<pair<char,int>> cd;
        // Traverse the heap
        // For each task
            // Pop from the heap and push to the cooldown queue
            // If the queue size is equal k+1
                // If the queue front is not idle, push to the heap
            // If the queue front is <= 0, break
        while (true)
        {
            intervalCount++;
            if (!maxHeap.empty())
            {
                pair<char,int> curTask = maxHeap.top();
                maxHeap.pop();
                curTask.second--;
                cd.push(curTask);
            }
            else if (cd.size() < k + 1)
            {
                cd.push(make_pair('_', -1));
            }

            if (cd.size() == k+1)
            {
                if (cd.front().second > 0)
                {
                    maxHeap.push(cd.front());
                }
                cd.pop();
            }
            if (maxHeap.empty() && cd.front().second <= 0) break;
        }
        return intervalCount;
    }
};

#endif // SOLUTION_HPP
