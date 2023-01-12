#include <bits/stdc++.h>

using namespace std;

#include "../Header/Interval.hpp"
#include "Solution.hpp"

//* Merge Intervals
vector<vector<Interval>> MIIntervals {
  {{1, 3}, {2, 5}, {7, 9}},
  {{6, 7}, {2, 4}, {5, 9}},
  {{1, 4}, {2, 6}, {3, 5}}
};
//* Insert Interval
vector<vector<Interval>> IIntervals {
  {{1,3},{5,7},{8,12}},
  {{1,3},{5,7},{8,12}},
  {{2,3},{5,7}}
};
vector<Interval> IINewIntervals {
  {4,6},{4,10},{1,4}
};
//* Interval Intersection
vector<vector<Interval>> IIArr1 {
  {{1, 3}, {5, 6}, {7, 9}},
  {{1, 3}, {5, 7}, {9, 12}}
};
vector<vector<Interval>> IIArr2 {
  {{2, 3}, {5, 7}},
  {{5, 10}}
};
//* Employee Free Time
vector<vector<vector<Interval>>> EFTIntervals = {
  {{{1,3}, {5,6}}, {{2,3}, {6,8}}},
  {{{1,3}, {9,12}}, {{2,4}, {6,8}}},
  {{{1,3}, {2,4}}, {{3,5}, {7,9}}}
};

int main(int argc, char *argv[]) {
    /* Start and end timing */
    clock_t start, end;

    /* Start timing */
    start = clock();

    /* Compiler switch */
    int _switch = 1;

    /**
     * TODO: Modify input here
     * TODO: Print the output
     */
    for (int i = 0; i < IINewIntervals.size(); i++) {
        InsertInterval ii(IIntervals[i], IINewIntervals[i]);
        for (auto interval : ii.solve()) {
          cout << interval.start <<"-"<< interval.end << " ";
        }
        cout << endl;
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