#include<vector>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	long int a, b;
	cin >> a >> b;
	a = a + b;
	if (a == 0)
	{
		cout << 0;
		return 0;
	}
	char sign;
	if (a >= 0)
	{
		sign = '+';
	}
	else
	{
		a = (-a);
		sign = '-';
	}
	string result;
	int n1 = 1;
	while (a != 0)
	{
		char mid;
		mid = a % 10 + '0';
		a = (a - a % 10) / 10;
		result.insert(result.begin(), mid);
		if (n1 % 3 == 0)
		{
			result.insert(result.begin(), ',');
		}
		n1++;
	}
	if (result[0] == ',')
	{
		result.erase(0, 1);
	}
	for (int n1 = 0; n1 < result.size();n1++)
	{
		if (result[n1] == '0')
		{
			result.erase(0, 1);
		}
		else
		{
			break;
		}
	}
	if (sign == '-')
	{
		result.insert(result.begin(), '-');
	}
	cout << result;
	system("pause");
	return 0;
}