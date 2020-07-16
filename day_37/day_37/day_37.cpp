/*
选择题

1.
A,B两台机器都正常工作,B机器未监听任何端口.如果A机器向B机器80端口发送SYN包,会收到何种类型的回包(D)
A ACK包
B FIN包
C 不会收到回包
D RST包
注：
因为B机器未监听任何端口,A又向B的80端口发送了数据包,所以B不会建立连接,
会异常结束建立连接,会发送 RST 包,如果是正常结束的话就会发送 FIN包,
RST 是 TCP 连接中 出现差错产生的, RST 置1可以用来拒绝一个非法的报文段或拒绝打开一个连接。

2.
以下哪个ip不和10.11.12.91/28处于同一个子网()
A 10.11.12.85/28
B 10.11.12.88/28
C 10.11.12.94/28
D 10.11.12.97/28
注：
IP地址由网络号和主机号组成，前28位为网络号，所以前28位都相同，可得子网掩码为（255.255.255.240）—>（11111111.111111111.111111111.11110000）
本题中IP地址前部分都是10.11.12，因此只用关注后面部分，
10.11.12.91/28中91可表示为01011011，前4位为网络号，后四位为主机号，
位于同一子网只用区分主机号即可，故包含10.11.12.91的子网范围是（01010000~01011111）即（80-95），
因此只有D不符合要求
*/


/*
编程题

1.
链接：https://www.nowcoder.com/questionTerminal/05f97d9b29944c018578d98d7f0ce56e

Web系统通常会频繁地访问数据库，如果每次访问都创建新连接，性能会很差。
为了提高性能，架构师决定复用已经创建的连接。当收到请求，并且连接池中没有剩余可用的连接时，
系统会创建一个新连接，当请求处理完成时该连接会被放入连接池中，供后续请求使用。
现在提供你处理请求的日志，请你分析一下连接池最多需要创建多少个连接。

输入
6
A connect
A disconnect
B connect
C connect
B disconnect
C disconnect
输出
2
*/


/*
[题目解析]
1. 服务器后台访问数据库时，需要先连上数据库，而为了连上数据库，需要连接方和数据库服务上各自都
要维护链接，而链接本身的创建维护是有成本的
2. 要减少开销，这里的解决方案就是将以前的mysql链接复用起来，从而节省了创建和销毁的时间成本，
该题目就是想让你根据算法，结合日志，计算当前的业务需要预先创建多少链接，来满足正常使用
[解题思路]
使用一个set来做，如果某个记录是connect，就加到set中去，如果是disconnect，就把set中对应的值删除
掉。在加进去的过程中，不断判断set元素的最大个数，最终返回这个最大个数即可。
*/


#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		set<string> pool;
		string id, con;
		int maxSize = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> id >> con;
			if (con == "connect") 
				pool.insert(id);
			else if (con == "disconnect")
				pool.erase(id);
			int size = pool.size();
			maxSize = max(maxSize, size);
		}
		cout << maxSize << endl;
	}
	return 0;
}



/*
2.
链接：https://www.nowcoder.com/questionTerminal/433c0c6a1e604a4795291d9cd7a60c7a

工作中，每当要部署一台新机器的时候，就意味着有一堆目录需要创建。例如要创建目录“/usr/local/bin”，
就需要此次创建“/usr”、“/usr/local”以及“/usr/local/bin”。好在，Linux下mkdir提供了强大的“-p”选项，
只要一条命令“mkdir -p /usr/local/bin”就能自动创建需要的上级目录。
现在给你一些需要创建的文件夹目录，请你帮忙生成相应的“mkdir -p”命令。

输入
3
/a
/a/b
/a/b/c
3
/usr/local/bin
/usr/bin
/usr/local/share/bin
输出
mkdir -p /a/b/c

mkdir -p /usr/bin
mkdir -p /usr/local/bin
mkdir -p /usr/local/share/bin
*/


/*
[题目解析]
1. 该题目需要你了解 mkdir -p 命令，改命令可以递归创建目录
2. 但是该题目其实想让我们解决的问题是，给你一组数据（详情见题目），怎么用最少的 mkdir -p 创建
出我们想要的多个目录
[解题思路]
只要按照题面，将前缀字符串路径和相同路径剔除，只mkdir －p最长或者唯一路径就可以解决这个问题
*/


#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> list(n);
		vector<bool> flag(n, true);
		for (int i = 0; i < n; ++i) cin >> list[i];
		sort(list.begin(), list.end()); //将类似字符串经过排序，放在一起
		for (int i = 0; i < list.size() - 1; ++i)
		{
			// 1、两串相同
			// 2、前串是后串的子串，而且后串后一位是 '/'
			if (list[i] == list[i + 1]) flag[i] = false;
			else if (list[i].size() < list[i + 1].size() && \
				list[i] == list[i + 1].substr(0, list[i].size()) && list[i + 1]
				[list[i].size()] == '/')
				flag[i] = false;
		} 
		for(int i = 0; i < list.size(); ++i)
			if (flag[i]) cout << "mkdir -p " << list[i] << endl;
		cout << endl;
	} 
	return 0;
}