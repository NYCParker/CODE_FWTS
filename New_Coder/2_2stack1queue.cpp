//有个矛盾点 如果先pop 那么return是下一个top，如果先return pop得放到下一轮
//用一个技巧，来处理看一下栈顶元素，并出栈        temp = stack2.top();
//       stack2.pop();
//       return temp;
//两个栈实现队列，一定要清空stack2之后再

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        int temp;

        if (stack2.empty())
        {
            while (stack1.size())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        temp = stack2.top();
        stack2.pop();
        return temp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

Solution s;
int main()
{
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.push(4);
    s.pop();
    s.pop();
    s.pop();
}