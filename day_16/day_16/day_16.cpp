/*
选择题

1.
void swap_int(int *a,int *b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}

以下说法正确的是(B)
A 结果不正确，因为会溢出，用位与的方式就没问题
B 结果正确，即使会溢出
C 结果正确，不会溢出
D 其他选项都不对

注：
即使会产生溢出，但是运算法则仍然成立，举个例子，假设int只有4bit，
那么-8 + （-5） = -13（溢出）, 实际结果为3，而3-（-8） = 11（依然溢出），实际结果是-5，
所以，swap程序中的第二句： *b=*a-*b，相当于*b = *a+*b-*b；溢出并没有影响。


2.
以下代码有什么问题(A)
struct Test
{
	Test( int ) {}
	Test() {}
	void fun() {}
};
void main( void )
{
	Test a(1);
	a.fun();
	Test b();
	b.fun();
}
A b.fun（）会出错
B Test结构的定义中应该加上public修饰符，这样才能main函数中调用改类的方法
C Test(int){} 应该改成Test(int a){}
D 以上说法都不正确

注：b.fun(); //b不是Test的实例对象
类是结构体的bai扩展,在类中封装了对数据成du员的操作,缺省的成员为私有的,
而结构体为公有dao的,这就是它们的区别,对构造函数的调用,如果没有参数,是不需要加上括号的,
如果加了括号,就不是定义一个对象了,而是声明了一个函数,返回该类型,
所以上面的Test b(),实际上是调用一个函数名为b,返回类型为Test的函数,而不是创建了一个对象b,
去掉括号后,就是调用的没有形参的构造函数。
*/


/*
编程题

1.
链接：https://www.nowcoder.com/practice/7299c12e6abb437c87ad3e712383ff84?tpId=37&&tqId=21279&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。
给定函数count(int n),用于计算n以内(含n)完全数的个数。计算范围, 0 < n <= 500000
返回n以内完全数的个数。 异常情况返回-1
*/

/*
本题可以通过遍历每一个约数，求和，判断完全数。约数计算可以遍历sqrt(n)的范围
*/

#include <iostream>
using namespace std;

bool ISPerfectNumber(int x)
{
	int sum = 0;
	int sq = sqrt(x);
	for (int i = 1; i < sq; i++)
	{

		if (x % i == 0)
			sum += i;
	}
	if (sum == x)
		return true;
	return false;
}


int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0, i = 0;
		for (int i = 1; i <= n; i++)
		{
			if (ISPerfectNumber(i))
				count++;
		}
		cout << count << endl;
	}
}


/*
2.
链接：https://www.nowcoder.com/practice/0a92c75f5d6b4db28fcfa3e65e5c9b3f?tpId=49&&tqId=29277&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A，2各4张，小王1张，大王1张。牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）:)
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如：4 4 4 4-joker JOKER
请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR
基本规则：
（1）输入每手牌可能是个子，对子，顺子（连续5张），三个，炸弹（四个）和对王中的一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）
（3）大小规则跟大家平时了解的常见规则相同，个子，对子，三个比较牌面大小；顺子比较最小牌大小；炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
（4）输入的两手牌不会出现相等的情况。

答案提示：
（1）除了炸弹和对王之外，其他必须同类型比较。
（2）输入已经保证合法性，不用检查输入是否是合法的牌。
（3）输入的顺子已经经过从小到大排序，因此不用再排序了.
输入描述:
输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如4 4 4 4-joker JOKER。
输出描述:
输出两手牌中较大的那手，不含连接符，扑克牌顺序不变，仍以空格隔开；如果不存在比较关系则输出ERROR。
示例1
输入
4 4 4 4-joker JOKER
输出
joker JOKER
*/

/*
思路：
本题的题目意思是输入的只是这些类型中的一种，个子，对子，顺子（连续5张），三个，炸弹
（四个）和对王。其实就是最多5张牌（顺子），最少1一张牌之间的比较。不存在其他情况。
由输入保证两手牌都是合法的，顺子已经从小到大排列，按照题意牌面类型的确定和大小的比较
直接可以转换为牌个数的比较
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string line;
	while (getline(cin, line)){
		//王炸最大，直接输出
		if (line.find("joker JOKER") != -1)
			cout << "joker JOKER" << endl;
		else
		{
			int dash = line.find('-');
			//分开两手牌
			string car1 = line.substr(0, dash);
			string car2 = line.substr(dash + 1);
			//获取空格的次数，牌数为c + 1
			int c1 = count(car1.begin(), car1.end(), ' ') + 1;
			int c2 = count(car2.begin(), car2.end(), ' ') + 1;
			//拿到第一张牌
			string first1 = car1.substr(0, car1.find(' '));
			string first2 = car2.substr(0, car2.find(' '));
			string str = "345678910JQKA2jokerJOKER";
			if (c1 == c2)
			{
				//只要牌数相等，则第一张牌大的即为大
				if (str.find(first1) > str.find(first2))
					cout << car1 << endl;
				else
					cout << car2 << endl;
			}
			else
			{
				//牌数不相同，说明类型不同,只有炸弹可以和其它牌比较
				//其它类型都是错误的
				if (c1 == 4)
				cout << car1 << endl;
				else if (c2 == 4)
					cout << car2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}
}