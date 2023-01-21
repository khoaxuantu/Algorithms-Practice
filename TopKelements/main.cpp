#include <bits/stdc++.h>

#include "../Header/Point.hpp"
#include "Solution.hpp"

using namespace std;

//* Top K Numbers
vector<vector<int>> TKNArr {
    {3,1,5,12,2,11},
    {5,12,11,-1,12}
};
vector<int> TKNK {3,3};
//* Kth Smallest Number
vector<vector<int>> KSNArr {
    {1, 5, 12, 2, 11, 5},
    {1, 5, 12, 2, 11, 5},
    {5,12,11,-1,12}
};
vector<int> KSNK {3,4,3};
//* K Closet Point to the Origin
vector<vector<Point>> KCPOArr {
    {{1,2},{1,3}},
    {{1,3},{3,4},{2,-1}}
};
vector<int> KCPOK {1,2};
//* Connect Ropes
vector<vector<int>> CRArr {
    {1,3,11,5},
    {3,4,5,6},
    {1,3,11,5,2}
};
//* Top K Frequent Numbers
vector<vector<int>> TKFNArr {
    {1, 3, 5, 12, 11, 12, 11},
    {5,12,11,3,11}
};
vector<int> TKFNK {2,2};
//* Frequency Sort
vector<string> FSStr {
    "Programming", "abcbab"
};
//* Kth Largest Number in a Stream
vector<vector<int>> KLNSArr {
    {3,1,5,12,2,11}
};
vector<int> KLNSK {4};
//* K Closet Numbers
vector<vector<int>> KCNArr {
    {5,6,7,8,9},
    {2,4,5,6,9},
    {2,4,5,6,9}
};
vector<int> KCNK {3,3,3};
vector<int> KCNX {7,6,10};
//* MAximum Distinct Elements
vector<vector<int>> MDEArr {
    {7, 3, 5, 8, 5, 3, 3},
    {3,5,12,11,12},
    {1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5}
};
vector<int> MDEK {2,3,2};
//* Sum of Elements
vector<vector<int>> SEArr {
    {1, 3, 12, 5, 15, 11},
    {3,5,8,7}
};
vector<int> SEK1 {3,1};
vector<int> SEK2 {6,4};
//* Rearrange String
vector<string> RSStr {
    "aappp", "Programming", "aapa"
};
//* Rearrange String K Distance Apart
vector<string> RSKDAStr {
    "mmpp", "Programming", "aab", "aappa"
};
vector<int> RSKDAK {2,3,2,3};
//* Scheduling Tasks
vector<vector<char>> STTasks {
    {'a','a','a','b','c','c'},
    {'a','b','a'}
};
vector<int> STCd {2,3};

int main(int argc, char const *argv[])
{
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
    
    
    /* End timing */
    end = clock();
    
    /* Print out time */
    double time_taken = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000;
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " ms " << endl;
    cout << endl;
}
