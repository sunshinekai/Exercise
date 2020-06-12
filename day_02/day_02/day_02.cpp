/*
选择题：
请将下列构造函数补充完整，使得程序的运行结果是5(B)

#include<iostream>
using namespace std;
class Sample
{
public:
	Sample(int x)
	{
		_________
	} 
	~Sample()
	{
		if(p)
		delete p;
	}
	int show()
	{
		return *p;
}
private:
	int*p;
};

int main()
{
	Sample S(5);
	cout << S.show() << endl;
	return 0;
}
A *p=x;
B p=new int(x);
C *p=new int(x);
D p=&x;

A、*p = x，把x的值赋值给指针p指向的内存空间，但是p之前没有指向任何一块内存空间，所以这个操作非法
B、p = new int(x)，新申请一块内存空间，内存空间中的值是x，并且把这块内存空间赋值给p，p也就指向了这块内存空间。并且程序结束后也不释放这块内存空间。
C、*p = new int(x)。由于p之前没有指向任何一块内存空间，所以直接给*p赋值是错误的。（*p表示p指向的内存空间。）
D、p = &x，表示把x的地址赋值给p，但是这里的x 是形参，函数调用结束后x就被释放了，所以*p就找不到x。
*/


/*
编程题：

1.
链接：https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderByHotValue=1&page=1&onlyReference=false

牛牛定义排序子序列为一个数组中一段连续的子序列,并且这段子序列是非递增或者非递减排序的。
牛牛有一个长度为n的整数数组A,他现在有一个任务是把数组A分为若干段排序子序列,牛牛想知道他最少可以把这个数组分为几段排序子序列.
如样例所示,牛牛可以把数组A划分为[1,2,3]和[2,2,1]两个排序子序列,至少需要划分为2个排序子序列,所以输出2

输入描述:
输入的第一行为一个正整数n(1 ≤ n ≤ 10^5)
第二行包括n个整数A_i(1 ≤ A_i ≤ 10^9),表示数组A的每个数字。

输出描述:
输出一个整数表示牛牛可以将A最少划分为多少段排序子序列
示例1
输入
6
1 2 3 2 2 1
输出
2
*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a;
	a.resize(n + 1);
	a[n] = 0;
	// 读入数组
	int i = 0;
	for (; i < n; ++i)
		cin >> a[i];
	i = 0;
	int count = 0;
	while (i < n)
	{
		// 非递减子序列
		if (a[i] < a[i + 1])
		{
			while (i < n && a[i] <= a[i + 1])
				i++;
			count++;
			i++;
		} 
		else if (a[i] == a[i + 1])
		{
			i++;
		}
		else // 非递增子序列
		{
			while (i < n && a[i] >= a[i + 1])
				i++;
			count++;
			i++;
		}
	}
	cout << count << endl;
	return 0;
}



/*
2.
链接：https://www.nowcoder.com/practice/ee5de2e7c45a46a090c1ced2fdc62355?tpId=85&&tqId=29867&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

将一句话的单词进行倒置，标点不倒置。
比如 I like beijing. 经过函数后变为：beijing. like I
输入描述:
每个测试输入包含1个测试用例： I like beijing. 输入用例长度不超过100.
输出描述:
依次输出倒置之后的字符串,以空格分割.
示例:
输入
I like beijing.
输出
beijing. like I
*/


// 解法1
/*
思路：用rfind找到第1个空格与最后一个空格，记录位置
用一个空字符串接收最后一个单词，然后删掉最后一个单词(包括空格)
直到输入的rpos找不到空格为止.
*/
#include <iostream>
#include <string>

using namespace std;
int main()
{
	string s, s1, s2;
	getline(cin, s1);
	int pos = s1.find(' ');
	int rpos = s1.rfind(' ');
	s2 = s1.substr(0, pos);
	while (rpos >= 0)
	{
		s += s1.substr(rpos + 1) + ' ';
		s1.erase(rpos);
		rpos = s1.rfind(' ');
	}
	s += s2;
	cout << s << endl;
	return 0;
}


// 解法2
/*
先将整个字符串逆置过来，再遍历字符串，找出每个单词，对单词逆置。这里我们使用了stl算法中的
reverse，所以这里使用迭代器遍历string
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	// 翻转整个句子
	reverse(s.begin(), s.end());

	// 翻转单词
	string::iterator start = s.begin();
	while (start != s.end())
	{
		auto end = start;
		while (end != s.end() && *end != ' ')
			end++;
		reverse(start, end);

		if (end != s.end())
			start = end + 1;
		else
			start = end;
	}

	cout << s << endl;
	return 0;
}


// 解法3
/*
这是一个比较讨巧的思路，直接利用cin>>s接收输入，遇到空格就结束了，自然就分割开了每个单
词，其次将每次接收到的单词拼接到之前串的前面就逆置过来了。
*/

#include <iostream>
#include <string>
using namespace std;
// cin读取string时自动会被空格分隔开，用另一个字符串存储进行逆序输出
int main()
{
	string s1, s2;
	cin >> s2;
	while (cin >> s1)
		s2 = s1 + ' ' + s2;
	cout << s2 << endl;
	return 0;
}