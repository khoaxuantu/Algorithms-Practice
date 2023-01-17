using namespace std;

#include <bits/stdc++.h>

#include "Solution.hpp"

//* Cyclic Sort
vector<vector<int>> CSArr {
    {3, 1, 5, 4, 2},
    {2, 6, 4, 3, 1, 5},
    {1, 5, 6, 4, 3, 2}
};
//* Find all Missing Numbers
vector<vector<int>> FAMNArr {
    {2, 3, 1, 8, 2, 3, 5, 1},
    {2, 4, 1, 2},
    {2,3,2,1}
};
//* Find the Duplicate Numbers
vector<vector<int>> FTDNArr {
    {1, 4, 4, 3, 2},
    {2, 1, 3, 3, 5, 4},
    {2, 4, 1, 4, 4}
};
//* Find all Duplicate Numbers
vector<vector<int>> FADNArr {
    {3, 4, 4, 5, 5},
    {5, 4, 7, 2, 3, 5, 3}
};
//* Find the Corrupted Pair
vector<vector<int>> FTCPArr {
    {3, 1, 2, 5, 2},
    {3, 1, 2, 3, 6, 4}
};
//* Find the Smallest Missing Positive Number
vector<vector<int>> FSMPNArr {
    {-3, 1, 5, 4, 2},
    {3, -2, 0, 1, 2}
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
