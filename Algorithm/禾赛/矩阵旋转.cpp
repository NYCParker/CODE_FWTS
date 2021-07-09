#include<iostream>
#include <vector>
using namespace std;

/*
有一个NxN整数矩阵，请编写一个算法，将矩阵顺时针旋转90度。 
给定一个NxN的矩阵，和矩阵的阶数N,请返回旋转后的NxN矩阵,保证N小于等于300。 
测试样例： [[1,2,3],[4,5,6],[7,8,9]],3 返回：[[7,4,1],[8,5,2],[9,6,3]]
*/

class Rotate {

public:

    vector<vector<int>> rotateMatrix(vector<vector<int>> mat, int n) 
	{
		for(int i = 0;i<n/2;i++)
		{
			for(int j=i;j<n-i-1;j++)
			{
				int temp  = mat[i][j];
				int M = n - j -1;
				int N = n - i -1;
				mat[i][j] = mat[M][i];
				mat[M][i] = mat[N][M];
				mat[N][M] = mat[j][N];
				mat[j][N] = temp;				
			}
		}
		return mat;
	}
};

int main()
{
	vector<vector<int>> test = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	cout<<"rotate before:"<<endl;
	for(auto i:test)
	{
		for(auto j:i)
			cout<<j<<',';
		cout<<endl;	
	}
	
	Rotate R;
	vector<vector<int>> res = R.rotateMatrix(test,test.size());
	cout<<"rotate after:"<<endl;
	for(auto i:res)
	{
		for(auto j:i)
			cout<<j<<',';
		cout<<endl;	
	}
}
	