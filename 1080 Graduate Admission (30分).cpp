#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct student
{
	int ge, gi;
	int sum;
	int rank, index;
	int gue[6];
	student(int gee, int gie, int _rank, int _index) :ge(gee), gi(gie), rank(_rank), index(_index),sum((gee+gie)/2) {};
};
struct school
{
	int sum;
	int muqian;
	int lu[40010];
	int presum=0, prege=0;
	school(int _sum, int _muqian) :sum(_sum), muqian(_muqian) {};
};
bool cmp(student x, student y)
{
	if (x.sum != y.sum)
	{
		return x.sum > y.sum;
	}
	else
	{
		return x.ge > y.ge;
	}
}
vector<school> sch;
vector<student> stu;
int main()
{
	int n, m, k;
	scanf_s("%d%d%d", &n, &m, &k);
	for (int n1 = 0; n1 < m; n1++)
	{
		int mid;
		scanf_s("%d", &mid);
		sch.push_back(school(mid, 0));
	}
	for (int n1 = 0; n1 < n; n1++)
	{
		int ge, gi;
		scanf_s("%d%d", &ge, &gi);
		stu.push_back(student(ge, gi, 0, n1));
		for (int n2 = 0; n2 < k; n2++)
		{
			int mid;
			scanf_s("%d", &mid);
			stu[n1].gue[n2] = mid;
		}
	}
	sort(stu.begin(), stu.end(), cmp);
	for (int n1 = 0; n1 < stu.size(); n1++)
	{
		for (int n2 = 0; n2 < k; n2++)
		{
			int ind = stu[n1].gue[n2];
			if (sch[ind].muqian < sch[ind].sum)
			{
				
				sch[ind].lu[sch[ind].muqian] = stu[n1].index;
				sch[ind].muqian += 1;
				sch[ind].presum = stu[n1].sum;
				sch[ind].prege = stu[n1].ge;
				break;
			}
			else if(stu[n1].sum==sch[ind].presum&&stu[n1].ge==sch[ind].prege)
			{
				sch[ind].lu[sch[ind].muqian] = stu[n1].index;
				sch[ind].muqian += 1;
				break;
			}
		}
	}
	for (int n1 = 0; n1 < sch.size(); n1++)
	{
		sort(sch[n1].lu, sch[n1].lu + sch[n1].muqian);
		for (int n2 = 0; n2 < sch[n1].muqian; n2++)
		{
			printf("%d", sch[n1].lu[n2]);
			if (n2 != sch[n1].muqian - 1)
			{
				printf(" ");
			}
		}
		if (sch[n1].muqian==0||n1 != sch.size() - 1)
		{
			printf("\n");
		}
	}
	system("pause");
	return 0;
}
/*
9 6 3
2 1 2 2 2 3
100 100 0 1 2
100 90 0 3 4
90 100 1 2 0
80 90 1 0 2
80 80 0 1 2
80 80 0 1 2
80 70 1 3 2
70 80 1 2 3
100 100 0 2 4*/