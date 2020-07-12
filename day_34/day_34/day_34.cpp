/*
选择题

1.
TCP断开连接的四次挥手中，第四次挥手发送的包会包含的标记，最正确的描述是(C)
A FIN
B FIN,PSH
C ACK
D FIN,ACK
注：FIN是第三次的内容


2.
某浏览器发出的HTTP 请求报文如下：
下列叙述中，错误的是(C)
A 该浏览器请求浏览 index.html
B Index.html 存放在 www.test.edu.cn 上
C 该浏览器请求使用持续连接
D 该浏览器曾经浏览过 www.test.edu.cn

注：
Connection: 连接方式，   
Close 表明为非持续连接方式，   
keep-alive 表示持续连接方式。 
Cookie值是由服务器产生的，  
HTTP请求报文中有Cookie报头表示曾经访问过www.test.edu.cn服务器。
*/


/*
编程题

1.
链接：https://www.nowcoder.com/questionTerminal/5973a31d58234b068fa1fe34f7290855

NowCoder每天要给许多客户写电子邮件。正如你所知，如果一封邮件中包含多个收件人，
收件人姓名之间会用一个逗号和空格隔开；如果收件人姓名也包含空格或逗号，则姓名需要用双引号包含。
现在给你一组收件人姓名，请你帮他生成相应的收件人列表。

输入
3
Joe
Quan, William
Letendre,Bruce
2
Leon
Kewell
输出
Joe, "Quan, William", "Letendre,Bruce"
Leon, Kewell
*/


/*
先接收到一个数字，代表接下来是多少组数据，一个一个接，接到一个就拼一个，后面跟上一个逗号和一个空格，
全部接完就给个回车。如果输入的字符串里有逗号或者空格，就要加双引号。可以选择拼接好了输出，也可以选择
一段段直接输出。下面的代码是直接一段段输出的结果。
*/


#include <iostream>
#include <string>
#include <cstdio>
int main()
{
	int n;
	while (std::cin >> n) //接收数字
	{
		std::cin.get(); //处理回车
		std::string name;
		for (int i = 0; i < n; i++) //名字分别处理
		{
			bool quote = false;
			std::getline(std::cin, name);
			if (name.find(',') != std::string::npos ||
				name.find(' ') != std::string::npos) //找到逗号或者空格，就要加双引号
			{
				quote = true;
			} 
			
			if(quote)
			{
				putchar('\"'); //putchar效率更高
			}

			std::cout << name;
			if (quote)
			{
				putchar('\"');
			}
			if(i == n - 1) //如果已经是最后一个字符串，那就补回车，否则加逗号和空格
			{
				putchar('\n');
			} 
			else
			{
				putchar(',');
				putchar(' ');
			}
		}
	} 
	return 0;
}



/*
2.
链接：https://www.nowcoder.com/questionTerminal/71d3849a19f04a1591c415964ac148f1
一只成熟的兔子每天能产下一胎兔子。每只小兔子的成熟期是一天。 某人领养了一只小兔子，请问第N天以后，他将会得到多少只兔子。
输入
1
2

输出
1
2
*/

/*
本题的兔子第二天就开始下小兔了，所以这个是从第二项开始的斐波那契数列。前90组的数据恰好还在long long
的范围内，所以不需要高精度，直接long long求解
*/

#include <iostream>
#include <cstdio>
int main()
{
	long long n[91] = { 1, 2 };
	for (int i = 2; i <= 90; i++)
	{
		n[i] = n[i - 1] + n[i - 2];
	} 
	int d;
	while (std::cin >> d)
	{
		printf("%lld\n", n[d - 1]);
	}
}