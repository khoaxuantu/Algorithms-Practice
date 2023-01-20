#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

#define pairInt pair<int, int>
#define pairIvInt pair<Interval, int>

/**
 * @brief Find the Median of a Number Stream
 * 
 * @return :double: the median of the number stream
 */
class MedianOfAStream
{
public:
    priority_queue<int> maxHeap;                             // containing first half of numbers
    priority_queue<int, vector<int>, greater<int>> minHeap;  // containing second half of numbers

    virtual void insertNum(int num) {
        if (maxHeap.empty() || maxHeap.top() >= num) {
          maxHeap.push(num);
        } else {
          minHeap.push(num);
        }

        // either both the heaps will have equal number of elements or max-heap will have one
        // more element than the min-heap
        if (maxHeap.size() > minHeap.size() + 1) {
          minHeap.push(maxHeap.top());
          maxHeap.pop();
        } else if (maxHeap.size() < minHeap.size()) {
          maxHeap.push(minHeap.top());
          minHeap.pop();
        }
  }

  virtual double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
          // we have even number of elements, take the average of middle two elements
          return maxHeap.top() / 2.0 + minHeap.top() / 2.0;
        }
        // because max-heap will have one more element than the min-heap
        return maxHeap.top();
  }
};


/**
 * @brief Sliding Window Median 
 * 
 * @param nums An array of numbers
 * @param k an input number representing the size of subarrays
 * 
 * @return :vector<double>: The median of all 'k' sized
 * subarrays of the array
 */
class SlidingWindowMedian
{
private:
    int streamL = 0;
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;
    int startMemo;
    int endMemo;
public:
    void insertNum(int num)
    {
        // TODO:Write your code here
        // If both heaps are empty and num < maxHeap
        // If the max heap is not empty
        // If both heaps are not empty
            // MinHeapSize > MaxHeapSize, move one element from min to max
        if (max.empty())
        {
            if (!min.empty() && num > min.top())
            {
                min.push(num);
            }
            else max.push(num);
        }
        else if (num < max.top())
        {
            max.push(num);
        }
        else
        {
            min.push(num);
        }

        if (max.size() > min.size() + 1)
        {
            min.push(max.top());
            max.pop();
        }
        else if (max.size() < min.size())
        {
            max.push(min.top());
            min.pop();
        }
        streamL++;
    }

    void modifyHeap()
    {
        // If startMemo > maxTop 
            // Move the min heap's element to the max heap until meet the startMemo value
            // Move the transfered values back to the min again
        // Else do reversedly
        int stackTimes = 0;
        if (startMemo > max.top())
        {
            while (!min.empty() && min.top() <= startMemo)
            {
                max.push(min.top());
                min.pop();
                stackTimes++;
            }
            max.pop();
            while (stackTimes > 1)
            {
                min.push(max.top());
                max.pop();
                stackTimes--;
            }
        }
        else
        {
            while (!max.empty() && max.top() >= startMemo)
            {
                min.push(max.top());
                max.pop();
                stackTimes++;
            }
            min.pop();
            while (stackTimes > 1)
            {
                max.push(min.top());
                min.pop();
                stackTimes--;
            }
        }

        insertNum(endMemo);
        streamL--;
    }

    virtual double findMedian()
    {
        // TODO: Write your code heare
        if (streamL % 2 != 0) return max.top();
        else return ((double) max.top() + (double) min.top()) / 2;
    }

    virtual vector<double> findSlidingWindowMedian(vector<int> &nums, int k) {
        vector<double> result(nums.size() - k + 1);
        // TODO: Write your code here
        // Initialize start and end window ptr
        int start = 0, end = start + k - 1;
        // For each iter
        // Insert the elements of window to the heap
            // Shrink the window
        // Find median
        while (end < nums.size())
        {
            endMemo = nums[end];
            if (max.empty() && min.empty())
            {
                for (int i = start; i < k; i++)
                {
                    insertNum(nums[i]);
                }
            }
            else
            {
                modifyHeap();
            }
            
            if (start < result.size()) result[start] = findMedian();
            startMemo = nums[start];
            start++;
            end++;
        }

        while (!max.empty())
        {
            max.pop();
        }
        while (!min.empty())
        {
            min.pop();
        }
        return result;
    }
};


/**
 * @brief Maximize Capital
 * 
 * @param capitals The capitals of corresponding projects. We can
 * start an investment project only when we have the required capital.
 * Once a project is selected, we can assume that its profit has become
 * out capital
 * @param profits The projects' respective profits
 * @param numberOfProjects The number of projects
 * @param initialCapital A given initial capital
 * 
 * @return :int: The maximum total capital after selecting 
 * the most profitable projects
 */
class MaximizeCapital
{
private:
    vector<int> capitals;
    vector<int> profits;
    int numberOfProjects;
    int initialCapital;
public:
    MaximizeCapital(vector<int>& cap, vector<int>& pro, int noOfProjects, int initCap) :
        capitals(cap), profits(pro), numberOfProjects(noOfProjects), initialCapital(initCap) {}
    int solve() {
        // TODO: Write your code here
        // Pair<capital, capitalindex>
        // Pair<profits, capitalindex>
        // capitalindex ~ project
        auto custMinCmp = [](pair<int, int>& x, pair<int, int>& y) { return x.first > y.first; };
        priority_queue<pairInt, vector<pairInt>, decltype(custMinCmp)> minHeap(custMinCmp);

        auto custMaxCmp = [](pairInt& x, pairInt& y){ return x.first < y.first; };
        priority_queue<pairInt, vector<pairInt>, decltype(custMaxCmp)> maxHeap(custMaxCmp);
        // Store the capital in the min heap
        // For each capital, take all of the appopriate projects-profits and store in maxHeap
        // Get total profit from the maxHeap
        for (int i = 0; i < capitals.size(); i++)
        {
            minHeap.push(make_pair(capitals[i], i));
        }

        int curCapital = initialCapital;
        for (int proNo = 0; proNo < numberOfProjects; proNo++)
        {
            while (!minHeap.empty() && minHeap.top().first <= curCapital)
            {
                int capitalIndex = minHeap.top().second;
                minHeap.pop();

                maxHeap.push(make_pair(profits[capitalIndex], capitalIndex));
                
            }
            
            curCapital += maxHeap.top().first;
            maxHeap.pop();
        }
        
        return curCapital;
    }
};


/**
 * @brief Next Interval
 * 
 * @param intervals An array of intervals
 * 
 * @return  :vector<int>: The next interval of each intervals
 */
class NextInterval
{
private:
    vector<Interval> intervals;
    bool checkConflict(const Interval& base, const Interval& checked)
    {
        if (base.start >= checked.end || base.end <= checked.start)
        {
            return false;
        }
        return true;
    }
public:
    NextInterval(vector<Interval>& input) : intervals(input) {}
    vector<int> solve() {
        int n = intervals.size();
        vector<int> result(n);
        // TODO: Write your code here
        auto startCmp = [](pairIvInt& x, pairIvInt& y) 
        {
            if (x.first.start == y.first.start)
            {
                return x.first.end > y.first.end;
            }
            return x.first.start > y.first.start; 
        };
        priority_queue<pairIvInt, vector<pairIvInt>, decltype(startCmp)> minHeapStart(startCmp);

        auto endCmp = [](pairIvInt& x, pairIvInt& y) 
        { 
            if (x.first.start == y.first.start)
            {
                return x.first.end > y.first.end;
            }
            return x.first.end > y.first.end; 
        };
        priority_queue<pairIvInt, vector<pairIvInt>, decltype(endCmp)> minHeapEnd(endCmp);
    minHeapStart.push(make_pair(intervals[0], 0));
        for (int i = 1; i < intervals.size(); i++)
        {
            // Check conflict
            if (checkConflict(intervals[0], intervals[i]))
            {
                minHeapEnd.push(make_pair(intervals[i], i));
            }
            else
            {
                minHeapStart.push(make_pair(intervals[i], i));
            }
        }
        // Traverse the minHeapStart
            // Check if conflicts with minHeapEnd.top
            // Assign to the result based on the index
                // Check which non-conflict interval has smaller value
        while (!minHeapStart.empty() || !minHeapEnd.empty())
        {
            // Check the minHeapStart is not empty first
            if (!minHeapStart.empty())
            {
                // Pop the top out
                pairIvInt tmp = minHeapStart.top();
                minHeapStart.pop();
                // Consider if any top interval in minHeapEnd does not conflict 
                while (!minHeapEnd.empty() && !checkConflict(tmp.first, minHeapEnd.top().first))
                {
                    // the value is less than tmp
                    if (minHeapEnd.top().first.end <= tmp.first.start)
                    {
                        result[minHeapEnd.top().second] = tmp.second;
                    }
                    // the value is larger than tmp
                    else if (minHeapEnd.top().first.start >= tmp.first.end)
                    {
                        result[tmp.second] = minHeapEnd.top().second;
                        break;
                    }
                    minHeapEnd.pop();
                }

                if (!minHeapStart.empty())
                {
                    if (!checkConflict(tmp.first, minHeapStart.top().first))
                    {
                        result[tmp.second] = minHeapStart.top().second;
                    }
                }
                else result[tmp.second] = -1;
            }
            // Else consider the minHeapEnd
            else if (!minHeapEnd.empty())
            {
                pairIvInt tmp = minHeapEnd.top();
                minHeapEnd.pop();

                // if (minHeapEnd.empty())
                // {
                //     result[tmp.second] = -1;
                // }
                if (minHeapEnd.empty() || checkConflict(tmp.first, minHeapEnd.top().first))
                {
                    result[tmp.second] = -1;
                }
                else
                {
                    result[tmp.second] = minHeapEnd.top().second;
                }
            }
        }

        return result;
    }
};

#endif // SOLUTION_HPP
