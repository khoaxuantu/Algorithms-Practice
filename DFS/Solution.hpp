#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

/**
 * @brief Binary Tree Path Sum 
 * 
 * @param root The root of a binary tree
 * @param sum The target sum 
 * 
 * @return :boolean: If the tree has a path from root to leaf
 * such that the sum of all the node values of that path 
 * equals to the target sum
 */
class TreePathSum
{
private:
    TreeNode* root;
    int sum;
    bool hasPath(TreeNode* root, int sum) {
        // TODO: Write your code here
        if (root == nullptr) return false;

        sum -= root->val;
        if (sum == 0) return true;

        if (hasPath(root->left, sum)) return true;
        if (hasPath(root->right, sum)) return true;
        
        return false;
    }
public:
    TreePathSum(TreeNode* root, int sum) : root(root), sum(sum) {}
    bool solve() {
        return hasPath(root, sum);
    }
};


/**
 * @brief All Paths for a Sum 
 * 
 * @param root The root of a binary tree
 * @param sum The target sum 
 * 
 * @return :vector<vector<int>>: All paths form root to leaf such that
 * the sum of all the node values of each path equals sum 
 */
class FindAllTreePaths
{
private:
    TreeNode* root;
    int sum;
    void collectPath(TreeNode* root, int sum, vector<vector<int>>& allPaths, vector<int> track)
    {
        if (!root) return;
        
        sum -= root->val;
        track.push_back(root->val);
        
        if (sum == 0 && !root->left && !root->right)
        {
            allPaths.push_back(track);
        }

        collectPath(root->left, sum, allPaths, track);
        collectPath(root->right, sum, allPaths, track);
    }
public:
    FindAllTreePaths(TreeNode* root, int sum) : root(root), sum(sum) {}
    vector<vector<int>> sovle() {
        vector<vector<int>> allPaths;
        // TODO: Write your code here
        vector<int> track;
        collectPath(root, sum, allPaths, track);
        return allPaths;
    }
};


/**
 * @brief Sum of Path Numbers
 * 
 * @param root The root of a binary tree. Each node can only have
 * a digit (0-9) value
 * 
 * @return :int: The total sum of all the numbers represented 
 * by all paths
 */
class SumOfPathNumbers
{
private:
    TreeNode* root;
    int cal(TreeNode* root, int& ans, int pathNum)
    {
        if (!root) return ans;
        pathNum = pathNum*10 + root->val;
        if (!root->left && !root->right)
        {
            ans += pathNum;
            return ans;
        }   

        if(root->left) ans = cal(root->left, ans, pathNum);
        if (root->right) ans = cal(root->right, ans, pathNum);

        return ans;
    }
public:
    SumOfPathNumbers(TreeNode* root) : root(root) {}
    int solve() {
        // TODO: Write your code here
        int ans = 0;
        ans = cal(root, ans, 0);
        return ans;
    }
};


/**
 * @brief Path With Given Sequence
 * 
 * @param root The root of a binary tree
 * @param sequence A target sequence
 * 
 * @return :boolean: If the sequence is presented as a 
 * root to leaf path in the tree
 */
class PathWithGivenSequence
{
private:
    TreeNode* root;
    vector<int> sequence;
    bool checkPath(TreeNode* node, const vector<int>& sequence, int index)
    {
        // Validate node
            // Not a leaf node
        // Validate index
            // index > seq.size, return false
        if (!node)
        {
            return false;
        }
        else if (!node->left && !node->right)
        {
            if (sequence[index] == node->val)
            {
                return true;
            }
        }

        if (node->val != sequence[index])
        {
            return false;
        }

        if (index >= sequence.size())
        {
            return false;
        }
        // Call recursion
        return checkPath(node->left, sequence, index+1) ||
               checkPath(node->right, sequence, index+1);
    }
public:
    PathWithGivenSequence(TreeNode* root, vector<int>& seq) :
        root(root), sequence(seq) {}
    bool solve() {
        // TODO: Write your code here
        // Calling a recursive func(root, seq, index)
        if (checkPath(root, sequence, 0)) return true;
        return false;
    }
};


/**
 * @brief Count Paths for a Sum 
 * 
 * @param root The root of a binary tree
 * @param S The target number
 * 
 * @return :int: all paths in the tree such that the sum 
 * of all the node values of each equals S 
 */
class CountAllPathSum
{
private:
    TreeNode* root;
    int S;
    int ans = 0;
    void findSum(int& S, vector<int>& path)
    {
        int left = 0;
        int right = 1;
        int sum = path[0];
        while (left < right)
        {            
            if (right < path.size())
            {
                sum += path[right];
                right++;
            }
            else
            {
                sum -= path[left];
                left++;
            }

            if (sum == S)
            {
                ans++;
            }
        }
    }

    void findAns(TreeNode* node, int& S, vector<int>& path)
    {
        if (!node) return;
        path.push_back(node->val);

        findSum(S, path);

        if (node->left) findAns(node->left, S, path);
        if (node->right) findAns(node->right, S, path);

        path.pop_back();
    }
public:
    CountAllPathSum(TreeNode* root, int S) : root(root), S(S) {}
    int solve() {
        // TODO: Write your code here
        vector<int> path;
        findAns(root, S, path);
        return ans;
    }
};


/**
 * @brief Tree Diameter
 * 
 * @param root The root of a binary tree
 * 
 * @return :int: The length of the tree's diameter. The diameter of a tree
 * is the number of nodes on the longest path between any two leaf nodes
 */
class TreeDiameter
{
private:
    TreeNode* root;
    int findSubDepth(TreeNode* node, int& diameter)
    {
        // Validate the node
        if (!node) return 0;
        // Traverse to the leaf node
        int leftSubDepth = findSubDepth(node->left, diameter);
        int rightSubDepth = findSubDepth(node->right, diameter);
        // Update the diameter
        diameter = max(diameter, leftSubDepth + rightSubDepth + 1);
        // Return the subDepth
        int subDepth = max(leftSubDepth, rightSubDepth) + 1;
        // cout << node->val << " | ";
        // cout << " lefSubDepth:" << leftSubDepth << " rightSubDepth:" << rightSubDepth;
        // cout << " >>> " << diameter << endl;
        return subDepth;
    }
public:
    TreeDiameter(TreeNode* root) : root(root) {}
    int solve() {
        int treeDiameter = 0;
        // TODO: Write your code here
        findSubDepth(root, treeDiameter);
        return treeDiameter;
    }
};


/**
 * @brief Path with Maximum Sum 
 * 
 * @param root The root of a binary tree
 * 
 * @return :int: The maximum sum 
 */
class MaximumPathSum
{
private:
    TreeNode* root;
    int findSubSum(TreeNode* node, int& maxSum)
    {
        // Validate the node
        if (!node) return 0;
        // Traverse the child nodes
        int leftSubSum = findSubSum(node->left, maxSum);
        int rightSubSum = findSubSum(node->right, maxSum);
        // Update the maxSum
        maxSum = max(maxSum, leftSubSum + rightSubSum + node->val);
        // Return the maximum subSum + nodeval
        return max(leftSubSum, rightSubSum) + node->val;
    }
public:
    MaximumPathSum(TreeNode* root) : root(root) {}
    int solve() {
        // TODO: Write your code here
        int ans = INT_MIN;
        findSubSum(root, ans);
        return ans;
    }
};

#endif // SOLUTION_HPP
