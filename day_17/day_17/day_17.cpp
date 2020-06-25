/*
选择题

1.
下列给定程序中，函数fun的功能是:求ss所指字符串数组中长度最短的字符串所在的行下标，
作为函数值返回，并把其串长放在形参n所指的变量中。ss所指字符串
数数组中共有M个字符串，且串长小于N。
请在程序的下画线处填入正确的内容并将下画线删除，使程序得出正确的结果(C)

#define M 5
#define N 20
int fun(char(*ss)[N], int *n)
{
	int i, k = 0, len = N;
	for (i = 0; i < ______; i++)
	{
		len = strlen(ss[i]);
		if (i == 0)
			*n = len;
		if (len ____ * n)
		{
			*n = len;
			k = i;
		}
	} 
	return(_____);
} 

main()
{
	char ss[M][N] = { "shanghai", "guangzhou", "beijing", "tianjing", "chongqing" };
	int n, k, i;
	printf("\nThe originalb stringsare:\n");
	for (i = 0; i < M; i++)
		puts(ss[i]);
	k = fun(ss, &n);
	printf("\nThe length of shortest string is: % d\n", n);
	printf("\nThe shortest string is: % s\n", ss[k]);
}

A N，<，k
B N，>，k
C M，<，k
D M，>，k
注：根据提示做出相应判断即可

2.
如何捕获异常可以使得代码通过编译(B)
class A 
{
public:
	A(){}
};

void foo()
{
	throw new A;
}
A catch (A && x)
B catch (A * x)
C catch (A & x)
D 以上都是

题目中问的是能否通过编译，只有B会捕获到异常，进行异常处理，
而A和C由于和throw抛出的异常类型不匹配，导致这个异常不被捕获，
从而成为未捕获的异常，调用terminate函数结束程序。

3.
下列代码可以通过编译吗？如何修改使其通过编译(C)

template <class T>
struct sum 
{
	static void foo(T op1 , T op2)
	{
		cout << op1 <<op2;
	}
};
sum::foo(1,3);
A 编译通过
B 应该去掉static关键字
C 调用应该如下： sum<int>:: foo(1,3)
D 调用应该如下： sum:: <int>foo(1,3)
注：模板的应用

4.
有如下程序段：
#include <iostream>
using namespace std;

class A
{
public:
	~A() 
	{
		cout << "~A()";
	}
};

class B
{
public:
	virtual ~B()
	{
		cout << "~B()";
	}
};

class C : public A, public B
{
public:
	~C()
	{
		cout << "~C()";
	}
};

int main() 
{
	C * c = new C;
	B * b1 = dynamic_cast<B *>(c);
	A * a2 = dynamic_cast<A *>(b1);
	delete a2;
}

则程序输出(D)
A ~C()~B()~A()
B ~C()~A()~B()
C A、B都有可能
D 以上都不对

注：继承调用程序会报错
*/


/*
编程题

1.
链接：https://www.nowcoder.com/practice/8ef655edf42d4e08b44be4d777edbf43?tpId=37&&tqId=21276&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
1
1  1  1
1  2  3  2  1
1  3  6  7  6  3  1
1  4  10 16 19  16 10  4  1
以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。
求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出2，输入4则输出3。

输入
4
输出
3
*/

/*
思路：按照题目意思，可以发现第n行有2n - 1个元素，第i,j元素等于上一行第j - 2,j - 1,j三列元素之和，
每一行的第一列和最后一列都为1，如果是第二列，则只是两个元素之和
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n)
	{
		m = 2 * n - 1;
		vector<vector<int>> dp(n, vector<int>(m, 0));
		dp[0][0] = 1;
		for (int i = 1; i < n; i++)
		{
			//第一列和最后一列都为1
			dp[i][0] = dp[i][2 * i] = 1;
			for (int j = 1; j < 2 * i; ++j)
			{
				if (j == 1)
					//如果是第二列，则只是两个元素之和
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				else
					//第i,j元素等于上一行第j - 2,j - 1,j三列元素之和
					dp[i][j] = dp[i - 1][j - 2] + dp[i - 1][j - 1] + dp[i - 1][j];
			}
		} 
		int k;
		for (k = 0; k < m; k++)
		{
			if (dp[n - 1][k] % 2 == 0 && dp[n - 1][k] != 0)
			{
				cout << k + 1 << endl;
				break;
			}
		} 
		if(k == m)
			cout << -1 << endl;
	} 
	return 0;
}


/*
思路：按照数学规律
*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int pos = 0;
		if (n == 1 || n == 2)
			pos = -1;
		else if (n % 2 == 1 && n > 2)
			pos = 2;
		else if (n % 4 == 0)
			pos = 3;
		else
			pos = 4;
		cout << pos << endl;
	}
	return 0;
}

/*
2.
链接：https://www.nowcoder.com/practice/5821836e0ec140c1aa29510fd05f45fc?tpId=37&&tqId=21301&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
请设计一个算法完成两个超长正整数的加法。
输入
99999999999999999999999999999999999999999999999999
1
输出
100000000000000000000000000000000000000000000000000
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addStrings(string num1, string num2) 
{
	// 由低位向高位相加
	int i = num1.size() - 1;
	int j = num2.size() - 1;
	string result = "";
	// 当前位的相加结果
	int carry = 0;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0) 
			carry += num1[i] - '0';
		
		if(j >= 0)
			carry += num2[j] - '0';
		// 当前为的最大值不大于10
		result += (char)(carry % 10 + '0');
		// 如果大于10,向上进一位
		carry /= 10;
		i--;
		j--;
	}
	// 相加完之后，如果还有进位，则再加1
	if(carry == 1) 
		result += '1';
	// 整体逆置
	reverse(result.begin(), result.end());
	return result;
} 

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << addStrings(s1, s2) << endl;
	} 
	return 0;
}