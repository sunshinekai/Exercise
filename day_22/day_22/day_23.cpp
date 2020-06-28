/*
选择题

循环两列放在一维数组A[0…M-1]中，end1指向队头元素，end2指向队尾元素的后一个位置。假设队列两端
均可进行入队和出队操作，队列中最多能容纳M-1个元素。初始时为空，下列判断队空和队满的条件中，正
确的是(A)

A 队空：end1==end2； 队满：end1==(end2+1)modM
B 队空：end1==end2; 队满：end2==(end1+1)mod(M-1)
C 队空：end2==(end1+1)modM ; 队满：end1==（end2+1）modM
D 队空：end1==（end2+1）modM; 队满：end2==(end1+1)mod(M-1)

注：当满时，end2指向M-1，此时end1指向0。end2+1对应等于M，故(end2 + 1)% M ＝ 0 ＝ end1
当空时end1 = end2
*/



/*
编程题

1.
链接：https://www.nowcoder.com/practice/fe6c73cb899c4fe1bdd773f8d3b42c3d?tpId=49&&tqId=29329&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
小易经常沉迷于网络游戏.有一次,他在玩一个打怪升级的游戏,他的角色的初始能力值为 a.
在接下来的一段时间内,他将会依次遇见n个怪物,每个怪物的防御力为b1,b2,b3...bn. 
如果遇到的怪物防御力bi小于等于小易的当前能力值c,那么他就能轻松打败怪物,
并且使得自己的能力值增加bi;如果bi大于c,那他也能打败怪物,
但他的能力值只能增加bi 与c的最大公约数.那么问题来了,在一系列的锻炼后,小易的最终能力值为多少?

输入
3 50
50 105 200

5 20
30 20 15 40 100

输出
110

205
*/

/*
思路：本题的能力值的累加分两种情况，一种是直接相加bi,一种是累加当前能力值于bi的最大公约数。最大公约数
可以通过碾转相除法求得：a与b的最大公约数相当于b与a,b余数的最大公约数。如果求余结果为0， 则b为所
求结果
*/

#include <iostream>
#include <vector>

using namespace std;
int maxnum(int a, int b)
{
	int r;
	while (r = a % b)
	{
		a = b;
		b = r;
	}
	return b;
}
int main()
{
	int n, c;
	while (cin >> n >> c)
	{
		while (n--)
		{
			vector<int> v;
			for (auto &e : v)
				cin >> e;
			for (auto & e : v)
			{
				if (c >= e)
					c += e;
				else
					c += maxnum(c, e);
			}
			cout << c << endl;
		}
	}
	return 0;
}


/*
2.
链接：https://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4?tpId=37&&tqId=21282&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
找出字符串中第一个只出现一次的字符

输入：
asdfasdfo
输出
o
*/

/*
思路：
用一个数组的每一个位置表示对应的位置。对应的字符位置存放字符出现的次数。统计完之后，遍历输入字
符，遇到第一个只出现一次的字符就停止
*/

#include <string>
#include <iostream>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		int hashtable[256] = { 0 };
		for (auto& e : s)
		{
			hashtable[e]++;
		} 
		int i;
		for (i = 0; i < s.size(); i++)
		{
			if (hashtable[s[i]] == 1)
			{
				cout << s[i] << endl;
				break;
			}
		} 
		if(i >= s.size())
			cout << -1 << endl;
	} 
	return 0;
}
