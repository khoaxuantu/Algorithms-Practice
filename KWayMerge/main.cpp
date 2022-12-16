#include <bits/stdc++.h>

#include "../Header/ListNode.hpp"

#define pairMatrix pair<int, pair<int,int>>  // <nums, maximum avail sum<nums2Index, sum>>

using namespace std;


class Solution
{
public:
    static vector<pair<int, int>> solve(const vector<int>& nums1, const vector<int>& nums2, int k)
    {
        // TODO: Write your code here
        vector<pair<int, int>> result;
        // Init a maxHeap to keep track the nums <nums, maximum avail sum<nums2Index, sum>>
        // Only push element from nums1 to the heap
        // Keep track the maximum avail sum for each num
        auto custCmp = [](const pairMatrix& x, const pairMatrix& y){
            return x.second.second < y.second.second;
        };
        priority_queue<pairMatrix, vector<pairMatrix>, decltype(custCmp)> maxHeap(custCmp);
        // Add the elements of the nums1 list // 9 8 2       
        for (auto n : nums1)
        {
            maxHeap.push(make_pair(n, make_pair(0, n + nums2[0])));
        }
        // Traverse the heap
        // For each num, pop out of the heap
        // Push to the result
        // nums2Index++
        // If nums2Index < nums2 size, push back to the heap
        while (!maxHeap.empty())
        {
            auto curSum = maxHeap.top();
            maxHeap.pop();
            result.push_back(make_pair(curSum.first, nums2[curSum.second.first]));
            k--;
            if (k == 0) break;

            curSum.second.first++;
            int nums2Index = curSum.second.first;
            if (nums2Index < nums2.size())
            {
                curSum.second.second = curSum.first + nums2[nums2Index];
                maxHeap.push(curSum);
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
    
    auto result = Solution::solve({9, 8, 2}, {6, 3, 1}, 3);
    cout << "Pairs with largest sum are: ";
    for (auto pair : result) {
        cout << "[" << pair.first << ", " << pair.second << "] ";
    }cout << endl;
    
    result = Solution::solve({5,2,1}, {2,-1}, 3);
    cout << "Pairs with largest sum are: ";
    for (auto pair : result) {
        cout << "[" << pair.first << ", " << pair.second << "] ";
    }cout << endl;

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
