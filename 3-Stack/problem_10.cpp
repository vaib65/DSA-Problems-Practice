// check paranthesis
#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>
using namespace std;
bool checkparanthesis(string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty())
            {
                //matching
                char topch = st.top();
                if (ch == ')' && topch == '(')
                {
                    st.pop();
                }
                else if (ch == '}' && topch == '{')
                {
                    st.pop();
                }
                else if (ch == ']' && topch == '[')
                {
                    st.pop();
                }
      
                else
                {
                    //not matching
                    return false;
                }
            }
            else
            {
                //if empty
                return false;
            }
        }
    }

    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    
    // string str = "({[]})";
    string str="({({([[[]]])})})[";
    bool isvalid = checkparanthesis(str);
    

    if (isvalid)
    {
        cout << "string is valid";
    }
    else
    {
        cout << "invalid string";
    }

    // checkparanthesis(str);
}