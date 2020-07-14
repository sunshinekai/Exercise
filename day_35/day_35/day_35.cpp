/*
选择题

1.
主机甲和乙已建立了TCP连接，甲始终以MSS=1KB大小的段发送数据，并一直有数据发送；乙每收到一个数据
段都会发出一个接收窗口为10KB的确认段。若甲在t时刻发生超时时拥塞窗口为8KB，则从t时刻起，
不再发生超时的情况下，经过10个RTT后，甲的发送窗口是(A)
A 10KB
B 12KB
C 14KB
D 15KB

注：
t时刻发生超时时拥塞窗口为8KB，慢启动阈值设为其一半=4
拥塞窗口按指数增长：2，4（达到阈值，改为线性增长）5，6，7，8，9，10，11，12
发送窗口 = min{拥塞窗口，接收窗口}

2.
ARP 协议的功能是(A)
A 根据 IP 地址查询 MAC 地址
B 根据 MAC 地址查询 IP 地址
C 根据域名查询 IP 地址
D 根据 IP 地址查询域名

注：
ARP的功能：根据IP地址查询MAC地址


3.
TCP/IP 参考模型的网络层提供的是(A)
A 无连接不可靠的数据报服务
B 无连接可靠的数据报服务
C 有连接不可靠的虚电路服务
D 有连接可靠的虚电路服务

注：
TCP/IP的网络层向上只提供简单灵活的、无连接的、尽最大努力交付的数据报服务。
考查IP首部，如果是面向连接的，则应有用于建立连接的字段，但是没有；
如果提供可靠的服务，则至少应有序号和校验和两个字段，
但是IP分组头中也没有（IP首部中只是首部校验和）。通常有连接、可靠的应用是由运输层的TCP实现的。
*/



/*
编程题

1.
链接：https://www.nowcoder.com/questionTerminal/610e6c0387a0401fb96675f58cda8559

今年公司年会的奖品特别给力，但获奖的规矩却很奇葩：
1. 首先，所有人员都将一张写有自己名字的字条放入抽奖箱中；
2. 待所有字条加入完毕，每人从箱中取一个字条；
3. 如果抽到的字条上写的就是自己的名字，那么“恭喜你，中奖了！”
现在告诉你参加晚会的人数，请你计算有多少概率会出现无人获奖？

输入
2
输出
50.00%
*/

/*
思路：错排的递推公式是：D(n) = (n - 1) [D(n - 2) + D(n - 1)]，也就是n - 1倍的前两项和。公式推导可以参考百度百科。
通过这个递推公式可以得到在总数为n的时候，错排的可能性一共有多少种。那么要求错排的概率，我们还需要另
一个数值，就是当总数为n的时候，所有的排列组合一共有多少种，那么根据排列组合，肯定是使用A！
的公式来求，也就是n的阶乘。所以结果很简单，就是用公式求出第n项的错排种类，和n的阶乘，然后两者一除，就是概率了
*/

#include <iostream>
#include <iostream>
#include <cstdio>
int main()
{
	long long d[22] = { 0, 0, 1 }; // 错排数量，预留第一项为0，配合下文中输入的n
	long long f[22] = { 0, 1, 2 }; // 阶乘
	for (int i = 3; i < 22; i++)
	{
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]); //错排的递推公式
		f[i] = i * f[i - 1]; //阶乘的递推公式
	} 
	
	int n;
	while (std::cin >> n)
	{
		printf("%.2f%%\n", 100.0 * d[n] / f[n]); //用100.0来把结果处理成double，保留两位小数
	}
	return 0;
}


/*
2.
链接：https://www.nowcoder.com/questionTerminal/286af664b17243deb745f69138f8a800

NowCoder每天要处理许多邮件，但他并不是在收件人列表中，有时候只是被抄送。
他认为这些抄送的邮件重要性比自己在收件人列表里的邮件低，因此他要过滤掉这些次要的邮件，优先处理重要的邮件。
现在给你一串抄送列表，请你判断目标用户是否在抄送列表中。
*/

/*
本题最简单的思路，就是把第一行中的每一个人名都存在一个string容器里，然后和第二行的这个字符串一个一个
比过去，看有没有重合的即可。比较简单的思路是可以做一个string的数组，分割完了一比就行了。例如我下文中
使用的是比较基础的vector。当然也可以选择一些其他的更方便的容器。需要注意的点是双引号需要特殊处理，别
的都是正常的字符串处理
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
int main()
{
	std::string line;
	while (std::getline(std::cin, line)) //第一次的输入抓到line里
	{
		std::vector<std::string> names; //names里存放所有的数据
		size_t pos = 0;
		while (pos < line.length()) //位置如果大于等于了长度，那么证明找完了，双引号的情况从这里跳出
		{
			if (line[pos] == '\"') //找到双引号要处理双引号内部
			{
				size_t end = line.find("\"", pos + 1);
				names.push_back(line.substr(pos + 1, end - pos - 1)); //截取出来放到names里
				pos = end + 2;//跳掉后面的双引号和逗号
			} 
			else
			{
				size_t end = line.find(",", pos + 1);
				if (end == -1) //找不到逗号证明这是最后一个字符串了，直接存了这个字符串后跳出
				{
					names.push_back(line.substr(pos, line.size() - pos));
					break;
				} 
				names.push_back(line.substr(pos, end - pos));
				pos = end + 1; //跳掉后面的逗号
			}
		} 
		std::getline(std::cin, line);
		if (names.end() == std::find(names.begin(), names.end(), line))
			//std::find函数是在两个迭代器中间查找，最后一个参数是要找的值。
			//找到了返回对应迭代器，找不到就返回区间末尾的位置。本例中是end()。
		{
			printf("Important!\n"); //没找到
		} 
		else
		{
			printf("Ignore\n"); //找到了
		}
	}
	return 0;
}