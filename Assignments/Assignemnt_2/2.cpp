// In the Name Of Allah, Who is most merciful.
#include <iostream>
#include <stack>
#include <cstring>
#include <cmath> // for pow

int isoperand(char x)
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

char *convert_to_postfix(char *infix)
{
    std::stack<char> st;
    char *postfix = new char[strlen(infix) + 1];
    int i = 0, j = 0;

    while (infix[i] != '\0')
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
                st.pop(); // remove '('
            i++;
        }
        else
        {
            while (!st.empty() && ((precedence_check(infix[i]) < precedence_check(st.top())) ||
                                   (precedence_check(infix[i]) == precedence_check(st.top()) && infix[i] != '^')))
            {
                postfix[j++] = st.top();
                st.pop();
            }
            st.push(infix[i++]);
        }
    }

    while (!st.empty())
    {
        postfix[j++] = st.top();
        st.pop();
    }

    postfix[j] = '\0';
    return postfix;
}

int Evaluation(char *postfix)
{
    std::stack<int> st;
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isoperand(postfix[i]))
        {
            st.push(postfix[i] - '0');
        }
        else
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            int result = 0;
            switch (postfix[i])
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            case '^':
                result = pow(a, b);
                break;
            }
            st.push(result);
        }
    }
    return st.top();
}

int main(int argc, char *argv[])
{
    char infix[100];

    if (argc > 1)
        strcpy(infix, argv[1]);
    else
    {
        std::cout << "Enter infix expression: ";
        std::cin >> infix;
    }

    if (!isValidExpression(infix))
    {
        std::cout << "Invalid Expression!" << std::endl;
        return 1;
    }

    char *postfix = convert_to_postfix(infix);
    std::cout << "Postfix expression: " << postfix << std::endl;

    int result = Evaluation(postfix);
    std::cout << "Result is " << result << std::endl;

    delete[] postfix;
    return 0;
}
