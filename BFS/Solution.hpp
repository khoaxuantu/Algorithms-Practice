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

#endif // SOLUTION_HPP
