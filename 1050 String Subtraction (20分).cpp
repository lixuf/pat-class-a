#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	string i1,i2;
	getline(cin, i1);
	getline(cin, i2);
	map<char, int> cc;
	for (int n1 = 0; n1 < i2.size(); n1++)
	{
		if (!cc.count(i2[n1]))
		{
			cc[i2[n1]] = 1;
		}
	}
	string oo = "";
	for (int n1 = 0; n1 < i1.size(); n1++)
	{
		if (!cc.count(i1[n1]))
		{
			oo+=i1[n1];
		}
	}
	cout << oo;
	system("pause");
	return 0;
}