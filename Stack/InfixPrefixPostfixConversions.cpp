#include <iostream>      // Include input-output stream library
#include <stack>         // Include stack library for stack operations
#include <algorithm>     // Include algorithm library for reverse function
#include <cctype>        // Include cctype library for isalnum function
using namespace std;     // Use standard namespace

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;       // Lower precedence for + and -
    else if (op == '*' || op == '/') return 2;  // Higher precedence for * and /
    else if (op == '^') return 3;               // Highest precedence for ^
    else return -1;                             // Return -1 if not an operator
}

// Function to convert infix expression to postfix expression
string infixToPostfix(const string& infix) {
    stack<char> s;         // Stack to hold operators
    string postfix;        // Resultant postfix expression

    // Iterate through each character in the infix expression
    for (char ch : infix) {
        if (isalnum(ch)) {     // If character is alphanumeric
            postfix += ch;     // Add it directly to postfix expression
        } else if (ch == '(') { // If opening bracket, push to stack
            s.push(ch);
        } else if (ch == ')') { // If closing bracket, pop until '(' is found
            while (!s.empty() && s.top() != '(') {
                postfix += s.top(); //add chars to resultant postfix expression
                s.pop(); //pop added char
            }
            s.pop();           // Remove the '(' from stack
        } else {               // If an operator
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);        // Push the current operator to stack
        }
    }

    // Pop all remaining operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;            // Return the resultant postfix expression
}

// Function to convert infix expression to prefix expression
string infixToPrefix(const string& infix) {
    stack<char> s;             // Stack to hold operators
    string prefix;             // Resultant prefix expression
    string reversed_infix = infix;

    // Reverse the infix expression
    reverse(reversed_infix.begin(), reversed_infix.end());
    for (char& ch : reversed_infix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }

    // Iterate through each character in the reversed infix expression
    for (char ch : reversed_infix) {
        if (isalnum(ch)) {     // If character is alphanumeric
            prefix += ch;      // Add it directly to prefix expression
        } else if (ch == '(') { // If opening bracket, push to stack
            s.push(ch);
        } else if (ch == ')') { // If closing bracket, pop until '(' is found
            while (!s.empty() && s.top() != '(') {
                prefix += s.top();
                s.pop();
            }
            s.pop();           // Remove the '(' from stack
        } else {               // If an operator
            while (!s.empty() && precedence(s.top()) > precedence(ch)) {
                prefix += s.top();
                s.pop();
            }
            s.push(ch);        // Push the current operator to stack
        }
    }

    // Pop all remaining operators from the stack
    while (!s.empty()) {
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());  // Reverse the resultant prefix expression
    return prefix;                          // Return the resultant prefix expression
}

// Function to convert postfix expression to infix expression
string postfixToInfix(const string& postfix) {
    stack<string> s;       // Stack to hold strings (operands and operators)

    // Iterate through each character in the postfix expression
    for (char ch : postfix) {
        if (isalnum(ch)) {     // If character is alphanumeric
            s.push(string(1, ch));  // Push it as a string to stack
        } else {               // If an operator
            string op2 = s.top(); s.pop();  // Pop top two elements from stack
            string op1 = s.top(); s.pop();
            string expr = "(" + op1 + ch + op2 + ")";  // Form the infix expression
            s.push(expr);       // Push the resultant expression back to stack
        }
    }

    return s.top();             // Return the final infix expression
}

// Function to convert prefix expression to infix expression
string prefixToInfix(const string& prefix) {
    stack<string> s;       // Stack to hold strings (operands and operators)

    // Traverse the prefix expression from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isalnum(ch)) {     // If character is alphanumeric
            s.push(string(1, ch));  // Push it as a string to stack
        } else {               // If an operator
            string op1 = s.top(); s.pop();  // Pop top two elements from stack
            string op2 = s.top(); s.pop();
            string expr = "(" + op1 + ch + op2 + ")";  // Form the infix expression
            s.push(expr);       // Push the resultant expression back to stack
        }
    }

    return s.top();             // Return the final infix expression
}

// Main function
int main() {
    string infix;       // Variable to hold infix expression

    // Get the infix expression from user
    cout << "Enter Infix Expression: ";
    cin >> infix;

    // Display the input infix expression
    cout << "Infix: " << infix << endl;
    // Display the postfix conversion of the infix expression
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    // Display the prefix conversion of the infix expression
    cout << "Prefix: " << infixToPrefix(infix) << endl;

    // Convert infix to postfix for example and display the infix conversion of it
    string postfix = infixToPostfix(infix);
    cout << "Postfix to Infix: " << postfixToInfix(postfix) << endl;

    // Convert infix to prefix for example and display the infix conversion of it
    string prefix = infixToPrefix(infix);
    cout << "Prefix to Infix: " << prefixToInfix(prefix) << endl;

    return 0;
}
