/*
选择题

1.
下列哪项最恰当地描述了建立TCP连接时“第一次握手”所做的工作(C)
A “连接发起方”向“接收方”发送一个SYN-ACK段
B “接收方”向“连接发起方”发送一个SYN-ACK段
C “连接发起方”向目标主机的TCP进程发送一个SYN段
D “接收方”向源主机得到TCP进程发送一个SYN段作为应答
注：
第一次握手：客户端向服务器端发送SYN包（syn＝j），进入SYN_SEND状态，等待服务器确认。
第二次握手：服务器收到SYN包，确认SYN，此时syn＝j+1，同时发送一个SYN包（syn＝k）
即SYN＋ACK包，此时服务器进入SYN_RECV状态；第三次握手：客户端收到SYN＋ACK包，
向服务器发送ACK确认包，此时客户端和服务器端均进入ESTABLISHED状态。

2.
关于以下 URL 的描述错误的是(A)
A http表明使用TCP协议；
B 又名统一资源定位符，方便确定一个资源，并表示它在哪里
C URL中隐藏了端口号，默认是80端口
D 访问URL可使用大写字母
注：
http表示使用HTTP协议,底层才是TCP

3.
不属于交换机攻击的是(A)
A 目录遍历攻击
B MAC泛洪攻击
C VLAN攻击
D DHCP欺骗攻击
注：
交换机有五种攻击类型：
1：vlan跳跃攻击
2：生成树攻击
3：mac表洪水攻击
4：arp攻击
5：vtp攻击
*/


/*
编程题

1.
链接：https://www.nowcoder.com/questionTerminal/754921e9c98b43d1b2d70c227b844101
NowCoder在淘宝上开了一家网店。他发现在月份为素数的时候，当月每天能赚1元；否则每天能赚2元。
现在给你一段时间区间，请你帮他计算总收益有多少。

输入
2000 1 1 2000 1 31
2000 2 1 2000 2 29

输出
62
29
*/


/*
日期计算器的话，我们将会把日期计算分为三个部分：第一个不足一年的年份，最后一个不足一年的年份，和中间
的足年年份。足年年份我们只需要判断闰年后加365或366就行了。不足年，我们就要求出这个日期是这一年的第
几天。假设要求的是1994年5月27日到2003年4月29日，那么，我们就要先求出5月27日是这一年的第几天，然后
判断1994年不是闰年，不是，所以用365减去这个天数，就得到结果了。本题中第一天也要算，所以还要加上这一
天。然后再算出4月29日是2003年的第几天，就可以解决问题了。所以，我们需要一个函数，功能是给出一个年月
日，求出这是这一年的第几天。
再去改造使得1、4、6、8、9、10、12月的天数翻倍，那么程序就全部完成了。
*/

#include <cstdio>
#include <cmath>
#include <iostream>
// 闰年判断函数
inline int leap_year(int year)
{
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
} 
// 足年天数
inline int profit_of_year(int year)
{
	return 2 * 31
		+ 1 * 28
		+ 1 * 31
		+ 2 * 30
		+ 1 * 31
		+ 2 * 30
		+ 1 * 31
		+ 2 * 31
		+ 2 * 30
		+ 2 * 31
		+ 1 * 30
		+ 2 * 31
		+ leap_year(year);
} 

// 判断这个月份是不是质数月
inline bool prime(int n)
{
	return n == 2 || n == 3 || n == 5 || n == 7 || n == 11;
} 

// 求出一个日子是这一年的第几天
int profit_of_this_year(int year, int month, int day)
{
	if(!prime(month))
	{
		day *= 2;
	} 
	while(--month)
	{
			switch (month)
			{
				case 1:
				case 8:
				case 10:
				case 12:
					day += 62;
					break;
				case 3:
				case 5:
				case 7:
					day += 31;
					break;
				case 4:
				case 6:
				case 9:
					day += 60;
					break;
				case 11:
					day += 30;
					break;
				case 2:
					day += 28 + leap_year(year);
					break;
				default:;
			}
		}
	return day;
}

int main()
{
	int year1, month1, day1, year2, month2, day2;
	int count_profit = 0;
	while (std::cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
	{
		count_profit = 0;
		count_profit += profit_of_year(year1) - profit_of_this_year(year1, month1, day1 - 1);
		//这里的day1 - 1虽然有可能会出现0日，但是实际2月0日就相当于1月31日，所以不影响结果。
		count_profit += profit_of_this_year(year2, month2, day2);
		if(year1 == year2) //避免起点和终点是同一年，如果是同一年，要减掉这一年的天数。
		{
			count_profit -= profit_of_year(year1);
		}
		for (int i = year1 + 1; i < year2; i++) //中间足年每一年的天数
		{
			count_profit += profit_of_year(i);
		} 
		std::cout << count_profit << std::endl;
	} 
	return 0;
}



/*
2.
链接：https://www.nowcoder.com/questionTerminal/c0a4b917a15f40a49ca10532ab9019fb

NowCoder号称自己已经记住了1-100000之间所有的斐波那契数。
为了考验他，我们随便出一个数n，让他说出第n个斐波那契数。当然，斐波那契数会很大。
因此，如果第n个斐波那契数不到6位，则说出该数；否则只说出最后6位。

输入
1
2
3
4
100000
输出
1
2
3
5
537501
*/

/*
思路：先求斐波那契数列在100000以内的每一项的后六位，然后需要的时候直接输出数组里的对应值即可。
*/

#include <iostream>
#include <cstdio>
int main()
{
	int fib[100001];
	fib[0] = 1;
	fib[1] = 1;
	//提前计算斐波那契数列，只保留后6位
	for (int i = 2; i <= 100000; ++i)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] = fib[i] % 1000000; //由于是相加，所以只要后六位不影响下一个数的结果
	} 
	//这里利用了OJ平台计时从开始读取数据的trick，这个技巧可以用在很多题目里
	int n;
	while (std::cin >> n)
	{
		if (n < 29)
		{
			//斐波那契数列小于6位
			printf("%d\n", fib[n]);
		} 
		else
		{
			printf("%06d\n", fib[n]);
		}
	} 
	return 0;
}