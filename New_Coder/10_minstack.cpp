//总体思路没问题
//一个栈正常进出，用另一个栈记录最小值，重复也需要记录（其实归根结底就是栈s1里的最小值你要随时有数）
//当栈弹出最小值时，记录的栈也要弹出，栈顶始终记录原栈里存在的最小值

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void push(int value)
    {
        if (s1.size() == 0)
        {
            min1 = value;
            s2.push(min1);
        }
        else
        {
            if (min1 > value || min1 == value)
            {
                min1 = value;
                s2.push(min1);
            }
        }
        s1.push(value);
    }
    void pop()
    {
        if (s1.top() == min1)
        {
            s2.pop();
            min1 = s2.top();
        }
        s1.pop();
    }

    int top()
    {
        return s1.top();
    }
    int min()
    {
        return min1;
    }

private:
    stack<int> s1;
    stack<int> s2;
    int min1 = 0;
    int flag = 0;
};