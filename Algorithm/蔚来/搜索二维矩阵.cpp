#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        if(m == 0 || n == 0 ||(matrix[0][0] > target || matrix[m-1][n-1] < target)) 
            return false;
        
        for(int i = 0; i < m; i++)
        {
            if(matrix[i][n-1] < target)  //判断是否在i行
            {
            	
			}
            else if(matrix[i][n-1] == target)
                return true;
            else
            {
                for(int j = 0; j < n; j++) //i行是否存在target
                {
                    if(matrix[i][j] == target)
                        return true;
                }
                return false;
            }
        }
        return false;
    }
};

int main()
{
	Solution s;
	vector<vector<int>> test = {{1},{3}};
	int target = 3;
	cout<<s.searchMatrix(test,target);
}