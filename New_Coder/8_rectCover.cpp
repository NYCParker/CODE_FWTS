//画一下就知道了 还是斐波拉契

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rectCover(int number)
    {
        int first = 2;
        int second = 3;
        int last = 5;
        if (number < 4)
        {
            return number;
        }

        else
        {
            for (int i = 0; i < number - 4; i++)
            {
                first = second;
                second = last;
                last = first + second;
            }
            return last;
        }
    }
};