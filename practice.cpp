using namespace std;

#include <bits/stdc++.h>


class Solution {
private:
public:
    static int solve(vector<int>& arr) {
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


int main(int argc, char const *argv[])
{
    /* Start and end timing */
    clock_t start, end;
    
    /* Start timing */
    start = clock();
    
    /* Example */
    // If non-constant vectors are required
    vector<int> arr1 {1, 2, 5, 3, 13, 7, 10, 9, 12};
    vector<int> arr5 {1, 2, 5, 3, 7, 10, 9, 12};
    vector<int> arr2 {1, 3, 2, 0, -1, 7, 10};
    vector<int> arr3 {1,2,3};
    vector<int> arr4 {3,2,1};
    
    // For non-vector
    cout << Solution::solve(arr1) << endl;
    cout << Solution::solve(arr5) << endl;
    cout << Solution::solve(arr2) << endl;
    cout << Solution::solve(arr3) << endl;
    cout << Solution::solve(arr4) << endl;

    // For vector
    // vector<vector<vector<int>>> example {
    //     Solution::solve(arr1, 1),
    //     Solution::solve(arr2, 2)
    // };
    // for (int i = 0; i < example.size(); i++)
    // {
    //     // Print each example
    //     cout << "{ "; // {} for more than a vector
    //     for (auto x : example[i])
    //     {
    //         // cout << x << " ";
    //         // For another vector in vector
    //         cout << "[ ";
    //         for (auto inner : x)
    //         {
    //             cout << inner << " ";
    //         }
    //         cout << "]";
    //     }
    //     cout << " }" << endl;
    // }

    /* End timing */
    end = clock();

    /* Print out time */
    double time_taken = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000;
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " ms " << endl;
    cout << endl;
}
