/*
选择题

1.
求fun（484）的返回值（A）
bool fun(int n)
{
	int sum = 0;
	for(int i = 1; n > sum; i = i + 2)
		sum = sum + i;
	return (n == sum);
}

A True
B False

注：本题考查1 + 3 + 5 + 7 +...会不会最终等于484
最后可知i = 43时，sum = 484

2.
已知二叉树后序遍历序列是bfegcda，中序遍历序列是badefcg，它的前序遍历序列是(B)
A abcdefg
B abdcefg
C adbcfeg
D abecdfg

注：后序遍历中的最后一个元素是根节点，a，然后查找中序中a的位置，把中序遍历分成
b a defcg，易知左子树为b，右子树为defcg，再递归求解，可画出原始二叉树
         a
	   /   \
      b     d
	         \
			  c
			/   \
           e     g
		   \
		    f
故知前序遍历序列为B。
*/

/*
编程题

1.
链接：https://www.nowcoder.com/practice/fe298c55694f4ed39e256170ff2c205f?tpId=37&&tqId=21245&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”
答案是5瓶，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，
这时候剩2个空瓶子。然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。
如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？

输入
3
10
81

输出
1
5
40
*/

/*
本题题意简单，每次空瓶的数量除以2，直到最后空瓶的数量少于两瓶，就累加到了课兑换的数量
*/

#include<iostream>
#include<string>
using namespace std;
int calculateNum(int num)
{
	//总兑换数
	int sum = 0;
	while (num > 1)
	{
		//每三瓶换一瓶
		int result = num / 3;
		//剩余不足三瓶的先保留
		int reminder = num % 3;
		sum = sum + result;
		//下一次可以兑换的空瓶
		num = result + reminder;
		if (num == 2)
		{
			++sum;
			break;
		}
	}
	return sum;
}

int main()
{
	int number;
	while (cin >> number)
	{
		cout << calculateNum(number) << endl;
	} 
	return 0;
}



/*
2.
链接：https://www.nowcoder.com/practice/181a1a71c7574266ad07f9739f791506?tpId=37&&tqId=21288&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个

输入
abcdefghijklmnop
abcsafjklmnopqrstuv

输出
jklmnop
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		//以最短的字符串作为s1
		if (str1.size() > str2.size())
			swap(str1, str2);
		int len1 = str1.size(), len2 = str2.size();
		int i, j, start = 0, max = 0;
		vector<vector<int>> MCS(len1 + 1, vector<int>(len2 + 1, 0));
		for (i = 1; i <= len1; i++)
		for (j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				MCS[i][j] = MCS[i - 1][j - 1] + 1;
			//如果有更长的公共子串，更新长度
			if (MCS[i][j] > max)
			{
				max = MCS[i][j];
				//以i结尾的最大长度为max, 则子串的起始位置为i - max
				start = i - max;
			}
		}
		cout << str1.substr(start, max) << endl;
	}
	return 0;
}