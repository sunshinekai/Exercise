/*
选择题

1.
C++中关于堆和栈的说法，哪个是错误的(D)
A 堆的大小仅受操作系统的限制，栈的大小一般一般较小
B 在堆上频繁的调用new/delete容易产生内存碎片，栈没有这个问题
C 堆和栈都可以静态分配
D 堆和栈都可以动态分配
注：堆不可以静态分配

2.下面程序会输出什么(B)

#include <iostream>

static int a = 1;
void fun1(void){ a = 2; }
void fun2(void){ int a = 3; }
void fun3(void){ static int a = 4;}
int main(int argc, char** args){
	printf("%d", a);
	fun1();
	printf("%d", a);
	fun2();
	printf("%d",a);
	fun3();
	printf("%d", a);

A 1 2 3 4
B 1 2 2 2
C 1 2 2 4
D 1 1 1 4
注：第二次输出，访问到了早已定义的全局变量i，并改写值，第二次为2。
第三次输出，内部定义了一个同名的变量， 它并没有返回值或者被该次执行程序以外任何程序读取a值，所以第三次输出仍然是a。
第四次输出，定义了一个静态的局部变量，静态局部变量在函数调用结束后仍然存在，
及它的内存空间不会被释放，但其他函数是不能引用它的，所以，两个静态变量虽然同名，但是并不是一样的东西

3.
In the main(C) function, after ModifyString(text) is called, what’s the value of ‘text’？

int FindSubString(char* pch)
{
	int count = 0;
	char * p1 = pch;
	while (*p1 != '\0')
	{
		if (*p1 == p1[1] - 1)
		{
			p1++;
			count++;
		}
		else {
			break;
		}
	} 
	
	int count2 = count;
	while (*p1 != '\0')
	{
		if (*p1 == p1[1] + 1)
		{
			p1++;
			count2--;
		}
		else {
			break;
		}
	} 
	if(count2 == 0)
		return(count);
	return(0);
} 
void ModifyString(char* pText)
{
	char * p1 = pText;
	char * p2 = p1;
	while (*p1 != '\0')
	{
		int count = FindSubString(p1);
		if (count > 0)
		{
			*p2++ = *p1;
			sprintf(p2, "%i", count);
			while (*p2 != '\0')
			{
				p2++;
			} 
			p1 += count + count + 1;
		}
		else 
		{
			*p2++ = *p1++;
		}
	}
}
void main(void)
{
	char text[32] = "XYBCDCBABABA";
	ModifyString(text);
	printf(text);
}

A XYBCDCBABABA
B XYBCBCDA1BAA
C XYBCDCBA1BAA
D XYBCDDBA1BAB


FindSubString函数查找"对称!!!"的连续上升再连续下降回文子串（例如CDC，题目中的BCDCBA不是），返回count，
若不是回文子串或者不对称则返回0
字符串XYBCDCBABABA 之前的所有字符执行的都是 ModifyString函数中的else子段，即*p2++=*p1++;
字符串 XYBCDCBABABA 的 第一个对称回文子串为ABA，此时sprintf语句会用count(此时为1)替换B，并自动添加串结尾符'\0'在第二个A的位置，
则下边的while语句即将p2指针移动到第二个A的位置，p1 += count + count +1将p1移动到第二个A后面的B位置上，即p2的后一位
这之后没有对称回文子串，则执行*p2++=*p1++，直到p1到达串尾，即用倒数第二个字符替换倒数第三个，用倒数第一个字符替换倒数第二个
综上，结果是XYBCDCB A1 BA A

4.
关于以下代码，哪个说法是正确的(B)
myClass::foo()
{
	delete this;
}
..

void func()
{
	myClass *a = new myClass();
	a->foo();
}

A 它会引起栈溢出
B 都不正确
C 它不能编译
D 它会引起段错误

注：
总结一下 
一，在foo()中调用delete this;没有问题，但是在析构函数中调用则会由于
delete this会自动调用析构函数的原因造成无限递归，导致栈溢出。
二，调用完delete this 之后，对象的内存空间被释放了，导致不能再访问数据成员和虚函数

5.
下面这段代码会打印出什么(A)
class A
{ 
public :
	A()
	{
		printf("A ");
	} 

	~A()
	{
		printf("deA ");
	}
};
class B
{
	
public :
	B()
	{
		printf("B ");
	} 
	
	~B()
	{
		printf("deB ");
	}
};
class C : public A, public B
{
	
public :
	C()
	{
		printf("C ");
	} 
	
	~C()
	{
		printf("deC ");
	}
};
int main()
{
	A *a = new C();
	delete a;
	return 0;
}

A A B C deA
B C A B deA
C A B C deC
D C A B deC

注：
构造函数的执行先执行父类，再执行子类。析构顺序相反
A B的析构函数不是虚函数，所以不会执行子类的虚函数。
*/

/*
编程题

1.
链接：https://www.nowcoder.com/practice/1b46eb4cf3fa49b9965ac3c2c1caf5ad?tpId=37&&tqId=21285&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
输入一个整数，计算整数二进制中1的个数。
输入
5
输出
2
*/

/*
思路1：可以将数字转为2进制，然后直接计算统计出1的个数即可
*/

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	int number;
	while (cin >> number)
	{
		int count = 0;
		bitset<32> bitnum(number);
		for (size_t i = 0; i < bitnum.size(); i++)
		{
			if (bitnum[i] == 1)
				count++;
		}
		cout << count << endl;
	}
	return 0;
}

/*
思路2：本题是计算一个数二进制表示中1的个数，通过（n >> i) & 1可以获取第i位的二进制值，每次n右
移一位，可以获取一位的二进制值，右移32次，n变成0，循环终止。
*/

#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		while (n)
		{
			if ((n & 1) == 1)
				count++;
			n >>= 1;
		}
		cout << count << endl;
	} 
	return 0;
}

/*
2.
链接：https://www.nowcoder.com/practice/365d5722fff640a0b6684391153e58d8?tpId=49&&tqId=29337&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。
A先生现在要出门，所以他要去地下室选手套。但是昏暗的灯光让他无法分辨手套的颜色，只能分辨出左右手。
所以他会多拿一些手套，然后选出一双颜色相同的左右手手套。
现在的问题是，他至少要拿多少只手套(左手加右手)，才能保证一定能选出一双颜色相同的手套。
给定颜色种数n(1≤n≤13),同时给定两个长度为n的数组left,right,分别代表每种颜色左右手手套的数量。
数据保证左右的手套总数均不超过26，且一定存在至少一种合法方案。

4,[0,7,1,6],[1,5,0,6]
返回：10(解释：可以左手手套取2只，右手手套取8只)
*/

/*
对于非0递增序列a1,a2...an，要想最终取值覆盖每一个种类
n = sum(a1...an) - a1 + 1（也就是总数减去最小值之后加一）
所以对于左右手手套颜色都有数量的序列，想要覆盖每一种颜色，则最小数量leftsum = 左边数量
和 - 左边最小值 + 1， rightsum = 右边数量和 - 右边的最小值 + 1。而对于有0存在的，则需要做
累加，保证覆盖每一种颜色。
*/

class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		int left_sum = 0, left_min = INT_MAX;
		int right_sum = 0, right_min = INT_MAX;
		int sum = 0;
		//遍历每一种颜色的左右手套序列
		for (int i = 0; i<n; i++){
			//对于有0存在的颜色手套，累加
			if (left[i] * right[i] == 0)
				sum += left[i] + right[i];
			//对于左右手都有的颜色手套，执行累加-最小值+1
			//找到最小值和总数
			else{
				left_sum += left[i];
				right_sum += right[i];
				left_min = min(left_min, left[i]);
				right_min = min(right_min, right[i]);
			}
		} 
		// 结果为有左右都有数量的手套序列的结果 + 有0存在的手套数 + 最后再加一肯定就能保证了
			return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
	}
};