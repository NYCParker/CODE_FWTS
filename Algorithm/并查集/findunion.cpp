#include <iostream>
using namespace std;
#include <vector>

int fa[10000];

/****初始化，每个节点的祖先指向自己****/
void init(int n)
{
	for(int i = 0; i < n;i++)
	{
		fa[i] = i;
	}
}

/****找到节点的祖先****/
int find(int i)
{
	if(fa[i] == i)
		return i;
	else
		fa[i] = find(fa[i]);//路径压缩
	return fa[i];
}

/***合并两个节点的祖先****/
void unionn(int i, int j)
{
	int fai = find(i);
	int faj = find(j);
	if(fai!=faj)
		fa[fai] = faj; //i的祖先指向j的祖先
}

/*
//例题
int main()
{
	int n,m;
	cin>>n>>m;
	init(n);
	
	int j,k;
	
	for(int i = 0; i < m; i++)
	{
		cin>>j>>k;
		unionn(j,k);
	}
	
	int q;
	cin>>q;
	
	string ans;
	
	for(int i = 0; i < q; i++)
	{
		cin>>j>>k;
		if(find(j)==find(k))
			ans += "YES\n";
		else
			ans += "NO\n";
	}
	cout<<ans;
}
*/

//乐鑫2020笔试第二题
int main()
{
	int m,n,a,b;
	cin>>n>>m>>a>>b;
	
	init(n);
	
	int j,k;
	
	for(int i = 0;i < m; i++)
	{
		cin>>j>>k;
		unionn(j,k);
	}
	
	int ans = 0;
	int count = 0;
	for(int i = 0;i < n; i++)
	{
		if(fa[i] == i)
			count++;
	}
	ans = 2*b+(count-1)*b+count*a;
	cout<<ans<<endl;
	

}

