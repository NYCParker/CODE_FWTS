#include <iostream>
using namespace std;
#include <vector>

int binaryfind(vector<int> &list, int target)
{
	int left = 0;
	int right = list.size() - 1;
	
	while(left <= right)
	{
		int mid = (right+left)/2;
		if(list[mid] > target)
			right = mid-1;
		else if(list[mid] < target)
			left = mid+1;
		else
			return mid;
	}
	
	return -1;
}

int main()
{
	vector<int> my_list = {1,3,5,7,9};
	
	cout<<binaryfind(my_list, 3)<<endl;
}