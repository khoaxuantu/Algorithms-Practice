#include <bits/stdc++.h>

using namespace std;

#include "Solution.hpp"

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

//* Order-agnostic Binary Search
vector<vector<int>> OBSArr {
    {4,6,10},
    {1,2,3,4,5,6,7},
    {10,6,4},
    {10,6,4}
};
vector<int> OBSKey {10,5,10,4};
//* Ceiling of a Number
vector<vector<int>> CNArr {
    {4,6,10},
    {1,3,8,10,15},
    {4,6,10},
    {4,6,10}
};
vector<int> CNKey {6,12,17,-1};
//* Next Letter
vector<vector<char>> NLArr {
    {'a','c','f','h'},
    {'a','c','f','h'},
    {'a','c','f','h'}
};
vector<char> NLKey {'f','b','m','h'};
//* Number Range
vector<vector<int>> NRArr {
    {4,6,6,6,9},
    {1,3,8,10,15},
    {1,3,8,10,15}
};
vector<int> NRKey {6,10,12};
//* Minimum Difference Element
vector<vector<int>> MDEArr {
    {4,6,10},
    {4,6,10},
    {1,3,8,10,15}
};
vector<int> MDEKey {7,4,12};
//* Bitonic Array Maximum
vector<vector<int>> BAMArr {
    {1,3,8,12,4,2},
    {3,8,3,1},
    {1,3,8,12},
    {10,9,8}
};
//* Search Bitonic Array
vector<vector<int>> SBAArr {
    {1,3,8,4,3},
    {3,8,3,1},
    {1,3,8,12},
    {10,9,8}
};
vector<int> SBAKey {4,8,12,10};
//* Search in Rotated Array
vector<vector<int>> SRAArr {
    {10,15,1,3,8},
    {4, 5, 7, 9, 10, -1, 2}
};
vector<int> SRAKey {15,10};
//* Rotation Count
vector<vector<int>> RCArr {
    {10, 15, 1, 3, 8},
    {4, 5, 7, 9, 10, -1, 2},
    {1, 3, 8, 10}
};
vector<int> RCKey {2,5,0};

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
