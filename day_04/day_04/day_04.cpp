/*
选择题

1.
print()函数是一个类的常成员函数，它无返回值，下列表示中正确的是(C)
A const void print();
B void const print();
C void print() const;
D void print(const);
注：const void print(const int num)const 第一个const修饰返回类型
第二个const修饰参数 第三个const修饰调用对象

2.
下列有关this指针使用方法的叙述正确的是（）
A 保证基类保护成员在子类中可以被访问
B 保证基类私有成员在子类中可以被访问
C 保证基类共有成员在子类中可以被访问
D 保证每个对象拥有自己的数据成员，但共享处理这些数据的代码
注：this是指向实例化对象本身时候的一个指针，里面存储的是对象本身的地址，
通过该地址可以访问内部的成员函数和成员变量。 为什么需要this？
因为this作用域是在类的内部，自己声明一个类的时候，还不知道实例化对象的名字，
所以用this来使用对象变量的自身

3.
下面程序输出结果是什么? (A)
#include<iostream>
using namespace std;

class A
{
public:
	A(char *s)
	{
		cout << s << endl;
	} 
	~A(){}
};

class B : virtual public A
{
public :
	B(char *s1, char*s2) : A(s1)
	{
		cout << s2 << endl;
	}
};

class C : virtual public A
{
public:
	C(char *s1, char*s2) : A(s1)
	{
		cout << s2 << endl;
	}
};

A class A class B class C class D
B class D class B class C class A
C class D class C class B class A
D class A class C class B class D
注：对于构造函数调用顺序：基类构造函数->子类成员变量构造函数->子类构造函数 
对于析构函数调用顺序：子类析构函数->子类成员变量析构函数->基类析构函数 
*/


/*
编程题

1.
链接：https://www.nowcoder.com/practice/02d8d42b197646a5bbd0a98785bb3a34?tpId=85&&tqId=29857&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
A, B, C三个人是好朋友, 每个人手里都有一些糖果, 我们不知道他们每个人手上具体有多少个糖果, 但是我们知道以下的信息：
A - B, B - C, A + B, B + C.这四个数值.每个字母代表每个人所拥有的糖果数.
现在需要通过这四个数值计算出每个人手里有多少个糖果, 即A, B, C。这里保证最多只有一组整数A, B, C满足所有题设条件。
输入描述 :
输入为一行，一共4个整数，分别为A - B，B - C，A + B，B + C，用空格隔开。 范围均在 - 30到30之间(闭区间)。
输出描述 :
输出为一行，如果存在满足的整数A，B，C则按顺序输出A，B，C，用空格隔开，行末无空格。 如果不存在这样的整数A，B，C，则输出No
示例：
输入
1 - 2 3 4
输出
2 1 3
*/


#include <iostream>
using namespace std;
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = (a + c) / 2;
	int C = (d - b) / 2;
	int B1 = (c - a) / 2;
	int B2 = (b + d) / 2;
	if (B1 != B2)
		cout << "No";
	else
		cout << A << " " << B1 << " " << C;
	return 0;
}


/*
2.
给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
示例：
输入
7 2
复制
111
*/


#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s, table = "0123456789ABCDEF";
	int M, N;
	cin >> M >> N;
	bool flag = false;
	// 如果是负数，则转成正数，并标记一下
	if (M < 0)
	{
		M = 0 - M;
		flag = true;
	}
	// 按进制换算成对应的字符添加到s
	while (M)
	{
		s += table[M % N];
		M /= N;
	}
	if(flag)
		s += '-';
	reverse(s.begin(), s.end());
	cout << s << endl;
	return 0;
}