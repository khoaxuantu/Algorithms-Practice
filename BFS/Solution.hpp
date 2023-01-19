#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

/**
 * @brief Binary Tree Level Order Traversal
 * 
 * @param root The root of a binary tree
 * 
 * @return :vector<vector<int>>: An array to represent its level-by-level
 * traversal
 */
class LevelOrderTraversal
{
private:
    TreeNode* root;
public:
    LevelOrderTraversal(TreeNode* root) : root(root) {}
    vector<vector<int>> solve() {
        vector<vector<int>> result;
        // TODO: Write your code here
        // Initialize a queue
        // Add root to queue
        queue<TreeNode*> q;
        q.push(root);
        // Run the queue until it is empty
        // For each queue top element
            // Assign to a tmp element
            // Pop the top
            // Add nei of the tmp into the queue
        TreeNode* tmp;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> treeLevel;
            for (int i = 0; i < size; i++)
            {
                tmp = q.front();
                q.pop();

                treeLevel.push_back(tmp->val);

                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            result.push_back(treeLevel);
        }
        return result;
    }
};


/**
 * @brief Zigzag Traversal
 * 
 * @param root The root of a binary tree
 * 
 * @return :vector<vector<int>>: An array to represent its zigzag level
 * order traversal. You should populate the values of all nodes of the 
 * first level from left to right, then right to left for the next level
 * and keep alternating in the same manner for the following levels
 */
class ZigzagTraversal
{
private:
    TreeNode* root;
public:
    ZigzagTraversal(TreeNode* root) : root(root) {}
    vector<vector<int>> solve() {
        vector<vector<int>> result;
        // TODO: Write your code here
        // Initialize a queue
        // Add root to queue
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        // Run the queue until it is empty
        // For each queue top element
            // Assign to a tmp element
            // Pop the top
            // Add nei of the tmp into the queue
        TreeNode* tmp;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> treeLevel;
            for (int i = 0; i < size; i++)
            {
                tmp = q.front();
                q.pop();

                if (level % 2 != 0)
                {
                    treeLevel.push_back(tmp->val);
                }
                else
                {
                    treeLevel.insert(treeLevel.begin(), tmp->val);
                }

                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            result.push_back(treeLevel);
            level++;
        }
        return result;
    }
};


/**
 * @brief Level Averages in a Binary Tree 
 * 
 * @param root The root of a binary tree
 * 
 * @return :vector<double> An array representing the averages
 * of all of its levels
 */
class LevelAverage
{
private:
    TreeNode* root;
public:
    LevelAverage(TreeNode* root) : root(root) {}
    vector<double> solve() {
        vector<double> result;
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            int levelSize = queue.size();
            double levelSum = 0;
            for (int i = 0; i < levelSize; i++) {
                TreeNode *currentNode = queue.front();
                queue.pop();
                // add the node's value to the running sum
                levelSum += currentNode->val;
                // insert the children of current node to the queue
                if (currentNode->left != nullptr) {
                    queue.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    queue.push(currentNode->right);
                }
            }
            // append the current level's average to the result array
            result.push_back(levelSum / levelSize);
        }

        return result;
    }
};


/**
 * @brief Minimum Depth of a Binary Tree
 * 
 * @param root The root of a binary tree
 * 
 * @return :int: The minimum depth of the binary tree
 */
class MinimumBinaryTreeDepth
{
private:
    TreeNode* root;
public:
    MinimumBinaryTreeDepth(TreeNode* root) : root(root) {}
    int solve() {
        int result = 0;
        // TODO: Write your code here
        // Initialize a queue
        // Add root to queue
        queue<TreeNode*> q;
        q.push(root);
        // Run the queue until it is empty
        // For each queue top element
            // Assign to a tmp element
            // Pop the top
            // Add nei of the tmp into the queue
        int depth = 1;
        bool foundAns = false;
        TreeNode* tmp;
        while (!q.empty())
        {
            int size = q.size();
            int treeLevel = 0;
            for (int i = 0; i < size; i++)
            {
                tmp = q.front();
                q.pop();

                if (!tmp->left && !tmp->right)
                {
                    result = depth;
                    foundAns = true;
                    break;
                }

                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            if (foundAns) break;
            depth++;
        }
        return result;
    }
};


/**
 * @brief Level Order Successor
 * 
 * @param root The root of a binary tree
 * @param key A given node
 * 
 * @return :TreeNode: The level order successor of the given node in the tree.
 * The level order successor is the node that appears right after 
 * the given node in the level order travesal
 */
class LevelOrderSuccessor
{
private:
    TreeNode* root;
    int key;
public:
    LevelOrderSuccessor(TreeNode* root, int key) : root(root), key(key) {}
    TreeNode* solve() {
        // TODO: Write your code here
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* curNode = q.front();
                q.pop();

                if (curNode->left) q.push(curNode->left);
                if (curNode->right) q.push(curNode->right);
                
                if (curNode->val == key)
                {
                    return q.front();
                }
            }
        }
        return nullptr;
    }
};


/**
 * @brief Connect Level Order Siblings
 * 
 * @param root The root of a binary tree
 * 
 * @return :void: The tree after connecting each node with
 * its level order successor
 */
class ConnectLevelOrderSiblings
{
private:
    TreeNode* root;
public:
    ConnectLevelOrderSiblings(TreeNode* root) : root(root) {}
    TreeNode* solve() {
        // TODO: Write your code here
        queue<TreeNode*> q;
        q.push(root);

        TreeNode* curNode;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                curNode = q.front();
                q.pop();

                if (curNode->left) q.push(curNode->left);
                if (curNode->right) q.push(curNode->right);

                if (i == size - 1)
                {
                    curNode->next = nullptr;
                }
                else
                {
                    curNode->next = q.front();
                }
            }
        }
        return root;
    }
};


/**
 * @brief Connect All Level Order Siblings
 * 
 * @param root The root of a binary tree
 * 
 * @return :TreeNode: The tree after connecting each node
 * with its level order successor
 */
class ConnectAllSiblings
{
private:
    TreeNode* root;
public:
    ConnectAllSiblings(TreeNode* root) : root(root) {}
    TreeNode* solve() {
        // TODO: Write your code here
        queue<TreeNode*> q;
        q.push(root);

        TreeNode* curNode;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                curNode = q.front();
                q.pop();

                if (curNode->left) q.push(curNode->left);
                if (curNode->right) q.push(curNode->right);

                if (!q.empty())
                {
                    curNode->next = q.front();
                }
            }
        }
        return root;
    }
};


/**
 * @brief Right View of a Binary Tree
 * 
 * @param root The root of a binary tree
 * 
 * @return :vector<TreeNode>: An array containing nodes in 
 * tree's right view
 */
class RightViewTree
{
private:
    TreeNode* root;
public:
    RightViewTree(TreeNode* root) : root(root) {}
    vector<TreeNode*> solve() {
        vector<TreeNode *> result;
        // TODO: Write your code here
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* curNode = q.front();
                q.pop();

                if (curNode->left) q.push(curNode->left);
                if (curNode->right) q.push(curNode->right);

                if (i == size - 1)
                {
                    result.push_back(curNode);
                }
            }
            
        }
        return result;
    }
};

#endif // SOLUTION_HPP
