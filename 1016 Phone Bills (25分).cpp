#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;
vector<int> t2m;
struct node
{
	int re, shi, fen;
	int stuat;
	string name;
	node(int _re, int _shi, int _fen, int _stuat, string _name) :re(_re), shi(_shi), fen(_fen), stuat(_stuat), name(_name) {};
};
vector<node> table;
int zhuan(char x, char y)
{
	return (x - '0') * 10 + (y - '0');
}
int suan(int x, int y)
{
	int miu = 0;
	int cost = 0;
	while (table[x].re != table[y].re||table[x].shi!=table[y].shi)
	{
		int cha;
		cha=60 - table[x].fen;
		miu += cha;
		cost+=t2m[table[x].shi] *cha;
		table[x].fen = 0;
		table[x].shi += 1;
		if (table[x].shi >= 24)
		{
			table[x].shi = 0;
			table[x].re += 1;
		}
	}
	int cha = table[y].fen - table[x].fen;;
	miu += cha;
	cost += t2m[table[x].shi] * cha;
	printf(" %d $%.2f\n", miu, cost / 100.0);
	return cost;
	
}
bool cmp(node x, node y)
{
	if (x.name == y.name)
	{
		if (x.re != y.re)return x.re<y.re;
		if (x.shi != y.shi)return x.shi<y.shi;
		if (x.fen != y.fen)return x.fen<y.fen;
	}
	else
	{
		return x.name < y.name;
	}
}

map<string, int> yue;
int main()
{
	for (int n1 = 0; n1 < 24; n1++)
	{
		int mid;
		scanf_s("%d", &mid);
		t2m.push_back(mid);
	}
	int n;
	scanf_s("%d", &n);
	for (int n1 = 0; n1 < n; n1++)
	{
		string name, time, stua;
		cin >> name >> time >> stua;
		bool stuat;
		if (stua == "on-line")
		{
			stuat = 1;
		}
		else
		{
			stuat = 0;
		}
		yue[name]= zhuan(time[0], time[1]);
		table.push_back(node(zhuan(time[3], time[4]), zhuan(time[6], time[7]), zhuan(time[9], time[10]), stuat, name));
	}
	sort(table.begin(), table.end(), cmp);
	int totel = 0;
	int stuu = 1;
	int stuuu = 1;
	for (int n1 = 0; n1 < table.size(); n1++)
	{
		if (n1 == 0 || table[n1].name != table[n1 - 1].name)
		{
			stuu = 0;
			
			if (stuuu == 0)
			{
				printf("Total amount: $%.2f\n", totel / 100.0);
			}
			totel = 0;
			stuuu = 1;
		}
		else if (table[n1].stuat < table[n1 - 1].stuat)
		{
			if (stuu == 0)
			{
				cout << table[n1].name;
				printf(" %02d\n", yue[table[n1].name]);
				stuu = 1;
				stuuu = 0;
			}
			printf("%02d:%02d:%02d %02d:%02d:%02d", table[n1 - 1].re, table[n1 - 1].shi, table[n1 - 1].fen, table[n1].re, table[n1].shi, table[n1].fen);
			totel += suan(n1 - 1, n1);
		}
	}
	if (stuuu == 0)
	{
		printf("Total amount: $%.2f", totel / 100.0);
	}
	system("pause");
	return 0;
}

/*
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
9
CYLL 01:01:06:01 on-line
CYLL 01:01:06:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:02:08:03 off-line
CYJJ 01:02:05:59 on-line
aaa 02:01:01:03 on-line
aaa 02:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 02:05:02:24 on-line
*/