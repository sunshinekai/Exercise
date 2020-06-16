/*
选择题

1.
某函数申明如下：
void Func(int &nVal1);
有int a,下面使用正确的为：(A)
A Func(a)
B Func(&a)
C Func(*a)
D Func(&(*a))

注：参数&，表示引用，也就是变量的另一个别名。
&(引用)==>出现在变量声明语句中位于变量左边时,表示声明的是引用.
&(取地址运算符)==>在给变量赋初值时出现在等号右边或在执行语句中
作为一元运算符出现时表示取对象的地址.

2.
当一个类的某个函数被说明为virtual，则在该类的所有派生类中的同原型函数(D)
A 只有 被重新说明时才识虚函数
B 只有被重新说明为virtual时才是虚函数
C 都不是虚函数
D 都是虚函数
注：父类的所有子类中，同名函数都是虚函数。

3.
有如下程序：
运行时的输出结果是(B)
void Func(int &nVal1);
#include<iostream>
using namespace std;
class MyClass{
public:
	MyClass(int i=0){cout<<1;}
	MyClass(const MyClass&x){cout<<2;}
	MyClass& operator=(const MyClass&x){cout<<3; return*this;}
	~MyClass(){cout<<4;}
};
int main(){
	MyClass obj1(1),obj2(2),obj3(obj1);
	return 0;
}
A 121,444
B 112,444
C 11,114,444
D 11,314,445
E 11,314,444
C MyClass obj3 = obj1;

注：obj3还不存在，所以调用拷贝构造函数输出2，
如果obj3存在，obj3 = obj，则调用复制运算符重载函数，输出3

4.
代码执行后，a和b的值分别为(A)
class Test{
public:
	int a;
	int b;
	virtual void fun() {}
	Test(int temp1 = 0, int temp2 = 0)
	{
		a = temp1;
		b = temp2;
	}
	int getA()
	{
		return a;
	}
	int getB()
	{
		return b;
	}
};
int main()
{
	Test obj(5, 10);
	// Changing a and b
	int* pInt = (int*)&obj;
	*(pInt + 0) = 100;
	*(pInt + 1) = 200;
	cout << "a = " << obj.getA() << endl;
	cout << "b = " << obj.getB() << endl;
	return 0;
}

A 200 10
B 5 10
C 100 200
D 100 10
注：需要考虑虚函数表，指向虚函数表的指针在32位系统下占用4个字节，
其地址分布在整个类成员变量的地址的首部，接下来就是变量a的地址、b的地址。
当将test对象obj赋给指向整型的pInt后，指针pInt指向了地址的首部也就是虚函数表指针，
所以*（pInt+0）=100改变的是虚函数表的值，接下来*（pInt+1）=200改变的是变量a的值，变量b没有变换。
*/



/*
编程题

1.
链接：https://www.nowcoder.com/practice/e7e0d226f1e84ba7ab8b28efc6e1aebc?tpId=8&&tqId=11065&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
请编写一个函数，将两个数字相加。不得使用+或其他算数运算符。
给定两个int A和B。请返回A＋B的值

测试样例：
1,2
返回：3
*/

/*
思路：A&B是A与B相同的位，A^B是取A与B相同的位，相同位*2 + 不同位即为加法运算
(A & B) << 1 + (A & B),如此循环直到进位之后的结果为0时，相加结束
*/

class UnusualAdd {
public:
	int addAB(int A, int B) {
		int x = A ^ B; // A与B不同的位
		int y = A & B; // A与B相同的位
		while (y != 0)
		{
			y = y << 1; // 相同位*2
			int tmp = x;
			x = x ^ y;
			y = tmp & y;
		}
		return x;
	}
};

/*
2.
链接：https://www.nowcoder.com/practice/e2a22f0305eb4f2f9846e7d644dba09b?tpId=37&&tqId=21314&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
请编写一个函数（允许增加子函数），计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）
沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，
即：只能往右和往下走，不能往左和往上走。
示例：
输入
2
2
输出
6
*/

/*
思路：本题为求取路径总数的题目，一般可以通过递归求解，对于复杂的问题，可以通过动态规划求解。
| 1 | 2 | 3 |
-------------
| 4 | 5 | 6 |
-------------
| 7 | 8 | 9 |
-------------
1. 对于上面的n*m(3*3)的格子，有两种情况
a. 如果n或者m为1，则只有一行或者一列，从左上角走到右下角的路径数为n + m
比如： 1 * 1格子，可以先向下走，再向右走，到达右下角；或者先向右走，
再向下走，到达右下角，共两条，即 1 + 1 = 2，对于1 * m和 n * m
b. 如果n,m都大于1，那么走到[n][m]格子的右下角只有两条路径，
<1>: 从[n - 1][m]格子的右下角向下走，到达
<2>: 从[n][m - 1]格子的右下角向右走，到达
所以走到[n][m]格子的右下角的数量为[n-1][m] + [n][m - 1],可以通过递归实现，情况a为递归的终止条
件。
*/


#include<iostream>
using namespace std;
int pathNum(int n, int m)
{
	if (n > 1 && m > 1)
		// b情况，递归
		return pathNum(n - 1, m) + pathNum(n, m - 1);
	else if (((n >= 1) && (m == 1)) || ((n == 1) && (m >= 1)))
		// a情况，终止条件
		return n + m;
	else
		// 格子为0时， 路径为0
		return 0;
} 
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		cout << pathNum(n, m) << endl;
	} 
	return 0;
}