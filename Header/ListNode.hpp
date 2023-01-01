#if !defined(LISTNODE_HPP)
#define LISTNODE_HPP

/**
 * @brief A node of a linked list
 * 
 * @param value a node's value
 * @param next a node's next node
 */
class ListNode
{
private:
public:
    int value = 0;
    ListNode* next;
    ListNode(int val);
    ~ListNode();
};

ListNode::ListNode(int val)
{
    this->value = val;
    this->next = nullptr;
}

ListNode::~ListNode()
{}


/**
 * @brief A linked list class
 * 
 * @param root The header of the list
 */
class LinkedList
{
private:
    ListNode* root;
public:
    LinkedList() { root = nullptr; }
    LinkedList(vector<int>& arr) {
        constructFromArr(arr);
    }

    void constructFromArr(vector<int>& arr);
    ListNode* getRoot();
    ListNode* getTail(ListNode* node);
    ListNode* getNthNode(int N);
    void insert(int val, ListNode* tail);
    ~LinkedList() {}
};

void LinkedList::constructFromArr(vector<int>& arr) 
{
    root = new ListNode(arr[0]);
    ListNode* runner = root;
    for (int i = 1; i < arr.size(); i++) {
        runner->next = new ListNode(arr[i]);
        runner = runner->next;
    }
    runner = nullptr;
    delete runner;
}

ListNode* LinkedList::getRoot()
{
    return root;
}

ListNode* LinkedList::getTail(ListNode* node)
{
    ListNode* runner = node;
    while (runner->next) {
        runner = runner->next;
    }
    return runner;
}

ListNode* LinkedList::getNthNode(int N)
{
    ListNode* runner = root;
    for (int i = 1; i < N; i++) {
        try
        {
            if (runner->next) {
                runner = runner->next;
            }
            else throw("Exceed the list's node numbers");
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            cout << "Node numbers are: " << i << endl;
        }
    }
    return runner;
}

void LinkedList::insert(int val, ListNode* tail) 
{
    tail->next = new ListNode(val);
}

#endif // LISTNODE_HPP
