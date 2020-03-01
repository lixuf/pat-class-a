#include<iostream>
#include<string>
#include<map>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct car
{
	string name;
	int h, m, s;
	int stu;
	car(int hd, int md, int sd, int st, string na) :name(na), stu(st), h(hd), m(md), s(sd) {};
};
struct quryt
{
	int h, m, s;
	int ind;
	quryt(int hd, int hm, int hs, int indx):ind(indx), h(hd), m(hm), s(hs) {};
};
bool cmp(car x, car y)
{
	if (x.h != y.h)return x.h < y.h;
	if (x.m != y.m)return x.m < y.m;
	return x.s < y.s;
}
bool cmpq(quryt x, quryt y)
{

	if (x.h != y.h)return x.h < y.h;
	if (x.m != y.m)return x.m < y.m;
	if(x.s!=y.s)return x.s < y.s;
	return x.ind < y.ind;
	
}
vector<car> list;
vector<quryt> ques;
map<string,int> s2h;
map<string, int> s2m;
map<string, int> s2s;
map<string, int> s2ind;
quryt maxn=quryt(0,0,0,0);
vector<string> pai;
int mh=0, mm=0, ms=0;
int op(int h, int m, int s)
{
	if (h != mh)return h < mh;
	if (m != mm)return m < mm;
	if (s != ms)return s < ms;
	return -1;
}
map<string, int> ht, mt, st;
void chepai(quryt x, quryt y,string na)
{
	int h, m, s;
	h = y.h - x.h;
	m = y.m - x.m;
	s = y.s - x.s;
	if (s < 0)
	{
		s += 60;
		m -= 1;
	}
	if (m < 0)
	{
		m += 60;
		h -= 1;
	}
	if (ht.count(na) == 0)
	{
		ht[na] = h;
		mt[na] = m;
		st[na] = s;
	}
	else
	{

		ht[na] += h;
		mt[na] += m;
		st[na] += s;
	}
	int t = op(ht[na],mt[na],st[na]);
	if (t==0)
	{
		mh = ht[na];
		mm = mt[na];
		ms = st[na];
		pai.clear();
		pai.push_back(na);
	}
	else if (t == -1)
	{
		pai.push_back(na);
	}
}
int main()
{
	int n, k;
	cin >>n >> k;
	for (int n1 = 0; n1 < n; n1++)
	{
		string name, st;
		int h, m, s;
		cin >> name;
		scanf_s("%d:%d:%d", &h, &m, &s);
		cin >> st;
		if (st == "in")
		{
			list.push_back(car(h, m, s, 1, name));
		}
		else
		{
			list.push_back(car(h, m, s, 0, name));
		}
	}
	sort(list.begin(), list.end(), cmp);
	for (int n1 = 0; n1 < k; n1++)
	{
		int h, m, s;
		scanf_s("%d:%d:%d", &h, &m, &s);
		ques.push_back(quryt(h, m, s, n1));
	}
	for (int n1 = 0; n1 < list.size(); n1++)
	{
		string na = list[n1].name;
		if (list[n1].stu == 1)
		{
			
			s2h[na] = list[n1].h;
			s2m [na]= list[n1].m;
			s2s[na] = list[n1].s;
			s2ind [na]= -1;
		}
		else if (s2h.count(list[n1].name) && s2ind[list[n1].name]== -1)
		{
			s2ind[list[n1].name] = -2;
			ques.push_back(quryt(s2h[na],s2m[na],s2s[na],s2ind[na]));
			ques.push_back(quryt(list[n1].h, list[n1].m, list[n1].s, -1));
			chepai(quryt(s2h[na], s2m[na], s2s[na], s2ind[na]), quryt(list[n1].h, list[n1].m, list[n1].s, -1),na);
		}
	}
	sort(ques.begin(), ques.end(), cmpq);
	int ex = 0;
	vector<int> res(k, 0);
	for (int n1 = 0; n1 < ques.size(); n1++)
	{
		if (ques[n1].ind == -2)
		{
			ex++;
		}
		else if (ques[n1].ind == -1)
		{
			ex--;
		}
		else
		{
			res[ques[n1].ind] = ex;
		}
	}
	for (int n1 = 0; n1 < k; n1++)
	{
		cout << res[n1] << "\n";
	}
	sort(pai.begin(), pai.end());
	for (int n1 = 0; n1 < pai.size(); n1++)
	{
		cout << pai[n1]<<" ";
		
	}
	printf("%02d:%02d:%02d", mh, mm, ms);
	system("pause");
	return 0;
}
/*
16 7
07BD 18:00:01 in
00001 11:30:08 out
DB8A 13:00:00 out
625 23:59:50 out
33CH 10:23:00 in
Z0001 04:09:59 in
H007BD 05:09:59 in
A3Q625 11:42:01 out
H007BD 05:10:33 in
A3Q625 06:30:50 in
J007BD 12:23:42 out
ZAQ625 23:55:00 in
JH00BD 12:24:23 out
ZA13CH 17:11:22 out
JH007D 18:07:01 out
DB8888 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00
*/