#include <bits/stdc++.h>
using namespace std;

/*
Floyed算法：求解任意两个点的最短路径
*/
int a[101][3];
double f[101][101];
int n,i,j,k,x,y,m,s,e;


int main()
{
	freopen("short.in","r",stdin);
	freopen("short.out","w",stdout);
	cin>>n;
	for(int i =1; i <= n;i++)
		cin>>a[i][1]>>a[i][2];
	cin>>m;
	memset(f,0x7f,sizeof(f));
	
	for(int i =1; i <= m;i++)
	{
		cin>>x>>y;
		f[y][x] = f[x][y] = sqrt(pow(double(a[x][1]-a[y][1]),2)+pow(double(a[x][2]-a[y][2]),2));
	}
	cin>>s>>e;
	
	/*二维数组存储图*/
	//vector<vector<int>> graph(n+1,vector<int>(n+1,m_max));	
	/*Floyed算法*/
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			for(int k = 1;k <= n;k++)
			{
				if((i!=j)&&(i!=k)&&(j!=k)&&(f[j][k]>f[k][i]+f[i][k]))
					f[j][k] = f[k][i]+f[i][k];
			}
	printf("%.2lf",f[s][e]);
	//cout << "answer=" << setprecision(3) << f[s][e] <<endl;

}