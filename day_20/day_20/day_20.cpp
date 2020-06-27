/*
�����

1.
���ӣ�https://www.nowcoder.com/practice/e45e078701ab4e4cb49393ae30f1bb04?tpId=37&&tqId=21235&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

д��һ�����򣬽���һ���ַ�����Ȼ��������ַ�����ת����ַ��������ַ������Ȳ�����1000��

����
abcd
���
dcba
*/

/*
�ַ�����ת����Ҫ������β�ַ���������β����λ��start��end��
ÿ�ν�����β�ַ���Ȼ��start++, end--��ֱ��start��end��������ת���
*/


#include<iostream>
#include<string>
using namespace std;

string reverseString(string s)
{
	if (s.empty())
		return s;
	size_t start = 0;
	size_t end = s.size() - 1;

	while (start < end)
	{
		swap(s[start], s[end]);
			++start;
		--end;
	} 
	return s;
} 
int main()
{
	string s;
	getline(cin, s);
	cout << reverseString(s) << endl;
	return 0;
}



/*
2.
���ӣ�https://www.nowcoder.com/practice/98dc82c094e043ccb7e0570e5342dd1b?tpId=37&&tqId=21298&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
���������ַ�������󹫹��ִ��ĳ��ȣ��ַ������ִ�Сд��
����
asdfas
werasdfaswer
���
6
*/

/*
˼·������󹫹��Ӵ���ʹ�õ���ʵ�� ���� x(i): �ַ�����i���ַ� y(j): �ַ�����j���ַ� dp[i][j]: ��x(i),y(j)��β����
���Ӵ����� ���磺x: "abcde" y:"bcdae" dp[2][1]: ��x(2),y(1)��β������Ӵ����� ����x������"abc", y����
��"bc", �����ַ�'c'��βʱ��󹫹��Ӵ�Ϊ"bc" �ʣ�������dp[i][j]ʱ�����ȿ�x(i),y(j)��ֵ�� ��1��: x(i) == y(j)
��ǰ�����ַ�����β���ַ���ȣ�dp[i][j] = dp[i-1][j-1] + 1 �������ĳ��ȼ�1 ��2��: x(i) != y(j) ��ǰ�����ַ�
����β���ַ�����ȣ�˵��û�����������ַ���β�Ĺ����Ӵ� ��dp[i][j] = 0 ��3��: dp[0][j] �� dp[i][0]��ʾ��
ĳ���Ӵ��ĵ�һ���ַ���β����󳤶�Ϊ1 ���x(0) == y(j) ���� x(i) == y(0), �򳤶�Ϊ1������Ϊ0 ��dp�е�
����Ԫ�ؼ�����֮�󣬴����Ҵ�����ֵ���
*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int max = 0; //max��ֵ.
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int len1 = str1.size();
		int len2 = str2.size();
		int max = 0;
		//����ֵ��ʼ��Ϊ0
		vector<vector<int>> dp(len1, vector<int>(len2, 0));
		//����dp
		for (int i = 0; i < len1; i++)
		{
			for (int j = 0; j < len2; j++)
			{
				//�����ǰ��β���ַ���ȣ�����dp[i-1][j-1]�Ļ����ϼ�1
				if (str1[i] == str2[j])
				{
					if (i >= 1 && j >= 1)
						dp[i][j] = dp[i - 1][j - 1] + 1;
					else
						//dp[i][0] or dp[0][j]
						dp[i][j] = 1;
				}
				//�������ֵ
				if (dp[i][j] > max)
					max = dp[i][j];
			}
		}
		cout << max << endl;
	}
}