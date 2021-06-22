#include <iostream>
using namespace std;
#include <vector>

/*
01背包问题（01 knapsack problem）：一共有N件物品，第i（i从1开始）件物品的重量为w[i]，价值为v[i]。在总重量不超过背包承载上限W的情况下，能够装入背包的最大价值是多少？
https://zhuanlan.zhihu.com/p/93857890?utm_source=wechat_session
*/

int main()
{
	int W;
	cin>>W;
	
	int temp;
	vector<int> w;
	
	while(cin>>temp)
	{
		w.push_back(temp);
		if(cin.get() == '\n')
			break;
	}
	
	vector<int> v;
	
	while(cin>>temp)
	{
		v.push_back(temp);
		if(cin.get() == '\n')
			break;
	}
	int N = v.size();
	
	//dp[i][j]将前i件物品装进限重为j的背包可以获得的最大价值, 0<=i<=N, 0<=j<=W
	vector<vector<int>> dp(N+1, vector<int>(W+1,0));
	
	for(int i = 1;i <= N;i++)
	{
		for(int j = 1;j <= W;j++)
		{
			if (j < w[i-1])//剩余容量小于第i件物品的重量
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i-1]] + v[i-1]);
		}
	}
	
	//动态规划表的输出
	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < dp[0].size(); j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	
	cout << dp[N][W] << endl;
	
	
	
	return 0;
	
}