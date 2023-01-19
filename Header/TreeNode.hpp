#if !defined(TREENODE_HPP)
#define TREENODE_HPP

/**
 * @brief A node of a binary tree
 * 
 * @param val Node's value
 * @param left Pointer pointing to the left children node
 * @param right Pointer pointing to the right children node
 * @param parent Pointer pointing to the parent node
 * @param next Pointer pointing to the node that stands horizontally
 * next to the current node in the tree
 * @param count 
 * 
 * @note parent, next and count are used only for some of the problems
 */
class TreeNode
{
private:
public:
    int val = 0;
    TreeNode* left, *right;
    // Below data members used only for some of the problems
    TreeNode* parent, *next;
    int count;

    TreeNode(int val) 
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
        this->next = nullptr;
        this->count = 0;
    }

    static void printTree(TreeNode* root)
    {
        if(!root) return;
        // Inorder
        printTree(root->left);
        std::cout << root->val << " ";
        printTree(root->right);
    }

    static void printLevelOrderTree(TreeNode* root);

    ~TreeNode() {}
};

void TreeNode::printLevelOrderTree(TreeNode* root)
{
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);

    TreeNode* curNode;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            curNode = q.front();
            q.pop();
            cout << curNode->val << " ";
            if (curNode->left) q.push(curNode->left);
            if (curNode->right) q.push(curNode->right);
        }
    }
    cout << endl;
    curNode = nullptr;
    delete curNode;
}

/**
 * @brief A binary tree class
 * 
 * @param root The root node of the tree
 */
class BinaryTree
{
private:
    TreeNode* root;
public:
    BinaryTree() { root = nullptr; }
    BinaryTree(vector<int>& arr) {
        constructBFS(arr);
    }
    BinaryTree(vector<string>& arr) {
        constructBFSByStr(arr);
    }

    void constructBFS(vector<int>& arr);
    void constructBFSByStr(vector<string>& arr);
    void constructDFS(vector<int>& arr);
    void printTree();
    void printLevelOrderTree();
    TreeNode* getRoot();

    ~BinaryTree() {}
};

void BinaryTree::constructBFS(vector<int>& arr)
{
    root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    int j = 1;
    while (!q.empty() && j < arr.size())
    {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto curNode = q.front();
            q.pop();
            TreeNode* newNode = new TreeNode(arr[j]);
            curNode->left = newNode;
            q.push(newNode);
            j++;
            if (j >= arr.size()) return;
            newNode = new TreeNode(arr[j]);
            curNode->right = newNode;
            q.push(newNode);
            j++;
            if (j >= arr.size()) return;
        }
    }
    
}

void BinaryTree::constructBFSByStr(vector<string>& arr) {
    root = new TreeNode(stoi(arr[0]));
    queue<TreeNode*> q;
    q.push(root);
    int j = 1;
    TreeNode* newNode;
    while (!q.empty() && j < arr.size())
    {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto curNode = q.front();
            q.pop();
            if (arr[j] != ".") {
                newNode = new TreeNode(stoi(arr[j]));
                q.push(newNode);
            }
            else newNode = nullptr;
            curNode->left = newNode;
            j++;
            if (arr[j] != ".") {
                newNode = new TreeNode(stoi(arr[j]));
                q.push(newNode);
            }
            else newNode = nullptr;
            curNode->right = newNode;
            j++;
            if (j >= arr.size()) return;
        }
    }
    
}

void BinaryTree::constructDFS(vector<int>& arr) 
{
    root = new TreeNode(arr[0]);
    int i = 1;
    // TODO
}

void BinaryTree::printTree()
{
    TreeNode::printTree(root);
}

void BinaryTree::printLevelOrderTree()
{
    TreeNode::printLevelOrderTree(root);
}

TreeNode* BinaryTree::getRoot()
{
    return this->root;
}

#endif // TREENODE_HPP
