/*
选择题

下面程序的输出是(B)

class A
{
public :
	void foo()
	{
		printf("1");
	}
	virtual void fun()
	{
		printf("2");
	}
};

class B : public A
{
public :
	void foo()
	{
		printf("3");
	} 
	void fun()
	{
		printf("4");
	}
};
int main()
{
	A a;
	B b;
	A *p = &a;
	p->foo();
	p->fun();
	p = &b;
	p->foo();
	p->fun();
	A *ptr = (A *)&b;
	ptr->foo();
	ptr->fun();
	return 0;
}

A 121434
B 121414
C 121232
D 123434


1.首先声明为A类型的指针指向实际类型为A的对象，调用的肯定是A的方法，输出1 2,
2.然后声明为A类型的指针指向实际类型为B的对象，则非虚函数调用A的方法，
输出1，虚函数调用实际类型B的方法，输出4
3.声明类型为A的指针指向实际类型为B的对象，进行一个强制类型转换，
其实这种父类指针指向子类会自动进行类型转换，所以是否强制类型转换都不影响结构，原理同上一步，结果输出1 4
*/


/*
编程题

1.
链接：https://www.nowcoder.com/practice/70e00e490b454006976c1fdf47f155d9?tpId=8&&tqId=11017&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。
现在有两个结点a，b。请设计一个算法，求出a和b点的最近公共祖先的编号。
给定两个int a,b。为给定结点的编号。请返回a和b的最近公共祖先的编号。
注意这里结点本身也可认为是其祖先。

测试样例：
2，3
返回：1
*/

/*
思路：题目所描述的满二叉树如下： 
        1
	   / \ 
	  2   3
	 / \ / \ 
    4   56  7 ...
上述树中子节点与父节点之间的关系为root = child / 2
所以如果a ！= b，就让其中的较大数除以2， 如此循环直到a == b 即是原来两个数的最近公共祖先 比如： 2
和7的最近公共祖先：7/2 = 3 ---> 3/2 = 1， 2/2 = 1， 得到1为它们的公共祖先
*/

class LCA {
public:
	int getLCA(int a, int b) {
		while (a != b)
		{
			if (a > b)
				a /= 2;
			else
				b /= 2;
		}
		return a;
	}
};


/*
链接：https://www.nowcoder.com/practice/4b1658fd8ffb4217bc3b7e85a38cfaf2?tpId=37&&tqId=21309&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
2.功能: 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
输入: 一个byte型的数字
输出: 对应的二进制数字中1的最大连续数
*/

/*
解法1：将byte数字转化为二进制，记录连续1的个数即可
*/

#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

int main()
{
	int input;
	while (cin >> input)
	{
		bitset<8> bitnum(input);
		int count = 0, maxcount = 0;
		for (size_t i = 0; i < bitnum.size(); i++)
		{
			if (bitnum[i] == 1)
				count++;
			else
				count = 0;
			maxcount = max(count, maxcount);
		}
		cout << maxcount << endl;
	}
	return 0;
}

/*
解法2：根据位运算，获取每一位的二进制值。获取第i位的值： (n >> i) & 1。如果1连续，则计数累加，如果不连
续，则从0开始计数。
*/

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0, maxCount = 0;
		// n右移32次就变为0
		while (n)
		{
			//获取当前位的二进制值
			if (n & 1)
				++count;
			else
				count = 0;
			maxCount = max(count, maxCount);
			n = n >> 1;
		} 
		cout << maxCount << endl;
	}
	return 0;
}