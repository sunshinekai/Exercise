/*
ѡ����

1.
��fun��484���ķ���ֵ��A��
bool fun(int n)
{
	int sum = 0;
	for(int i = 1; n > sum; i = i + 2)
		sum = sum + i;
	return (n == sum);
}

A True
B False

ע�����⿼��1 + 3 + 5 + 7 +...�᲻�����յ���484
����֪i = 43ʱ��sum = 484

2.
��֪�������������������bfegcda���������������badefcg������ǰ�����������(B)
A abcdefg
B abdcefg
C adbcfeg
D abecdfg

ע����������е����һ��Ԫ���Ǹ��ڵ㣬a��Ȼ�����������a��λ�ã�����������ֳ�
b a defcg����֪������Ϊb��������Ϊdefcg���ٵݹ���⣬�ɻ���ԭʼ������
         a
	   /   \
      b     d
	         \
			  c
			/   \
           e     g
		   \
		    f
��֪ǰ���������ΪB��
*/

/*
�����

1.
���ӣ�https://www.nowcoder.com/practice/fe298c55694f4ed39e256170ff2c205f?tpId=37&&tqId=21245&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
������һ�������⣺��ĳ�̵�涨����������ˮƿ���Ի�һƿ��ˮ��С��������ʮ������ˮƿ���������Ի�����ƿ��ˮ�ȣ���
����5ƿ���������£�����9����ƿ�ӻ�3ƿ��ˮ���ȵ�3ƿ���ģ������Ժ�4����ƿ�ӣ���3���ٻ�һƿ���ȵ���ƿ���ģ�
��ʱ��ʣ2����ƿ�ӡ�Ȼ�������ϰ��Ƚ����һƿ��ˮ���ȵ���ƿ���ģ������Ժ���3����ƿ�ӻ�һƿ���Ļ����ϰ塣
���С��������n������ˮƿ�������Ի�����ƿ��ˮ�ȣ�

����
3
10
81

���
1
5
40
*/

/*
��������򵥣�ÿ�ο�ƿ����������2��ֱ������ƿ������������ƿ�����ۼӵ��˿ζһ�������
*/

#include<iostream>
#include<string>
using namespace std;
int calculateNum(int num)
{
	//�ܶһ���
	int sum = 0;
	while (num > 1)
	{
		//ÿ��ƿ��һƿ
		int result = num / 3;
		//ʣ�಻����ƿ���ȱ���
		int reminder = num % 3;
		sum = sum + result;
		//��һ�ο��Զһ��Ŀ�ƿ
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
���ӣ�https://www.nowcoder.com/practice/181a1a71c7574266ad07f9739f791506?tpId=37&&tqId=21288&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
���������ַ���a,b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ�

����
abcdefghijklmnop
abcsafjklmnopqrstuv

���
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
		//����̵��ַ�����Ϊs1
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
			//����и����Ĺ����Ӵ������³���
			if (MCS[i][j] > max)
			{
				max = MCS[i][j];
				//��i��β����󳤶�Ϊmax, ���Ӵ�����ʼλ��Ϊi - max
				start = i - max;
			}
		}
		cout << str1.substr(start, max) << endl;
	}
	return 0;
}