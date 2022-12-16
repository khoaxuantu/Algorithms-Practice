#include <bits/stdc++.h>

using namespace std;


class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval (int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class MergeIntervals {
 private:
  

 public:
  static vector<Interval> merge(vector<vector<Interval>> &schedule) {
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

int main(int argc, char *argv[]) {
  /* Start and end timing */
    clock_t start, end;
    
    /* Start timing */
    start = clock();
    
  /* Example */
  vector<vector<vector<Interval>>> input = {
    {{{1,3}, {5,6}}, {{2,3}, {6,8}}},
    {{{1,3}, {9,12}}, {{2,4}, {6,8}}},
    {{{1,3}, {2,4}}, {{3,5}, {7,9}}}
  };
  cout << "Merged intervals:\n";
  for (auto arr : input)
  {
    for (auto interval : MergeIntervals::merge(arr))
    {
      cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;
    // cout << MergeIntervals::merge(arr) << endl;
  }

  /* End timing */
    end = clock();

    /* Print out time */
    double time_taken = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000;
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " ms " << endl;
    cout << endl;
}