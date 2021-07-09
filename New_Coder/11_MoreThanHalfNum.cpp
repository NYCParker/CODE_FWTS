
//先按照自己的方式写
//malloc的用法 count = (int*)(malloc(sizeof(int)));
//这题先用我的弱智办法做
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        //先找原数组最大值和最小值
        int max = numbers[0];
        int min = numbers[0];
        int pos;

        for (int i = 1; i < numbers.size(); i++)
        {
            if (max < numbers[i])
            {
                max = numbers[i];
            }

            if (min > numbers[i])
            {
                min = numbers[i];
            }
        }

        //开辟max-min+1长度的数组,并初始化
        int *pcount;
        pcount = (int *)malloc(sizeof(int) * (max - min + 1));

        for (int i = 0; i < max - min + 1; i++)
        {
            pcount[i] = 0;
        }

        for (int i = 0; i < numbers.size(); i++)
        {
            pcount[numbers[i] - min]++;
        }

        //现在找到pcount里大于numbers.size()/2的元素
        for (int i = 0; i < max - min + 1; i++)
        {
            if(pcount[i]>(numbers.size()>>1))
            {
                pos =  i+min;
            }
        }

        return pos;
    }
};