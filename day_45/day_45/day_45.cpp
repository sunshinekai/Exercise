/*
选择题

设有一个数据库mydb中有一个表tb1，表中有六个字段，主键为ID，有十条记录，ID从0到9，
以下代码输出结果是(C)
A 6
B 4
C 3
D 5

mysql_num_fields 取得结果集中字段的数目select从表中只查找id,name，age。所以是3
*/


/*
编程题

1.
链接：https://www.nowcoder.com/questionTerminal/bb4f1a23dbb84fd7b77be1fbe9eaaf32
nowcoder有两盒（A、B）乒乓球，有红双喜的、有亚力亚的……现在他需要判别A盒
是否包含了B盒中所有的种类，并且每种球的数量不少于B盒中的数量，该怎么办呢？

示例：
输入
ABCDFYE CDE
ABCDGEAS CDECDE

输出
Yes
No
*/

/*
思路1：采用计数排序
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string A, B;
	while (cin >> A >> B)
	{
		int countA[26] = { 0 };
		int countB[26] = { 0 };
		string res = "Yes";
		for (size_t i = 0; i < A.size(); i++)
		{
			countA[A[i] - 'A']++;
		}
		for (size_t i = 0; i < B.size(); i++)
		{
			countB[B[i] - 'A']++;
		}
		int index = 0;
		while (index <= 26)
		{
			if (countA[index] < countB[index])
			{
				res = "No";
				break;
			}
			index++;
		}
		cout << res << endl;
	}
	return 0;
}


/*
思路2：
借助 map 统计出每个盒子中的每种球的类别和数目. 然后遍历其中的一个 map 和另外一个 map 进行对比即可.
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	string str, res;
	while (cin >> str >> res)
	{
		// sta 这个变量表示当前是否满足 B 盒的球在 A 盒中存在, 并且数目不大于 A 盒.
		bool sta = true;
		// strdata 保存了 A 盒的球. key 为球的种类, value 为球的数目
		// resdata 保存了 B 盒的球. key 为球的种类, value 为球的数目
		map<char, int> strdata, resdata;
		// 统计两个盒子中的球的类别和数目
		for (auto c : str)
			strdata[c]++;
		for (auto c : res)
			resdata[c]++;
		// 在 B 盒中遍历球的种类, 和 A 盒的同类球进行数目对比.
		for (map<char, int>::iterator it = resdata.begin(); it != resdata.end(); it++)
		{
			// 只要有一种球数目不满足条件, 就用 sta 标记为 false
			// 反之, 必须所有种类的球都能够满足条件, 才能保持为 true
			if (strdata[it->first] < it->second)
			{
				sta = false;
				break;
			}
		} 
		
		if(true == sta)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	} 
	return 0;
}


/*
2.
查找兄弟单词
链接：https://www.nowcoder.com/questionTerminal/03ba8aeeef73400ca7a37a5f3370fe68
先输入字典中单词的个数，再输入n个单词作为字典单词。
输入一个单词，查找其在字典中兄弟单词的个数
再输入数字n

示例:
输入
3 abc bca cab abc 1
输出
2
bca
*/

/*
【解题思路】：
1. 将字典中的单词先放到 vector 中
2. 将 vector 进行排序
3. isBrother 函数依次判定每个输入的单词是否是兄弟单词
4. 判定兄弟单词的规则是
	1. 先判定长度
	2. 如果长度相同, 再看是否是完全相同(完全相同不算兄弟)
	3. 然后将两个单词排序, 排序相同才是真兄弟单词.
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
// 判定两个单词是否是兄弟单词
bool isBrother(string str, string s){
	// 1. 先判定长度是否相同. 不相同的一定不是兄弟单词
	if (str.size() == s.size()){
		// 2. 再判定字符串是否完全相同. 相同了也不算兄弟三次
		if (str == s)
			return false;
		// 3. 将两个单词排序. 排序后相同才是兄弟单词(因此参数不能用 const&)
		sort(str.begin(), str.end());
		sort(s.begin(), s.end());
		if (str == s)
			return true;
	} 
	return false;
} 
int main(){
	int num;
	while (cin >> num)
	{
		string str;
		string word, s;
		int index;
		vector<string> vs;
		// 读取字典中的单词, 把字典放到 vs 中.
		for (int i = 0; i < num; ++i)
		{
			cin >> str;
			vs.push_back(str);
		} 
		
		// [注意!!] 题意说的是 "字典", 因此要将里面的单词按照字典序排序~否则得到的 k 会存在问题.
		sort(vs.begin(), vs.end());
		// 读入要判定的词和k
		cin >> word;
		cin >> index;
		int counts = 0;
		// 统计字典中存在多少个兄弟单词.
		for (int i = 0; i < num; ++i){
			if (isBrother(word, vs[i])){
				counts++;
				// 将第 k 个兄弟单词保存到 s 中.
				if (counts == index)
					s = vs[i];
			}
		} 
		
		// 最后输出结果
		if (!vs.empty())
			cout << counts << endl;
		if (counts >= index)
			cout << s << endl;
	}
	return 0;
}