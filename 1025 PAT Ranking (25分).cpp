#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
struct node
{
	string reg;
	int chang;
	int fen;
	int pai;
	node(int _chang, int _fen, string _reg) :chang(_chang), fen(_fen), reg(_reg) {};
};
bool cmp(node x, node y)
{
	if (x.fen != y.fen)
	{
		return x.fen > y.fen;
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
	cin >> n;
	vector<int> chang_rank;
	vector<int> crm;
	for (int n1 = 1; n1 <= n; n1++)
	{
		int num;
		cin >> num;
		for (int n2 = 0; n2 < num; n2++)
		{
			string reg;
			cin >> reg;
			int fen;
			scanf_s("%d", &fen);
			list.push_back(node(n1, fen, reg));
		}
		chang_rank.push_back(1);
		crm.push_back(0);
	}
	sort(list.begin(), list.end(), cmp);
	int rank = 1;
	int rmid = 0;
	cout << list.size() << "\n";
	for (int n1 = 0; n1 < list.size(); n1++)
	{
		if (n1 != 0 && list[n1].fen != list[n1 - 1].fen)
		{
			rank += rmid;
			rmid = 0;
			for (int n3 = 0; n3 < crm.size(); n3++)
			{
				if (crm[n3] != 0)
				{
					chang_rank[n3] += crm[n3];
					crm[n3] = 0;
				}
			}
			
		}
		cout << list[n1].reg;
		printf(" %d %d %d", rank, list[n1].chang, chang_rank[list[n1].chang - 1]);
		rmid += 1;
		crm[list[n1].chang - 1] += 1;
		if (n1 != list.size() - 1)
		{
			cout << "\n";
		}
	}
	system("pause");
	return 0;
}