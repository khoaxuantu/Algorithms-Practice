#include <bits/stdc++.h>

using namespace std;

#include "../Header/ListNode.hpp"
#include "Solution.hpp"

//* LinkedList Cycle
    //* To create a cycle linked list
        // LinkedList newList(inputArray);
        // ListNode* root = newList.getRoot(); or ListNode* node = newList.getNthNode(N);
        // ListNode* tail = newList.getTail(root);
        // tail->next = root or node;
vector<int> LCArr {1,2,3,4,5,6};
//* Start of Linked List Cycle
vector<int> SLLCArr {1,2,3,4,5,6};
//* Happy Number
vector<int> HNArr {23,12};
//* Start of LinkedList Cycle
vector<int> SLCArr {1,2,3,4,5,6};
//* Palindrome LinkedList
vector<vector<int>> PLArr {
    {2,4,6,4,2},
    {2,4,6,4,2,2},
    {2,4,5,5,4,2}
};

int main(int argc, char * argv[])
{
    /* Start and end timing */
    clock_t start, end;
    
    /* Start timing */
    start = clock();

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