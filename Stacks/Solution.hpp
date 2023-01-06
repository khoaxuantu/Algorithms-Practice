#if !defined(SOLUTION_HPP)
#define SOLUTION_HPP

/**
 * @brief Basic Calculator
 * 
 * @param expression A string containing an arithmetic expression
 * 
 * @return :int: The result of a basic calculator that evaluates 
 * the expression string
 */
class BasicCalculator
{
private:
    string expression;
public:
    BasicCalculator(string& input) : expression(input) {}
    int solve() {
        // TODO: your code will replace this placeholder return statement
        //* Store numeric strings
        //* Push to the stack: numeric strings and the '('
        //* Attach an operator
        //* Every time meeting a close parentheses, start evaluating the expression until '('
        int ans = 0;
        stack<pair<string, char>> st;
        char oper = '+';
        int i = 0;
        string tmp;
        while (i < expression.size()) { // 108:+ 
            if (expression[i] == ' ') {
                i++;
                continue;
            }
            if (expression[i] == '(') {
                st.push(make_pair("(", oper));
                oper = '+';
            }
            else if (expression[i] == ')') {
                int eval = 0;
                if (tmp != "") st.push(make_pair(tmp, oper));
                oper = '+';
                while (!st.empty() && st.top().first != "(") {
                    if (st.top().second == '-') {
                        eval = -1*stoi(st.top().first) + eval;
                    }
                    else eval = stoi(st.top().first) + eval;
                    oper = st.top().second;
                    st.pop();  
                }
                st.top().first = to_string(eval);
                tmp = "";
            }
            else {
                if (isdigit(expression[i])) {
                    tmp += expression[i];
                }
                else {
                    if (tmp != "") st.push(make_pair(tmp, oper));
                    oper = expression[i];
                    tmp = "";
                }   
            }
            i++;
        }
        if (tmp != "") st.push(make_pair(tmp, oper));
        oper = '+';
        while(!st.empty()) {
            if (st.top().second == '-') {
                ans = -1*stoi(st.top().first) + ans;
            }
            else ans = stoi(st.top().first) + ans;
            oper = st.top().second;
            st.pop();
        }
        return ans;
    }
};


/**
 * @brief Remove All Adjacent Duplicates in String
 * 
 * @param toCleanUp A string consisting of lowercase English letters
 * 
 * @return :string: The string after removing adjacent duplicate letters
 */
class RemoveDuplicates
{
private:
    string toCleanUp;
public:
    RemoveDuplicates(string& input) : toCleanUp(input) {}
    string solve() {
        if (toCleanUp.size() == 1) return toCleanUp;
        string ans;
        //* Use a stack
        //* When I traverse the string, check if the char is similar to
        //* stack's top char
            // If yes, pop out of stack
            // Otherwise, push the char to the stack
        stack<char> st;
        st.push(toCleanUp[0]);
        for (int i = 1; i < toCleanUp.size(); i++) {
            if (!st.empty() && toCleanUp[i] == st.top()) st.pop();
            else st.push(toCleanUp[i]);
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


/**
 * @brief Minimum Remove to Make Valid Parentheses
 * 
 * @param s A string with matched and unmatched parentheses
 * 
 * @return :string: The result string with valid parenthesization after
 * minimum numbers of parentheses removed
 */
class MinRemoveParentheses
{
private:
    string s;
public:
    MinRemoveParentheses(string& input) : s(input) {}
    string solve() {
        //* Use stacks to store parentheses with corresponding index
        //* If stack top is '(' and cur char is ')', pop 
        //* Create a new string with excluded parentheses
        unordered_set<int> invalidChar;
        stack<pair<char,int>> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(make_pair('(', i));
            else if (s[i] ==')') {
                if (!st.empty()) st.pop();
                else invalidChar.insert(i);
            }
        }
        while (!st.empty()) {
            invalidChar.insert(st.top().second);
            st.pop();
        }
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (invalidChar.find(i) == invalidChar.end()) {
                ans += s[i];
            }
        }
        return ans;
    }
};


/**
 * @brief Exclusive Execution Time of Functions
 * 
 * @param n the number of functions running in a single-thread CPU
 * @param logs A list of strings representing an execution log. Each string has
 * format {function_id}:{"start"|"end"}:{timestamp}
 * 
 * @return :vector<int>: The exclusive times of the functions in the program 
 */
/* Support Templates */
void Split(string &s, string &delim, vector<string> &elems)
{
    regex rgx(delim);
    sregex_token_iterator iter(s.begin(), s.end(), rgx, -1);
    sregex_token_iterator end;
    while (iter != end)
    {
        elems.push_back(*iter);
        ++iter;
    }
}

class Log
{
public:
    int id;
    bool isStart;
    int time;
    Log(string content)
    {
        vector<string> strs;
        string delim = ":";
        Split(content, delim, strs);
        id = stoi(strs[0]);
        isStart = strs[1] == "start";
        time = stoi(strs[2]);
    }
}; // End of support templates

class ExclusiveTime
{
private:
    int n;
    vector<string> logs;
public:
    ExclusiveTime(int inputN, vector<string>& inputS) : 
        n(inputN), logs(inputS) {}
    vector<int> solve() { //   5 3 3 6
        // TODO: Write your code here
        vector<int> ans (n);
        //* Traverse the logs
        //* Use a stack to keep track the functions
            // If meet a start log, check if there is a running log and push to stack
            // If meet an end log, update the time taken and pop the corresponding start log
        stack<Log> st; // 0:5
        for (int i = 0; i < logs.size(); i++) {
            Log log(logs[i]);
            if (log.isStart) {
                st.push(log);
            }
            else {
                int execute = log.time - st.top().time + 1;
                ans[log.id] += execute;
                st.pop();
                if (!st.empty()) ans[st.top().id] -= execute;
            }
        }
        return ans;
    }
};


/**
 * @brief Flatten Nested List Iterator
 * 
 * @param 
 */

#endif // SOLUTION_HPP
