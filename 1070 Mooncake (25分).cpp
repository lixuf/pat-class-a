#include<vector>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	float liang;
	float price;
	float dan;
	node(float liang1) :liang(liang1) {};
};
bool cmp(node x, node y)
{
	return x.dan > y.dan;
}
int main()
{
	int n;
	cin >> n;
	int m;
	cin >>  m;
	vector<node> list;//1Kucn 2price
	int maxhave= 0;
	for (int n1 = 0; n1 < n; n1++)
	{
		float mid;
		scanf_s("%f", &mid);
		maxhave += mid;
		list.push_back(node(mid));
	}
	float maxq = 0;
	for (int n1 = 0; n1 < n; n1++)
	{
		float mid;
		scanf_s("%f", &mid);
		maxq += mid;
		list[n1].dan = mid/ list[n1].liang;
		list[n1].price = mid;
	}
	if (maxhave <= m)
	{
		printf("%.2f", maxq);
		system("pause");
		return 0;
	}
	sort(list.begin(), list.end(), cmp);
	float resu = 0.0;
	for (int n1 = 0; n1 < list.size(); n1++)
	{
		if (m <= list[n1].liang)
		{
			if (m == list[n1].liang)
			{
				resu += list[n1].price;
				break;
			}
			else
			{
				resu += list[n1].dan*m;
				break;
			}

		}
		resu += list[n1].price;
		m -= list[n1].liang;
	}
	printf("%.2f", resu);
	system("pause");
	return 0;
}
/*
3 1
10 12 10
7.5 7.2 4.5
*/