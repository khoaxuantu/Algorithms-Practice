#include <bits/stdc++.h>

using namespace std;

#include "../Header/ListNode.hpp"
#include "Solution.hpp"

//* Reverse a Linked List
vector<vector<int>> RLLArr {
    {2,4,6,8,10}
};
//* Reverse a Sub-list
vector<vector<int>> RSArr {
    {1,2,3,4,5}, {1}, {1,2}
};
vector<int> RSp {2};
vector<int> RSq {4};
//* Reverse every K-element Sub-list
vector<vector<int>> RKSArr {
    {1,2,3,4,5,6,7,8}
};
vector<int> RKSk {3};
//* Reverse alternating K-element Sub-list
vector<vector<int>> RAKSArr {
    {1,2,3,4,5,6,7,8}
};
vector<int> RAKSk {2};
//* Rotate a Linked List
vector<vector<int>> RLArr {
    {1,2,3,4,5,6},
    {1,2,3,4,5}
};
vector<int> RLk {3, 8};

int main(int argc, char * argv[])
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