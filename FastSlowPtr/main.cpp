#include <bits/stdc++.h>

using namespace std;


class ListNode
{
private:
    /* data */
public:
    int value = 0;
    ListNode* next;
    ListNode(int value) : value(value), next(nullptr) {}
};

static ListNode *slow;
class LinkedList
{
private:
    static int moveIndex(int index, const vector<int>& arr, bool& makeCycle)
    {
        int M = arr[index];

        if (M > 0)
        {
            for (int i = 0; i < M; i++)
            {
                index++;
                if (index > arr.size()-1)
                {
                    index = 0;
                    makeCycle = true;
                }
            }
        }
        else if (M < 0)
        {
            for (int i = M; i < 0; i++)
            {
                index--;
                if (index < 0)
                {
                    index = arr.size() - 1;
                    makeCycle = true;
                }
            }
        }

        return index;
    }


public:
    static bool solve(const vector<int>& arr)
    {
        // TODO: Write your code here
        // initialize 2 ptr, one moves 1 step, one moves 2 steps each iter
        int ptrSlow = 0, ptrFast = 0;
        // Run the 2 ptrs until one of them (ptrFast) exceed the scope of the arr
            // If ptrSlow = ptrFast return true
        bool makeCycle = false;
        do
        {
            ptrSlow = moveIndex(ptrSlow, arr, makeCycle);
            ptrFast = moveIndex(moveIndex(ptrFast, arr, makeCycle), arr, makeCycle);
            // cout << ptrSlow << "," << ptrFast << " ";
            if (ptrSlow == ptrFast)
            {
                if (makeCycle == true) return true;
                else break;
            }

        } while (ptrFast >= 0 || ptrFast < arr.size());
        
        return false;
    }
};


int main(int argc, char * argv[])
{
    /* Start and end timing */
    clock_t start, end;
    
    /* Start timing */
    start = clock();

    /* Creating link lists required */
    //ListNode *head = new ListNode(2);
    // head->next = new ListNode(4);
    // head->next->next = new ListNode(6);
    // head->next->next->next = new ListNode(8);
    // head->next->next->next->next = new ListNode(10);
    // head->next->next->next->next->next = new ListNode(12);
    // LinkedList::solve(head);
    // while (head != nullptr) {
    //     cout << head->value << " ";
    //     head = head->next;
    // }
    // head->next->next->next->next->next->next = new ListNode(7);

    // head->next->next->next->next->next->next = head->next->next;
    // cout << "LinkedList has cycle: " << LinkedList::solve(head)->value << endl;

    // head->next->next->next->next->next->next = head->next->next->next;
    // cout << "LinkedList has cycle: " << LinkedList::solve(head)->value << endl;

    // head->next->next->next->next->next->next = head;
    // cout << "LinkedList has cycle: " << LinkedList::solve(head)->value << endl;


    /* Non-linked-list input */
    cout << boolalpha << LinkedList::solve(vector<int>{1, 2, -1, 2, 2}) << endl;
    cout << boolalpha << LinkedList::solve(vector<int>{2, 2, -1, 2}) << endl;
    cout << boolalpha << LinkedList::solve(vector<int>{2, 1, -1, -2}) << endl;

    /* End timing */
    end = clock();

    /* Print out time */
    double time_taken = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000;
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " ms " << endl;
    cout << endl;
}