/*
选择题

以下关于HTTP状态码的描述，错误的是(D)
A 100，代表客户端应当继续发送请求
B 2xx，代表请求已成功被服务器接收、理解、并接受
C 301，代表被请求的资源已永久移动到新位置，用于重定向
D 4xx，代表服务器在处理请求的过程中有错误或者异常状态发生

注：
100-199 指定客服端相应的某些动作
200-299 表示请求成功
300-399 用于已经移动的文件并且包含在定位头信息中
400-499 指定客服端错误
500-599 服务端错误
*/


/*
编程题

1.
链接：https://www.nowcoder.com/questionTerminal/1046cd038f7a4b04b2b77b415973de1c
一块花布条，里面有些图案，另有一块直接可用的小饰条，里面也有一些图案。
对于给定的花布条和小饰条，计算一下能从花布条中尽可能剪出几块小饰条来呢？

输入
abcde a3
aaaaaa aa
输出
0
3
*/

/*
C语言可以通过strstr函数找，用STL的string库可以通过find函数找，找到以后跳过一个T串的长度。
例如：在abcacbcbcabscbc中找cbc，第一次找到了这个位置：abcacbcbcabscbc，找到这个下标后，
会跳过整体cbc，也就是从这个位置继续找：abcacbcbcabscbc，否则如果你只跳一个字符，
会导致cbcbc会被算成2次，而按照本题的题意，应该算一次
*/

#include <iostream>
#include <string>

using namespace std;
int main()
{
	string s, t;
	while (cin >> s >> t)
	{
		int count = 0;

		while (s.find(t) != -1)
		{
			count++;
			s.erase(s.find(t), t.size());
		}
		cout << count << endl;
	}
	return 0;
}


/*
2.
链接：https://www.nowcoder.com/questionTerminal/3549ff22ae2c4da4890e9ad0ccb6150d

NowCoder开了一家早餐店，这家店的客人都有个奇怪的癖好：他们只要来这家店吃过一次早餐，就会每天都过来；并且，所有人在这家店吃了两天早餐后，接下来每天都会带一位新朋友一起来品尝。
于是，这家店的客人从最初一个人发展成浩浩荡荡成百上千人：1、1、2、3、5……
现在，NowCoder想请你帮忙统计一下，某一段时间范围那他总共卖出多少份早餐（假设每位客人只吃一份早餐）。

老样子，先准备好斐波那契的数组，然后遍历那一段数组，求出他们的和即可。而第80项斐波那契数列是一个17
位数，所以需要用long long来解决问题。
然而这个题还有另一个更有意思的思路。斐波那契数列的的前n项和其实是有一个很有意思的公式，
根据文章我们能知道，斐波那契数列的前n项和，就是第n+2项的值减1，例如前10项的和143，
就是第12项的144 - 1的结果。所以，我们如果我们要第n项到第m项的和，那么只要求出前m项的和，
减去前n - 1项的和，就能得到结果了。例如要求第3项到第5项的和，我们就只需要用前5项的和减去前2项的和，
而公式中的减一在这个过程中抵消掉了，也就是结果直接就是第7项的值减去第4项的值，
这样我们在操作的时候就更简单了。就数值而言，第7项是13，第4项是3，差值是10，而2+3+5也是10，
结果是正确的。
*/

#include <iostream>
#define MAX 83 //如果用公式计算，需要接下来两项的值

void solve(long long num[])
{
	for (int i = 2; i < MAX; i++)
	{
		num[i] = num[i - 1] + num[i - 2];
	}
} 

long long sum_traversal(long long num[], int from, int to) //解法1：用遍历求和求解
{
	long long ans = 0;
	for (int i = from - 1; i < to; i++) //让数组下标从from - 1遍历到to - 1
	{
		ans += num[i];
	} 
	return ans;
} 

long long sum_formula(long long num[], int from, int to) //解法2：用公式求解
{
	return num[to + 1] - num[from]; //第to + 2项的下标是to + 1，第from + 2 - 1项的下标是from
} 

int main()
{
	int from, to;
	long long num[MAX] = { 1, 1 };
	//提前计算Fibonacci数列
	solve(num);
	while (std::cin >> from >> to)
	{
		std::cout << sum_formula(num, from, to) << std::endl; //两个方法二选一。公式更快。
	} 
	
	return 0;
}