/*
1.
链接：https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b?orderByHotValue=1&page=1&onlyReference=false
牛牛举办了一次编程比赛,参加比赛的有3*n个选手,每个选手都有一个水平值a_i.现在要将这些选手进行组队,
一共组成n个队伍,即每个队伍3人.牛牛发现队伍的水平值等于该队伍队员中第二高水平值。
例如:
一个队伍三个队员的水平值分别是3,3,3.那么队伍的水平值是3
一个队伍三个队员的水平值分别是3,2,3.那么队伍的水平值是3
一个队伍三个队员的水平值分别是1,5,2.那么队伍的水平值是2
为了让比赛更有看点,牛牛想安排队伍使所有队伍的水平值总和最大。
如样例所示:
如果牛牛把6个队员划分到两个队伍
如果方案为:
team1:{1,2,5}, team2:{5,5,8}, 这时候水平值总和为7.
而如果方案为:
team1:{2,5,8}, team2:{1,5,5}, 这时候水平值总和为10.
没有比总和为10更大的方案,所以输出10.
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		long long sum = 0;
		vector<int> a;
		a.resize(3 * n);
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> a[i];
		} 
		/*
		排序，然后取下标为3n - 2，3n - 4 ，3n - 4...n + 2，n位置的元素累加即可，
		相当下标为[0, n - 1]的n个数做每组的最左边的数，剩下的2个数据两个为一组，
		大的值做最右边的数，次大的做中间值，这里就是把这个次大的值加起来
		*/
		std::sort(a.begin(), a.end());
		for (int i = n; i <= 3 * n - 2; i += 2)
		{
			sum += a[i];
		} 
		cout << sum << endl;
	}
}



/*
2.
链接：https://www.nowcoder.com/practice/f0db4c36573d459cae44ac90b90c6212?tpId=85&&tqId=29868&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
输入：They are students.
	  aeiou
输出：Thy r stdnts.
*/

// 方法1：暴力解法
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	getline(cin,s1);
	cin >> s2;
	string::iterator it1 = s1.begin();
	string::iterator it2 = s2.begin();
	while (it1 != s1.end())
	{
		string::iterator it2 = s2.begin();
		while (it2 != s2.end())
		{
			if (*it1 == *it2)
			{
				s1.erase(it1);
			}
			++it2;
		}
		++it1;
	}
	cout << s1 << endl;
	return 0;
}
/*
传统的暴力查找方式，如判断第一个串的字符是否在第二个串中，在再挪动字符删除这个字符
的方式，效率为O(N^2)，效率太低，很难让人满意。
ps：使用“暴力算法”的case通过率为75.00%，并不能通过全部的测试用例
*/


// 方法2：
/*
1. 将第二个字符串的字符都映射到一个hashtable数组中，用来判断一个字符在这个字符串。
2. 判断一个字符在第二个字符串，不要使用删除，这样效率太低，因为每次删除都伴随数据挪动。这里可
以考虑使用将不在字符添加到一个新字符串，最后返回新新字符串
*/

#include<iostream>
#include<string>
using namespace std;
int main()
{
	// oj中IO输入字符串最好使用getline。
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	// 使用哈希映射思想先str2统计字符出现的次数
	int hashtable[256] = { 0 };
	for (size_t i = 0; i < str2.size(); ++i)
	{
		hashtable[str2[i]]++;
	}
	// 遍历str1，str1[i]映射hashtable对应位置为0，则表示这个字符在
		// str2中没有出现过，则将他+=到ret。注意这里最好不要str1.erases(i)
		// 因为边遍历，边erase，容易出错。
		string ret;
	for (size_t i = 0; i < str1.size(); ++i)
	{
		if (hashtable[str1[i]] == 0)
			ret += str1[i];
	} 
	cout << ret << endl;
	return 0;
}