//在字符串中找到第一个只出现一次的字符
//str 里出现1次的字符可能有很多 如何确定并找到第一个呢
//字母 ascii码的范围是：65~122  （中间有不是字母的） 但是不影响解题
//貌似这个就是哈希法
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int FirstNotRepeatingChar(string str)
    {
        //首先设一个长度足够长的数组，最长不过(int)('z') - (int)('A') + 1;
        //然后遍历一次，计数各个字母出现的次数
        //重新遍历，把第一个找到出现次数为1的字母返回

        int len = (int)('z') - (int)('A') + 1;
        vector<int> vec(len, 0);

        for (int i = 0; i < str.length(); i++)
        {
            vec[(int)(str[i] - 'A')]++;
        }

        for (int i = 0; i < str.length(); i++)
        {
            if (vec[(int)(str[i] - 'A')] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};

//看到一个写法 用stl的
class Solution
{
public:
    int FirstNotRepeatingChar(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str.find_first_of(str[i]) == str.find_last_of(str[i]))
            {
                return i;
            }
        }
        return -1;
    }
};