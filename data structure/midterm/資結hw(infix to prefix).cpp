#include <iostream>
#include<stack>
using namespace std;

bool isOperator(char c)
{
    /*if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    else
        return false;*/
    return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

string infixToPrefix(stack<char> s, string infix)
{
    string prefix;
    int l = infix.size();
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < l; i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }
    for (int i = 0; i < l; i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            prefix += infix[i];
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((s.top() != '(') && (!s.empty()))
            {
                prefix += s.top();
                s.pop();
            }
            if (s.top() == '(')
            {
                s.pop();
            }
        }
        else if (isOperator(infix[i]))
        {
            if (s.empty())
            {
                s.push(infix[i]);
            }
            else
            {
                if (getPriority(infix[i]) > getPriority(s.top()))
                {
                    s.push(infix[i]);
                }
                else if ((getPriority(infix[i]) == getPriority(s.top())) && (infix[i] == '^'))
                {
                    while ((getPriority(infix[i]) == getPriority(s.top())) && (infix[i] == '^'))
                    {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
                else if (getPriority(infix[i]) == getPriority(s.top()))
                {
                    s.push(infix[i]);
                }
                else
                {
                    while ((!s.empty()) && (getPriority(infix[i]) < getPriority(s.top())))
                    {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while(!s.empty())
    {
        prefix += s.top();
        s.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

// Driver code
int main()
{
    string infix, prefix;
    stack<char> stack;
    cout << "enter a infix expression: ";
    cin >> infix;
    cout << "infix expression: " << infix << '\n';
    prefix = infixToPrefix(stack, infix);
    cout << "infix expression: " << prefix << '\n';
    return 0;
}