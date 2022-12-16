#include <bits/stdc++.h>

using namespace std;

class ArrayReader {
public:
    vector<int> arr;

    ArrayReader(const vector<int> &arr) { this->arr = arr; }

    virtual int get(int index) {
        if (index >= arr.size()) {
        return numeric_limits<int>::max();
        }
        return arr[index];
    }
};


class Solution
{
private:
    

public:
    static int solve(const vector<int>& arr)
    {
        // TODO: Write your code here
        // If the first element is larger than the last one, return 0
        int start = 0, end = arr.size() - 1;
        if (arr[start] < arr[end]) return 0;
        // Perform the binary search pattern

        // Take start, end
            // Cal mid
            // If mid <= end, mid = end
            // IF mid > end, mid = start
        int mid;
        while (start < end)
        {
            mid = start + (end-start)/2;

            if (arr[mid] <= arr[end]) end = mid;
            else start = mid+1;
        }
        
        return start;
    }
};

int main(int argc, char const *argv[])
{
    /* Start and end timing */
    clock_t start, end;
    
    /* Start timing */
    start = clock();

    cout << Solution::solve(vector<int>{10, 15, 1, 3, 8}) << endl;
    cout << Solution::solve(vector<int>{4, 5, 7, 9, 10, -1, 2}) << endl;
    cout << Solution::solve(vector<int>{1, 3, 8, 10}) << endl;
    
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
