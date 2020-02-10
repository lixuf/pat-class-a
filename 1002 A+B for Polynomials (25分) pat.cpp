#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int max1 = 1000;
float ci[max1] = { 0 };
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	vector<int> flag;
	for (int n1 = 0; n1 < 2; n1++)
	{
		int n;
		cin >> n;
		for (int n2 = 0; n2 < n; n2++)
		{
			int mid1;
			float mid2;
			cin >> mid1 >> mid2;
			ci[mid1 - 1] += mid2;
			flag.push_back(mid1);
		}
	}

	sort(flag.begin(), flag.end(),cmp);
	int pre = flag[0];
	for (int n1 = 1; n1 < flag.size(); n1++)
	{
		if (flag[n1] == pre)
		{
			flag.erase(flag.begin() + n1);
			n1--;
		}
		else
		{
			pre = flag[n1];
		}

	}
	for (int n1 = 0; n1 < flag.size(); n1++)
	{
		if (ci[flag[n1] - 1] == 0)
		{
			flag.erase(flag.begin() + n1);
			n1--;
		}
	}
	if (flag.size() == 0)
	{
		cout << "0";
	}
	else
	{
		cout << flag.size() << " ";
	}
	for (int n1 = 0; n1 < flag.size(); n1++)
	{

			cout << flag[n1] << " ";
			printf("%.1f", ci[flag[n1] - 1]);
			if (n1 != (flag.size() - 1))
			{
				cout << " ";
			}

	}
	system("pause");
	return 0;
}