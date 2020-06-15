/*
选择题

1.
请找出下面程序中有哪些错误(C)
int main()
{
	int i=10;
	int j=1;
	const int *p1; //(1)
	int const *p2=&i; //(2)
	p2=&j; //(3)
	int *const p3=&i;//(4)
	*p3=20;//(5)
	*p2=30;//(6)
	p3=&j;//(7)
	return 0;
}

A 1,2,3,4,5,6,7
B 1,3,5,6
C 6,7
D 3,5
注：const在前，内容不能变；
const在后，指针不能变；
const* ，指针指向为常量；
*const ，指针本身为常量。

2.
假定有类AB，有相应的构造函数定义，能正确执行
AB a(4),b(5),c[3],*p[2]={&a,&b};
语句，请问执行完此语句后共调用该类的构造函数次数为(A)
A 5
B 4
C 3
D 9
注：只有在给指针分配空间时才调用构造函数

3.
关于函数的描述正确的是(D)。
A 虚函数是一个static型的函数
B 派生类的虚函数与基类的虚函数具有不同的参数个数和类型
C 虚函数是一个非成员函数
D 基类中说明了虚函数后，派生类中起对应的函数可以不必说明为虚函数

注：虚函数是允许在派生类中重新定义与基类同名的函数，
并且可以通过基类指针或引用来访问基类和派生类中的同名函数。
在基类中用virtual声明成员函数为虚函数，在派生类中重新定义此函数，
要求函数名、函数类型、函数参数个数和类型全部与基类的虚函数相同。

4.
有如下程序，执行后输出的结果是(D)
#include <iostream.h>
class cla
{
	static int n;
public:
	cla(){n++;}
	~cla(){n--;}
	static int get_n(){return n;}
};

int cla::n= 0;

int main()
{
	cla *p = new cla;
	delete p;
	cout<<"n ="<< cla::get_n() << endl;
	return 0;
}

A n=3
B n=4
C n=1
D n=0

注：
类的实例化：cla *p = new cla，p分配在栈上，p指向的对象分配在堆上。
n为静态成员变量，没有this指针，属于类域，所有对象共享。
实例化——调用构造函数，所以n++；
delete——调用析构函数，所以n--。
最后输仍旧为0。

5.
以下程序输出结果是()
class A
{
public:
	A ():m_iVal(0){test();}
	virtual void func() {std::cout<<m_iVal<<‘ ’;}
	void test(){func();}
public:
	int m_iVal;
};
class B : public A
{
public:
	B(){test();}
	virtual void func()
	{
		++m_iVal;
		std::cout<<m_iVal<<‘ ’;
	}
};
int main(int argc ,char* argv[])
{
	A*p = new B;
	p->test();
	return 0;
}

A 1 0
B 0 1
C 0 1 2
D 2 1 0
E 不可预期
F 以上都不对

本问题涉及到两个方面：
1.C++继承体系中构造函数的调用顺序。
2.构造函数中调用虚函数问题。

C++继承体系中，初始化时构造函数的调用顺序如下
(1).任何虚拟基类的构造函数按照他们被继承的顺序构造
(2).任何非虚拟基类的构造函数按照他们被继承的顺序构造
(3).任何成员对象的函数按照他们声明的顺序构造
(4).类自己的构造函数

据此可知 A*p = newB;先调用A类的构造函数再调用B类的构造函数。
构造函数中调用虚函数,虚函数表现为该类中虚函数的行为，即在父类构造函数中调用虚函数，
虚函数的表现就是父类定义的函数的表现。

原因如下：
假设构造函数中调用虚函数，表现为普通的虚函数调用行为，即虚函数会表现为相应的子类函数行为，并且假设子类存在一个成员变量int a；
子类定义的虚函数的新的行为会操作a变量，在子类初始化时根据构造函数调用顺序会首先调用父类构造函数，那么虚函数回去操作a，
而因为a是子类成员变量，这时a尚未初始化，这是一种危险的行为，作为一种明智的选择应该禁止这种行为。所以虚函数会被解释到基类而不是子类。
*/


/*
编程题

1.
链接：https://www.nowcoder.com/practice/839f681bf36c486fbcc5fcb977ffe432?tpId=85&&tqId=29844&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法：
1.根据字符串的字典序排序。例如：
"car" < "carriage" < "cats" < "doggies < "koala"
2.根据字符串的长度排序。例如：
"car" < "cats" < "koala" < "doggies" < "carriage"
考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。

示例：
输入
3
a
aa
bbb

输出
both
*/

/*
思路：将接受的字符串都放到vector容器中，利用string的operator>=运算符重载来按ascii比较字符
串，利用string的size来比较字符串的长度
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//int main()
//{
//	int n;
//	cin >> n;
//	vector<string> v;
//	v.resize(n);
//	for (auto& str : v)
//		cin >> str;
//
//	bool lenSym = true, lexSym = true;
//	// 这里要注意从i=1开始遍历，前后比较，比较长度
//	for (size_t i = 1; i < v.size(); ++i)
//	{
//		if (v[i - 1].size() >= v[i].size())
//		{
//			lenSym = false;
//			break;
//		}
//	}
//	
//	// 比较ASCII码
//	for (size_t i = 1; i < v.size(); ++i)
//	{
//		if (v[i - 1] >= v[i])
//		{
//			lexSym = false;
//			break;
//		}
//	}
//
//	if(lenSym && lexSym)
//		cout << "both" << endl;
//	else if (!lenSym && lexSym)
//		cout << "lexicographically" << endl;
//	else if (lenSym && !lexSym)
//		cout << "lengths" << endl;
//	else if (!lenSym && !lexSym)
//		cout << "none" << endl;
//	return 0;
//}

/*
2.
链接：https://www.nowcoder.com/practice/22948c2cad484e0291350abad86136c3?tpId=37&&tqId=21331&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，
设计一个算法，求输入A和B的最小公倍数。

示例：
输入
5 7
输出
35
*/

/*
思路：最小公倍数 = 两数之积除以最大公约数，这里使用碾转相除法进行最大公约数的求解：即a与b的最大公约数
可以转化为a、b之间的余数为两者之间最小的数之间的公约数。所以对于输入的两个数进行连续求余，直到
余数为0，求余的分母即为结果
*/

#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	int r;
	while (r = a%b)
	{
		a = b;
		b = r;
	}
	return b;
} 

int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << a*b / gcd(a, b) << endl;
	} 
	return 0;
}