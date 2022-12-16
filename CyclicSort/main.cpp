using namespace std;

#include <bits/stdc++.h>


class Solution {
private:
    static void swap(vector<int>& nums, int a, int b)
    {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }

    static bool findZero(vector<int>& nums)
    {
        for (auto num : nums)
        {
            if (num == 0) return true;
        }
        return false;
    }


public:
    static vector<int> solve(vector<int>& nums, int k) {
        // TODO: Write your code here
        vector<int> missingNumbers;
        // // Find if the nums included 0
        // bool haveZero = findZero(nums);

        for (int n = 0; n < k; n++)
        {
            nums.push_back(0);
        }
        
        // Place each num into the correct index
            // Take the correct based on Zero or nonZero
            // Check if the val is in the correct index or not
            // If not then move to the next index
        int i = 0;
        while (i < nums.size())
        {
            // int j = haveZero ? nums[i] : nums[i] - 1;
            int j = nums[i] - 1;
            if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[j])
            {
                swap(nums, i, j);
            }
            else
            {
                i++;
            }
        }
        
        // Traverse the nums again and find the missing num 
        for (i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
            // int j = haveZero ? nums[i] : nums[i] - 1;
            if (nums[i] != i + 1 && missingNumbers.size() < k)
            {
                missingNumbers.push_back(i + 1);
            }
        }
        cout << endl;
        return missingNumbers;
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
    vector<int> arr1 {3, -1, 4, 5, 5}; // 0 -1 3 4 5 5 0 0
    vector<int> arr2 {2, 3, 4};
    vector<int> arr3 {-2, -3, 4};
    vector<int> arr4 {5, -2, 0, 1, 2};
    vector<int> arr5 {1, 2, 5, 3, 7, 10, 9, 12};
    
    // For non-vector
    //cout << Solution::solve(arr1) << endl;
    //cout << Solution::solve(arr2) << endl;
    //cout << Solution::solve(arr3) << endl;

    // For vector
    vector<vector<int>> example {
        Solution::solve(arr1, 3),
        Solution::solve(arr2, 3),
        Solution::solve(arr3, 2)
    };
    for (int i = 0; i < example.size(); i++)
    {
        // Print each example
        cout << "{ "; // {} for more than a vector
        for (auto x : example[i])
        {
            cout << x << " ";
            // For another vector in vector
            // cout << "[ ";
            // for (auto inner : x)
            // {
            //     cout << inner << " ";
            // }
            // cout << "]";
        }
        cout << "}" << endl;
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
