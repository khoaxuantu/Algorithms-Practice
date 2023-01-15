using namespace std;

#include <bits/stdc++.h>

#include "Solution.hpp"

//* Cyclic Sort
vector<vector<int>> CSArr {
    {3, 1, 5, 4, 2},
    {2, 6, 4, 3, 1, 5},
    {1, 5, 6, 4, 3, 2}
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
