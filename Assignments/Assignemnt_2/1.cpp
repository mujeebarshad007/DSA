// In the Name Of Allah , Who is most merciful.
#include <iostream>
#include <stack>
#include <cstring>
#include <cmath>
int isoperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')' || x == '^') // This will return if the given character is operand or not
    {
        return 0;
    }
    else
        return 1;
}
int precedence_check(char x) // checking precedence by using numbers as a return
{

    if (x == '+' || x == '-')
    {
        return 1;
    }

    else if (x == '*' || x == '/')
    {
        return 2;
    }

    else if (x == '^')
    {
        return 3;
    }
    return 0;
}
bool Balanced(const char *expression)
{
    std::stack<char> st;
    for (int i = 0; expression[i] != '\0'; ++i)
    {
        if (expression[i] == '(')
        {
            st.push('(');
        }
        else if (expression[i] == ')')
        {
            if (st.empty())
                return false;
            else
            {
                st.pop();
            }
        }
    }
    return st.empty();
}
char *convert_to_postfix(char *infix)
{
    std::stack<char> st;
    char *postfix = new char[strlen(infix) + 1];
    int i = 0;
    int j = 0;

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

            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
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

bool valid(const char *expression)
{
    for (int i = 0; expression[i] != '\0'; ++i)
    {
        char c = expression[i];

        if (c >= '0' && c <= '9')
            continue;

        // checking valid operators and parentheses
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')')
            continue;

        return false;
    }

    return true;
}

int Evaluation(char *postfix)
{
    std::stack<int> st;
    int i = 0;
    for (i = 0; postfix[i] != '\0'; i++)
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
    // Take input
    if (argc > 1)
    {
        strcpy(infix, argv[1]);
    }
    else
    {
        std::cout << "Enter infix expression: ";
        std::cin.getline(infix, 100);
    }

    // Validate input first
    if (!valid(infix))
    {
        std::cout << " Invalid expression! Please use only digits and parentheses.\n";
        return 1;
    }

    //  Check balanced parentheses
    if (!Balanced(infix))
    {
        std::cout << "Unbalanced . !\n";
        return 1;
    }

    char *postfix = convert_to_postfix(infix);
    std::cout << " Postfix expression: " << postfix << std::endl;

    int result = Evaluation(postfix);
    std::cout << " Result is: " << result << std::endl;

    delete[] postfix;
    return 0;
}
