/*
选择题

1.
假设寄存器为8位，用补码形式存储机器数，包括一位符号位，那么十进制数-25在寄存器表示为(D)
A 67H
B 99H
C E6H
D E7H

注：
十进制数-25的原码为10011001，反码为11100110，补码是反码加1，即为11100111，转化为十六进制即为E7

2.
有一个类B继承自类A，他们数据成员如下：
class A {
	...
private:
	int a;
};
class B : public A {
	...
private:
	int a;
public:
	const int b;
	A &c;
	static const char* d;
	B* e;
}

则构造函数中，成员变量一定要通过初始化列表来初始化的是(F)。
A a b c
B b c e
C b c d e
D c e
E b d
F b c

注：
构造函数初始化时必须采用初始化列表一共有三种情况，
a.需要初始化的数据成员是对象(继承时调用基类构造函数)
b.需要初始化const修饰的类成员
c.需要初始化引用成员数据

3.
下面程序运行后的结果为(D)

char str[] = "glad to test something";
char *p = str;
p++;
int *p1 = reinterpret_cast<int *>(p);
p1++;
p = reinterpret_cast<char *>(p1);
printf("result is %s\n", p);

A result is glad to test something
B result is ad to test something
C result is test something
D result is to test something

注：
p的类型为char *，p++后p指向str数组的第2个元素即字母“l”的位置。
p1的类型为int *，p1++后p1指向的位置增加4个字节，指向str数组中的第6个元素即字母“t”的位置。
因此最后p的内容为“to test something”

4.以下程序的输出是(C)

#include <iostream>
class Base {
public:
	Base(int j) : i(j) {}
	virtual~Base() {}
	void func1() 
	{
		i *= 10;
		func2();
	} 
	int getValue() 
	{
		return i;
	} 
protected:
	virtual void func2() 
	{
		i++;
	} 
protected:
	int i;
};
class Child : public Base {
public:
	Child(int j) : Base(j) {}
	void func1() {
		i *= 100;
		func2();
	} 
protected :
	void func2() {
		i += 2;
	}
};
int main() {
	Base * pb = new Child(1);
	pb->func1();
	cout << pb->getValue() << endl; 
	delete pb;
}

A 11
B 101
C 12
D 102

注：
func1不是虚函数。func2是虚函数。所以
pb->func1();
调用的是Base类的func1和Child类的func2
*/

/*
编程题：

1.
链接：https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&&tqId=21296&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
根据输入的日期，计算是这一年的第几天。。
详细描述：
输入某年某月某日，判断这一天是这一年的第几天？

输入
2012
12
31

输出
366
*/

/*
思路：用一个数组存放每月的累积天数
输入的日期天数 = 当月的天数 + 当月之前的累积天数
如果包含二月，再去判断是否为闰年，如果是闰年，再加1天即可
*/

#include <iostream>
using namespace std;

int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		int MonthDays[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
		int days = MonthDays[month - 1] + day;
		if ((month > 2) && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
			days++;
		cout << days << endl;
	}
	return 0;
}


/*
2.
链接：https://www.nowcoder.com/practice/a5190a7c3ec045ce9273beebdfe029ee?tpId=85&&tqId=29839&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子是幸运的。现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。

输入
3
1 1 1
输出
2
*/
/*
本题的本质是求符合条件的子集个数。

解题思路：
每次从全集中选择若干元素（小球）组成子集（袋子）。对于任意两个正整数a, b如果满足
a + b>ab，则必有一个数为1.可用数论证明：设a = 1 + x, b = 1 + y，则1 + x + 1 + y>(1 + x)(1 + y)，--->
1>xy，则x，y必有一个为0，即a, b有一个为1.推广到任意k个正整数，假设a1, a2, ...ak，如果不满
足给定条件，即和sum小于等于积pi。如果此时再选择一个数b, 能使其满足sum + b > pib，则，b必
然为1，且为必要非充分条件。反之，如果选择的b>1，则sum + b <= pi*b，即a1, a2, ..., ak, b不满
足给定条件。
因此，将球按标号升序排序。每次从小到大选择，当选择到a1, a2, ..., ak - 1时满足给定条件，而再
增加选择ak时不满足条件（ak必然大于等于max(a1, a2, ..., ak - 1)），继续向后选择更大的数，必然
无法满足！此时不必再继续向后搜索。如果有多个1，即当k = 1时，sum(1)>pi(1)不满足，但下一
个元素仍为1，则可以满足1 + 1>1 * 1，
所以要判断当前ak是否等于1，如果等于1，虽然不能满足，组合的个数不能增加，但是继续向后
搜索，仍然有满足条件的可能.对于重复数字，组合只能算一个，要去重。
*/


#include<iostream>
#include<algorithm>
using namespace std;
/*
getLuckyPacket:从当前位置开始搜索符合要求的组合，一直搜索到最后一个位置结束
x[]: 袋子中的所有球
n: 球的总数
pos: 当前搜索的位置
sum: 到目前位置的累加和
multi: 到目前位置的累积值
*/
int getLuckyPacket(int x[], int n, int pos, int sum, int multi)
{
	int count = 0;
	//循环，搜索以位置i开始所有可能的组合
	for (int i = pos; i<n; i++)
	{
		sum += x[i];
		multi *= x[i];
		if (sum > multi)
		{
			//找到符合要求的组合，加1，继续累加后续的值，看是否有符合要求的集合
			count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
		}
		
		else if (x[i] == 1)
		{
			//如何不符合要求，且当前元素值为1，则继续向后搜索
			count += getLuckyPacket(x, n, i + 1, sum, multi);
		}

		else
		{
			//如何sum大于multi,则后面就没有符合要求的组合了
			break;
		} 
		// 要搜索下一个位置之前，首先恢复sum和multi
			sum -= x[i];
		multi /= x[i];
		//数字相同的球，没有什么区别，都只能算一个组合，所以直接跳过
		while (i < n - 1 && x[i] == x[i + 1])
		{
			i++;
		}
	} 
	return count;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int x[n];
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		} 
		sort(x, x + n);
		//从第一个位置开始搜索
		cout << getLuckyPacket(x, n, 0, 0, 1) << endl;
	} 
	return 0;
}