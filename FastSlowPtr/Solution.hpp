#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

/**
 * @brief Linked List Cycle
 * 
 * @param head The head of a Singly Linked List
 * 
 * @return :boolean: If the linked list has a cycle in it or not
 */
class LinkedListCycle
{
private:
    ListNode* head;
public:
    LinkedListCycle(ListNode* root) : head(root) {}
    bool solve() {
        // TODO: Write your code here
        // Initialize 2 pointers, one runs 1 step and one runs 2 steps
        ListNode* fastptr = head; 
        ListNode* slowptr = head;
        // Traverse the list, will end if there is no cycle (i.e pointer reaches null)
        // Firstly, increment the pointers
        // For each iter, check if fastptr == slowptr
            // If yes, return true
        while (fastptr != NULL && fastptr->next != NULL)
        {
            fastptr = fastptr->next->next;
            slowptr = slowptr->next;
            if (fastptr == slowptr)
            {
                return true;
            }
        }
        return false;
    }
};

#endif // SOLUTION_HPP
