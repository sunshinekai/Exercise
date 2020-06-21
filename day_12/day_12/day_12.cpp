/*
选择题

1.
下面程序的输出结果是(D)。

#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
using namespace std;
#define SQR(A) A*A
void main() 
{
	int x = 6, y = 3, z = 2;
	x /= SQR(y + z) / SQR(y + z);
	cout << x << endl;
}

A 5
B 6
C 1
D 0

注：x = 6 / (3 + 2 * 3 + 2 / 3 + 2 * 3 + 2) = 6 / 17 = 0;

2.
在一个64位的操作系统中定义如下结构体：

struct st_task
{
	uint16_t id;
	uint32_t value;
	uint64_t timestamp;
};

同时定义fool函数如下：
void fool()
{
	st_task task = {};
	uint64_t a = 0x00010001;
	memcpy(&task, &a, sizeof(uint64_t));
	printf("%11u,%11u,%11u", task.id, task.value, task.timestamp);
}

上述fool()程序的执行结果为（A）
A 1，0，0
B 1，1，0
C 0，1，1
D 0，0，1

注：要考虑内存对齐，uint16_t、unit32_t、unit64_t分别占2个字节、4个字节、8个字节，
    取中间4个字节为对齐单位，设为m，则对齐后，
　　unit16_t占1个对齐单位m，即4个字节；
　　unit32_t占1个对齐单位m，即4个字节；
　　unit64_t占2个对齐单位2m，即8个字节。
　　也就是：
　　id 占 4个字节，但是高2个字节无效，存储 0x0001 0001，实际为 0x0000 0001；
　　value 占4个字节， 存储 0x0000 0000，实际为 0x0000 0000 ；
　　timestamp 占8个字节， 存储 0x00000000 00000000 ，实际为 0x00000000 00000000。
所以：答案是 1 0 0
*/

/*
编程题

1.
链接：https://www.nowcoder.com/practice/30c1674ad5694b3f8f0bc2de6f005490?tpId=8&&tqId=11019&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
有两个32位整数n和m，请编写算法将m的二进制数位插入到n的二进制的第j到第i位,
其中二进制的位数从低位数到高位且以0开始。
给定两个数int n和int m，同时给定int j和int i，意义如题所述，
请返回操作后的数，保证n的第j到第i位均为零，且m的二进制位数小于等于i-j+1。

测试样例：
1024，19，2，6
返回：1100
*/

/*
思路：i j
m:1024：100000000 00 n:19 ： 10011 要把n的二进制值插入m的第j位到第i位，只需要把n先左移j位，然
后再进行或运算（|）即可。
m: 10000000000
n: 00001001100
10001001100
*/

class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		m <<= j;
		return n | m;
	}
};


/*
2.
链接：https://www.nowcoder.com/practice/f8538f9ae3f1484fb137789dec6eedb9?tpId=37&&tqId=21283&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，
本题目要求输出组成指定偶数的两个素数差值最小的素数对

输入
20
输出
7
13
*/

/*
本题首先需要判断素数，素数表示除过1和本身，不能被其它数整除。通过循环遍历来判断一个数是否为素
数。最近的两个素数应该从最中间的位置开始向两边查找。
*/

#include<iostream>
#include<algorithm>
using namespace std;
//判断素数
bool isPrime(int num)
{
	int tmp = sqrt(num);
	//只遍历到开方出，不能被开方左边的数整除，则一定不能被开方右边的数整除
	for (int i = 2; i <= tmp; i++)
	{
		if (num %i == 0)
			return false;
	} 
	return true;
} 
int main()
{
	int num;
	int half;
	int i;
	while (cin >> num)
	{
		half = num / 2;
		//从中间向两边找
		for (i = half; i > 0; i--)
		{
			if (isPrime(i) && isPrime(num - i))
				break;
		} 
		cout << i << endl << num - i << endl;
	} 
	return 0;
}