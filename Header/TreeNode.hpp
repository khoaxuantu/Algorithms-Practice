#if !defined(TREENODE_HPP)
#define TREENODE_HPP

class TreeNode
{
private:
public:
    int val = 0;
    TreeNode* left, *right;
    // Below data members used only for some of the problems
    TreeNode* parent, *next;
    int count;

    TreeNode(int val);

    static void printTree(TreeNode* root)
    {
        if(!root) return;
        // Inorder
        printTree(root->left);

        std::cout << root->val << " ";

        printTree(root->right);
    }

    ~TreeNode();
};

TreeNode::TreeNode(int val)
{
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->next = nullptr;
    this->count = 0;
}

TreeNode::~TreeNode() {}


#endif // TREENODE_HPP
