#include <bits/stdc++.h>

#include "../Header/Interval.hpp"

// Macro
#define pairInt pair<int, int>
#define pairIvInt pair<Interval, int>

using namespace std;

class Solution
{
private:
    int streamL = 0;
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;

    bool checkConflict(const Interval& base, const Interval& checked)
    {
        if (base.start >= checked.end || base.end <= checked.start)
        {
            return false;
        }
        return true;
    }

public:
    // Solving problem
    // index = nextInterval.start - curInterval.start
    // If no nextInterval => index = -1
    // min 5,6:2
    // max 
    // 1, 2, -1
    vector<int> solve(const vector<Interval> &intervals)
    {
        int n = intervals.size();
        vector<int> result(n);
        // TODO: Write your code here
        // Initialize 2 heaps
            // Non-conflicted with the 0-index interval => minHeap of starting time
            // The conflicted one => minHeap of ending time
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


int main(int argc, char const *argv[])
{
    /* Start and end timing */
    clock_t start, end;
    
    /* Start timing */
    start = clock();
    cout << endl;
    
    Solution solution;
    vector<Interval> intervals = {{2, 3}, {3, 4}, {5, 6}};
    vector<int> result = solution.solve(intervals);
    for (auto index : result) {
        cout << index << " ";
    }
    cout << endl << endl;

    intervals = {{3, 4}, {1, 5}, {4, 6}};
    result = solution.solve(intervals);
    for (auto index : result) {
        cout << index << " ";
    }
    cout << endl << endl;

    intervals = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
    result = solution.solve(intervals);
    for (auto index : result) {
        cout << index << " ";
    }
    cout << endl << endl;

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
