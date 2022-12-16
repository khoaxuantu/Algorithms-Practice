#include <bits/stdc++.h>


using namespace std;


class TreeNode
{
public:
    int val = 0;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution
{
public:
    static int solve(TreeNode* root)
    {
        // TODO: Write your code here
        int ans = INT_MIN;
        findSubSum(root, ans);
        return ans;
    }

private:
    static int findSubSum(TreeNode* node, int& maxSum)
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
};


int main(int argc, char const *argv[])
{
    /* Start and end timing */
    clock_t start, end;
    
    /* Start timing */
    start = clock();
    
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    cout << "Tree diameter: \n" << Solution::solve(root) << endl;
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    root->right->left->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    cout << "Tree diameter: \n" << Solution::solve(root) << endl;
    root = new TreeNode(-1);
    root->left = new TreeNode(-3);
    cout << "Tree diameter: \n" << Solution::solve(root) << endl;
    // for (auto vec : result) {
    //     for (auto num : vec) {
    //     cout << num << " ";
    //     }
    //     cout << endl;
    // }

    // vector<vector<int>> input {
    //     {1,0,7},
    //     {1,1,6}
    // };
    // for (auto arr : input)
    // {
    //     cout << "Tree has path sequence: " << Solution::solve(root, arr) << endl;
    // }
    /* End timing */
    end = clock();
    
    /* Print out time */
    double time_taken = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000;
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " ms " << endl;
    cout << endl;
    return 0;
}
