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
    static vector<TreeNode*> solve(TreeNode* root)
    {
        vector<TreeNode*> result;
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


int main(int argc, char *argv[]) {
    /* Start and end timing */
    clock_t start, end;
    
    /* Start timing */
    start = clock();

    TreeNode *root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(9);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    root->left->left->left = new TreeNode(3);
    vector<TreeNode*> result = Solution::solve(root);
    for (auto node : result)
    {
        cout << node->val << " ";
    }
    cout << endl;
    // int result = Solution::solve(root);
    // cout << "Level order traversal:\n";
    // // for (auto vec : result) {
    // //     // for (auto num : vec) 
    // //     // {
    // //     //     cout << num << " ";
    // //     // }
    // //     // cout << endl;
    // //     cout << vec << " ";
    // // }
    // // cout << endl;

    // cout << result <<endl;

    /* End timing */
    end = clock();

    /* Print out time */
    double time_taken = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000;
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " ms " << endl;
    cout << endl;
}