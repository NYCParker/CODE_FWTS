/*
给定一个整形数组arr,已知其他所有的值都是非负的，将这个数组看作一个容器，请返回容器能装多少水
*/

#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
	/**
	 * max water
	 * @param arr int整型vector the array
	 * @return long长整型
	 */
	long long maxWater(vector<int>& arr) {
		// write code here 
		int len = arr.size();
		int maxleft = arr[0];
		int maxright = arr[len-1];
		
		int i = 0;
		int j = len-1;
		long ret = 0;
		while(i<j)
		{
			if(maxleft < maxright)
			{
				i++;
				if(maxleft <= arr[i])
				{
					maxleft = arr[i];
				}
				else
				{
					ret += maxleft - arr[i];
				}
			}
			else
			{
				j--;
				if(maxright<= arr[j])
				{
					maxright = arr[j];
				}
				else
				{
					ret += maxright - arr[j];
				}				
			}		
		}
		return ret;
	}
};

int main()
{
	vector<int> arr = {3,1,2,5,2,4};
	
	Solution s;
	long ret = s.maxWater(arr);
	
	cout<<ret<<endl;
}