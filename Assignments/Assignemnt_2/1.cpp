// In the Name Of Allah , Who is most merciful.
#include <iostream>
#include <stack>
#include <cstring>

int isoperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    else
        return 1;
}

int precedence_check(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }

    else if (x == '*' || x == '/')
    {
        return 2;
    }
    return 0;
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
            }
            st.push(result);
        }
    }
    return st.top();
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
        else if (st.empty() || precedence_check(infix[i]) > precedence_check(st.top()))
        {
            st.push(infix[i++]);
        }
        else
        {
            postfix[j++] = st.top();
            st.pop();
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

int main()
{
    char infix[100];
    std::cout << "Enter infix expression: ";
    std::cin >> infix;

    char *postfix = convert_to_postfix(infix);
    std::cout << "Postfix expression: " << postfix << std::endl;

    int result = Evaluation(postfix);
    std::cout << " Result is " << result << std::endl;
    delete[] postfix;
    return 0;
}