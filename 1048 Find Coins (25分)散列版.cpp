#include<cstdio>
#include<map>
using namespace std;
int main()
{
	int n, m;
	scanf_s("%d%d", &n, &m);
	map<int, int> cc;
	for (int n1 = 0; n1 < n; n1++)
	{
		int mid;
		scanf_s("%d", &mid);
		if (cc.count(mid))
		{
			cc[mid] += 1;
		}
		else
		{
			cc[mid] = 1;
		}
	}
	for (pair<int, int> c : cc)
	{
		int cha = m - c.first;
		if (cha < c.first)
		{
			printf("No Solution");
			break;
		}
		if (cc.count(cha))
		{
			if (cha == c.first)
			{
				if (c.second < 2)
				{
					printf("No Solution");
					
				}
				else
				{
					printf("%d %d", c.first, c.first);
				}
			}
			else
			{
				printf("%d %d", c.first, cha);
			}
			break;
		}
	}
	system("pause");
	return 0;
}