#include <bits/stdc++.h>

using namespace std;

#include "../Header/ListNode.hpp"
#include "Solution.hpp"

//* Merge K Sorted Lists
vector<vector<vector<int>>> MKSLArr {
    {
        {2,6,8}, {3,6,7}, {1,3,4}
    },
    {
        {5,8,9}, {1,7}
    }
};
//* K Smallest Number in M Sorted Lists
vector<vector<vector<int>>> KSNMSLArr {
    {
        {2,6,8}, {3,6,7}, {1,3,4}
    },
    {
        {5,8,9}, {1,7}
    }
};
vector<int> KSNMSLK {5,3};
//* Kth Smallest Number in a Sorted Matrix
vector<vector<vector<int>>> KSNSMMatrix {
    {
        {2,6,8},
        {3,7,10},
        {5,8,11}
    }
};
vector<int> KSNSMK {5};
//* Smallest Number Range
vector<vector<vector<int>>> SNRArr {
    {
        {1,5,8}, {4,12}, {7,8,10}
    },
    {
        {1,9},{4,12},{7,10,16}
    }
};
//* K Pairs With Largest Sums
vector<vector<int>> KPWLSArr1 {
    {9,8,2}, {5,2,1}
};
vector<vector<int>> KPWLSArr2 {
    {6,3,1}, {2,-1}
};
vector<int> KPWLSK {3,3};

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
