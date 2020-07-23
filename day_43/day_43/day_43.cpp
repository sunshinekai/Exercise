/*
ѡ����
���ӣ�https://www.nowcoder.com/questionTerminal/0e3833932215440cb04a30ef32e70eed?toCommentId=382832

1.
������ ( �����ţ���Ա���ţ��������ţ��������� ) �ж�����Ϊ������Ҫɾ��������ǰ������ǰ����Ϣ�� SQL Ϊ(D)
A delete from ������ where ��������<getdate()+3
B delete from ������ where ��������<DATEADD(yy,3,getdate())
C delete from ������ where ��������<getdate()-3
D delete from ������ where ��������<DATEADD(yy,-3,getdate())

ע��
DATEADD() ��������������ӻ��ȥָ����ʱ������
�﷨
DATEADD(datepart,number,date)
datapart������ȡֵ��Χ��{yy/yyyy,qq/q,mm/m,dy/y,dd/d,wk/ww,dw/w,hh,mi/n,ss/s,ms,mcs,ns}
number ����ϣ����ӵļ����
date �����ǺϷ������ڱ��ʽ

2.
SQL ��ѯ����� WHERE �� GROUP BY �� HAVING ��Щ�ؼ���������÷��ܽ������ǣ�D��
A HAVING�ڲ�ѯ����б���������GROUP BY
B WHERE�Ӿ���������SELECT���ӱ���ָ��ѡȡ����
C GROUP BY�Ӿ���������WHERE�Ӿ����������
D HAVING�Ӿ������ӷ���Ľ����ɸѡ��

ע��
1.havingֻ������group by֮�󣬶Է����Ľ������ɸѡ��ɸѡ��(��ʹ��having��ǰ�������Ƿ���)
2.where�϶���group by֮ǰ 
3.where����������ʽ�ﲻ����ʹ�þۺϺ�������having����
*/


/*
�����

1.
���ӣ�https://www.nowcoder.com/questionTerminal/ceb89f19187b4de3997d9cdef2d551e8

��ͼ��һ���绰�ľŹ�����������һ�����ֶ�ӦһЩ��ĸ������ڹ�����ҵϲ���ѵ绰������Ƴ����Լ���˾�������Ӧ��
���繫˾��Help Desk������4357����Ϊ4��ӦH��3��ӦE��5��ӦL��7��ӦP�����4357����HELP��ͬ��TUT-GLOP�ʹ���888-4567��310-GINO����310-4466��
NowCoder�ս������󣬲���ϰ��������������ʽ�����ڸ���һ���绰�����б��������ת����������ʽ�ĺ��룬��ȥ���ظ��Ĳ��֡�

ʾ����
����
12
4873279
ITS-EASY
888-4567
3-10-10-10
888-GLOP
TUT-GLOP
967-11-11
310-GINO
F101010
888-1200
-4-8-7-3-2-7-9-
487-3279

4 
UTT-HELP
TUT-GLOP
310-GINO
000-1213

���
310-1010
310-4466
487-3279
888-1200
888-4567
967-1111
000-1213
310-4466
888-4357
888-4567
*/

// ��set�����Զ�����
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	int n;
	string mapper[2] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ","22233344455566677778889999" };
	while (cin >> n && n)
	{
		string str, temp;
		set<string> list;
		for (int i = 0; i < n; ++i)
		{
			cin >> str; 
			temp = "";
			for (auto &ch : str)
			{
				if (ch != '-' && isalpha(ch))
					temp += mapper[1][toupper(ch) - 'A'];
				else if (ch != '-' && isalnum(ch))
					temp += ch;
			}
			temp.insert(temp.begin() + 3, '-');
			list.insert(temp);
		}
		for (auto &e : list) 
			cout << e << endl;
		cout << endl;
	}
	return 0;
}

/*
2.
���ӣ�https://www.nowcoder.com/questionTerminal/11cc498832db489786f8a03c3b67d02c
������������ n �� m��������1��2��3.......n ������ȡ������, 
ʹ��͵��� m, Ҫ���������еĿ�������г���

ʾ����
����
���
5 5
1 4 2 3 5
*/

// ��dfs + ����������������

#include<iostream>
#include<vector>
using namespace std;
void help(int n, int m, vector<int>& v, int beg) 
{
	//if (beg>n) return;
	if (m == 0) 
	{
		for (int i = 0; i<v.size(); i++)
			i == 0 ? cout << v[i] : cout << " " << v[i];

		cout << endl;
	}
	for (int i = beg; i <= n && i <= m; i++)
	{
		v.push_back(i);
		help(n, m - i, v, i + 1);
		v.pop_back();
	}
}
int main() 
{
	int n, m;
	while (cin >> n >> m) 
	{
		vector<int> v;
		help(n, m, v, 1);
	}
}