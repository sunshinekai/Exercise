/*
ѡ����
���³�������ʱ��������1abcedf2df<�س�>��������(C)

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
int main()
{
	char a = 0, ch;

	while ((ch = getchar()) != '\n')
	{
		if (a % 2 != 0 && (ch >= 'a' &&ch <= 'z'))
		ch = ch - 'a' + 'A';
		a++;
		putchar(ch);
	}
	printf("\n");
}

A 1abcedf2df
B 1ABCEDF2DF
C 1AbCeDf2dF
D 1abceDF2DF
*/



/*
�����

1.
���ӣ�https://www.nowcoder.com/practice/1183548cd48446b38da501e58d5944eb?tpId=85&&tqId=29840&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
����С����һ��W*H��������ӣ�������б��Ϊ0~H-1��������б��Ϊ0~W-1��ÿ������������Է�һ�鵰�⣬
�������鵰���ŷ����þ��벻�ܵ���2������������������(x1,y1),(x2,y2)��ŷ����þ���Ϊ:
((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2)) ������ƽ����
С����֪�������ԷŶ��ٿ鵰������������
ʾ����
����
3 2
���
4
*/


/*
�ⷨ1��
˼·��ʹ��vector<vector<int>>����һ����ά���飬resize���ռ䲢��ʼ����
ÿ��λ�ó�ʼ��Ϊ1����ʾ�����⣬a[i][j]λ�÷ŵ��⣬����Ա�Ǵ�a[i][j+2]��a[i+1][j]λ��
���ܷŵ��⣬����һ���ά���飬��Ǵ����ܷŵ����λ�ã�ͳ��Ҳ��ͳ�Ƴ��˵������λ������
*/

#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int w, h, res = 0;
	cin >> w >> h;
	vector<vector<int>> a;
	a.resize(w);
	for (auto& e : a)
		e.resize(h, 1);
	for (int i = 0; i<w; i++)
	{
		for (int j = 0; j<h; j++)
		{
			if (a[i][j] == 1)
			{
				res++;
				// ��ǲ��ܷŵ����λ��
				if ((i + 2)<w)
					a[i + 2][j] = 0;
				if ((j + 2)<h)
					a[i][j + 2] = 0;
			}
		}
	}
	cout << res;
	return 0;
}

/*
�ⷨ2��
�ܽ���ɡ����ù�ʽ
*/

#include<iostream>

using namespace std;
int main()
{
	int W, H;
	while (cin >> W >> H)
	{
		int count = 0;
		if ((W % 4 == 0) || (H % 4 == 0))
			count = W * H / 2;
		else if ((W % 2 == 0) && (H % 2 == 0))
			count = (W * H / 4 + 1) * 2;
		else
			count = W * H / 2 + 1;
		cout << count << endl;
	}
	return 0;
}



/*
2.
��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0
���ӣ�https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp=6&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
��������:
����һ���ַ���,����������ĸ����,����Ϊ��
�������:
����ǺϷ�����ֵ����򷵻ظ����֣����򷵻�0
ʾ����
����
+2147483647
1a33
���
2147483647
0
*/


/*
˼·������Ĺؼ���Ҫ�������ؼ��߽�������
1. ���ַ���
2. �����Ŵ���
3. ���ִ��д��ڷǷ��ַ�
4. �ַ�����������
*/


class Solution {
public:
	int StrToInt(string str) {
		int ret = 0;
		if (str.empty())
			return 0;
		int flag = 1;
		size_t i = 0;
		if (str[0] == '+' || str[0] == '-')
			i = 1;
		if (str[0] == '-')
			flag = -1;
		for (; i < str.size(); i++)
		{
			if (str[i] < '0' || str[i] > '9'
				|| str == "-2147483649"
				|| str == "2147483648")
				return 0;
			ret = ret * 10 + (str[i] - '0');
		}
		return (ret * flag);
	}
};