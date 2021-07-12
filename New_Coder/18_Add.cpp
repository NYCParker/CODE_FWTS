//加法，但又不是加法
//这题没做出来
//2进制 或可以求得

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Add(int num1, int num2) {
        int x = num1;

        num1 = num1^num2;
        num2 = (x&num2)<<1;

        while(num2!=0)
        {
            x = num1;
            num1 = num1^num2;
            num2 = (x&num2)<<1;
        }
        return num1;
    }
};