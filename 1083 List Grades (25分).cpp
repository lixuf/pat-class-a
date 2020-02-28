#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
struct node
{
	int fen;
	string reg, name;
	node(int _fen, string _name, string _reg) :name(_name), reg(_reg), fen(_fen) {};
};
int main()
{
	vector<node> list;
	int n;
	cin >> n;
	vector<int> flist[101];
	for (int n1 = 0; n1 < n; n1++)
	{
		int fen;
		string reg, name;
		cin >> name >> reg >> fen;
		list.push_back(node(fen,name,reg));
		flist[fen].push_back(n1);
	}
	int r, l;
	cin >> r >> l;
	int flag = 0;
	for (int n1 = l; n1 >= r; n1--)
	{
		if (flist[n1].size() != 0)
		{
			if (flag == 1)
			{
				cout << "\n";
			}
				flag = 1;
				cout << list[flist[n1][0]].name << " " << list[flist[n1][0]].reg;
			
		}
	}
	if (flag == 0)
	{
		cout << "NONE";
	}
	system("pause");
	return 0;
}
