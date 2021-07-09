//#include <stdio.h>    
//#include <string.h>
//#include <ctype.h>      
//#include <stdlib.h>   
//#include <math.h>  

#include  <iostream>
using namespace std;
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <set>

class Solution {
public:
	bool backspaceCompare(string s, string t) {
		string s1, s2;
		int i = 0;
		int j = 0;
		while (s[i] != '\0')
		{
			if (s[i] != '#')
				s1.push_back(s[i]);
			else
				s1.erase(s1.end() - 1);

			i++;
		}

		while (t[j] != '\0')
		{
			if (t[j] != '#')
				s2.push_back(t[j]);
			else
				s2.erase(s2.end() - 1);
			j++;
		}

		if (s1.compare(s2) == 0)
			return true;
		else
			return false;
	}
};

int main() {

	Solution S;
	string s = "ab#c";
	string t = "ad#c";
	cout<<S.backspaceCompare(s, t);

	system("pause");

	return 0;
}