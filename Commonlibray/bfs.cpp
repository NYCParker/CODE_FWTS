#include <iostream>
using namespace std;
#include<queue>

string compileSeq(string input);
int main()
{
	string input = "1,2,-1,1";
	string output = compileSeq(input);
	cout<<output;

}

string compileSeq(string input) {
        // write code here
        //去除','转换成数组
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
                nums.push_back(-1);
            i++;
        }
        
        int n = nums.size();
        vector<vector<int>> e(n);
        vector<int> r(n,0);
        for(int i = 0; i < n; i++){
            if(nums[i] != -1){
                e[nums[i]].push_back(i);
                r[i]++;
            }
        }
        string ans;
        priority_queue<int,vector<int>,greater<>> q;
        for(int i=0;i<n;i++)
		{
            if(r[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int f=q.top();
            q.pop();
            for(int t:e[f]){
                r[t]--;
                if(r[t]==0)
                    q.push(t);
            }
            ans+=','+to_string(f);
        }
        return ans.substr(1);
    }