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
 * @brief Insert Interval
 * 
 * @param intervals A list of non-overlapping intervals
 * @param newInterval A new interval to be inserted
 * 
 * @return :vector<Interval>: The new list after inserting
 */
class InsertInterval
{
private:
    vector<Interval> intervals;
    Interval newInterval;
    bool isOverlap(Interval& x, Interval& y) {
        return (x.start < y.start && x.end > y.start) ||
               (y.start < x.start && y.end > x.start);
    }
public:
    InsertInterval(vector<Interval>& intervals, Interval& newInterval) :
        intervals(intervals), newInterval(newInterval) {}
    vector<Interval> solve() {
        vector<Interval> ans;
        int i = 0;
        while (i < intervals.size()) {
            if (isOverlap(intervals[i], newInterval)) {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
            else if (intervals[i].end <= newInterval.start) {
                ans.push_back(intervals[i]);
            }
            else if (intervals[i].start >= newInterval.end) {
                ans.push_back(newInterval);
                newInterval = {-1,-1};
                break;
            }
            i++;
        }
        if (newInterval.start != -1 && newInterval.end != -1) ans.push_back(newInterval);
        while (i < intervals.size()) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};


/**
 * @brief Interval Intersection
 * 
 * @param arr1 The 1st interval list (disjoint intervals sorted on their start time)
 * @param arr2 The 2nd interval list (  ""  ""  ""  ""  ""  ""  ""  ""  ""  ""  "" )
 * 
 * @return :vector<Interval>: The intersection between 2 lists
 */
class IntervalsIntersection
{
private:
    vector<Interval> arr1;
    vector<Interval> arr2;
    bool isOverlap(Interval& x, Interval& y) {
        if ((x.start <= y.start && x.end >= y.start) || 
            (x.start >= y.start && x.start <= y.end)) return true;
        return false;
    }
public:
    IntervalsIntersection(vector<Interval>& arr1, vector<Interval>& arr2) :
        arr1(arr1), arr2(arr2) {}
    vector<Interval> solve() {
        vector<Interval> ans;
        int i = 0, j = 0;
        Interval tmp(0,0);
        while (i < arr1.size() && j < arr2.size()) {
            if (isOverlap(arr1[i], arr2[j])) {
                tmp.start = max(arr1[i].start, arr2[j].start);
                tmp.end = min(arr1[i].end, arr2[j].end);
                ans.push_back(tmp);
            }
            if (arr2[j].end > arr1[i].end) i++;
            else j++;
        }
        return ans;
    }
};


/**
 * @brief Conflicting Appointment
 * 
 * @param intervals An array of intervals representing "N" appointments
 * 
 * @return :boolean: If a person can attend all the appoinments
 */
class ConflictingAppointments
{
private:
    vector<Interval> intervals;
public:
    ConflictingAppointments(vector<Interval>& intervals) : intervals(intervals) {}
    bool solve() {
        sort(intervals.begin(), intervals.end(), 
             [](Interval& x, Interval& y){ return x.start < y.start; });
        for (int i = 0; i < intervals.size()-1; i++) {
            if (intervals[i].end > intervals[i+1].start) return false;
        }
        return true;
    }
};


/**
 * @brief Minimum Meeting Rooms
 * 
 * @param meetings A list of intervals representing the start and the end
 * of "N" meetings
 * 
 * @return :int: The minimum number of rooms required to hold all the meetings 
 */
class MinimumMeetingRooms
{
private:
    vector<Interval> meetings;
public:
    MinimumMeetingRooms(vector<Interval> intervals) :
        meetings(intervals) {}
    int solve() {
        // TODO: Write your code here
        if (meetings.size() == 0) return 0;
        int ans = 1;
        // Sort the intervals first
        sort(meetings.begin(), meetings.end(),
            [] (const Interval& x, const Interval& y) { return x.start < y.start; });
        // Start with the earlist meeting
        // Check whether the following overlaps with the consideringMeeting i.e curMeeting
        // When reach the non-ovelapped meeting, update the room to the ans (Max)
        // Check if the meeting overlaps with the prev meeting
        // If yes, move the pointer to the prev meeting
        // Else move to the meeting
        int curMeeting = 0;
        while (curMeeting < meetings.size())
        {
            // cout << "(" << curMeeting << ") ";
            int countRoom = 1;
            int pointer = curMeeting + 1;
            while (pointer < meetings.size() && meetings[pointer].start < meetings[curMeeting].end)
            {
                countRoom++;
                pointer++;
                // cout << pointer << " ";
            }
            //cout << "| ";
            
            int curEndpoint;
            if (pointer < meetings.size()) curEndpoint = pointer;
            else curEndpoint = pointer - 1;

            int tmpPoint = curEndpoint - 1;
            while (tmpPoint != curMeeting && meetings[curEndpoint].start <= meetings[tmpPoint].end)
            {
                if (meetings[curEndpoint].start == meetings[tmpPoint].end) countRoom--;
                //cout << tmpPoint << ":" << countRoom << " ";
                tmpPoint--;
            }
            ans = max(countRoom, ans);
            if (pointer == meetings.size()) 
            {
                break;
            }
            curMeeting = tmpPoint + 1;
        }
        return ans;
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
