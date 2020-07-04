/*
选择题

下列选项中，导致 创建 新进程的操作是(C)

I用户登陆成功II设备分配III启动程序执行

A 仅I和II
B 仅II和III
C 仅I和III
D I、II和III

注：
用户登录成功后，操作系统将启动与用户有关的初始程序，此时需要创建新的进程。
启动程序执行时毫无疑问会启动新进程。但设备分配是针对现有进程，不会创建新进程
*/


/*
编程题

1.
链接：https://wenku.baidu.com/view/b18808d8a48da0116c175f0e7cd184254b351bfb.html
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号
*/

/*
解题思路：数字的相加可以转换为二进制的加法，注意每一位相加与进位即可
1. 两个数异或：相当于每一位相加，而不考虑进位；
*/

class Solution {
public:
	int Add(int num1, int num2) {
		while (num2 != 0){
			int sum = num1 ^ num2; //得到相加后不包含进位的数据
			int carray = (num1 & num2) << 1; //得到两数相加的进位
			num1 = sum; //两个结果相加，直到进位为0
			num2 = carray;
		} 
		return num1;
	}
};



/*
2.
链接：https://www.nowcoder.com/questionTerminal/c67a09062c0f4a5b964eef0945d3dd06
给定三条边，请你判断一下能不能组成一个三角形。

输入
1 2 3
2 2 2
输出
No
Yes
*/

/*
思路：对输入的三个数字分别进行两两相加与另一个数进行比较
*/

#include <iostream>
#include <string>
#define ADD(x, y) ((x) + (y))
#define CMP(x, y) ((x) > (y))
int main()
{
	double a, b, c;
	while (std::cin >> a >> b >> c)
	{
		//对两边进行求和与第三遍进行比较
		if (CMP(ADD(a, b), c) && CMP(ADD(b, c), a) && CMP(ADD(a, c), b))
			std::cout << "Yes" << std::endl;
		else
			std::cout << "No" << std::endl;
	} 
	return 0;
}