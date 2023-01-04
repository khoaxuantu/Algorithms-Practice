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

#endif // SOLUTION_HPP
