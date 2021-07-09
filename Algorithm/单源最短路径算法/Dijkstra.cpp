#include <bits/stdc++.h>
using namespace std;

/*
Dijkstra算法的时间复杂度O(n^2)，它不能处理存在负边权的情况，只能计算起点只有一个的情况
算法描述：
设起点s，disv[v]表示从s到v的最短路径长度，w[u][v]为u到v边长的值
a)初始化：dis[v]=∞(v≠s),dis[s]=0
b)for(i=1;i<=n;i++)
1. 在没有被访问过的点中找一个顶点u使得dis[u]最小
2. u标记为已确定最短路径的顶点（白点）
3.For 与u相连的每个未确定最短路径的顶点v（蓝点）
if(dis[u]+w[u][v] < dis[v])
{
	dis[v] = dis[u]+w[u][v];
}
c)dis[v]为s到v的最短距离
*/

const static int m_max=0x3f3f3f;
int n,m,s;


int Dijkstra(int n, int m, vector<vector<int> >& graph) 
{
        // write code here
        vector<vector<int>> mp(n+1,vector<int>(n+1,m_max));
        for(int i=0;i<m;i++)
        {
            int u = graph[i][0];
            int v = graph[i][1];
            if(mp[u][v]>graph[i][2])
                mp[u][v]=mp[v][u]=graph[i][2];  //如果是有向图mp[u][v]=graph[i][2]; 
		}
        
        vector<int> vis(n+1,0);
        vector<int> dis(n+1,m_max);
        dis[1]=0;
        while(1)
        {	
            //寻找蓝点
            int mini=0,minx=m_max;
            for(int i = 1;i <= n;i++)
            {
                if(!vis[i] && dis[i] < minx)
                {
                    mini = i;
                    minx = dis[i];
                }
            }

            if(mini == 0)break;//如果没有蓝点结束
            vis[mini] = 1;

			/*计算与蓝点相连的每个未确定最短路径的顶点（白点）的距离*/
            for(int i=1;i<=n;i++)
            {
                if(!vis[i] && dis[mini]+mp[mini][i] < dis[i])
                {
                    dis[i] = dis[mini]+mp[mini][i];
                }
            }
        }
        return dis[n];
}

/*
输入
2 1
1 2 3
3 3
1 2 5
2 3 5
3 1 2
5 5
1 2 2
1 4 5
2 3 3
3 5 4
4 5 5
0 0


输出
3
2
9

*/


int main()
{	
	while(scanf("%d%d",&n,&m)!=EOF&&n)
	{
		vector<vector<int>> graph(m,vector<int>(3,0));
		for(int i=0;i<m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			graph[i][0] = u;
			graph[i][1] = v;
			graph[i][2] = w;
		}
		int ret = Dijkstra(n,m,graph);
		cout<<ret<<endl;
	}
}