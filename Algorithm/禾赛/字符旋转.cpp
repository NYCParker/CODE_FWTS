#include <iostream>
#include <string>
using namespace std;


bool CheckReverseEqual(string s1,string s2)
{
	if(s1.length()!=s2.length())
		return false;
		
	s1.append(s1);
	
	if(s1.find(s2) != -1)
		return true;
	return false;
}



int main()
{
	string s1 = "Hello world";
	string s2 = "worldhello";
 
	string s3 = "waterbottle";
	string s4 = "erbottlewat";
 
	cout <<CheckReverseEqual( s1,s2) <<endl;
	cout <<CheckReverseEqual( s3,s4) <<endl;
	cout << endl;
	return 0;
}