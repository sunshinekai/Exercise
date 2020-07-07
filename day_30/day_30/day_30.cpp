/*
选择题

1.
某系统中有11台打印机，N个进程共享打印机资源，每个进程要求3台，当N的取值不超过（B）时系统不会发生死锁。
A 4
B 5
C 6
D 7
注：每个进程要求3台，所以先给每个进程2台，再如果多出一台，分给某一个进程，等这个进程执行完了，
释放自己的资源给其他进程用，这样就不会发生死锁。即2N+1=11，得N=5。N=4时，不是最大值，不符合题意，N=6时，资源不够用，可能死锁。

2.
什么是内存抖动（Thrashing）（A）
A 非常频繁的换页活动
B 非常高的CPU执行活动
C 一个极长的执行进程
D 一个极大的虚拟内存

注：页面的频繁更换，导致整个系统效率急剧下降，这个现象称为内存抖动。
抖动一般是内存分配算法不好，内存太小引或者程序的算法不佳引起的页面频繁从内存调入调出。

3.
在所有非抢占CPU调度算法中，系统平均响应时间最优的是（B）
A 实时调度算法
B 短任务优先算法
C 时间片轮转算法
D 先来先服务算法
注：平均响应时间是短作业优先。时间片轮转，短作业的响应时间变长了，
然而长作业或中间的作业的响应时间也没变短多少，甚至不变短反而变长。

4.
下面关于inode描述错误的是(A)
A inode和文件是一一对应的
B inode能描述文件占用的块数
C inode描述了文件大小和指向数据块的指针
D 通过inode实现文件的逻辑结构和物理结构的转换

注：般情况下，文件名和inode号码是"一一对应"关系，每个inode号码对应一个文件名。
但是，Unix/Linux系统允许，多个文件名指向同一个inode号码。这意味着，可以用不同的文件名访问同样的内容；
对文件内容进行修改，会影响到所有文件名；但是，删除一个文件名，不影响另一个文件名的访问。
这种情况就被称为"硬链接"（hard link）。 除了硬链接以外，还有一种特殊情况。
文件A和文件B的inode号码虽然不一样，但是文件A的内容是文件B的路径。读取文件A时，系统会自动将访问者导向文件B。
因此，无论打开哪一个文件，最终读取的都是文件B。这时，文件A就称为文件B的"软链接"（soft link）或者"符号链接（symbolic link）。 
这意味着，文件A依赖于文件B而存在，如果删除了文件B，打开文件A就会报错："No such file or directory"。
这是软链接与硬链接最大的不同：文件A指向文件B的文件名，而不是文件B的inode号码，文件B的inode"链接数"不会因此发生变化。
*/

/*
1.
编程题
链接：https://www.nowcoder.com/questionTerminal/9f6b8f6ec26d44cfb8fc8c664b0edb6b

NowCoder生活在充满危险和阴谋的年代。为了生存，他首次发明了密码，用于军队的消息传递。假设你是军团中的一名军官，需要把发送来的消息破译出来、并提
供给你的将军。
消息加密的办法是：对消息原文中的每个字母，分别用该字母之后的第5个字母替换（例如：消息原文中的每个字母A 都分别替换成字母F），
其他字符不变，并且消息原文的所有字母都是大写的。密码中的字母与原文中的字母对应关系如下。
密码字母：A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
原文字母：V W X Y Z A B C D E F G H I J K L M N O P Q R S T U
输入
HELLO WORLD
SNHJ

输出
CZGGJ RJMGY
NICE
*/

/*
题目很容易理解，原文与密码错位5个英文字符
密码字母：A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
原文字母：V W X Y Z A B C D E F G H I J K L M N O P Q R S T U
【解题思路】：密码 > 'E'
则：原文 = 密码 - 5
*/

#include <cstdio>
int main() {
	char c;
	while ((c = getchar()) != EOF)
	{
		if ('A' <= c && 'Z' >= c)
			c = (c > 'E') ? (c - 5) : (c + 21);
		putchar(c);
	} 
	return 0;
}

/*
2.
链接：https://www.nowcoder.com/questionTerminal/e8fb8f89f5d147ec92fd8ecfefe89b0d

一个正整数可以分解成一个或多个数组的积。例如36=2*2*3*3，即包含2和3两个因子。
NowCoder最近在研究因子个数的分布规律，现在给出一系列正整数，他希望你开发一个程序输出每个正整数的因子个数。
*/

/*
题目解析：求一个数字的因子（>=2的最小不能整除数字）个数
解题思路：从最小因子2到数字的最大因子数（数字的平方根）开始判断是否能够取余
可以则循环取余直到取余不为0，因子个数+1；否则使用下一个因子计算；
最终整除了各个因子数之后剩余的数字不为1则本身也是一个因子，因此因子数+1
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		int ret = (int)sqrt(n);
		for (int i = 2; i <= ret; i++)
		{
			if (n % i == 0)
			{
				while (n % i == 0)
					n /= i;

				count++;
			}
		}
		if (n > 1)
			count++;
		cout << count << endl;
	}
	return 0;
}