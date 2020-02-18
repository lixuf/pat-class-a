#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
bool cmp(pair<int, int> x, pair<int, int> y)
{
	return x.second > y.second;
}
vector<char> fuhao = { 'A','C','M','E' };
int main()
{
	int n, m;
	map<int, bool> i2b;
	scanf_s("%d%d", &n, &m);
	if (m == 0)
	{
		return 0;
	}
	vector<pair<int, int>> data[4];
	//0 A 1 c 2 m 3 e
	//fir hao  sce shu
	for (int n1 = 0; n1 < n; n1++)
	{
		int hao, c[4];
		scanf_s("%d%d%d%d", &hao, &c[1], &c[2], &c[3]);
		i2b[hao] = 1;
		c[0] = (c[2] + c[3] + c[1]);
		for (int n2 = 0; n2 < 4; n2++)
		{
			data[n2].push_back(pair<int,int>(hao, c[n2]));
		}
	}
	for (int n1 = 0; n1 < 4; n1++)
	{
		sort(data[n1].begin(), data[n1].end(), cmp);
	}
	int shu = 0;
	map<int, pair<int,char>> result;
	for (int n1 = 0; n1 < data[0].size(); n1++)
	{
		for (int n2 = 0; n2 < 4; n2++)
		{
			if (i2b[data[n2][n1].first])
			{
				i2b[data[n2][n1].first] = 0;
				result[data[n2][n1].first] = pair<int,char>(n1+1,fuhao[n2]);
				shu += 1;
			}
			if (shu == n)
			{
				break;
			}
		}
		if (shu == n)
		{
			break;
		}
	}
	vector<int> incha;
	for (int n1 = 0; n1 < m; n1++)
	{
		int mid;
		scanf_s("%d",&mid);
		incha.push_back(mid);
	}
	for (int n1 = 0; n1 < m; n1++)
	{
		int cha;
		cha = incha[n1];
		if (result.count(cha) != 0)
		{
			printf("%d %c", result[cha].first, result[cha].second);
		}
		else
		{
			printf("N/A");
		}
		if (n1 != m - 1)
		{
			printf("\n");
		}
	}
	system("pause");
	return  0;

}
/*
5 5
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105

*/