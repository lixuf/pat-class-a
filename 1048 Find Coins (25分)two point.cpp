#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n,m;
	vector<int> list;
	scanf_s("%d %d", &n, &m);
	for (int n1 = 0; n1 < n; n1++)
	{
		int mid;
		scanf_s("%d", &mid);
		list.push_back(mid);
	}
	sort(list.begin(), list.end());
	int flag = 0;
	int res2,res1;
	for (int n1 = 0; n1 < list.size(); n1++)
	{
		int cha = m - list[n1];
		if (cha <= list[n1])
		{
			flag = 1;
			break;
		}
		for (int n2 = list.size() - 1; n2 > n1; n2--)
		{
			if (list[n2] == cha)
			{
				flag = 2;
				res2 = list[n2];
				res1 = list[n1];
				break;
			}
			else if (list[n2] < cha)
			{
				if (n2 == list.size() - 1)
				{
					flag = 1;
				}
				break;
			}
		}
		if (flag)
		{
			break;
		}
	}
	if (flag == 1)
	{
		printf("No Solution");
	}
	else
	{
		printf("%d %d", res1, res2);
	}
	system("pause");
	return 0;
}