#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

/**
 * @brief Reverse a Linked List
 * 
 * @param head The head of a singly linked list
 * 
 * @return :ListNode: A new head of the reversed linked list
 */
class ReverseLinkedList
{
private:
    ListNode* head;
public:
    ReverseLinkedList(ListNode* root) : head(root) {}
    ListNode* solve() {
        // TODO: Write your code here
        ListNode* tail = head;
        while (tail->next != nullptr)
        {
        ListNode* nextNode = tail->next;
        tail->next = nextNode->next;
        nextNode->next = head;
        head = nextNode;
        }
        return head;
    }
};


/**
 * @brief Reverse a Sub-list
 * 
 * @param head The head of a singly linked list
 * @param p position 'p'
 * @param q position 'q'
 * 
 * @return :ListNode: The head of the linked list after reversing 
 * from 'p' to 'q'
 */
class ReverseSubList
{
private:
    ListNode* head;
    int p;
    int q;
public:
    ReverseSubList(ListNode* root, int p, int q) : head(root), p(p), q(q) {}
    ListNode* solve() {
        // TODO: Write your code here
        // Initialize a tail node
            // Run to the pth node
            // Start travesing in this node in q-p+1 times
        ListNode* subHead = head;
        ListNode* prevSubHead = head;
        for (int i = 0; i < p - 1; i++)
        {
            if (i == p - 2) prevSubHead = subHead;
            subHead = subHead->next;
        }

        int steps = q - p;
        ListNode* tail = subHead;
        ListNode* nextNode;
        while (tail->next != nullptr && steps > 0)
        {
            nextNode = tail->next;
            tail->next = nextNode->next;
            nextNode->next = subHead;
            subHead = nextNode;

            prevSubHead->next = nextNode;
            
            steps--;
        }
        
        // cout << subHead->value << endl;
        return head;
    }
};


/**
 * @brief Reverse every K-element Sub-list
 * 
 * @param head The head of a singly linked list
 * @param k An input number 'k'
 * 
 * @return :ListNode: The head after reversing every 'k' size sub-list
 * starting from the head. If, in the end, you are left with a sub-list
 * which less than 'k' nodes, reverse it too
 */
class ReverseEveryKElements
{
private:
    ListNode* head;
    int k;
    void reverseSubList(ListNode*& head, int k, int start)
    {
        // Set the times that needed to perform traversing
        k--;
        // Move the substart to the wanted node (start position)
        ListNode* subStart = head;
        ListNode* prevSubStart = nullptr;
        for (int i = 0; i < start - 1; i++)
        {
            if (i == start - 2) prevSubStart = subStart;
            subStart = subStart->next;
        }
        // cout << "Call " << endl;
        // Start reversing, check whether the tail->next is not null and have not stepped k-1 times
            // Take a next node of the tail node
            // Point the tail node to next next node
            // Point the next node to the substart node
            // Connect the prevSubStart node to the next node
            // Update the substart node
        ListNode* tail = subStart;
        ListNode* nextNode;
        while (tail->next != nullptr && k > 0)
        {
            nextNode = tail->next;
            tail->next = nextNode->next;
            nextNode->next = subStart;

            if (prevSubStart) prevSubStart->next = nextNode;
            subStart = nextNode;

            k--;
        }
        if (start == 1) head = subStart;        
    }
public:
    ReverseEveryKElements(ListNode* root, int k) : head(root), k(k) {}
    ListNode* solve() {
        // TODO: Write your code here
        // Count the num of nodes
        int countNode = 0;
        ListNode* cur = head;
        while (cur != NULL)
        {
            countNode++;
            cur = cur->next;
        }
        
        // Initialize the first node of a sublist
            // For the fist list it is the 1st node
        // Iterate every (firstNode + k)th node
            // Call a func to iterate a sublist
        int startNode = 1;
        while (startNode < countNode)
        {
            reverseSubList(head, k, startNode);
            startNode += k;
        }

        return head;
    }
};


/**
 * @brief Reverse alternating K-element Sub-list
 * 
 * @param head The head of a singly linked list
 * @param k An input number 'k'
 * 
 * @return :ListNode: The head after reversing every alternating 'k' size
 * sub-list starting from the head
 */
class ReverseAlternatingKElements
{
private:
    ListNode* head;
    int k;
    void reverseSubList(ListNode*& head, int k, int start)
    {
        // Set the times that needed to perform traversing
        k--;
        // Move the substart to the wanted node (start position)
        ListNode* subStart = head;
        ListNode* prevSubStart = nullptr;
        for (int i = 0; i < start - 1; i++)
        {
            if (i == start - 2) prevSubStart = subStart;
            subStart = subStart->next;
        }
        // cout << "Call " << endl;
        // Start reversing, check whether the tail->next is not null and have not stepped k-1 times
            // Take a next node of the tail node
            // Point the tail node to next next node
            // Point the next node to the substart node
            // Connect the prevSubStart node to the next node
            // Update the substart node
        ListNode* tail = subStart;
        ListNode* nextNode;
        while (tail->next != nullptr && k > 0)
        {
            nextNode = tail->next;
            tail->next = nextNode->next;
            nextNode->next = subStart;

            if (prevSubStart) prevSubStart->next = nextNode;
            subStart = nextNode;

            k--;
        }
        if (start == 1) head = subStart;
    }
public:
    ReverseAlternatingKElements(ListNode* root, int k) : head(root), k(k) {}
    ListNode* root() {
        // TODO: Write your code here
        // Count the num of nodes
        int countNode = 0;
        ListNode* cur = head;
        while (cur != NULL)
        {
            countNode++;
            cur = cur->next;
        }
        
        // Initialize the first node of a sublist
            // For the fist list it is the 1st node
        // Iterate every (firstNode + k)th node
            // Call a func to iterate a sublist
        int startNode = 1;
        while (startNode < countNode)
        {
            if (startNode + k > countNode) break;
            reverseSubList(head, k, startNode);
            startNode += k + k;
        }
        return head;
    }
};


/**
 * @brief Rotate a Linked List
 * 
 * @param head The head of a singly linked list
 * @param k An input number 'k'
 * 
 * @return :ListNode: the head after rotate to the right by 'k' nodes
 */
class RotateList
{
private:
    ListNode* head;
    int k;
public:
    RotateList(ListNode* root, int k) : head(root), k(k) {}
    ListNode* solve() {
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

#endif // SOLUTION_HPP
