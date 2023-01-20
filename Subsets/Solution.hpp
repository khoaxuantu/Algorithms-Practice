#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

/**
 * @brief Subsets
 * 
 * @param nums A given set with distinct elements
 * 
 * @return :vector<vetor<int>>: All of the distinct subsets
 */
class Subsets
{
private:
    vector<int> nums;
public:
    Subsets(vector<int>& nums) : nums(nums) {}
    vector<vector<int>> solve() {
        vector<vector<int>> subsets;
        // TODO: Write your code here
        // Initialize a queue
        // Push nums[0] to queue pair<value, index>
        queue<pair<int, int>> q;
        q.push(make_pair(nums[0], 0));

        unordered_set<int> numVisited;
        // numVisited.insert(nums[0]);

        // BFS -> queue is empty 
        // Push each num to subsets in the first iter
        // For each iter 
            // Initialize a allNumsAftCurNum subset for all nums after the curnum
            // For each num after the curNum
                // Add to allNumsAftCurNum subset and push to ans
                // Push (curNum, num) to ans
        int curNum;
        int index = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                curNum = q.front().first;
                index = q.front().second;
                q.pop();
                if (numVisited.find(curNum) == numVisited.end())
                {
                    vector<int> num {curNum};
                    subsets.push_back(num);
                    numVisited.insert(curNum);
                }

                vector<int> allNumsAftCurNum {curNum};
                for (int j = index + 1; j < nums.size(); j++)
                {
                    allNumsAftCurNum.push_back(nums[j]);
                    if (allNumsAftCurNum.size() != 2)
                    {
                        subsets.push_back(allNumsAftCurNum);
                    }

                    vector<int> pairSubset {curNum, nums[j]};
                    subsets.push_back(pairSubset);

                    if (numVisited.find(nums[j]) == numVisited.end())
                    {
                        q.push(make_pair(nums[j], j));
                    }
                }
            }          
        }
        return subsets;
    }
};


/**
 * @brief Subsets With Duplicate
 * 
 * @param nums A given set with distinct elements
 * 
 * @return :vector<vector<int>>: All of its distinct subsets
 */
class SubsetWithDuplicates
{
private:
    vector<int> nums;
public:
    SubsetWithDuplicates(vector<int>& nums) : nums(nums) {}
    vector<vector<int>> solve() {
        vector<vector<int>> subsets;
        // TODO: Write your code here
        // Sort the nums
        sort(nums.begin(), nums.end());
        // Initialize null vector, push to the subset, store for memo copy
        // Traverse the nums
            // For each num 
                // If the num is duplicated 
                    // Add the num to memo copy
                    // Push memo copy to subsets
                // Else
                    // Init new copy
                    // Add the num to every subset of the new copy
                    // Push to the subsets and store the memo copy
        vector<vector<int>> memoCopy;
        memoCopy.push_back({});
        subsets.push_back({});

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i-1])
            {
                for (auto& arr : memoCopy)
                {
                    arr.push_back(nums[i]);
                    subsets.push_back(arr);
                }
            }
            else
            {
                vector<vector<int>> copy (subsets);
                for (auto& arr : copy)
                {
                    arr.push_back(nums[i]);
                    subsets.push_back(arr);
                }
                memoCopy = copy;
            }
        }
        return subsets;
    }
};


/**
 * @brief Permutation
 * 
 * @param nums a set of distinct numbers
 * 
 * @return :vector<vector<int>>: All of the permutations
 */
class Permutations
{
private:
    vector<int> nums;
public:
    Permutations(vector<int>& nums) : nums(nums) {}
    vector<vector<int>> solve() {
        vector<vector<int>> result;
        queue<vector<int>> permutations;
        permutations.push(vector<int>());
        for (auto currentNumber : nums) {
            // we will take all existing permutations and add the current number to create new
            // permutations
            int n = permutations.size();
            for (int i = 0; i < n; i++) {
                vector<int> oldPermutation = permutations.front();
                permutations.pop();
                // create a new permutation by adding the current number at every position
                for (int j = 0; j <= oldPermutation.size(); j++) {
                    vector<int> newPermutation(oldPermutation);
                    newPermutation.insert(newPermutation.begin() + j, currentNumber);
                    if (newPermutation.size() == nums.size()) {
                        result.push_back(newPermutation);
                    } else {
                        permutations.push(newPermutation);
                    }
                }
            }
        }
        return result;
    }
};


/**
 * @brief String Permutations by changing case
 * 
 * @param str An input string
 * 
 * @return :vector<string>: All of the permutations preserving 
 * the chars sequence but changing case
 */
class LetterCaseStringPermutation
{
private:
    string str;
public:
    LetterCaseStringPermutation(string& str) : str(str) {}
    vector<string> solve() {
        vector<string> permutations;
        // TODO: Write your code here
        cout << "This algorithm will take more space for the queue\n";

        // Initialize a queue
        // Push to the queue the first char
        queue<string> q;
        string firstChar = "";
        q.push(firstChar += str[0]);
        firstChar = "";
        if (isalpha(str[0]))
        {
            if (islower(str[0]))
            {
                q.push(firstChar += toupper(str[0]));
            }
            else
            {
                q.push(firstChar += tolower(str[0]));
            }
        }
        // Run until the queue is empty
            // Take a size of the queue
            // Traverse the queue based on the size
                // Take out the front as a permutation until the last strIndex
                // Init a copy of the permutation
                    // Add with a lowercase and a uppercase if is a letter
                    // Otherwise add with a digit
                    // Push the copy to the queue
                // If the index is the last char
                    // Push the permutation to the result
            // Increment the index
        int strIndex = 1;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                string tmp = q.front();
                q.pop();

                string strCopy = tmp;
                if (isalpha(str[strIndex]))
                {
                    strCopy += str[strIndex];
                    q.push(strCopy);
                    strCopy = tmp;
                    if (islower(str[strIndex]))
                    {
                        strCopy += (char)toupper(str[strIndex]);
                    }
                    else
                    {
                        strCopy += (char)tolower(str[strIndex]);
                    }
                    q.push(strCopy);

                }
                else
                {
                    strCopy += str[strIndex];
                    q.push(strCopy);
                }

            }
            if (strIndex == str.size() - 1)
            {
                while (!q.empty())
                {
                    permutations.push_back(q.front());
                    q.pop();
                }
                break;
            }
            strIndex++;
        }
        return permutations;
    }
};


/**
 * @brief Balanced Parentheses
 * 
 * @param num A given number N 
 * 
 * @return :vector<string>: All the combination of 'N' pairs
 * of balanced parentheses
 */
class GenerateParentheses
{
private: 
    int num;
    // Option
    // 0: Add into a couple of parentheses
    // 1: Add to right
    // 2: Add to left
    static void addToQueue(queue<pair<string, bool>>& q, string copyStr, bool curBool, int option)
    {
        switch (option)
        {
        case 0:
            copyStr = "(" + copyStr + ")";
            break;
        case 1:
            copyStr += "()";
            break;
        case 2:
            copyStr = "()" + copyStr;
            break;
        default:
            break;
        }

        if (!curBool && copyStr[0] == copyStr[1])
        {
            curBool = true;
        }

        q.push(make_pair(copyStr, curBool));
    }
public:
    GenerateParentheses(int n) : num(n) {}
    vector<string> solve() {
        vector<string> result;
        // TODO: Write your code here
        // Initialize a queue to push in every string created by parentheses
        // Push to the queue the first couple of parentheses pair[string, haveDoubleParentheses]
        queue<pair<string, bool>> q;
        string parentheses = "()";
        q.push(make_pair(parentheses, false));
        // Run until the queue is empty
        // For each level
            // Create new strings based on the size of the queue
                // Add into a couple of parentheses and push to the queue
                // Add a couple of parentheses at outside
                    // Left -> push to the queue
                    // If curStr[0] == curStr[1], add another to right -> push to the queue
        // For the last level, add all strings to the result
        string curStr;
        bool curBool;
        int level = 1;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                curStr = q.front().first;
                curBool = q.front().second;
                q.pop();

                // Case 0
                addToQueue(q, curStr, curBool, 0);
                // Case 1
                addToQueue(q, curStr, curBool, 1);

                if (curBool == true)
                {
                    // Case 2
                    addToQueue(q, curStr, curBool, 2);
                }
            }
            
            level++;
            if (level == num)
            {
                while (!q.empty())
                {
                    result.push_back(q.front().first);
                    q.pop();
                }
                break;
            }
        }
        return result;
    }
};


/**
 * @brief Unique Generalized Abbreviations
 * 
 * @param str A given word
 * 
 * @return :vector<string>: All of its unique generalized abbreviations
 */
class GeneralizedAbbreviation
{
private:
    string str;
    string subStrToNum(string& s)
    {
        string copyString;
        int sSize = s.length();
        for (int i = 0; i < sSize; i++)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            else if (s[i] != '_')
            {
                copyString += s[i];
            }
            else
            {
                int endSub = i;
                while (endSub < s.size() && s[endSub] == '_')
                {
                    endSub++;
                }
                int subLength = endSub - i;
                i = endSub-1;
                copyString += to_string(subLength);
            }
        }
        return copyString;
    }
public:
    GeneralizedAbbreviation(string& s) : str(s) {}
    vector<string> solve() {
        vector<string> result;
        // TODO: Write your code here
        // Initialize a queue abbreviations in each level
        // Add "" to queue ("_" represents null char)
        queue<string> q;
        q.push(" ");
        // Run until the queue is empty
        // For each char in str
            // Run every string in the queue
            // For each string
                // Add with "_" and push to the queue
                // Add with str[char] and push to the queue
            // In the last char
                // convert "_" substr to num in each string
                // Push to ans
        int c = 0;
        string curStr;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                curStr = q.front();
                q.pop();

                string strCopy = curStr;
                strCopy += "_";
                q.push(strCopy);

                strCopy = curStr;
                strCopy += str[c];
                q.push(strCopy);
            }
            if (c == str.length() - 1)
            {
                while (!q.empty())
                {
                    string tmp = subStrToNum(q.front());
                    q.pop();
                    result.push_back(tmp);
                }
                break;
            }
            c++;
        }
        return result;
    }
};


/**
 * @brief Evaluate Expression
 * 
 * @param input an expression containing digits and operations (+, -, *)
 * 
 * @return :vector<int>: All possible ways in which the expression
 * can be evaluated by grouping the numbers and operators using parentheses
 */
class EvaluateExpression
{
private:
    string input;
    bool numOnly(const string& input)
    {
        for (char c : input)
        {
            if (!isdigit(c))
            {
                return false;
            }
        }
        return true;
    }
    vector<int> diffWaysToEvaluateExpression(const string& input) {
        vector<int> result;
        // TODO: Write your code here
        // If the input is number only
        // Else
            // Call left part and right part recursively
            // For each product in left part
                // Combine with each product in right part
        if (numOnly(input))
        {
            result.push_back(stoi(input));
        }
        else
        {
            for (int i = 0; i < input.size(); i++)
            {
                if (!isdigit(input[i]))
                {
                    vector<int> leftInput = diffWaysToEvaluateExpression(input.substr(0, i));
                    vector<int> rightInput = diffWaysToEvaluateExpression(input.substr(i + 1));

                    for (auto lChar : leftInput)
                    {
                        for (auto rChar : rightInput)
                        {
                            switch (input[i])
                            {
                            case '+':
                                result.push_back(lChar + rChar);
                                break;
                            case '-':
                                result.push_back(lChar - rChar);
                                break;
                            case '*':
                                result.push_back(lChar * rChar);
                                break;
                                
                            default:
                                break;
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
public:
    EvaluateExpression(string& s) : input(s) {}
    vector<int> solve() {
        return diffWaysToEvaluateExpression(input);
    }
};


/**
 * @brief Structurally Unique Binary Search Trees
 * 
 * @param input A number 'n'
 * 
 * @return :vector<TreeNode>: All structurally unique Binary Search Tree
 * that can store values 1 to n 
 */
class UniqueTrees
{
private:
    int input;
    vector<TreeNode*> buildTree (int sRange, int eRange)
    {
        vector<TreeNode*> result;
        // Base case: when the input is out of the scope
            // Push the node input to result and return 
        if (sRange >= eRange)
        {
            if (sRange == eRange)
            {
                TreeNode* node = new TreeNode(sRange);
                result.push_back(node);
            }
            else result.push_back(nullptr);
            return result;
        }
        // Traverse every num in range
        // For each num as root
            // Call recursively to left range and right range
            // Traverse each BSTs found in left and right range
                // Connect with the curNum 
                // Push to result
        for (int i = sRange; i <= eRange; i++)
        {
            TreeNode* curNode;

            vector<TreeNode*> leftBSTs = buildTree(sRange, i - 1);
            vector<TreeNode*> rightBSTs = buildTree(i + 1, eRange);
            for (auto ltree : leftBSTs)
            {
                curNode = new TreeNode(i);
                curNode->left = ltree;
                for (auto rtree : rightBSTs)
                {
                    curNode->right = rtree;
                    result.push_back(curNode);
                }
            }
        }
        return result;       
    }
public: 
    UniqueTrees(int n) : input(n) {}
    vector<TreeNode*> solve() {
        vector<TreeNode *> result;
        // TODO: Write your code here
        result = buildTree(1, input);
        return result;
    }
};

#endif // SOLUTION_HPP
