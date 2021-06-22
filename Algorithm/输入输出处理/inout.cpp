#include <iostream>
#include <string>
#include <vector>
#include "stdio.h"
using namespace std;

/***空格间隔****/ 
//int main()
//{
//    int a[20];
//    int i = 0;
//    char c;
//    cin>>a[i++];
//    while((c=getchar())!='\n')
//    {
//        cin>>a[i++];
//    }
//    for(int j=0;j<i;j++)
//    {
//        cout<<a[j]<<' ';
//    }
//}


/***逗号间隔****/ 
//int main ()
//{
//    string s;
//
//    while(cin>>s){
//
//        vector<int>nums;
//
//        char *str = (char *)s.c_str();//string --> char
//        const char *split = ",";
//        char *p = strtok (str,split);//逗号分隔依次取出
//
//        int a;
//        while(p != NULL) {
//            sscanf(p, "%d", &a);//char ---> int
//            nums.push_back(a);
//            p = strtok(NULL,split);
//        }
//
//        //printf
//        for (int i=0; i<nums.size(); i++) {
//            printf ("%d\n",nums[i]);
//        }
//    }
//
//
//    return 0;
//}

/**终极版 处理逗号或者空格间隔**/
void inputdeal(void)
{
	vector<int> data;
	int tmp;
	while (cin>>tmp){
		data.push_back(tmp);
		if (cin.get() == '\n') break;
	}
	for(int j=0;j<data.size();j++)
    {
        cout<<data[j]<<' ';
    }
}

/**处理类似"1,2;3,4"的结构，解析成二维数组**/
void inputdeal2(void)
{
	int n;
	cin>>n;
	
	vector<vector<int>> in;
	
	int temp;
	vector<int> tem;
	
	while(cin>>temp)
	{
		tem.push_back(temp);
		char var = cin.get();
		if(var == '\n' )
		{ 
			in.push_back(tem);
			break;
		}
		else if(var == ';')
		{
			in.push_back(tem);
			tem.resize(0);
		} 
	}
	
	
	
	
	for(const auto& e : in){
        for(const auto& i : e)
            cout << i << ' ';
        cout << '\n';
    }

}


/***输入是字符串逗号间隔解析成数组（支持负数），输出带逗号间隔的数组****/
string compileSeq(string input) {
    // write code here
    //去除','转换成数组
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

    string ans;
    for(int i= 0;i < n;i++)
    {
    	ans+=','+to_string(nums[i]);
	}
           
    return ans.substr(1);
}

    
    
int main()
{
	string input = "-1,2,1,3,-9,-7,0,1,1";
	string output = compileSeq(input);
	cout<<output;
}
