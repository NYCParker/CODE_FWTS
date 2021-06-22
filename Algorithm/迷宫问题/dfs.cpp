#include <bits/stdc++.h>
using namespace std;

/*
5 4
1 1 2 1
1 1 1 1
1 1 2 1
1 2 1 1
1 1 1 2
1 1 4 3

*/
static int a[100][100]; //存储节点是否有障碍 1：无障碍 2：有障碍
static int v[100][100];//存储节点的访问情况，0：未访问 1：访问

int dy[4] = {1,0,-1,0};//顺时针访问：右下左上
int dx[4] = {0,1,0,-1};
int endx,endy;
int minstep = numeric_limits<int>::max();

void dfs(int x, int y, int step)
{
	if(x==endx && y==endy)
	{
		if(step<minstep)
			minstep = step;
		return;
	}
	
	//顺时针试探
	for(int k = 0;k < 4;k++)
	{
		int tx = x + dx[k];
		int ty = y + dy[k];
		if(a[tx][ty]==1 && v[tx][ty]==0)
		{
			v[tx][ty] = 1;
			dfs(tx,ty,step+1);
			v[tx][ty] = 0;      //回溯时，要将当前点设置为未访问
		}
	}
	return;
}



int main()
{
	int m,n;
	cin>>m>>n;
	int x,y;
	for(int i = 1;i <= m;i++)
		for(int j = 1;j <= n;j++)
		{
			scanf("%d",&a[i][j]);
		}
		
	int startx, starty;
	cin>>startx>>starty>>endx>>endy;
	
	v[startx][starty]=1;
	dfs(startx,starty,0);
	cout<<"answer is: "<<minstep<<endl;
}