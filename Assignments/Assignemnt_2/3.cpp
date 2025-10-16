#include <iostream>
#include <stack>
#include <cstring>
#include <cmath> // for pow
nt isoperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
        return 0;
    else
        return 1;
}

int precedence_check(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '^')
        return 3; // highest precedence
    return 0;
}

// Check if parentheses are balanced
bool isBalanced(const char *exp)
{
    std::stack<char> s;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            s.push('(');
        else if (exp[i] == ')')
        {
            if (s.empty())
                return false;
            s.pop();
        }
    }
    return s.empty();
}

// Simple validation for allowed characters and operators
bool isValidExpression(const char *exp)
{
    if (!isBalanced(exp))
        return false;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        char c = exp[i];
        if (!(isoperand(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')'))
            return false;

        // check consecutive operators
        if (!isoperand(c) && c != '(' && c != ')')
        {
            if (i == 0 || !isoperand(exp[i - 1]) && exp[i - 1] != ')')
                return false;
            if (exp[i + 1] != '\0' && !isoperand(exp[i + 1]) && exp[i + 1] != '(')
                return false;
        }
    }
    return true;
}
char *convert(char *infix)
{
    int i, j;
    i = j = 0;

    std::stack<char> st;
    char *postfix = new char[strlen(infix) + 1];

    while (infix[i != '\0'])
    {
        if (isoperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else if (infix[i] == '(')
        {
            st.push(infix[i++]);
        }
        else if (infix[i] == ')')
        {

            while (!st.empty() && st.top() != '(')
            {

                postfix[j++] = st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
                i++;
            }
        }
        else
        {
            while (st.empty() && precedence_check(infix[i] < precedence_check(st.top())) || precedence_check(infix[i]) == precedence_check(st.top() && infix[i] != '^'))
            {
                postfix[j++] = infix[i++];
                st.pop();
            }
            st.push(infix[i++]);
        }
    }
}
int main()
{
    return 0;
}