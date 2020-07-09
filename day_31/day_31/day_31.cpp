/*
选择题

1.
主机 A 向主机 B 连续发送了两个 TCP 报文段，其序号分包是 70 和 100 ，
如果 A 发送的第一个报文段丢失了，但第二个报文段达到了 B ， B 在第二个报文段到达
后向 A 发送确认，那么这个确认号是多少(C)
A 100
B 101
C 70
D 71

注：确认号指的是接收方想要接收的报文段的序号，比如想要1-5的报文，在接收过程中收到了2-5，
而1丢了，这时候会再发一遍1。
在这里序号70的丢了，所以确认号就是70，和后面的没关系。

2.
每个 IP 地址都可以有一个主机名，通过主机名得到该主机对应 ip 地址的过程叫（B）
A ip地址解析
B 域名解析
C 域名编译
D ip地址编译

注：每个IP地址都可以有一个主机名,主机名由一个或多个字符串组成,字符串之间用小数点...通过主机名,
最终得到该主机名对应的IP地址的过程叫做域名解析(或主机名解析)。
*/


/*
编程题
1.
链接：https://www.nowcoder.com/questionTerminal/d95d98a2f96e49078cd7df84ba0c9d79

和中国的节日不同，美国的节假日通常是选择某个月的第几个星期几这种形式，因此每一年的放假日期都不相同。具体规则如下：
* 1月1日：元旦
* 1月的第三个星期一：马丁·路德·金纪念日
* 2月的第三个星期一：总统节
* 5月的最后一个星期一：阵亡将士纪念日
* 7月4日：美国国庆
* 9月的第一个星期一：劳动节
* 11月的第四个星期四：感恩节
* 12月25日：圣诞节
现在给出一个年份，请你帮忙生成当年节日的日期。

输入
2014
2013
输出
2014-01-01
2014-01-20
2014-02-17
2014-05-26
2014-07-04
2014-09-01
2014-11-27
2014-12-25

2013-01-01
2013-01-21
2013-02-18
2013-05-27
2013-07-04
2013-09-02
2013-11-28
2013-12-25
*/


/*
思路：
第一个难点是如何判断一天到底是周几。那么为了判断一天到底是周几，我们有以下两种手段：
1、找个参照日，写一个日期计算器，算出两个天数之间的差值后对7取余数即可知道目标日期是星期几。
2、通过蔡勒公式计算星期数：
公式中w就是计算出的星期；c是世纪，其值为真实的世纪数-1，也就是y / 100的结果；y是这是这个世纪的第几
年，也就是y % 100；m是月，但是1月和2月要看做13月和14月计算；d是日。根据泰勒公式，我们只需要知道年
月日，就可以算出星期。然而因为现行的格里历，所以在1582年之前的日期，我们要采用另一个公式，本题中用
不到，可以参考百度百科：https://baike.baidu.com/item/%E8%94%A1%E5%8B%92%E5%85%AC%E5%BC%8F
两个方法比较而言，肯定是方法2的代码更好写，所以我们就用泰勒公式就好。
第一个难点解决了，第二个难点，如何通过这个参照点拿到一个月的第N个星期W。
那么，我们假设要拿到一个月的第一个周五，我们要怎么做呢？一个很简单的思路就是，先看看这个月的1号是周
几，然后往后数就行了，假如1号是周四，那么2号就是第一个周五，假如1号是周六，那么7号就是第一个周五。
那么怎么拿到这个向后的天数呢？
我们发现，如果所求星期数比1号星期数大，那么直接相减后+1就是那一天了，例如1号周三，我要周五，那么(5-
3)+1即可求出第一个周五是3号。那么反过来是所求星期数小，例如1号周三，我要周一，那么显然要先把周一看成
周八才行。也就是(8-3)+1。第一个周一是6号。但是这样要判断，所以干脆统统都让它加7以后减，减完后的结果
再mod一下7，就能得到结果了。也就是：(所求星期数 + 7 - 1号星期数) % 7 + 1。这样我们就拿到了求第一个周几
公式。随后，我们只需要在这个公式上，加上7 * (n - 1)，即刻求出第n个周几。
而面对某个月的最后一个周几，我们要做的是拿到下个月的第一天然后往回推即可。公式跟上面的差不多，有了上
面的公式，可以尝试自己来做做看。
*/


#include <iostream>
#include <cstdio>
// 根据 年-月-日 通过蔡勒公式计算当前星期几
// 1: 星期一 ... 7: 星期日
int day_of_week(int year, int month, int day)
{
	if (month == 1 || month == 2)
	{
		month += 12;
		year -= 1;
	}

	int century = year / 100;
	year %= 100;
	int week = year + (year / 4) + (century / 4) - 2 * century + 26 * (month + 1) / 10 + day - 1;
	week = (week % 7 + 7) % 7;
	if (week == 0)
		week = 7;

	return week;
}

int day_of_demand(int year, int month, int count, int d_of_week)
{
	int week = day_of_week(year, month, 1); //求出1号星期数
	// 1 + 7(n - 1) + (所求星期数 + 7 - 1号星期数) % 7
	int day = 1 + (count - 1) * 7 + (7 + d_of_week - week) % 7;
	return day;
} 

// 元旦
void new_year_day(int year)
{
	printf("%d-01-01\n", year);
}

// 马丁·路德·金纪念日（1月的第三个星期一）
void martin_luther_king_day(int year)
{
	printf("%d-01-%02d\n", year, day_of_demand(year, 1, 3, 1));
} 

// 总统日（2月的第三个星期一）
void president_day(int year)
{
	printf("%d-02-%02d\n", year, day_of_demand(year, 2, 3, 1));
} 

// 阵亡将士纪念日（5月的最后一个星期一）
void memorial_day(int year)

{
	// 从6月往前数
	int week = day_of_week(year, 6, 1);
	// 星期一的话，从 31 号往前数 6 天，否则，数 week - 2 天
	int day = 31 - ((week == 1) ? 6 : (week - 2));
	printf("%d-05-%02d\n", year, day);
} 

// 国庆
void independence_day(int year)
{
	printf("%d-07-04\n", year);
} 

// 劳动节（9月的第一个星期一）
void labor_day(int year)
{
	printf("%d-09-%02d\n", year, day_of_demand(year, 9, 1, 1));
} 

// 感恩节（11月的第四个星期四）
void thanks_giving_day(int year)
{
	printf("%d-11-%02d\n", year, day_of_demand(year, 11, 4, 4));
} 

// 圣诞节
void christmas(int year)
{
	printf("%d-12-25\n", year);
} 

// 美国节日
void holiday_of_usa(int year)
{
	new_year_day(year);
	martin_luther_king_day(year);
	president_day(year);
	memorial_day(year);
	independence_day(year);
	labor_day(year);
	thanks_giving_day(year);
	christmas(year);
} 

int main()
{
	int year;
	while (std::cin >> year)
	{
		holiday_of_usa(year);
		putchar('\n');
	}
}



/*
1.
链接：https://www.nowcoder.com/questionTerminal/0f6976af36324f8bab1ea61e9e826ef5

所谓因子分解，就是把给定的正整数a，分解成若干个素数的乘积，即 a = a1 × a2 × a3 × ... × an,
并且 1 < a1 ≤ a2 ≤ a3 ≤ ... ≤ an。其中a1、a2、...、an均为素数。 先给出一个整数a，请输出分解后的因子。
*/


/*
输入
10
18
输出
10 = 2 * 5
18 = 2 * 3 * 3
*/


/*
注：看到短除法后，我们很清楚的知道，要想求出它的每一个质因数，我们需要用质数去试除。90能被2整除，那就拿
商继续除以2，除不尽就换3，一直到除到质数为止。基础代码框架类似判断质数，只是被判断的数字在过程中不断
被除，最终循环结束的时候，那个被处理过的数字，就是最后一个质因数。以下代码注释以90为例。
*/
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool IsPrime(int number)
{
	int ret = (int)sqrt(number);
	for (int i = 2; i <= ret; i++)
	{
		if (number % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int a;
	while (cin >> a)
	{
		int tmp = a;
		vector<int> v;
		int i = 2;
		while (tmp > 1)
		{
			if (tmp % i == 0 && IsPrime(i))
			{
				v.push_back(i);
				tmp /= i;
			}
			else
				i++;
		}
		cout << a << " = ";
		for (size_t i = 0; i < v.size() - 1; i++)
			cout << v[i] << " * ";
		cout << v[v.size() - 1] << endl;
	}
	return 0;
}
