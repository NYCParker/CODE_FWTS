//构建乘积数组
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> multiply(const vector<int> &A)
    {
        vector<int> vecB(A.size(), 1);

        for (int i = 0; i < A.size(); i++)
        {
            vecB[0] = vecB[0] * A[i];
        }

        for (int i = 1; i < vecB.size(); i++)
        {
            for (int j = 0; j < A.size(); j++)
            {
                if (i != j)
                {
                    vecB[i] = vecB[i] * A[j];
                }
            }
        }
        return vecB;
    }
};