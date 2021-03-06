/*
选择题

1.
TCP连接释放过程，叙述不正确的是(B)
A 通过设置FIN为来表示释放连接
B 当一方释放连接后另一方即不能继续发送数据
C 只有双方均释放连接后，该连接才被释放
D 释放连接采用四次挥手机制

注：
当一方释放连接（发送FIN）时只是表明这一方不会在此次连接中发送数据了。另一方还是可以发送数据的

2.
下面有关TCP协议的描述，说法错误的是(D)
A TCP使用窗口机制进行流量控制
B 由于TCP连接是全双工的，因此每个方向都必须单独进行关闭，需要四次握手
C TCP连接建立需要三次握手
D 被动关闭socket后，会进入到TIME_WAIT状态

注：
TCP是面向连接的服务；三次握手（建立连接）和四次挥手（关闭连接）；使用滑动窗口机制进行流量控制；
TCP要保证在所有可能的情况下使得所有的数据都能够被投递，当你关闭一个socket时，
主动关闭一端的socket将进入TIME_WAIT状态，而被动关闭一方则转入CLOSED状态，这的确能够保证所有的数据都被传输。
1）首先A

B端的TCP进程都处于established状态， 当A的应用程序传送完报文段，就会去 主动关闭 连接。A
会停止发送报文段（但是还会接收），并向B发送[FIN = 1,seq=u]数据，之后进入FIN-WAIT-1状态；

2）B接收到A发送的请求之后，会通知应用进程A已经不再发送数据，B会向A发送ACK确认数据[ACK=1,seq=v,ack=u+1],B进入

CLOSE-WAIT状态，
A接收到B发送的数据之后，A进入FIN-WAIT-2状态；此时A到B方的连接已经关闭了。
3）当B的应用进程发现自己也没有数据需要传送，B应用进程就会发出 被动关闭 的请求，
B此时向A发送[FIN=1,ACK=1,seq=w,ack=u+1]数据，并且进入LAST-ACK状态；【所以D不对】

4）A接收到B发送的数据之后，向B发送确认数据[ACK
=1,seq=u+1,ack=w+1],进入TIME-WAIT状态，等待2MSL之后关闭连接进入CLOSED状态；
B接收到A发送的确认之后进入CLOSED状态。B到A方的连接关闭

3.
某IP地址192.168.48.10，掩码为255.255.255.128，其所在的子网为()，广播地址为()，有效的主机IP地址范围从()到().（A）
A 192.168.48.0/192.168.48.127/192.168.48.1 到 192.168.48.126
B 192.168.48.0/192.168.48.255/192.168.48.1 到 192.168.48.255
C 192.168.48.1/192.168.48.255/192.168.48.1 到 192.168.48.126
D 192.168.48.1/192.168.48.127/192.168.48.1 到 192.168.48.255

注：
网络位为25  主机位为7
网络地址ip和子网掩码相与的192.168.48.0
广播地址等于网络地址的主机位的二进制为1=192.168.48.127

有效的主机IP地址=网络地址+1   
广播地址-1==192.168.48.1 到 192.168.48.126

4.
172.16.100.5/255.255.255.252 的网络地址和主机号是多少(A)
A 172.16.100.4 1
B 172.16.100.4 5
C 172.16.100.5 1
D 172.16.100.5 5

注：
172.16.100.4 1
子网掩码是255.255.255.252
前三个字节是255，代表前三个字节是网络地址
最后一字节写成二进制形式为11111100
也就是说最后一字节中的前六位也是网络地址，后两位是主机地址
11111100与172.16.100.5最后一字节5按位与运算，5的二进制表示为101，与运算结果为4
即网络号为172.16.100.4，主机号为1
*/


/*
编程题

1.
链接：https://www.nowcoder.com/questionTerminal/a811535fed784ea492b63622c28c75c5

NowCoder最近爱上了五子棋，现在给你一个棋局，请你帮忙判断其中有没有五子连珠（超过五颗也算）
示例：
输入
....................
....................
....................
....................
......*.............
.......*............
........*...........
....++++.*..........
..........*.........
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
.......*............
......+*+++.........
.......*............
.......*............
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................

输出
Yes<br/>No
*/


/*
思路：
结构设计：dir代表当前位置的8个方向，其中上下、左右、左上右下、右上左下为必须放在一起检测。
获取一个棋盘，按照行列检测棋盘中的每个位置，当拿到一个位置后，按照以下步骤进行操作：
1. 以该位置为中心，依次检测该位置的上下、左右、左上右下、右上左下，比如左上
2. 从该位置开始向上检测，找出连在一起的同种棋子个数，再向下检测同种棋子的个数并累计，注意在检
测时，中心位置统计了两次，上下统计完时，需要给结果减去1
3. 按照2统计完上下、左右、左上右下、右上左下各个方向，找出最大的同种棋子个数
4. 检测3中统计出的最大同种棋子个数，如果大于等于5，输出YSE，否则取下一个位置继续1
5. 如果所有的位置检测完，没有超过5个的相同棋子，则输出NO
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define N 20
int count(string table[], char ch, int x, int y)
{
	int maxc = 0;
	int dir[4][2][2] = { { { -1, 0 }, { 1, 0 } }, { { 0, -1 }, { 0, 1 } }, { { -1, -1 }, { 1, 1 } }, { { -1, 1}, { 1, -1 } } };
	for (int i = 0; i < 4; ++i) // 四种方向
	{
		int c = 0;
		for (int j = 0; j < 2; ++j) // 两个小方向
		{
			int nx = x, ny = y;
			while (nx >= 0 && nx < N && ny >= 0 && ny < N && table[nx][ny] == ch)
			{
				nx += dir[i][j][0];
				ny += dir[i][j][1];
				++c;
			}
		} 
		maxc = (maxc > c ? maxc : c);
	} 
	return maxc - 1; //统计两个方向（如横向的左右两个方向）的时候，当前棋子被计算了两次
}

bool solve(string table[])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (table[i][j] == '*' || table[i][j] == '+')
			if (count(table, table[i][j], i, j) >= 5)
				return true;
		}
	} 
	return false;
}

int main()
{
	string table[N];
	while (cin >> table[0])
	{
		for (int i = 1; i < N; ++i) cin >> table[i];
		cout << (solve(table) ? "Yes" : "No") << endl;
	} 
	return 0;
}


/*
2.
链接：https://www.nowcoder.com/questionTerminal/1a92fbc771a54feb9eb5bd9b3ff2d0a9
Emacs号称神的编辑器，它自带了一个计算器。与其他计算器不同，
它是基于后缀表达式的，即运算符在操作数的后面。例如“2 3 + ”等价于中缀表达式的“2 + 3”。
请你实现一个后缀表达式的计算器。
示例
输入
3
2 3 +
5
2 2 + 3 *
5
2 2 3 + *
输出
5
12
10
*/

/*
思路：
循环输入，获取逆波兰表达式，然后进行以下补助，直到测试完所有的测试用例：
1. 遇到数字字符串，将该数字字符串转化为数字然后入栈。
2. 遇到操作符时，从栈顶取两个数字，然后进行该运算符所对应运算，完成好将结果入栈，注意：先取到
的数字为运算符的右操作数。
3. 继续1和2，直到处理完所有的字符串，最终栈顶元素即为所要结果。
*/

#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int n;
	int a, b, ret;
	while (cin >> n)
	{
		if (n == 0)
			continue;
		vector<string> s(n);
		stack<int> st;
		for (int i = 0; i<n; i++)
		{
			cin >> s[i];
		} 
		for(int i = 0; i<n; i++)
		{
				if (s[i][0] >= '0'&&s[i][0] <= '9')
				{
					st.push(atoi(s[i].data()));
				} 
				else
				{
					a = st.top();
					st.pop();
					b = st.top();
					st.pop();
					switch (s[i][0])
					{
					case '+': st.push(a + b); break;
					case '-': st.push(b - a); break;
					case '*': st.push(a*b); break;
					case '/': st.push(b / a); break;
					}
				}
		} 
		cout << st.top() << endl;
	} 
	return 0;
}