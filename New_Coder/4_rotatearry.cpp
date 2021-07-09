//sort算法还是不要直接用- - 有没有更优的办法呢？
//这题考察二分法
//这题二分法没写出来,这题搞死了
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        //sort(rotateArray.begin(),rotateArray.end());
        //return *(rotateArray.begin());
        int first = 0;
        int last = rotateArray.size() - 1;
        
        if(rotateArray.size()==0) 
        {
            return 0;
        }
        //原数列 右边的数 >= 左边的数 正常取最左边的就是答案
        //现在旋转了一部分数组，需要重新找到最左边的点
        //left最左 right最右开始，二分mid first+(last-first)/2   first~mid  mid+1~右
        //有两种情况可以确认位置属于mid的哪一半，否则只能一点点挪
        //1 last<mid 说明最小值在右半边 且mid肯定不是 mid+1~right 
        //2 mid<last 说明在left~mid-1 + mid 包括上

        //再换个思路 从first入手，感觉不行
        //first > mid 肯定在 first+1~mid 但first<mid并不能说明问题 要么first 要么 mid+1~last

        while (first < last)
        {
            if (rotateArray[first] < rotateArray[last])
            {
                return rotateArray[first];
            }

            int mid = first + ((last - first)>>1);

            if (rotateArray[last] < rotateArray[mid])
            {
                first = mid+1;
            }

            else if (rotateArray[mid] < rotateArray[last])
            {
                last = mid;
            }

            else
            {
                --last;
            }
        }

        return rotateArray[first];
    }
};
