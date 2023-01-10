#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP


/**
 * @brief Merge Intervals
 * 
 * @param intervals A list of intervals
 * 
 * @return :vector<Interval>: the list after mergeing the overlapping intervals
 */
class MergeIntervals
{
private:
    vector<Interval> intervals;
public:
    MergeIntervals(vector<Interval>& input) : intervals(input) {}
    vector<Interval> solve() {
        vector<Interval> mergedIntervals;
        // TODO: Write your code here
        sort(intervals.begin(), intervals.end(),
            [](const Interval &x, const Interval &y) { return x.start < y.start; });
        Interval interval = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (interval.end <= intervals[i].start) {
                mergedIntervals.push_back(interval);
                interval = intervals[i];
            }
            else {
                interval.end = max(interval.end, intervals[i].end);
            }
        }
        mergedIntervals.push_back(interval);
        return mergedIntervals;
    }
};


/**
 * @brief Employee Free Time 
 * 
 * @param schedule  A list of intervals representing the working hours
 * of each employee
 * 
 * @return :vector<Interval>: the free intervals that is common to all
 * employees
 */
class EmployeeFreeTime
{
public:
    vector<vector<Interval>> schedule;
private:
    EmployeeFreeTime(vector<vector<Interval>>& input) : schedule(input) {}
    vector<Interval> solve() {
        vector<Interval> ans;
        // Initialize a minHeap of the endtime
        auto custCompare = [&] (const Interval& x, const Interval& y) { return x.end > y.end; };
        priority_queue<Interval, vector<Interval>, decltype(custCompare)> minHeap (custCompare);
        // Push the schedule of every employee into the heap
        for (auto employee : schedule)
        {
        for (auto time : employee)
        {
            minHeap.push(time);
        }
        }
        // Traverse the heap until it is empty
        // In each iter, pop out the top as the cur
        // cur.end < heap.top.start
            // Push into the ans
        while (!minHeap.empty())
        {
        Interval curTime = minHeap.top();
        minHeap.pop();

        if (curTime.end < minHeap.top().start)
        {
            ans.push_back({curTime.end, minHeap.top().start});
        }
        }
        return ans;
    }
};

#endif // SOLUTION_HPP
