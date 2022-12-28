#include <iostream>
#include <cmath>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
};

class Stack
{
public:
    string reverse(string exp)
    {
        string ans = "";
        for (int i = exp.length() - 1; i >= 0; i--)
        {
            if (exp[i] == '(')
                ans += ')';
            else if (exp[i] == ')')
                ans += '(';
            else
                ans += exp[i];
        }
        return ans;
    }

    int getPrec(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }

    bool isOperand(char c)
    {
        if (c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
            return true;
        else
            return false;
    }

    bool isDigit(char c)
    {
        if (c >= '0' && c <= '9')
            return true;
        else
            return false;
    }

    bool isOperator(char c)
    {
        if (c == '-' || c == '+' || c == '*' || c == '/' || c == '^')
            return true;
        else
            return false;
    }

    int operation(int a, char c, int b)
    {
        if (c == '*')
            return b * a;
        else if (c == '/')
            return b / a;
        else if (c == '+')
            return b + a;
        else if (c == '-')
            return b - a;
        else if (c == '^')
            return pow(b, a);
    }

    void push(Node *&top, char c)
    {
        Node *nn = new Node();
        nn->data = c;
        if (top == NULL)
        {
            top = nn;
            nn->next = NULL;
        }
        else
        {
            nn->next = top;
            top = nn;
        }
    }

    void pop(Node *&top)
    {
        if (top == NULL)
            return;
        else
        {
            top = top->next;
        }
    }

    string toPrefix(Node *&top, string exp)
    {
        string e = reverse(exp);
        string ans = "";
        for (int i = 0; i < exp.length(); i++)
        {
            char c = e[i];
            if (c == ' ')
                continue;
            else if (isOperand(c))
            {
                ans += c;
            }
            else if (c == '(')
            {
                push(top, c);
            }
            else if (c == ')')
            {
                while (top->data != '(')
                {
                    ans += top->data;
                    pop(top);
                }
                pop(top);
            }
            else if (isOperator(c))
            {
                while (top != NULL && getPrec(top->data) >= getPrec(c))
                {
                    ans += top->data;
                    pop(top);
                }
                push(top, c);
            }
        }
        while (top != NULL)
        {
            ans += top->data;
            pop(top);
        }
        ans = reverse(ans);
        cout << "Prefix Expression = " << ans << endl;
        return ans;
    }

    string toPostfix(Node *top, string exp)
    {
        string ans = "";
        string e = exp;
        for (int i = 0; i < e.length(); i++)
        {
            char c = e[i];
            if (isOperand(c))
            {
                ans += c;
            }
            else if (c == '(')
            {
                push(top, c);
            }
            else if (c == ')')
            {
                while (top->data != '(')
                {
                    ans += top->data;
                    pop(top);
                }
                pop(top);
            }
            else if (isOperator(c))
            {
                while (top != NULL && getPrec(top->data) >= getPrec(c))
                {
                    ans += top->data;
                    pop(top);
                }
                push(top, c);
            }
        }
        while (top != NULL)
        {
            ans += top->data;
            pop(top);
        }
        cout << "Postfix Expression = " << ans << endl;
        return ans;
    }

    void prefixEval(Node *&top, string e)
    {
        e = reverse(e);
        cout << e << endl;
        for (int i = 0; i < e.length(); i++)
        {
            char c = e[i];
            if (c == ' ')
                continue;
            else if (isDigit(c))
            {
                push(top, c);
            }
            else if (isOperator(c))
            {
                int b = top->data - '0';
                pop(top);
                int a = top->data - '0';
                pop(top);
                a = operation(a, c, b) + '0';
                push(top, a);
            }
        }
        int ans = top->data - '0';
        pop(top);
        cout << "Prefix Evaluation = " << ans << endl;
    }

    void postfixEval(Node *&top, string e)
    {
        int ans;
        for (int i = 0; i < e.length(); i++)
        {
            char c = e[i];
            if (c == ' ')
                continue;
            else if (isDigit(c))
            {
                push(top, c);
            }
            else if (isOperator(c))
            {
                int a = top->data - '0';
                pop(top);
                int b = top->data - '0';
                pop(top);
                a = operation(a, c, b) + '0';
                push(top, a);
            }
        }
        ans = top->data - '0';
        pop(top);
        cout << "Postfix Evaluation = " << ans << endl;
    }

    bool validation(string s)
    {
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (isOperand(c))
            {
                ++count;
            }
            else if (isOperator(c))
            {
                --count;
            }
        }
        if (count == 1)
            return true;
        else
            return false;
    }
};

int main()
{
    Stack s;
    string exp;
    Node *top = NULL;
    int ch;
MENU:
    cout << "---------------[ MENU ]------------------------" << endl;
    cout << "\n0.Exit\n1.Convert to Prefix\n2.Convert to Postfix\n3.Prefix Evaluation\n4.Postfix Evaluation\n\nEnter Your Choice = ";
    cin >> ch;
    switch (ch)
    {
    case 0:
        cout << "Program Ended" << endl;
        break;
    case 1:
        cout << "Enter Expression = ";
        cin >> exp;
        s.toPrefix(top, exp);
        goto MENU;
    case 2:
        cout << "Enter Expression = ";
        cin >> exp;
        s.toPostfix(top, exp);
        goto MENU;
    case 3:
        cout << "Enter Numeric Prefix Expression (format : 1st Operator and then two Operands ) = ";
        cin >> exp;
        if (s.validation(exp))
            s.prefixEval(top, exp);
        else
            cout << "Invalid Expression" << endl;
        goto MENU;
    case 4:
        cout << "Enter Numeric Postfix Expression (format : 1st two Operands last Operator) = ";
        cin >> exp;
        if (s.validation(exp))
            s.postfixEval(top, exp);
        else
            cout << "Invalid Expression" << endl;
        goto MENU;
    default:
        cout << "Invalid Input!!!" << endl;
        goto MENU;
    }
}