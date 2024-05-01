#include<iostream> 
#include<string> 
#include<stack> 
using namespace std;

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else return 0;
}

void infix_to_postfix(string t)
{
    stack<char> s;
    int l = t.length();
    string ans;
    for (int i = 0; i < l; i++)
    {
        if ((t[i] >= 'a' && t[i] <= 'z') || (t[i] >= 'A' && t[i] <= 'Z'))
            ans += t[i];

        else if (t[i] == '(')
            s.push('(');

        else if (t[i] == ')')
        {
            while (s.top() != '(')
            {
                char c = s.top();
                ans += c;
                s.pop();

            }
            if (s.top() == '(')
            {
                char c = s.top();
                s.pop();
            }
        }
        else {
            while (s.empty() == false && precedence(t[i]) <= precedence(s.top()))
            {
                char c = s.top();
                ans += c;
                s.pop();

            }
            s.push(t[i]);
        }

    }

    while (!s.empty())
    {
        char c = s.top();
        ans += c;
        s.pop();

    }

    cout << ans << endl;
}

int main()
{
    string s = "a+(b*c)/(b^e)-c";
    infix_to_postfix(s);
    return 0;
}