#if !defined(LISTNODE_HPP)
#define LISTNODE_HPP

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
{
}

#endif // LISTNODE_HPP
