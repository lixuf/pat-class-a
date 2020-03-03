#include<map>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf_s("%d", &n);
	map<int, int> cc;
	for (int n1 = 0; n1 < n; n1++)
	{
		int mid;
		scanf_s("%d", &mid);
		if (cc.count(mid))
		{
			cc[mid] = -1;
		}
		else
		{
			cc[mid] = n1;
		}
	}
	int min = n;
	int mm;
	for (pair<int, int> c : cc)
	{
		if (c.second == -1)
		{
			continue;
		}
		else if(c.second<min)
		{
			min = c.second;
			mm = c.first;
		}
	}
	if (min == n)
	{
		printf("None");
	}
	else
	{
		printf("%d", mm);
	}
	system("pause");
	return 0;
}