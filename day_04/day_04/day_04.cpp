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

#include <iostream>

using namespace std;
int main()
{
	//int m, n, x, y;
	//while (cin >> m >> n >> x >> y)
	//{
	//	int A = (m + x) / 2;
	//	int B = (n + y) / 2;
	//	int C = (y - n) / 2;
	//	cout << A << ' ' << B << ' ' << C << endl;
	//}

	int a[5] = { 1, 3, 5, 7, 9 };
	int *p = (int*)(&a + 1);
	printf("%d,%d", *(a + 1), *(p - 1));
	return 0;

}

/*#include <iostream>
#include <vector>
#include <string>

using namespace std;
#include<iostream>
using namespace std;

void calculate(int n, int k)
{
	char num[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	int temp;
	temp = n % k;
	n /= k;
	if (n != 0)
		calculate(n, k);
	cout << num[temp];
}
int main()
{
	int M, N;
	while (cin >> M >> N)
	{
		calculate(M, N);
		cout << endl;
	}
	return 0;
}
*/