/*
编程题
1.
链接：https://www.nowcoder.com/practice/1221ec77125d4370833fd3ad5ba72395?tpId=37&tags=&title=&diffculty=0&judgeStatus=0&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔子都不死，问每个月的兔子总数为多少？
输入
9
输出
34
*/

/*
思路：第n个月的兔子数量由两部分组成，一部分是上个月的兔子f(n-1)，另一部是满足3个月大的兔子，
会生一只兔子f(n-2)。所以第n个月兔子总数： f(n) = f(n - 1) + f(n - 2)。
本题是在变相考察斐波那契数列
*/

// 递归
#include <iostream>
using namespace std;

int rabbits_count(int month)
{
	if (month < 3)
		return 1;
	return rabbits_count(month - 1) + rabbits_count(month - 2);
}

int main()
{
	int month;
	while (cin >> month)
	{
		int ret = rabbits_count(month);
		cout << ret << endl;
	}
	return 0;
}

// 非递归

#include <iostream>
using namespace std;
int main(){
	int month;
	while (cin >> month){
		int first = 1;
		int second = 1;
		int result;
		for (int i = 3; i <= month; ++i)
		{
			result = first + second;
			first = second;
			second = result;
		}
		cout << result << endl;
	} 
	return 0;
}


/*
2.
链接：https://www.nowcoder.com/practice/43072d50a6eb44d2a6c816a283b02036?tpId=37&&tqId=21294&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。
现要求实现字符串通配符的算法。
要求：
实现如下2个通配符：
*：匹配0个或以上的字符（字符由英文字母和数字0-9组成，不区分大小写。下同）
？：匹配1个字符

输入
te?t*.*
txt12.xls
输出
false
*/

/*
本题可以通过递归求解。从前向后一次匹配，遇到相同字符，都向后移动一个字符，如果通配符
遇到"?"，则不需匹配，自动跳过一个字符，如果通配符遇到"*"，则可以匹配任意多个字符，包括
0个，此时可以有三种选择，1，匹配0个，通配符向后移动一个字符，字符串不动。2，匹配1
个，通配符和字符串都向后移动一个字符。3，匹配多个，通配符不动，字符串向后移动一个字
符。
递归的终止条件：通配符或者字符串遇到'\0'。当他们同时结束。
*/

#include <iostream>
#include <string>
using namespace std;

bool match(const char* pattern, const char *str)
{
	// 当前字符结束，返回true
	if (*pattern == '\0' && *str == '\0')
		return true;
	// 两个字符串有一个先结束，则返回false
	if (*pattern == '\0' || *str == '\0')
		return false;
	if (*pattern == '?')
		// 遇到 ? 号，匹配一个字符，跳过一个位置
		return match(pattern + 1, str + 1);

	else if (*pattern == '*')
		// 遇到*号，匹配0个(str不挪动)，1个（两者都向前挪动一个字符）或多个(str向前挪动一个字符)
		return match(pattern + 1, str) || match(pattern + 1, str + 1) || match(pattern, str + 1);
	
	else if (*pattern == *str)
		// 如果当前字符相等，匹配下一个字符
		return match(pattern + 1, str + 1);
	
	return false;
}

int main()
{
	string pattern, str;
	while (cin >> pattern >> str)
	{
		bool ret = match(pattern.c_str(), str.c_str());

		if (ret)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	} 
	return 0;
}