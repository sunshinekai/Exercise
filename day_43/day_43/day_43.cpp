/*
选择题
链接：https://www.nowcoder.com/questionTerminal/0e3833932215440cb04a30ef32e70eed?toCommentId=382832

1.
订单表 ( 订单号，雇员代号，地区代号，订购日期 ) 中订单号为主键，要删除订单中前三年以前的信息， SQL 为(D)
A delete from 订单表 where 订购日期<getdate()+3
B delete from 订单表 where 订购日期<DATEADD(yy,3,getdate())
C delete from 订单表 where 订购日期<getdate()-3
D delete from 订单表 where 订购日期<DATEADD(yy,-3,getdate())

注：
DATEADD() 函数在日期中添加或减去指定的时间间隔。
语法
DATEADD(datepart,number,date)
datapart参数的取值范围是{yy/yyyy,qq/q,mm/m,dy/y,dd/d,wk/ww,dw/w,hh,mi/n,ss/s,ms,mcs,ns}
number 是您希望添加的间隔数
date 参数是合法的日期表达式

2.
SQL 查询语句中 WHERE 、 GROUP BY 、 HAVING 这些关键字区别和用法总结错误的是（D）
A HAVING在查询语句中必须依赖于GROUP BY
B WHERE子句用来限制SELECT语句从表中指定选取的行
C GROUP BY子句用来分组WHERE子句的输出结果集
D HAVING子句用来从分组的结果中筛选列

注：
1.having只能用在group by之后，对分组后的结果进行筛选，筛选行(即使用having的前提条件是分组)
2.where肯定在group by之前 
3.where后的条件表达式里不允许使用聚合函数，而having可以
*/


/*
编程题

1.
链接：https://www.nowcoder.com/questionTerminal/ceb89f19187b4de3997d9cdef2d551e8

上图是一个电话的九宫格，如你所见一个数字对应一些字母，因此在国外企业喜欢把电话号码设计成与自己公司名字相对应。
例如公司的Help Desk号码是4357，因为4对应H、3对应E、5对应L、7对应P，因此4357就是HELP。同理，TUT-GLOP就代表888-4567、310-GINO代表310-4466。
NowCoder刚进入外企，并不习惯这样的命名方式，现在给你一串电话号码列表，请你帮他转换成数字形式的号码，并去除重复的部分。

示例：
输入
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

输出
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

// 用set来做自动排序
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
链接：https://www.nowcoder.com/questionTerminal/11cc498832db489786f8a03c3b67d02c
输入两个整数 n 和 m，从数列1，2，3.......n 中随意取几个数, 
使其和等于 m, 要求将其中所有的可能组合列出来

示例：
输入
输出
5 5
1 4 2 3 5
*/

// 用dfs + 回溯逐个遍历结果集

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