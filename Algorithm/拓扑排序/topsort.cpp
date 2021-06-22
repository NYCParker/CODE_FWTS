#include<iostream>
using namespace std;
#include<queue>
#include<vector>

int topsort(vector<vector<int>>& relations) 
{
	/***1. 遍历，找入度为0的顶点，使用栈或队列存储**/
	
	/***2. 出栈，删除连线，然后与它相邻的定点，入度减1**/
	
	/***3. 入度为0的顶点入栈，然后出栈，删除连线，然后与它相邻的定点，入度减1**/
}



int main()
{	
	//去除','转换成数组
	string input = "1,2,-1,1";
    int flag = 0;
    int len=input.length();

    vector<int> nums;
    int i = 0;
    while(i < len)
    {
        string number;
        while(i < len && input[i]!=',')
        {
            number += input[i];
            i++;
        }
        if(number[0] != '-')
        {
        	nums.push_back(stoi(number));
        }
        else
        {           	
            nums.push_back(stoi(number.substr(1))*(-1));
        }
        i++;
    }
	
	int n = nums.size();
	priority_queue<int,vector<int>,greater<>> queue; //升序队列，小顶堆，默认大顶堆，题目要求升序输出
	vector<int> vis(n);
	
	for (int i = n - 1; i >= 0; --i) 
	{
        if (nums[i] == -1) 	
		{
            queue.push(i);
        }
    }
    
    string ans;
    
	while(!queue.empty())
	{
		int e = queue.top();
		queue.pop();
		vis[e] = 1;
		ans += ','+to_string(e);
		for (int i = n - 1; i >= 0; --i) 
		{
            if (!vis[i] && nums[i] == e) 
			{
                queue.push(i);
            }
        }		
	}	
//	for(const auto& i : nums)
//            cout << i << ' ';
            
    cout<<ans.substr(1);
}