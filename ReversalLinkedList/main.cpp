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


class LinkedList
{
private:
    


public:
    static ListNode* solve(ListNode* head, int k)
    {
        // TODO: Write your code here
        // Update the k if it is larger than number of nodes
        int countNode = 0;
        ListNode* cur = head;
        while (cur != NULL)
        {
           cur = cur->next;
           countNode++;
        }
        if (k % countNode != 0 && k > countNode) k -= k/countNode;
        
        // Store the tail node
        ListNode* tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
        
        // Reverse the list by k nodes
        ListNode* nextNode;
        while (k > 0)
        {
            nextNode = head->next;
            tail->next = head;
            head->next = nullptr;

            tail = head;
            head = nextNode;
            k--;
        }

        return head;
    }
};


int main(int argc, char * argv[])
{
    /* Start and end timing */
    clock_t start, end;
    
    /* Start timing */
    start = clock();

    /* Creating link lists required */
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next = new ListNode(6);
    // head->next->next->next->next->next->next = new ListNode(7);
    // head->next->next->next->next->next->next->next = new ListNode(8);
    ListNode* result = LinkedList::solve(head, 5);
    result = LinkedList::solve(head, 8);
    while (result != nullptr) {
        cout << result->value << " ";
        result = result->next;
    }
    cout << endl;
    // head->next->next->next->next->next->next = new ListNode(7);

    // head->next->next->next->next->next->next = head->next->next;
    // cout << "LinkedList has cycle: " << LinkedList::solve(head)->value << endl;

    // head->next->next->next->next->next->next = head->next->next->next;
    // cout << "LinkedList has cycle: " << LinkedList::solve(head)->value << endl;

    // head->next->next->next->next->next->next = head;
    // cout << "LinkedList has cycle: " << LinkedList::solve(head)->value << endl;


    /* Non-linked-list input */
    // cout << boolalpha << LinkedList::solve(vector<int>{1, 2, -1, 2, 2}) << endl;
    // cout << boolalpha << LinkedList::solve(vector<int>{2, 2, -1, 2}) << endl;
    // cout << boolalpha << LinkedList::solve(vector<int>{2, 1, -1, -2}) << endl;

    /* End timing */
    end = clock();

    /* Print out time */
    double time_taken = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000;
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " ms " << endl;
    cout << endl;
}