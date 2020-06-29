/*
选择题

1.
在双向循环链表中，在p指针所指的节点后插入一个指针q所指向的新节点，修改指针的操作是(C)

A p->next=q;q->prior=p;p->next->prior=q;q->next=q;
B p->next=q;p->next->prior=q;q->prior=p;q->next=p->next;
C q->prior=p;q->next=p->next;p->next->prior=q;p->next=q;
D q->next=p->next;q->prior=;p->next=q;p->next=q;
注：q的左指针赋为p的左指针，q的右指针赋为p，
这两步可以互换；然后将p的左指针指向的结点的右指针赋为q；最后将p的左指针赋为q所以应选C

2.
已知一个线性表（38，25，74，63，52，48），假定采用散列函数h（key) = key%7 
计算散列地址，并散列存储在散列表A【0....6】中，若采用线性探测方法解决
冲突，则在该散列表上进行等概率成功查找的平均查找长度为(C)
A．1.4
B．1.6
C．2.0
D．2.2
注：照散列函数h(key)=key%7和线性探测方法解决冲突将线性表(38,25,74,63,52,48)散列存储在散列表A[0…6]
在该散列表上进行等概率成功查找的平均查找长度。
*/



/*
1.
链接：https://www.nowcoder.com/practice/fbcf95ed620f42a88be24eb2cd57ec54?tpId=49&&tqId=29311&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
【微信红包】
春节期间小明使用微信收到很多个红包，非常开心。在查看领取红包记录时发现，某个红包金额出现的次数超过了红包总数的一半。请帮小明找到该红包金额。写出
具体算法思路和代码实现，要求算法尽可能高效。
给定一个红包的金额数组gifts及它的大小n，请返回所求红包的金额。
若没有金额超过总数的一半，返回0。

[1,2,3,2,2],5
返回：2
*/

/*
思路1：如果一个数出现次数超过一半了，排序过后，必然排在中间，则最后遍历
整个数组查看是否符合即可。
*/

class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		sort(gifts.begin(), gifts.end());
		//超过一半的数排序之后必然排在中间
		int middle = gifts[n / 2];
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			//统计排在中间的数的个数
			if (gifts[i] == middle)
				count++;
		} 
		// 如果个数大于一半，则存在超过一半的数
		if (count > n / 2)
			return middle;
		else
			return 0;
	}
};

/*
思路2：可以用map统计每个数字出现的次数，最后判断有没有超过一半的
数字
*/

class Gift {
public:
	int getValue(vector<int> gifts, int n) 
	{
		map<int, int> count;
		int middle = n / 2;
		for (const auto& e : gifts)
			++count[e];

		for(const auto& e : count)
		{
			if (e.second >= middle)
				return e.first;
		} 
		return 0;
	}
};



/*
2.
链接：https://www.nowcoder.com/practice/3959837097c7413a961a135d7104c314?tpId=37&&tqId=21275&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

Levenshtein 距离，又称编辑距离，指的是两个字符串之间，由一个转换成另一个所需的最少编辑操作次数。
许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。
编辑距离的算法是首先由俄国科学家Levenshtein提出的，故又叫Levenshtein Distance。
Ex：
字符串A:abcdefg
字符串B: abcdef
通过增加或是删掉字符”g”的方式达到目的。
这两种方案都需要一次操作。把这个操作所需要的次数定义为两个字符串的距离。
要求：
给定任意两个字符串，写出一个算法计算它们的编辑距离。
*/

/*
F(i,j):word1的前i个字符于word2的前j个字符的编辑距离 状态递推： F(i,j) = min { F(i-1,j）+1, F(i,j-1) +1, F(i-
1,j-1) +(w1[i]==w2[j]?0:1) } 上式表示从删除，增加和替换操作中选择一个最小操作数 F(i-1,j): w1[1,...,i-1]于
w2[1,...,j]的编辑距离，删除w1[i]的字符--->F(i,j) F(i,j-1): w1[1,...,i]于w2[1,...,j-1]的编辑距离，增加一个字符---
>F(i,j) F(i-1,j-1): w1[1,...,i-1]于w2[1,...,j-1]的编辑距离，如果w1[i]与w2[j]相同， 不做任何操作，编辑距离不
变，如果w1[i]与w2[j]不同，替换w1[i]的字符为w2[j]--->F(i,j) 初始化： 初始化一定要是确定的值，如果这里
不加入空串，初始值无法确定 F(i,0) = i :word与空串的编辑距离，删除操作 F(0,i) = i :空串与word的编辑距
离，增加操作 
返回结果：F(m,n)
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int minDistance(string word1, string word2)
{
	// word与空串之间的编辑距离为word的长度
	if (word1.empty() || word2.empty())
		return max(word1.size(), word2.size());

	int len1 = word1.size();
	int len2 = word2.size();
	// F(i,j)初始化
	vector<vector<int> > f(1 + len1, vector<int>(1 + len2, 0));
	for (int i = 0; i <= len1; ++i)
		f[i][0] = i;

	for (int i = 0; i <= len2; ++i)
		f[0][i] = i;

	for (int i = 1; i <= len1; ++i)
	{
		for (int j = 1; j <= len2; ++j)
		{
			// F(i,j) = min { F(i-1,j）+1, F(i,j-1) +1, F(i-1,j-1) +
			//(w1[i]==w2[j]?0:1) }
			// 判断word1的第i个字符是否与word2的第j个字符相等
			if (word1[i - 1] == word2[j - 1])
			{
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
				// 字符相等，F(i-1,j-1)编辑距离不变
				f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			}
			else
			{
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]);
				// 字符不相等，F(i-1,j-1)编辑距离 + 1
				f[i][j] = min(f[i][j], 1 + f[i - 1][j - 1]);
			}
		}
	}
	return f[len1][len2];
}

int main()
{
	string a, b;
	while (cin >> a >> b)
		cout << minDistance(a, b) << endl;
	return 0;
}