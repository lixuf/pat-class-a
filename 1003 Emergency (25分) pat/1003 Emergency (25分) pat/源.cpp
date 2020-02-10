#include<iostream>
#include<vector>
using namespace std;
struct node
{
	int hao;
	int len;
	node(int _hao, int _len) :hao(_hao), len(_len) {}
};
struct node2
{
	int len;
	int teem;
	node2(int _len, int _teem) :len(_len), teem(_teem) {}
};
const int maxlen = 501;
const int inf = 10000000;
int n, m, c1, c2,c1c;
vector<int> cityteem;
vector<node2> shortlen;
vector<node> zhen[maxlen];
vector<int> fangwen;
vector<int> fangwen2;
void djst()
{
	for (int n1 = 0; n1 < n; n1++)
	{
		fangwen[c1] = 1;
		for (int n2 = 0; n2 < zhen[c1].size(); n2++)
		{
			if (shortlen[c1].len + zhen[c1][n2].len < shortlen[zhen[c1][n2].hao].len)
			{
				shortlen[zhen[c1][n2].hao].len = shortlen[c1].len + zhen[c1][n2].len;
				shortlen[zhen[c1][n2].hao].teem = cityteem[zhen[c1][n2].hao] + shortlen[c1].teem;
				fangwen2[zhen[c1][n2].hao] = fangwen2[c1];
			}
			else if (shortlen[c1].len + zhen[c1][n2].len ==shortlen[zhen[c1][n2].hao].len)
			{
				if (cityteem[zhen[c1][n2].hao] + shortlen[c1].teem > shortlen[zhen[c1][n2].hao].teem)
				{
					shortlen[zhen[c1][n2].hao].teem = cityteem[zhen[c1][n2].hao] + shortlen[c1].teem;
				}
				fangwen2[zhen[c1][n2].hao] += 1;
			}
		}
		int min = inf;
		for (int n2 = 0; n2 < shortlen.size(); n2++)
		{
			if (shortlen[n2].len < min&&fangwen[n2] == 0)
			{
				min = shortlen[n2].len;
				c1= n2;
			}
		}
		if (min == inf)
		{
			return;
		}

	}
}

int main()
{
	cin >> n >> m >> c1c >> c2;
	c1= c1c;
	for (int n1 = 0; n1 < n; n1++)
	{
		int mid;
		cin >> mid;
		cityteem.push_back(mid);
		if (n1 == c1)
		{
			shortlen.push_back(node2(0,mid));
		}
		else
		{
			shortlen.push_back(node2(inf, 0));
		}
		fangwen.push_back(0);
		fangwen2.push_back(0);
	}
	fangwen2[c1c] = 1;
	for (int n1 = 0; n1 < m; n1++)
	{
		int start, end, l;
		cin >> start >> end >> l;
		zhen[start].push_back(node(end, l));
		zhen[end].push_back(node(start, l));
	}
	djst();
	cout << fangwen2[c2]<< " " << shortlen[c2].teem;
	system("pause");
	return 0;
}