//找子数组最大值,时间复杂度On 如何做呢

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        vector<int> sumarr;

        int maxitem = array[0];
        int sum = 0;
        int i = 0;
        int flag;

        for (i = 0; i < array.size(); i++)
        {
            if (maxitem < array[i])
            {
                maxitem = array[i];
            }

            if (array[i] < 0)
            {
                sumarr.push_back(sum);
                sum = sum + array[i];
                if (sum < 0)
                {
                    sum = 0;
                }
            }
            else
            {
                sum = sum + array[i];
                flag = 1;
            }
        }

        sumarr.push_back(sum);

        if(flag == 0)
        {
            return maxitem;
        }

        else
        {
        //找sum数组里的最大值
        int max = sumarr[0];

        for (i = 1; i < sumarr.size(); i++)
        {
            if (max < sumarr[i])
            {
                max = sumarr[i];
            }
        }

        return max;
        }
    }
};
