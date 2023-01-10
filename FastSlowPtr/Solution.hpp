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


/**
 * @brief Start of LinkedList Cycle
 * TODO: Rewrite the solution
 * 
 * @param head The head of a Linked List that contains cycle
 * 
 * @return :ListNode: the starting node of the cycle
 */
class LinkedListCycleStart
{
private:
    ListNode* head;
public:
    LinkedListCycleStart(ListNode* root) : head(root) {}
    ListNode* solve() {
        // TODO: Write your code here
        return head;
    }
};


/**
 * @brief Happy Number
 * 
 * @param num An input number
 * 
 * @return :boolean: If the number is a happy number. A number will be called
 * a happy number if, after repeatedly replacing it with a number equal to 
 * the sum of the square of all digits, lead us to number '1' 
 */
class HappyNumber
{
public:
    int num;
    int cal(int n)
    {
        int result = 0;
        do
        {
            int digit = n % 10;
            result += digit * digit;
            n /= 10;
        } while (n != 0);
        return result;
    }
private:
    HappyNumber(int input) : num(input) {}
    bool solve() {
        // TODO: Write your code here
        // Initialize 2 pointer for the num
        // One cals 2 tikmes, one cals 1 time
        int slow = num, fast = num;
        // Run until both btr is equality
        // If find a ptr to be 1, return true
        do
        {
            slow = cal(slow);
            fast = cal(cal(fast));
            if (slow == 1 || fast == 1) return true;
        } while (slow != fast);
        return false;
    }
};


/**
 * @brief Middle of the LinkedList
 * 
 * @param head The head of a Singly Linked List
 * 
 * @return :ListNode: The middle node of the linked list
 */
class MiddleOfLinkedList
{
private:
    ListNode* head;
public:
    MiddleOfLinkedList(ListNode* root) : head(root) {}
    ListNode* solve() {
        // TODO: Write your code here
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }   
        return slow;
    }
};


/**
 * @brief Palindrome LinkedList
 * 
 * @param head The head of a Singly Linked List
 * 
 * @return :boolean: If the linked list is a palindrome
 */
class PalindromicLinkedList
{
private:
    ListNode* head;
    ListNode *slow;
    bool check(ListNode* fast)
    {
        bool checkValue;
        // Return if the fast reach nullptr
        if (fast == slow || fast == slow->next) return true;
        if (fast == nullptr) return true;
        // Call stack
        checkValue = check(fast->next);
        cout << slow->value << "," << fast->value << " ";
        if (checkValue == false) 
        {
            slow = slow->next;
            return false;
        }
        // If fast != slow, return false
        // If fast = slow, move slow to the next node
        if (fast->value != slow->value)
        {
            checkValue = false;
        }
        slow = slow->next;

        return checkValue;  
    }
public:
    PalindromicLinkedList(ListNode* root) : head(root) {}
    bool solve() {
        // TODO: Write your code here
        // Find the middle of the list
        if (head->next != nullptr && head->next->next == nullptr)
        {
          if (head->value == head->next->value) return true;
          else return false;
        }
        ListNode *fast = head, *mid = head;
        slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            mid = mid->next;
        }
        cout << mid->value << " ";
        // Call stack the fast ptr
        return check(mid);
    }
};


/**
 * @brief Rearrange a LinkedList
 * 
 * @param head The head of a Singly Linked List
 * 
 * @return :ListNode: the list after modified such that the nodes
 * from the second half of the LinkedList are inserted alternately 
 * to the nodes from the first half in reverse order
 */
class RearrangeList
{
private:
    ListNode* head;
    ListNode* reverse(ListNode* root)
    {
        ListNode* tail = root;
        while (tail->next != nullptr)
        {
            ListNode* nextNode = tail->next;
            tail->next = nextNode->next;
            nextNode->next = root;
            root = nextNode;
        }
        return root;
    }
public:
    RearrangeList(ListNode* root) : head(root) {}
    ListNode* solve() {
        // TODO: Write your code here    
        // Should not use any extra place
        if (head == nullptr || head->next == nullptr) return;
        // Find the middle node
        ListNode *mid = head, *beforemid;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            beforemid = mid;
            fast = fast->next->next;
            mid = mid->next;
        }
        
        // From the middle node, reverse the nodes
        beforemid->next = reverse(mid);
        mid = beforemid->next;
        // From the middle node after reverse, insert to the first half nodes
        ListNode *firstHalf = head;
        while (mid->next != nullptr)
        {
            ListNode *curNode = mid;
            mid = mid->next;
            beforemid->next = mid;

            ListNode *nextFirstHalf = firstHalf->next; //8
            curNode->next = nextFirstHalf; //8
            firstHalf->next = curNode;
            firstHalf = nextFirstHalf;
        }
        return head;
    }
};


/**
 * @brief Circle in a Circular Array
 * 
 * @param arr An array containing positive and negative number
 * 
 * @return :boolean: If the array has a cycle
 */
class CircularArrayLoop
{
private:
    vector<int> arr;
    int moveIndex(int index, const vector<int>& arr, bool& makeCycle)
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
    CircularArrayLoop(vector<int>& inputArr) : arr(inputArr) {}
    bool solve() {
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

#endif // SOLUTION_HPP
