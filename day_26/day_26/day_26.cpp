/*
选择题

1.
在一个文件被用户进程首次打开的过程中，操作系统需做的是（B）
A 将文件内容读到内存中
B 将文件控制块读到内存中
C 修改文件控制块中的读写权限
D 将文件的数据缓冲区首指针返回给用户进程
注：
系统会在内存中维护一个以打开文件列表，如果打开文的文件不在此列表中，
会将该文件的FCB读取到内存，文件信息都存储在FCB中，然后更新已打开文件列表。

2.
某系统正在执行三个进程 P1、 P2 和 P3， 各进程的计算（CPU）时间和 I/O 时间比例如下表所示。

 进程 计算时间 I/O时间
  P1     90%     10%
  P2     50%     50%
  P3     15%     85%
为提高系统资源利用率，合理的进程优先级设置应为（A）

A P1>P2>P3
B P3>P2>P1
C P2>P1=P3
D P1>P2=P3
注：
为了合理地设置进程优先级，应该将进程的CPU利用时间和I/O时间做综合考虑，答案选B

3.
设系统缓冲区和用户工作区均采用单缓冲，从外设读入1 个数据块到系统缓冲区的时间为 100，从系统缓冲区读入 1 个数据块到用户工作区的时间为 5， 对用户工作
区中的 1 个数据块进行分析的时间为 90（如下图所示）。进程从外设读入并分析 2 个数据块的最短时间是(C)
A 200
B 295
C 300
D 390
注：
数据块1从外设到用户工作区的总时间为105，在这段时间中，
数据块2没有进行操作。在数据块1进行分析处理时，
数据块2从外设到用户工作区的总时间为105，这段时间是并行的。
再加上数据块2进行处理的时间90，总共是300
*/



/*
编程题：

1.
链接：https://www.nowcoder.com/questionTerminal/22243d016f6b47f2a6928b4313c85387
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

/*
【题目解析】：这个题目很容易理解，不过公式推导有些麻烦
假定第一次跳的是一阶，那么剩下的是n-1个台阶，跳法是f(n-1)； 假定第一次跳的是2阶，那么剩下的是n-2个台
阶，跳法是f(n-2)； 假定第一次跳的是3阶，那么剩下的是n-3个台阶，跳法是f(n-3)...... 假定第一次跳的是n-1阶，
那么剩下的是1个台阶，跳法是f(1)； 假定第一次跳的是n阶，那么剩下的是0个台阶，跳法是1种；

【解题思路】：
根据题图解析可以得出有一阶的时候 f(1) = 1 ； 有两阶的时候可以有 f(2) = 1+f(1)=2； 有三阶的时候可以有 f(3) =
1+f(2)+f(1)=4;
...
总跳法为: f(n) = 1+f(n-1) + f(n-2)+....+f(1) （第一个1是跳n阶只有一种方法）
依次类推，得到类推公式有n阶时：f(n)=2^(n-1)
*/

class Solution {
public:
	int jumpFloorII(int number) {
		//2^(n-1) == 1 << (n-1)
		return 1 << (number - 1);
		// return pow(2, number - 1);
	}
};



/*
2.
链接：https://www.nowcoder.com/questionTerminal/82424d93369649b98720743c25edc6ce

小喵们很喜欢把自己装进容器里的（例如碗），但是要是碗的周长比喵的身长还短，它们就进不去了。
现在告诉你它们的身长，和碗的半径，请判断一下能否到碗里去。
*/

/*
通过输入碗半径计算得到周长，与输入的猫的身长相比较
*/

#include <iostream>

using namespace std;

int main()
{
	double height, radius;
	while (cin >> height >> radius)
	{
		double perimeter = 2 * 3.14 * radius;
		if (height <= perimeter)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}