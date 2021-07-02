#include <bits/stdc++.h>
using namespace std;

int Binary_search(vector<int> &a ,int key)
{
	int low = 0;
	int high = a.size()-1;
	int count = 0;
	while(low <= high)
	{
		int mid = low + (high - low)/2;
		count++;
		if(a[mid] > key)
			high = mid-1;
		else if(a[mid] < key)
			low = mid+1;
		else
		{
			cout<<"Search Times:"<<count<<endl;
			return mid;
		}
	}
	return -1;
}

/* 插值查找 */
int Interpolation_Search(vector<int> &a ,int key)
{
	int count = 0;
	int low=1;	/* 定义最低下标为记录首位 */
	int high=a.size()-1;	/* 定义最高下标为记录末位 */
	while(low<=high)
	{
		int mid=low+ (high-low)*(key-a[low])/(a[high]-a[low]); /* 插值 */
		count++;
		if (key<a[mid])		/* 若查找值比插值小 */
			high=mid-1;		/* 最高下标调整到插值下标小一位 */
		else if (key>a[mid])/* 若查找值比插值大 */
			low=mid+1;		/* 最低下标调整到插值下标大一位 */
		else
		{
			cout<<"Search Times:"<<count<<endl;
			return mid;
		}
	}
	return 0;
}



int main()
{
	vector<int> v1;
	for( int i = 1; i <= 1000; i++ ) {
	   v1.push_back( 2*i );
	}  
	
	cout<<Binary_search(v1,56)<<endl;
	int ret = Interpolation_Search(v1,56);
	cout<<ret<<endl;

}