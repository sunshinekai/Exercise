/*
选择题
以下程序运行时，若输入1abcedf2df<回车>输出结果是(C)

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
int main()
{
	char a = 0, ch;

	while ((ch = getchar()) != '\n')
	{
		if (a % 2 != 0 && (ch >= 'a' &&ch <= 'z'))
		ch = ch - 'a' + 'A';
		a++;
		putchar(ch);
	}
	printf("\n");
}

A 1abcedf2df
B 1ABCEDF2DF
C 1AbCeDf2dF
D 1abceDF2DF
*/



/*
编程题

1.
链接：https://www.nowcoder.com/practice/1183548cd48446b38da501e58d5944eb?tpId=85&&tqId=29840&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，网格的列编号为0~W-1。每个格子至多可以放一块蛋糕，
任意两块蛋糕的欧几里得距离不能等于2。对于两个格子坐标(x1,y1),(x2,y2)的欧几里得距离为:
((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2)) 的算术平方根
小易想知道最多可以放多少块蛋糕在网格盒子里。
示例：
输入
3 2
输出
4
*/


/*
解法1：
思路：使用vector<vector<int>>定义一个二维数组，resize开空间并初始化，
每个位置初始化为1，表示当蛋糕，a[i][j]位置放蛋糕，则可以标记处a[i][j+2]和a[i+1][j]位置
不能放蛋糕，遍历一遍二维数组，标记处不能放蛋糕的位置，统计也就统计出了当蛋糕的位置数。
*/

#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int w, h, res = 0;
	cin >> w >> h;
	vector<vector<int>> a;
	a.resize(w);
	for (auto& e : a)
		e.resize(h, 1);
	for (int i = 0; i<w; i++)
	{
		for (int j = 0; j<h; j++)
		{
			if (a[i][j] == 1)
			{
				res++;
				// 标记不能放蛋糕的位置
				if ((i + 2)<w)
					a[i + 2][j] = 0;
				if ((j + 2)<h)
					a[i][j + 2] = 0;
			}
		}
	}
	cout << res;
	return 0;
}

/*
解法2：
总结规律、利用公式
*/

#include<iostream>

using namespace std;
int main()
{
	int W, H;
	while (cin >> W >> H)
	{
		int count = 0;
		if ((W % 4 == 0) || (H % 4 == 0))
			count = W * H / 2;
		else if ((W % 2 == 0) && (H % 2 == 0))
			count = (W * H / 4 + 1) * 2;
		else
			count = W * H / 2 + 1;
		cout << count << endl;
	}
	return 0;
}



/*
2.
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
链接：https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp=6&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0
示例：
输入
+2147483647
1a33
输出
2147483647
0
*/


/*
思路：本题的关键是要处理几个关键边界条件：
1. 空字符串
2. 正负号处理
3. 数字串中存在非法字符
4. 字符过长造成溢出
*/


class Solution {
public:
	int StrToInt(string str) {
		int ret = 0;
		if (str.empty())
			return 0;
		int flag = 1;
		size_t i = 0;
		if (str[0] == '+' || str[0] == '-')
			i = 1;
		if (str[0] == '-')
			flag = -1;
		for (; i < str.size(); i++)
		{
			if (str[i] < '0' || str[i] > '9'
				|| str == "-2147483649"
				|| str == "2147483648")
				return 0;
			ret = ret * 10 + (str[i] - '0');
		}
		return (ret * flag);
	}
};