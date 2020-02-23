#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	string name;
	int reg;
	int fen;
	node(int _reg, string _name, int _fen) :reg(_reg), name(_name), fen(_fen) {};
};
bool cmp1(node x, node y)
{
	return x.reg < y.reg;
}
bool cmp2(node x, node y)
{
	if (x.name != y.name)
	{
		return x.name < y.name;
	}
	else
	{
		return x.reg < y.reg;
	}
}
bool cmp3(node x, node y)
{
	if (x.fen != y.fen)
	{
		return x.fen < y.fen;
	}
	else
	{
		return x.reg < y.reg;
	}
}
vector<node> list;
int main()
{
	int n;
	int c;
	cin >> n >> c;
	for (int n1 = 0; n1 < n; n1++)
	{
		string  name;
		int reg;
		int fen;
		scanf_s("%d", &reg);
		cin >> name;
		scanf_s("%d", &fen);
		list.push_back(node(reg, name, fen));
	}
	if (c == 1)
	{
		sort(list.begin(), list.end(), cmp1);
	}
	else if(c==2)
	{
		sort(list.begin(), list.end(), cmp2);
	}
	else
	{
		sort(list.begin(), list.end(), cmp3);
	}
	for (int n1 = 0; n1 < list.size(); n1++)
	{
		printf("%06d %s %d",list[n1].reg, list[n1].name.c_str(),  list[n1].fen);
		if (n1 != list.size() - 1)
		{
			printf("\n");
		}
	}
	system("pause");
	return 0;
}