/*
选择题

1.
下面程序的输出结果是(B)
#include <iostream>
using namespace std;
int main()
{
	int n[][3] = { 10, 20, 30, 40, 50, 60 };
	int(*p)[3];
	p = n;
	cout << p[0][0] << "," << *(p[0] + 1) << "," << (*p)[2] << endl;
	return 0;
}
A 10,30,50
B 10,20,30
C 20,40,60
D 10,30,60
注：(*p)[3] = {10,20,30}*(p[0]+1) = p[0][1] = 20 (*p)[2] = 30

2.
int main()
{
	int a;float b,c;
	scanf("%2d%3f%4f",&a,&b,&c);
	printf("\na=%d,b=%d,c=%f\n",a,b,c);
}
若运行时从键盘上输入9876543210l,则上面程序在gcc编译器下的输出结果是(B)
A a=98,b=765,c=4321.000000
B a=98,b=0,c=0.000000
C a=98,b=765.000000,c=4321.000000
D a=98,b=765.0,c=4321.0
注：数据(int,float)在内存中的存储方式

3.
下面说法正确的是(A)
A 一个空类默认一定生成构造函数,拷贝构造函数,赋值操作符,引用操作符,析构函数
B 可以有多个析构函数
C 析构函数可以为virtual,可以被重载
D 类的构造函数如果都不是public访问属性,则类的实例无法创建
注：类的默认6个成员函数

4.请选择下列程序的运行结果(B)
A B0::display0 B0::display0 B0::display0
B B0::display0 B0::display0 D1::display0
C B0::display0 B1::display0 D1::display0
D B0::display0 B1::display0 B1::display0

#include<iostream>
using namespace std;
class B0 // 基类BO声明
{ 
public: // 外部接口
	virtual void display() // 虚成员函数
	{
		cout<<"B0::display0"<<endl;
	}
};

class B1:public B0 // 公有派生
{
public:
	void display() 
	{
		cout<<"B1::display0"<<endl;
	}
};

class D1: public B1//公有派生
{
public:
	void display()
	{ 
		cout<<"D1::display0"<<endl; 
	}
};

void fun(B0 ptr)//普通函数
{
	ptr.display();
}

int main()//主函数
{
	B0 b0;//声明基类对象和指针
	B1 b1;//声明派生类对象
	D1 d1;//声明派生类对象
	fun(b0);//调用基类B0函数成员
	fun(b1);//调用派生类B1函数成员
	fun(d1);//调用派生类D1函数成员
	return 0;
}
注：
虚函数的动态绑定仅在基类指针或引用绑定派生类对象时发生 ，
fun的形参不是指针，所以调用哪个版本的函数编译时就已经确定，
根据形参静态类型确定调用B0的成员。
*/

/*
编程题

1.
链接：https://www.nowcoder.com/practice/9d1559511b3849deaa71b576fa7009dc?tpId=85&&tqId=29842&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
“回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。
花花非常喜欢这种拥有对称美的回文串，生日的时候她得到两个礼物分别是字符串A和字符串B。
现在她非常好奇有没有办法将字符串B插入字符串A使产生的字符串是一个回文串。你接受花花的请求，
帮助她寻找有多少种插入办法可以使新串是一个回文串。如果字符串B插入的位置不同就考虑为不一样的办法。
例如：
A = “aba”，B = “b”。这里有4种把B插入A的办法：
* 在A的第一个字母之前: "baba" 不是回文
* 在第一个字母‘a’之后: "abba" 是回文
* 在字母‘b’之后: "abba" 是回文
* 在第二个字母'a'之后 "abab" 不是回文
所以满足条件的答案为2
输入
aba
b
输出
2
*/

/*
思路:本题使用暴力求解方式计算即可，遍历a，将b insert进a的每个位置，判断是否是回文，是就
++count；需要注意的是这里不能 a.insert(i, b)，这样的话a改变了，判断下一个位置就不对了。
所以每次使用a拷贝构造一个a_start，然后str.insert(i, b)，再判断
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
	string a,b;
	getline(cin, a);
	getline(cin, b);
	string a_start = a;
	size_t n = a.size();
	size_t i = 0, count = 0;
	for (;i <= n; i++)
	{
		a.insert(i, b);
		string str = a;
		reverse(a.begin(), a.end()); // 判断字符串是否回文

		if (str == a)
			count++;

		a = a_start;
	}
	cout << count << endl;
	return 0;
}

/*
2.
链接：
一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3
输入描述:
输入为两行。 第一行一个整数n(1 <= n <= 100000)，表示一共有n个元素 第二行为n个数，即每个元素,每个整数都在32位int范围内。以空格分隔。
输出描述:
所有连续子数组中和最大的值。
示例:
输入
3 -1 2 1
输出
3
*/

/*
思路：假设sum[i-1]是以数组中第nums[i-1]为最后一个元素的一段子数组最大和，
sum[i]是以数组中第nums[i]为最后一个元素的一段子数组最大和，
那么sum[i] = max(sum[i-1], 0) + nums[i]，理解了这个，下面代码中用sum1表示sum[i-1]，sum2表示
sum[i]，如果计算出更大的子数组和则保存到result中。如果sum[i]，及sum2都小于0了，则置为0，
因为他加上数组下一个数，不会计算出更大的子数组和。
*/

#include <iostream>
#include<vector>

using namespace std;
int main()
{
	int size;
	cin >> size;
	vector<int> nums(size);
	for (size_t i = 0; i < size; ++i)
		cin >> nums[i];
	int result = nums[0];
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		// 计算到num[i]的子数组的最大和
		sum2 = sum1 >= 0 ? sum1 + nums[i] : nums[i];
		if (sum2 > result)
			result = sum2;
		if (sum2 < 0)
			sum2 = 0;
		sum1 = sum2;
	}
	cout << result << endl;
	return 0;
}