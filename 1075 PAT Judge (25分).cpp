#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxk = 6;
struct node
{
	int reg;
	int ti[maxk] = { -1,-1,-1,-1,-1,-1 };
	int wanmei;
	int sum;
	bool flag;
	node(int hao,int _wanmei,int _sum,bool _flag ) :reg(hao),wanmei(_wanmei),sum(_sum),flag(_flag){};
};
vector<node> list;
bool cmp(node x, node y)
{
	if (x.sum != y.sum)
	{
		return x.sum > y.sum;
	}
	else
	{
		if (x.wanmei != y.wanmei)
		{
			return x.wanmei > y.wanmei;
		}
		else
		{
			return x.reg < y.reg;
		}
	}
}
int main()
{
	int n, k, m;
	scanf_s("%d%d%d", &n, &k, &m);
	vector<int> fenman(1, 0);
	for (int n1 = 0; n1 < k; n1++)
	{
		int mid;
		scanf_s("%d", &mid);
		fenman.push_back(mid);
	}
	list.push_back(node(0, 0, 0,false));
	for (int n1 = 0; n1 < n; n1++)
	{
		list.push_back(node(n1 + 1,0,0,false));
	}
	for (int n1 = 0; n1 < m; n1++)
	{
		int hao, ti, fen;
		scanf_s("%d%d%d", &hao, &ti, &fen);
		if (fen != -1)
		{
			list[hao].flag = true;
			if (list[hao].ti[ti] > 0)
			{
				if (list[hao].ti[ti] >= fen)
				{
					continue;
				}
				else
				{
					list[hao].sum -= list[hao].ti[ti];
				}
			}
			list[hao].sum += fen;
			list[hao].ti[ti] = fen;
			if (fen == fenman[ti])
			{
				list[hao].wanmei += 1;
			}
		}
		else
		{
			list[hao].ti[ti] = 0;
		}
	}
	int e = 0;
	for (int n1 = 0; n1 <= n; n1++)
	{
		
		if (list[n1-e].flag == false)
		{
			list.erase(list.begin() + (n1-e), list.begin() + (n1+1-e));
			e++;
		}
	}
	sort(list.begin(), list.end(), cmp);
	int rank = 1;
	int j = 0;
	for (int n1 = 0; n1 < list.size(); n1++)
	{
		if (n1 != 0 && list[n1].sum != list[n1 - 1].sum)
		{
			rank += j;
			j = 1;
		}
		else
		{
			j += 1;
		}
		printf("%d %05d %d", rank, list[n1].reg, list[n1].sum);
		for (int n2 = 1; n2 <= k; n2++)
		{
			if (list[n1].ti[n2] != -1)
			{
				printf(" %d", list[n1].ti[n2]);
			}
			else
			{
				printf(" -");
			}
		}
		if (n1 != list.size() - 1)
		{
			printf("\n");
		}
	}
	system("pause");
	return 0;
}
/*
100 5 10
20 25 25 30 9
00005 1 20
00006 4 -1
00001 2 18
00002 1 20
00004 2 20
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0
*/