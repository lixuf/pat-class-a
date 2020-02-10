#include<vector>
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int maxlen = 102;
struct Node
{
	
	vector<int> child;
}node[maxlen];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int n1 = 0; n1 < m; n1++)
	{
		int root;
		cin >> root;
		int child;
		cin >> child;
		for (int n2 = 0; n2 < child; n2++)
		{
			int mid;
			cin >> mid;
			node[root].child.push_back(mid);
		}
	}
	queue<int> level;
	level.push(1);
	int max_h = level.size();
	while (!level.empty())
	{
		int count = 0;
		for (int n2 = 0; n2 < max_h; n2++)
		{
			if (node[level.front()].child.size() == 0)
			{
				count++;
				level.pop();
			}
			else
			{
				for (int n1 = 0; n1 < node[level.front()].child.size(); n1++)
				{
					level.push(node[level.front()].child[n1]);
				}
				level.pop();
			}
		}
		max_h = level.size();
		cout << count;
		if (max_h != 0)
		{
			cout << " ";
		}
	}
	system("pause");
	return 0;
}