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
struct point
{
	int x;
	int y;
	int step;
};

queue<point> q;

static int a[100][100]; //存储节点是否有障碍 1：无障碍 2：有障碍
static int v[100][100];//存储节点的访问情况，0：未访问 1：访问

int dy[4] = {1,0,-1,0};//顺时针访问：右下左上
int dx[4] = {0,1,0,-1};
int endx,endy;


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
	
	point start;
	start.x = startx;
	start.y = starty;
	start.step = 0;
	q.push(start);        //队首入队
	v[startx][starty] = 1;
	
	while(!q.empty())
	{
		if(q.front().x == endx && q.front().y == endy)
		{
			cout<<"answer is: "<<q.front().step<<endl;
			break;
		}
		
		//以队首元素为起点沿顺时针方向进行扩展并依次入队
		for(int k = 0;k < 4;k++)
		{
			point temp;
			temp.x = q.front().x + dx[k];
			temp.y = q.front().y + dy[k];
			if(a[temp.x][temp.y] == 1 && v[temp.x][temp.y] == 0)
			{
				temp.step = q.front().step + 1;
				q.push(temp);
				v[temp.x][temp.x] = 1;
			}
		}
		q.pop();//扩展完了将队首元素出队
	}	
}