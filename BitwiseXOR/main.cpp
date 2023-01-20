#include <bits/stdc++.h>

using namespace std;

#include "Solution.hpp"

//* Single Number
vector<vector<int>> SNArr {
    {1, 4, 2, 1, 3, 2, 3},
    {7,9,7}
};
//* Two Single Number
vector<vector<int>> TSNArr {
    {1, 4, 2, 1, 3, 5, 6, 2, 3, 5},
    {2, 1, 3, 2}
};
//* Complement of Base 10 Number
vector<int> CBNNums {8,10};
//* Flip and Invert Image
vector<vector<vector<int>>> FIIArr {
    {
        {1,0,1},
        {1,1,1},
        {0,1,1}
    },
    {
        {1,1,0,0},
        {1,0,0,1},
        {0,1,1,1},
        {1,0,1,0}
    }
};

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
