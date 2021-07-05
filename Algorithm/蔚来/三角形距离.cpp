#include <iostream>
using namespace std;
#include <vector>

class Solution {
	float caculateDistance(vector<float>& point, vector<vector<float>>& triangle)
	{
		//判断点是否在三角形内部
		if(isInside(point, triangle))
		{
			return 0;
		}
		else
		{
			
		}
		
	}
	
	bool isInside(vector<float>& point, vector<vector<float>>& triangle)
	{
	    //注意输入点的顺序不一定是逆时针，需要判断一下
	    float x1 = triangle[0][0];
	    float y1 = triangle[0][1];
	    float x2 = triangle[1][0];
	    float y2 = triangle[1][1];
	    float x3 = triangle[2][0];
	    float y3 = triangle[2][1];
	    
	    float x = point[0];
	    
	    float y = point[1];
	    
	    if(crossProduct(x3 - x1, y3 - y1, x2 - x1, y2 - y1) >= 0)
	    {
	        float tmpx = x2;
	        float tmpy = y2;
	        x2 = x3;
	        y2 = y3;
	        x3 = tmpx;
	        y3 = tmpy;
	    }
	    if(crossProduct(x2 - x1, y2 - y1, x - x1, y - y1) < 0) return false;
	    if(crossProduct(x3 - x2, y3 - y2, x - x2, y - y2) < 0) return false;
	    if(crossProduct(x1 - x3, y1 - y3, x - x3, y - y3) < 0) return false;
	    return true;
	}
	
	float crossProduct(float x1, float y1, float x2, float y2)
	{
	    return x1 * y2 - x2 * y1;
	}
};

int main()
{
	
}