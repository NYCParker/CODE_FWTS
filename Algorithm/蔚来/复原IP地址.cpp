#include <iostream>
using namespace std;
#include <vector>

class Solution {
private: vector<string> IPResult;

public:

    vector<string> restoreIpAddresses(string s) {
        string temp;
        helper(0, temp,s,0);
        return IPResult;
    }


    void helper(int start, string temp,string &s, int count)
    {
        if (count == 4 && (temp.length()-4)==s.length()) //s全部取完，减4是去掉.的长度
        {
            temp.pop_back();			//去除点
            IPResult.push_back(temp);
            return;
        }

        if (count == 4)
            return;

        for (int i = start; i < s.length(); i++)
        {
            string temp1 = temp;
//            if (stringToValue(start, i, s) < 256)
			if(atoi(s.substr(start,(i-start+1)).c_str()) < 256) //ip段范围在0-255以内
            {
                if (i != start && s[start] == '0')break;//遇到00直接退出，含前导0
                temp  += s.substr(start,(i-start+1));
                temp.push_back('.');
            }
            else
            {
                break;
            }
            helper(i + 1, temp, s,count + 1);
            temp = temp1;
        }
    }
};


int main()
{
	Solution test;
	string s = "25525511135";
	vector<string> IPResult = test.restoreIpAddresses(s);

	for(auto i:IPResult)
		cout<<i<<' ';
}