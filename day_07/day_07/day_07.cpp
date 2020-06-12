/*
选择题：

1.下面关于类定义的说法中，正确的是(A)
A 类定义中包括数据成员和函数成员的声明
B 类成员的缺省访问权限是保护的
C 数据成员必须被声明为私有的
D 成员函数只能在类体外进行定义
注：类中缺省的访问权限是私有的(private)；
类的数据成员和函数成员的访问控制权限均可被声明为公有、私有和保护中的任意一种；
成员函数的实现即可以在类体内定义，也可以在类体外定义；

2.
#include <iostream>
using namespace std;
class parent
{
	int i;
protected:
	int x;
public:
	parent(){x=0;i=0;}
	void change(){x++;i++;}
	void display();
};
class son:public parent
{
public:
	void modify();
};
void parent::display(){cout<<"x="<<x<<endl;}
void son:: modify() {x++;}
int main()
{
	son A; parent B;
	A.display();
	A.change();
	A.modify();
	A.display();
	B.change();
	B.display();
}

下面程序的输出是什么(C)
A x=1 x=0 x=2
B x=2 x=0 x=1
C x=0 x=2 x=1
D x=0 x=1 x=2
注：子类会继承父类除构造函数和析构函数之外所有的数据成员和成员函数。
实例化后，子类和父类的对象互不影响。

#include<iostream>
#include<string>
using namespace std;

class A
{
	friend long fun(A s)
	{
		if (s.x<3) {
		return 1;
	} 
	return s.x+fun(A(s.x - 1));
public:
	A(long a)
	{
		x = a--;
	}
private:
	long x;
};

int main()
{
	int sum=0;
	for( int i=0; i<5; i++) 
	{
		sum += fun(A(i));
	} 
	cout<<sum;
}
代码运行结果是(B)
A 21
B 15
C 9
D 36
*/


/*
编程题：

1.
链接：https://www.nowcoder.com/practice/18ecd0ecf5ef4fe9ba3f17f8d00d2d66?tpId=85&&tqId=29846&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
Fibonacci数列是这样定义的：
F[0] = 0
F[1] = 1
for each i ≥ 2: F[i] = F[i-1] + F[i-2]
因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。
给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，
现在给你一个数N求最少需要多少步可以变为Fibonacci数。
输入
15
输出
2
*/


/*
思路：通过先找到距离N最近的两个Fibonacci数，这两个数分别取自距离N的最近的左边一个数L和右边一
个数R，然后通过min(N - L, R - N)找到最小步数。
*/
#include <iostream>

using namespace std;

int Fibonacci(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
	int N;
	int Minstep;
	while (cin >> N)
	{
		int i = 0;
		for (; Fibonacci(i) < N; i++);
		if (Fibonacci(i) == N)
			Minstep = 0;
		else
			Minstep = abs(Fibonacci(i) - N) <= abs(Fibonacci(i - 1) - N) ? 
					  abs(Fibonacci(i) - N) : abs(Fibonacci(i - 1) - N);
		cout << Minstep << endl;
	}
	return 0;
}

/*
2.
链接：https://www.nowcoder.com/practice/d8acfa0619814b2d98f12c071aef20d4?tpId=8&&tqId=11039&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。

测试样例：
"(()())",6
返回：true

测试样例：
"()a()()",7
返回：false

测试样例：
"()(()()",7
返回：false
*/

/*
思路：用栈结构实现，栈中存放左括号，当遇到右括号之后，检查栈中是否有左括号，如果有则出栈，如果没有，
则说明不匹配。
*/

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		stack<char> st; // 定义一个栈
		size_t i = 0;
		for (; i < n; i++)
		{
			if (A[i] == '(')
			{
				st.push(A[i]); // 如果为'('则压栈
			} 
			else if (A[i] == ')')
			{
				if (st.empty())
					break;
				// 之前为空则直接退出循环
				else
					st.pop();
				// 前面有对应的括号则出栈
			}
		} 
		if(st.empty() && i == n)
			return true;
		return false;
	}
};