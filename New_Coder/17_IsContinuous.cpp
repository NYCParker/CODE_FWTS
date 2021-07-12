//1~13 5张牌 连续  0癞子 

//注意创建一段连续内存的方式


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {

        //首先判断有没有重复元素，不算0
        vector <int>rep(14,0);
        for(int i=0;i<5;i++)
        {
            rep[numbers[i]]++;
            if(rep[0] == 4)
            {
                return true;
            }
        }

        for(int i=1;i<14;i++)
        {
            if(rep[i]>1)
            {
                return false;
            }
        }

        //除0以外没有重复 ok 继续 到这一步 最少没有0 最多3个0 rep【0】已经保存了
        sort(numbers.begin(),numbers.end());
        if( (numbers[4] - numbers[0+rep[0]]) < 5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};